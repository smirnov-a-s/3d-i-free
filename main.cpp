#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include "material.h"
#include "geometry.h"
#include "object.h"

#include "vert_buf_data.h"

#include <GLFW/glfw3.h>
GLFWwindow* window;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#define FSHADERPATH "shaders/frag_shader.frag"
#define VSHADERPATH "shaders/vert_shader.vert"

#define TEXPATH "textures/wall_512_1_05.tga"

int main(void)
{
    // init GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // open a window and create its OpenGL context
    window = glfwCreateWindow(1024, 768, "GLFW", NULL, NULL);

    if (window == NULL) {
        fprintf(stderr, "Failed to open GLFW window!\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // init GLEW
    glewExperimental = true;         // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }

    // ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // dark blue background
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    // enable depth test
    glEnable(GL_DEPTH_TEST);

    // accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    // ???
    GLuint vao_id;
    glGenVertexArrays(1, &vao_id);
    glBindVertexArray(vao_id);

    Material my_material(VSHADERPATH, FSHADERPATH);
    Geometry rect = GenSquare();

    rect.LogVertexData();
    rect.LoadData();

    MyObject obj(rect.GetVertexBufId(), rect.GetElemBufId(), rect.GetElemBufSize(), my_material.GetProgId());

    obj.BindUniforms();
    obj.BindTex(TEXPATH);

    // main loop
    do {
        // clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        double cur_time = glfwGetTime();
        // double delta_time = cur_time - last_time;
        // last_time = cur_time;

        // Send our transformation to the currently bound shader, in the "MVP" uniform
        // glUniformMatrix4fv(matrix_id, 1, GL_FALSE, &mvp[0][0]);

        // glUniform1f(time_id, cur_time);
        obj.Draw();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
        // check if the ESC key was pressed or the window was closed
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

    // move it from here
    // cleanup VBO and shader
    // glDeleteBuffers(1, &buffer_data_id);
    // glDeleteProgram(program_id);
    // glDeleteVertexArrays(1, &vao_id);

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
