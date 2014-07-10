#include "object.h"

#define BUFFER_OFFSET(x) ((const void*) (x))

void MyObject::BindUniforms()
{
    time_id = glGetUniformLocation(prog_id, "time");
    mat_model = glGetUniformLocation(prog_id, "modelMat");
    mat_view = glGetUniformLocation(prog_id, "viewMat");
    mat_proj = glGetUniformLocation(prog_id, "projMat");
    light_pos = glGetUniformLocation(prog_id, "lightPos");
    eye_pos = glGetUniformLocation(prog_id, "eyePos");
}

void MyObject::BindTex(const char* path)
{
    glGenTextures(1, &tex_id);
    glBindTexture(GL_TEXTURE_2D, tex_id);

    int width, height, channels;
    // unsigned char* image = SOIL_load_image(TEXPATH, &width, &height, &channels, SOIL_LOAD_L);
    unsigned char* image = SOIL_load_image(path, &width, &height, &channels, SOIL_LOAD_AUTO);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);
}

// uniforms?
void MyObject::Draw()
{
    // put somewhere else
    glUseProgram(prog_id);

    // glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);

    glDrawElements(GL_TRIANGLES, ebo_size, GL_UNSIGNED_INT, BUFFER_OFFSET(0));
    // glDrawElements(GL_TRIANGLES, ebo_size, GL_UNSIGNED_INT, 0);
}
