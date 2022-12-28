cmake_minimum_required(VERSION 3.0.0)
set(LIBRARY_NAME jelly)
set(JLY_SOURCE_DIR src)
set(JLY_LIBRARIES_DIR libs)
set(JLY_LIBRARIES glfw glm assimp)
set(IGD ${JLY_LIBRARIES_DIR}/imgui/)
set(SOURCE_FILES 
    # imgui
    ${IGD}/imgui.cpp
    ${IGD}/imgui_demo.cpp
    ${IGD}/imgui_draw.cpp
    ${IGD}/imgui_impl_glfw.cpp
    ${IGD}/imgui_impl_opengl3.cpp
    ${IGD}/imgui_tables.cpp
    ${IGD}/imgui_widgets.cpp

    # glad
    ${JLY_LIBRARIES_DIR}/glad/glad.c

    #JLY
    ${JLY_SOURCE_DIR}/window.cpp
    ${JLY_SOURCE_DIR}/object.cpp
    ${JLY_SOURCE_DIR}/shader.cpp
    ${JLY_SOURCE_DIR}/scene.cpp
    ${JLY_SOURCE_DIR}/translation.cpp
    ${JLY_SOURCE_DIR}/camera.cpp
    ${JLY_SOURCE_DIR}/input.cpp
)


project(${LIBRARY_NAME})

add_library(${LIBRARY_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${LIBRARY_NAME} PRIVATE ${JLY_LIBRARIES_DIR}/glad)
target_include_directories(${LIBRARY_NAME} PRIVATE ${JLY_LIBRARIES_DIR}/assimp/include)
target_include_directories(${LIBRARY_NAME} PRIVATE ${JLY_LIBRARIES_DIR})

foreach(LIBRARY ${JLY_LIBRARIES})
    add_subdirectory("${JLY_LIBRARIES_DIR}/${LIBRARY}")
endforeach(LIBRARY)
target_link_libraries(${LIBRARY_NAME} ${JLY_LIBRARIES})
