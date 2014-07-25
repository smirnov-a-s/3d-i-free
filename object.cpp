#include <stdio.h>
#include "object.h"

#define BUFFER_OFFSET(x) ((const void*) (x))

MyObject::MyObject(const char* name, const Geometry& geom, const Material& mater) :
    name(name), geom(geom), mater(mater)
{
    translation_matrix = glm::mat4(1.0f);
    rotation_matrix = glm::mat4(1.0f);
    scale_matrix = glm::mat4(1.0f);
    model_matrix = glm::mat4(1.0f);

    x_rot_ang = 0.0f;
    y_rot_ang = 0.0f;
    z_rot_ang = 0.0f;

    int tex = 0;
    glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &tex);

    printf("max tex = %d\n", tex);
}

void MyObject::SetAttribs()
{
    int offset = 0;

    // position
    glVertexAttribPointer(
        POS,
        VERT_POS_SIZE,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex),
        BUFFER_OFFSET(0));

    offset += VERT_POS_SIZE;

    // color
    glVertexAttribPointer(
        COL,
        VERT_COLOR_SIZE,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex),
        BUFFER_OFFSET(offset * sizeof(float)));

    offset += VERT_COLOR_SIZE;

    // texture coords
    glVertexAttribPointer(
        TEXCOORD,
        VERT_TEX_COORD_SIZE,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex),
        BUFFER_OFFSET(offset * sizeof(float)));

    offset += VERT_TEX_COORD_SIZE;

    // normal
    glVertexAttribPointer(
        NORMAL,
        VERT_NORMAL_SIZE,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex),
        BUFFER_OFFSET(offset * sizeof(float)));

    offset += VERT_NORMAL_SIZE;

    // binormal
    glVertexAttribPointer(
        BINORMAL,
        VERT_BINORMAL_SIZE,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex),
        BUFFER_OFFSET(offset * sizeof(float)));

    offset += VERT_BINORMAL_SIZE;

    // tangent
    glVertexAttribPointer(
        TANGENT,
        VERT_TANGENT_SIZE,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex),
        BUFFER_OFFSET(offset * sizeof(float)));

    glEnableVertexAttribArray(POS);
    glEnableVertexAttribArray(COL);
    glEnableVertexAttribArray(TEXCOORD);
    glEnableVertexAttribArray(NORMAL);
    glEnableVertexAttribArray(BINORMAL);
    glEnableVertexAttribArray(TANGENT);
}

void MyObject::SetTexture(const char* path)
{
    glGenTextures(1, &tex_id);
    glBindTexture(GL_TEXTURE_2D, tex_id);

    int width, height, channels;
    // unsigned char* image = SOIL_load_image(path, &width, &height, &channels, SOIL_LOAD_L);
    unsigned char* image = SOIL_load_image(path, &width, &height, &channels, SOIL_LOAD_AUTO);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);
}

void MyObject::AddTexture(const char* path)
{
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    int width, height, channels;
    // unsigned char* image = SOIL_load_image(path, &width, &height, &channels, SOIL_LOAD_L);
    unsigned char* image = SOIL_load_image(path, &width, &height, &channels, SOIL_LOAD_AUTO);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);

    textures.push_back(id);

    SOIL_free_image_data(image);
}

void MyObject::Translate(float tx, float ty, float tz)
{
    translation_matrix = glm::translate(translation_matrix, glm::vec3(tx, ty, tz));
}

void MyObject::Rotate(float angle_in_degr, RotationAxis &axis)
{
    switch (axis) {
    case RotationAxis::X:
    {
        // glm::vec4 tmp = rotation_matrix * glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
        // tmp = glm::normalize(tmp);
        rotation_matrix = glm::rotate(rotation_matrix, angle_in_degr, glm::vec3(1.0f, 0.0f, 0.0f));
    }
    break;
    case RotationAxis::Y:
    {
        // rotation_matrix = glm::mat4(1.0f);

        // y_rot_ang += angle_in_degr;
        // if (abs(y_rot_ang) >= 90.0f) {
        //     y_rot_ang = 0.0f;
        // }

        // printf("%f\n", &rotation_matrix[0][0]);
        // printf("%f\n", y_rot_ang);

        // glm::vec4 tmp = rotation_matrix * glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
        // tmp = glm::normalize(tmp);

        // float p = glm::dot(vec3(tmp), vec3(1.0f, 0.0f, 0.0f));
        // printf("%f\n", p);
        // if (p - 0.0000001 < 0.0f) {
        //     printf("%f\n", p);
        //     rotation_matrix = glm::mat4(1.0f);
        // }

        rotation_matrix = glm::rotate(rotation_matrix, angle_in_degr, glm::vec3(0.0f, 1.0f, 0.0f));
    }
    break;
    case RotationAxis::Z:
    {
        rotation_matrix = glm::rotate(rotation_matrix, angle_in_degr, glm::vec3(0.0f, 0.0f, 1.0f));
    }
    break;
    }
}

void MyObject::Rotate(float angle_in_degr, glm::vec3& axis)
{
    // glm::vec4 tmp = view * glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);

    rotation_matrix = glm::rotate(rotation_matrix, angle_in_degr, axis);
}


void MyObject::Scale(float sx, float sy, float sz)
{
    scale_matrix = glm::scale(translation_matrix, glm::vec3(sx, sy, sz));
}

// uniforms?
void MyObject::Draw()
{
    // put somewhere else
    glUseProgram(mater.GetProgId());

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textures[0]);

    GLuint id = glGetUniformLocation(mater.GetProgId(), "texture0");
    // glUniform1i(id, textures[0]);
    glUniform1i(id, 0);

    glActiveTexture(GL_TEXTURE0 + 1);
    glBindTexture(GL_TEXTURE_2D, textures[1]);

    id = glGetUniformLocation(mater.GetProgId(), "texture1");
    glUniform1i(id, 1);

    glActiveTexture(GL_TEXTURE0 + 2);
    glBindTexture(GL_TEXTURE_2D, textures[2]);

    id = glGetUniformLocation(mater.GetProgId(), "texture2");
    glUniform1i(id, 2);


    //     glActiveTexture(GL_TEXTURE0 + i);
    //     glBindTexture(GL_TEXTURE_2D, textures[k]);
    //     GLuint id = glGetUniformLocation(prog_id, "eyePos");
    //     glUniform1i(uniform, textures[k]);

    glBindBuffer(GL_ARRAY_BUFFER, geom.GetVertBufId());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geom.GetIndBufId());

    SetAttribs();

    GLuint model_matrix_id = glGetUniformLocation(mater.GetProgId(), "modelMatrix");
    model_matrix = translation_matrix * rotation_matrix * scale_matrix;

    glUniformMatrix4fv(model_matrix_id, 1, GL_FALSE, &model_matrix[0][0]);

    glDrawElements(GL_TRIANGLES, geom.GetIndBufSize(), GL_UNSIGNED_INT, BUFFER_OFFSET(0));
}
