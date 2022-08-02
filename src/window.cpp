#include <stdio.h>
#include <iostream>
#include <filesystem>
#include "internal.hpp"
#include <glm/glm.hpp>
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#define PI 3.1415

void print() {
    std::cout << "here " << std::endl;
};


void RenderScene(Scene scene){

    GLFWwindow* window;
    const char* glsl_version = "#version 450";
    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;
 
    if (!glfwInit())
        exit(EXIT_FAILURE);
 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
 
    window = glfwCreateWindow(1000, 640, "Test", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
 
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
    }
    glfwSwapInterval(1);

    std::string vs = parseShader("/home/josh/cpp/jelly/shaders/basic.vert");
    std::string fs = parseShader("/home/josh/cpp/jelly/shaders/basic.frag");
    unsigned int vs_compiled = compileShader(GL_VERTEX_SHADER, vs.c_str());
    unsigned int fs_compiled = compileShader(GL_FRAGMENT_SHADER, fs.c_str());
    
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vs_compiled);
    glAttachShader(shaderProgram, fs_compiled);
    glLinkProgram(shaderProgram);

    // generating and configuring buffers
    unsigned int VAO[scene.objects.size()], VBO[scene.objects.size()], EBO[scene.objects.size()];

    glGenVertexArrays(scene.objects.size(), &VAO[0]);
    glGenBuffers(scene.objects.size(), &VBO[0]);
    glGenBuffers(scene.objects.size(), &EBO[0]);

    for (int i=0; i<scene.objects.size(); i++) {
        Object cur_obj = scene.objects[i];
        float verticies[cur_obj.verticies.size()*3];
        int triangles[cur_obj.triangles.size()*3];

        for (int j=0; j<sizeof(verticies)/sizeof(float); j+=3) {
            verticies[j+0] = cur_obj.verticies[j/3].x;
            verticies[j+1] = cur_obj.verticies[j/3].y;
            verticies[j+2] = cur_obj.verticies[j/3].z;
        };
        for (int j=0; j<sizeof(triangles)/sizeof(int); j+=3) {
            triangles[j+0] = cur_obj.triangles[j/3].x;
            triangles[j+1] = cur_obj.triangles[j/3].y;
            triangles[j+2] = cur_obj.triangles[j/3].z;
        };

        glBindVertexArray(VAO[i]);
        glBindBuffer(GL_ARRAY_BUFFER,VBO[i]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO[i]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangles), triangles, GL_STATIC_DRAW);

        glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    };

    // imgui initialization
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
 
    glUseProgram(shaderProgram);
    glm::vec3 obrot = glm::vec3(0);
    glm::vec3 obtrans = glm::vec3(1);
    glm::vec3 obscale= glm::vec3(1);
    while (!glfwWindowShouldClose(window)) {
        glEnable(GL_DEPTH_TEST);  
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        float ratio = (float)display_w / (float)display_h;
        glfwPollEvents();
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.1,0.3,0.8,1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        for (int i=0; i<scene.objects.size(); i++){
            Object cur_obj = scene.objects[i];
            glm::mat4 rotate = getRotationMatrix(cur_obj.rotation);
            glm::mat4 translate = getTranslationMatrix(cur_obj.translation);
            glm::mat4 scaling= getScaleMatrix(cur_obj.scaling);
            setUniform4matF("rotation", rotate, shaderProgram);
            setUniform4matF("translation", translate, shaderProgram);
            setUniform4matF("scaling", scaling, shaderProgram);
            glBindVertexArray(VAO[i]);
            glDrawElements(GL_TRIANGLES, scene.objects[i].triangles.size()*3, GL_UNSIGNED_INT, 0);
        }

        //my imgui debugger
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::Begin("Debugger");
        ImGui::Text("hello wold %i \n", (int)scene.objects[0].triangles[0].y);
        ImGui::SliderFloat3("rotation", &scene.objects[0].rotation.x, 0.0f, 4*PI);
        ImGui::SliderFloat3("translation", &scene.objects[0].translation.x, -1.0f, 1.0f);
        ImGui::SliderFloat3("scaling", &scene.objects[0].scaling.x, -1.0f, 1.0f);
        ImGui::End();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }
 
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
 
    glfwTerminate();
    exit(EXIT_SUCCESS);
};

