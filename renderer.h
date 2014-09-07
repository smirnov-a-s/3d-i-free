#ifndef RENDERER_H
#define RENDERER_H

#include "object.h"

class Renderer {
    std::vector<MyObject> objects;

    glm::vec3 camera_pos;
    glm::vec3 camera_look_at;
    glm::vec3 camera_head;

    MyMath::Vec3 my_camera_pos;
    MyMath::Vec3 my_camera_look_at;
    MyMath::Vec3 my_camera_head;

    float y_rot_angle;
    glm::mat4 rotation_matrix;

    glm::mat4 view_matrix;
    glm::mat4 project_matrix;

    MyMath::Mat4 my_rotation_matrix;
    MyMath::Mat4 my_view_matrix;
    MyMath::Mat4 my_project_matrix;

    glm::vec3 light_pos;
    MyMath::Vec3 my_light_pos;

    double cur_time;
    double delta_time;

public:
    Renderer();
    void SetCamera(const glm::mat4& view_matrix, const glm::mat4& project_matrix);

    void SetCamera(const MyMath::Mat4& view_matrix, const MyMath::Mat4& project_matrix);

    void SetLightPos(float x, float y, float z);
    void SetEyePos(float x, float y, float z);
    void SetTime(double time);

    void AddObject(const MyObject& obj);

    void Render();

    // moving is a bit weird(but it moves)
    void ResetCamera();
    void CameraMoveLeft();
    void CameraMoveRight();
    void CameraMoveForward();
    void CameraMoveBackward();
    void CameraMoveUp();
    void CameraMoveDown();

    void ObjRotateLeft(const char* name);
    void ObjRotateRight(const char* name);
    void ObjRotateUp(const char* name);
    void ObjRotateDown(const char* name);

    // reset rotation
    void ObjResetRotationMatrix(const char* name);
};

#endif
