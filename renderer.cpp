#include <stdio.h>
#include <string.h>

#include "renderer.h"

#define MOVECAMERA 0.1f
#define OBJMOVESPEED   1.0f
#define CAMMOVESPEED   1.0f

Renderer::Renderer()
{
    camera_pos = glm::vec3(0.0f, 0.0f, 5.0f);
    camera_look_at = glm::vec3(0.0f, 0.0f, 0.0f);
    camera_head = glm::vec3(0.0f, 1.0f, 0.0f);

    my_camera_pos = MyMath::Vec3(0.0f, 0.0f, 5.0f);
    my_camera_look_at = MyMath::Vec3(0.0f, 0.0f, 0.0f);
    my_camera_head = MyMath::Vec3(0.0f, 1.0f, 0.0f);

    rotation_matrix = glm::mat4(1.0f);
    my_rotation_matrix = MyMath::Mat4(1.0f);
    y_rot_angle = 0.0f;

    view_matrix = glm::lookAt(camera_pos, camera_look_at, camera_head);
    project_matrix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

    my_view_matrix = MyMath::LookAt(my_camera_pos, my_camera_look_at, my_camera_head);
    my_project_matrix = MyMath::Perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

    light_pos = glm::vec3(0.0f, 0.0f, 5.0f);
    my_light_pos = MyMath::Vec3(0.0f, 0.0f, 5.0f);

    MyMath::print_mat(view_matrix);
    MyMath::print_mat(my_view_matrix);

    cur_time = 0;
    delta_time = 0;
}

void Renderer::ResetCamera()
{
    camera_pos = glm::vec3(0.0f, 0.0f, 5.0f);

    camera_look_at = glm::vec3(0.0f, 0.0f, 0.0f);
    camera_head = glm::vec3(0.0f, 1.0f, 0.0f);

    rotation_matrix = glm::mat4(1.0f);

    view_matrix = glm::lookAt(camera_pos, camera_look_at, camera_head);
    project_matrix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

    my_camera_pos = MyMath::Vec3(0.0f, 0.0f, 5.0f);

    my_camera_look_at = MyMath::Vec3(0.0f, 0.0f, 0.0f);
    my_camera_head = MyMath::Vec3(0.0f, 1.0f, 0.0f);

    my_rotation_matrix = MyMath::Mat4(1.0f);

    my_view_matrix = MyMath::LookAt(my_camera_pos, my_camera_look_at, my_camera_head);
    my_project_matrix = MyMath::Perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
}

void Renderer::SetCamera(const glm::mat4& view_matrix, const glm::mat4& project_matrix)
{
    this->view_matrix = view_matrix;
    this->project_matrix = project_matrix;
}

void Renderer::SetCamera(const MyMath::Mat4 &view_matrix, const MyMath::Mat4 &project_matrix)
{
    this->my_view_matrix = my_view_matrix;
    this->my_project_matrix = my_project_matrix;
}

void Renderer::CameraMoveLeft()
{
    rotation_matrix = glm::rotate(glm::mat4(1.0f), -OBJMOVESPEED, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::vec4 tmp = glm::vec4(camera_pos, 1.0f);
    tmp = tmp * rotation_matrix;
    camera_pos = glm::vec3(tmp);
    view_matrix = glm::lookAt(camera_pos, camera_look_at, camera_head);

    float speed = delta_time * CAMMOVESPEED;
    printf("speed = %f\n", speed);
    my_rotation_matrix = MyMath::RotateY(-speed);
    MyMath::Vec4 my_tmp = MyMath::Vec4(my_camera_pos, 1.0f);
    my_tmp = my_rotation_matrix * my_tmp;
    my_camera_pos = MyMath::Vec3(my_tmp);
    my_view_matrix = MyMath::LookAt(my_camera_pos, my_camera_look_at, my_camera_head);
}

void Renderer::CameraMoveRight()
{
    rotation_matrix = glm::rotate(glm::mat4(1.0f), OBJMOVESPEED, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::vec4 tmp = glm::vec4(camera_pos, 1.0f);
    tmp = tmp * rotation_matrix;
    camera_pos = glm::vec3(tmp);
    view_matrix = glm::lookAt(camera_pos, camera_look_at, camera_head);

    float speed = delta_time * CAMMOVESPEED;
    my_rotation_matrix = MyMath::RotateY(speed);
    MyMath::Vec4 my_tmp = MyMath::Vec4(my_camera_pos, 1.0f);
    my_tmp = my_rotation_matrix * my_tmp;
    my_camera_pos = MyMath::Vec3(my_tmp);
    my_view_matrix = MyMath::LookAt(my_camera_pos, my_camera_look_at, my_camera_head);
}

void Renderer::CameraMoveUp()
{
    if (camera_pos.y >= -10.0f)
        camera_pos.y -= MOVECAMERA;
    view_matrix = glm::lookAt(camera_pos, camera_look_at, camera_head);

    if (my_camera_pos.y >= -10.0f)
        my_camera_pos.y -= MOVECAMERA;
    my_view_matrix = MyMath::LookAt(my_camera_pos, my_camera_look_at, my_camera_head);
}

void Renderer::CameraMoveDown()
{
    if (camera_pos.y <= 10.0f)
        camera_pos.y += MOVECAMERA;
    view_matrix = glm::lookAt(camera_pos, camera_look_at, camera_head);

    if (my_camera_pos.y <= 10.0f)
        my_camera_pos.y += MOVECAMERA;
    my_view_matrix = MyMath::LookAt(my_camera_pos, my_camera_look_at, my_camera_head);
}

void Renderer::CameraMoveForward()
{
    camera_pos.z -= MOVECAMERA;
    view_matrix = glm::lookAt(camera_pos, camera_look_at, camera_head);

    my_camera_pos.z -= MOVECAMERA;
    my_view_matrix = MyMath::LookAt(my_camera_pos, my_camera_look_at, my_camera_head);
}

void Renderer::CameraMoveBackward()
{
    camera_pos.z += MOVECAMERA;
    view_matrix = glm::lookAt(camera_pos, camera_look_at, camera_head);

    my_camera_pos.z += MOVECAMERA;
    my_view_matrix = MyMath::LookAt(my_camera_pos, my_camera_look_at, my_camera_head);
}

void Renderer::SetLightPos(float x, float y, float z)
{
    light_pos.x = x;
    light_pos.y = y;
    light_pos.z = z;

    my_light_pos.x = x;
    my_light_pos.y = y;
    my_light_pos.z = z;
}

void Renderer::SetEyePos(float x, float y, float z)
{
    camera_pos.x = x;
    camera_pos.y = y;
    camera_pos.z = z;

    view_matrix = glm::lookAt(camera_pos, camera_look_at, camera_head);

    my_camera_pos.x = x;
    my_camera_pos.y = y;
    my_camera_pos.z = z;

    my_view_matrix = MyMath::LookAt(my_camera_pos, my_camera_look_at, my_camera_head);
}

void Renderer::SetTime(double time)
{
    delta_time = time - cur_time;
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

void Renderer::ObjResetRotationMatrix(const char *name)
{
    for (auto &o : objects) {
        if (strcmp(name, o.GetName()) == 0) {
            glm::mat4 tmp = glm::mat4(1.0f);
            o.SetRotationMatrix(tmp);

            MyMath::Mat4 idnt = MyMath::Mat4(1.0f);
            o.SetRotationMatrix(idnt);
        }
    }
}

void Renderer::ObjRotateLeft(const char *name)
{
    for (auto &o : objects) {
        if (strcmp(name, o.GetName()) == 0) {
            RotationAxis axis = RotationAxis::Y;
            o.Rotate(-OBJMOVESPEED, axis);
        }
    }
}

void Renderer::ObjRotateRight(const char *name)
{
    for (auto &o : objects) {
        if (strcmp(name, o.GetName()) == 0) {
            RotationAxis axis = RotationAxis::Y;
            o.Rotate(OBJMOVESPEED, axis);
        }
    }
}

void Renderer::ObjRotateUp(const char *name)
{
    for (auto &o : objects) {
        if (strcmp(name, o.GetName()) == 0) {
            RotationAxis axis = RotationAxis::X;
            o.Rotate(-OBJMOVESPEED, axis);
        }
    }
}

void Renderer::ObjRotateDown(const char *name)
{
    for (auto &o : objects) {
        if (strcmp(name, o.GetName()) == 0) {
            RotationAxis axis = RotationAxis::X;
            o.Rotate(OBJMOVESPEED, axis);
        }
    }
}

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

        // MyMath::print_mat(view_matrix);
        // MyMath::print_mat(my_view_matrix);

        // MyMath::print_mat(project_matrix);
        // MyMath::print_mat(my_project_matrix);

        // glUniformMatrix4fv(view_matrix_id, 1, GL_FALSE, &view_matrix[0][0]);
        // glUniformMatrix4fv(proj_matrix_id, 1, GL_FALSE, &project_matrix[0][0]);

        glUniformMatrix4fv(view_matrix_id, 1, GL_FALSE, my_view_matrix[0]);
        glUniformMatrix4fv(proj_matrix_id, 1, GL_FALSE, my_project_matrix[0]);

        // glUniform3fv(light_pos_id, 1, &light_pos[0]);
        // glUniform3fv(eye_pos_id, 1, &camera_pos[0]);

        glUniform3fv(light_pos_id, 1, (float*) &my_light_pos);
        glUniform3fv(eye_pos_id, 1, (float*) &my_camera_pos);

        o.Draw();
    }
}
