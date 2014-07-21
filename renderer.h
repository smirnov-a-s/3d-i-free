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

    double cur_time;

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

    void ObjRotateLeft(const char* name);
    void ObjRotateRight(const char* name);
    void ObjRotateUp(const char* name);
    void ObjRotateDown(const char* name);

    // reset rotation
    void ObjResetRotationMatrix(const char* name);
};

#endif
