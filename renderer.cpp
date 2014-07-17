#include "renderer.h"

#include <stdio.h>

// to handle key presses
#include <GLFW/glfw3.h>

#define MOVECAMERA 0.1f

Renderer::Renderer()
{
    camera_pos = glm::vec3(4.0f, 3.0f, -3.0f);
    camera_look_at = glm::vec3(0.0f, 0.0f, 0.0f);
    camera_head = glm::vec3(0.0f, 1.0f, 0.0f);

    view_matrix = glm::lookAt(camera_pos, camera_look_at, camera_head);
    project_matrix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

    light_pos = glm::vec3(0.5f, 0.5f, 0.5f);
    eye_pos = glm::vec3(1.0f, 1.0f, 1.0f);

    // test
    obj_rot_angle_x = 0;
    obj_rot_angle_y = 0;
    obj_rot_angle_z = 0;

    cur_time = 0;
}

void Renderer::ObjRotateX(float angle)
{
    obj_rot_angle_x = angle;
}

void Renderer::ObjRotateY(float angle)
{
    obj_rot_angle_y = angle;
}

void Renderer::ObjRotateZ(float angle)
{
    obj_rot_angle_z = angle;
}

void Renderer::SetCamera(const glm::mat4& view_matrix, const glm::mat4& project_matrix)
{
    this->view_matrix = view_matrix;
    this->project_matrix = project_matrix;
}

void Renderer::CameraMoveLeft()
{
    camera_pos.x -= MOVECAMERA;
    view_matrix = glm::lookAt(camera_pos, camera_look_at, camera_head);
}

void Renderer::CameraMoveRight()
{
    camera_pos.x += MOVECAMERA;
    view_matrix = glm::lookAt(camera_pos, camera_look_at, camera_head);
}

void Renderer::CameraMoveForward()
{
    camera_pos.z += MOVECAMERA;
    view_matrix = glm::lookAt(camera_pos, camera_look_at, camera_head);
}

void Renderer::CameraMoveBackward()
{
    camera_pos.z -= MOVECAMERA;
    view_matrix = glm::lookAt(camera_pos, camera_look_at, camera_head);
}

void Renderer::SetLightPos(float x, float y, float z)
{
    light_pos.x = x;
    light_pos.y = y;
    light_pos.z = z;
}

void Renderer::SetEyePos(float x, float y, float z)
{
    eye_pos.x = x;
    eye_pos.y = y;
    eye_pos.z = z;
}

void Renderer::SetTime(double time)
{
    cur_time = time;
}

void Renderer::AddObject(const MyObject &obj)
{
    objects.push_back(obj);
}

// glm::mat4 view_matrix;
// glm::mat4 project_matrix;

// glm::vec3 light_pos;
// glm::vec3 eye_pos;
// uniform float time;

// uniform mat4 modelMatrix;
// uniform mat4 viewMatrix;
// uniform mat4 projMatrix;

// uniform mat4 lightPos;
// uniform mat4 eyePos;

void Renderer::Render()
{
    for (auto &o : objects) {

        GLuint prog_id = o.GetProgId();
        GLuint time_id = glGetUniformLocation(prog_id, "time");
        GLuint view_matrix_id = glGetUniformLocation(prog_id, "viewMatrix");
        GLuint proj_matrix_id = glGetUniformLocation(prog_id, "projMatrix");
        GLuint light_pos_id = glGetUniformLocation(prog_id, "lightPos");
        GLuint eye_pos_id = glGetUniformLocation(prog_id, "eyePos");

        glUniform1f(time_id, cur_time);

        glUniformMatrix4fv(view_matrix_id, 1, GL_FALSE, &view_matrix[0][0]);
        glUniformMatrix4fv(proj_matrix_id, 1, GL_FALSE, &project_matrix[0][0]);

        light_pos = camera_pos;

        glUniform3fv(light_pos_id, 1, &light_pos[0]);
        glUniform3fv(eye_pos_id, 1, &eye_pos[0]);

        RotationAxis axis = RotationAxis::X;
        o.Rotate(obj_rot_angle_x, axis);

        axis = RotationAxis::Y;
        o.Rotate(obj_rot_angle_y, axis);

        axis = RotationAxis::Z;
        o.Rotate(obj_rot_angle_z, axis);

        obj_rot_angle_x = 0.0f;
        obj_rot_angle_y = 0.0f;
        obj_rot_angle_z = 0.0f;

        o.Draw();
    }
}
