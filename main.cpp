#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include "material.h"
#include "geometry.h"
#include "object.h"
#include "renderer.h"
#include "vert_buf_data.h"

#include <GLFW/glfw3.h>
GLFWwindow* window;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#define VSHADERPATH "shaders/bump.vert"
#define FSHADERPATH "shaders/bump.frag"

// #define VSHADERPATH "shaders/lambert_blinn_phong.vert"
// #define FSHADERPATH "shaders/lambert_blinn_phong.frag"

// #define TEXPATH "textures/wall_512_1_05.tga"

// #define TEXPATH "textures/coin1.jpg"
#define TEXPATH "textures/coin2.png"
// #define TEXPATH "textures/metal.png"

#define ROTANGLE   1.0f

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
    // Geometry rect = GenSquare();
    Geometry cube = GenCube();

    // cube.PrintVertData();

    // MyObject obj(rect, my_material);
    MyObject obj("cube", cube, my_material);
    obj.SetTexture(TEXPATH);

    Renderer render;

    // render.SetCamera(view, projection);
    render.AddObject(obj);

    // float angle = 0.0f;

    // main loop
    do {
        // clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        double cur_time = glfwGetTime();

        render.SetTime(cur_time);
        // double delta_time = cur_time - last_time;
        // last_time = cur_time;

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            // render.CameraMoveLeft();
            render.ObjRotateLeft("cube");
	}

	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
            render.ObjRotateRight("cube");
	}

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
            render.ObjRotateUp("cube");
	}

	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
            render.ObjRotateDown("cube");
	}

        if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS){
            render.ResetCamera();
            render.ObjResetRotationMatrix("cube");
	}

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            render.CameraMoveForward();
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            render.CameraMoveLeft();
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
            render.CameraMoveBackward();
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
            render.CameraMoveRight();
	}

        if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS){
            render.CameraMoveUp();
	}

        if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS){
            render.CameraMoveDown();
	}

        render.SetTime(cur_time);
        render.Render();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
        // check if the ESC key was pressed or the window was closed
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

    // move it from here
    // cleanup VBO and shader
    // glDeleteBuffers(1, &buffer_data_id);
    // glDeleteProgram(program_id);

    glDeleteVertexArrays(1, &vao_id);

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
