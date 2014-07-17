#ifndef RENDERER_H
#define RENDERER_H

#include "object.h"

class Renderer {
    std::vector<MyObject> objects;

    glm::vec3 camera_pos;
    glm::vec3 camera_look_at;
    glm::vec3 camera_head;

    glm::mat4 view_matrix;
    glm::mat4 project_matrix;

    glm::vec3 light_pos;
    glm::vec3 eye_pos;

    double cur_time;

    // test
    float obj_rot_angle_x;
    float obj_rot_angle_y;
    float obj_rot_angle_z;
public:
    Renderer();
    void SetCamera(const glm::mat4& view_matrix, const glm::mat4& project_matrix);

    void SetLightPos(float x, float y, float z);
    void SetEyePos(float x, float y, float z);
    void SetTime(double time);

    void AddObject(const MyObject& obj);

    void Render();

    // moving is wrong (but it moves)
    void CameraMoveLeft();
    void CameraMoveRight();
    void CameraMoveForward();
    void CameraMoveBackward();

    // test
    void ObjRotateX(float angle);
    void ObjRotateY(float angle);
    void ObjRotateZ(float angle);
};

#endif
