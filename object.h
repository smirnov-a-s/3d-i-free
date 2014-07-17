#ifndef OBJECT_H
#define OBJECT_H

#include <GL/glew.h>
#include <SOIL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "geometry.h"
#include "material.h"

enum class RotationAxis { X, Y, Z };

class MyObject {
    Geometry geom;
    Material mater;

    GLuint tex_id;

    glm::mat4 translation_matrix;
    glm::mat4 rotation_matrix;
    glm::mat4 scale_matrix;
    glm::mat4 model_matrix;

    void SetAttribs();
public:
    MyObject(const Geometry& geom, const Material& mater);

    GLuint GetProgId() const { return mater.GetProgId(); }

    void SetTexture(const char* path);

    void Translate(float tx, float ty, float tz);
    void Rotate(float angle_in_degr, RotationAxis& axis);
    void Scale(float sx, float sy, float sz);

    void Draw();
};

#endif
