#ifndef OBJECT_H
#define OBJECT_H

#include <GL/glew.h>
#include <SOIL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
// using namespace glm;

#include "geometry.h"
#include "material.h"

enum class RotationAxis { X, Y, Z };

class MyObject {
    // some kind of obj id
    const char* name;

    Geometry geom;
    Material mater;

    std::vector<GLuint> textures;

    GLuint tex_id;

    glm::mat4 translation_matrix;
    glm::mat4 rotation_matrix;
    glm::mat4 scale_matrix;
    glm::mat4 model_matrix;

    // change to horizontal/vertical?
    float x_rot_ang;
    float y_rot_ang;
    float z_rot_ang;

    void SetAttribs();
public:
    MyObject(const char* name, const Geometry& geom, const Material& mater);

    const char* GetName() const { return name; };

    GLuint GetProgId() const { return mater.GetProgId(); }

    void SetTexture(const char* path);
    void AddTexture(const char* path);

    void Translate(float tx, float ty, float tz);
    void Rotate(float angle_in_degr, RotationAxis& axis);
    void Rotate(float angle_in_degr, glm::vec3& axis);
    void Scale(float sx, float sy, float sz);

    // void SetModelMatrix(glm::mat4& model_matrix) { this->model_matrix = model_matrix; }
    void SetRotationMatrix(glm::mat4& rotation_matrix) { this->rotation_matrix = rotation_matrix; }

    void Draw();
};

#endif
