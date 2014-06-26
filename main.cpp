#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include <GLFW/glfw3.h>
GLFWwindow* window;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "utils/loadshaders.h"
#include "buffer_data.h"

#define BUFFER_OFFSET(x)  ((const void*) (x))

int main(void)
{
        // sliced surface CRUDE test init
        int num_squares = 16;
        int data_size = num_squares * 30;

        // float buffer_data[size];
        float* data = (float*) malloc(data_size * sizeof(float));

        float delta_coord = 0.5f;
        float delta_tex = 0.25f;

        float x = -1.0f;
        float y = -1.0f;
        // float z = 0.0f;

        float xt = 0.0f;
        float yt = 0.0f;

        printf("%f %f %f %f %f\n", x, y, 0.0f, xt, yt);

        for (int i = 0; i < data_size;) {
                // v1
                data[i] = x;
                data[i + 1] = y;
                data[i + 2] = 0.0f;
                data[i + 3] = xt;
                data[i + 4] = yt;

                // v2
                data[i + 5] = x + delta_coord;
                data[i + 6] = y;
                data[i + 7] = 0.0f;
                data[i + 8] = xt + delta_tex;
                data[i + 9] = yt;

                // v3
                data[i + 10] = x;
                data[i + 11] = y + delta_coord;
                data[i + 12] = 0.0f;
                data[i + 13] = xt;
                data[i + 14] = yt + delta_tex;

                // v1
                data[i + 15] = x + delta_coord;
                data[i + 16] = y;
                data[i + 17] = 0.0f;
                data[i + 18] = xt + delta_tex;
                data[i + 19] = yt;

                // v2
                data[i + 20] = x + delta_coord;
                data[i + 21] = y + delta_coord;
                data[i + 22] = 0.0f;
                data[i + 23] = xt + delta_tex;
                data[i + 24] = yt + delta_tex;

                // v3
                data[i + 25] = x;
                data[i + 26] = y + delta_coord;
                data[i + 27] = 0.0f;
                data[i + 28] = xt;
                data[i + 29] = yt + delta_tex;

                x += delta_coord;
                xt += delta_tex;

                i += 30;

                if (x >= 1.0f) {
                        x = -1.0f;
                        xt = 0.0f;

                        y += delta_coord;
                        yt += delta_tex;

                        printf("%f %f %f %f %f\n", x, y, 0.0f, xt, yt);
                }
        }

        //

	// init GLFW
	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}

        // glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// open a window and create its OpenGL context
	window = glfwCreateWindow(1024, 768, "GLFW", NULL, NULL);

	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible.\n");
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

        // vertex array object id
        GLuint vao_id;
        glGenVertexArrays(1, &vao_id);
	glBindVertexArray(vao_id);

	// create and compile our GLSL program from the shaders
	GLuint program_id = LoadShaders("vert_shader.vert", "frag_shader.frag");

	// get a handle for our "MVP" uniform
	GLuint matrix_id = glGetUniformLocation(program_id, "mvp");
	// get a handle for our time uniform
        GLuint time_id = glGetUniformLocation(program_id, "time");

	// projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

	// camera matrix
	glm::mat4 view = glm::lookAt(glm::vec3(4,3,-3),  // Camera is at (4,3,-3), in World Space
                                     glm::vec3(0,0,0),   // and looks at the origin
                                     glm::vec3(0,1,0));  // Head is up (set to 0,-1,0 to look upside-down)

	// model matrix : an identity matrix (model will be at the origin)
	glm::mat4 model = glm::mat4(1.0f);

	// our ModelViewProjection : multiplication of our 3 matrices
	glm::mat4 mvp = projection * view * model; // Remember, matrix multiplication is the other way around

	GLuint buffer_data_id;
	glGenBuffers(1, &buffer_data_id);
	glBindBuffer(GL_ARRAY_BUFFER, buffer_data_id);
	// glBufferData(GL_ARRAY_BUFFER, sizeof(buffer_data), buffer_data, GL_STATIC_DRAW);
        // float* buffer_data = NULL;
        // int size;
        // get_buffer_data(buffer_data, &size);

        // printf("%d\n", size);
#ifndef FLAG
        glBufferData(GL_ARRAY_BUFFER, sizeof(buffer_data), buffer_data, GL_STATIC_DRAW);
#else
        glBufferData(GL_ARRAY_BUFFER, data_size * sizeof(float), data, GL_STATIC_DRAW);
#endif

        // vertex position
        glVertexAttribPointer(
                0,                   // attribute. No particular reason for 0, but must match the layout in the shader.
                3,                   // size
                GL_FLOAT,            // type
                GL_FALSE,            // normalized?
                5 * sizeof(GLfloat), // stride
                BUFFER_OFFSET(0));   // array buffer offset

        // texture coords
        glVertexAttribPointer(
                1,
		2,
		GL_FLOAT,
		GL_FALSE,
                5 * sizeof(GLfloat),
		BUFFER_OFFSET(3 * sizeof(GLfloat)));

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glUseProgram(program_id);

        // double last_time = 0.0;
        // main loop
	do {
                double cur_time = glfwGetTime();
                // double delta_time = cur_time - last_time;
                // last_time = cur_time;

		// clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Send our transformation to the currently bound shader, in the "MVP" uniform
		glUniformMatrix4fv(matrix_id, 1, GL_FALSE, &mvp[0][0]);

                glUniform1f(time_id, cur_time);

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, NUM_VERT);

		// glDisableVertexAttribArray(0);
		// glDisableVertexAttribArray(1);

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
                // Check if the ESC key was pressed or the window was closed
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

	// cleanup VBO and shader
	glDeleteBuffers(1, &buffer_data_id);
	glDeleteProgram(program_id);
	glDeleteVertexArrays(1, &vao_id);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
