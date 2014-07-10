#include <GL/glew.h>
#include <SOIL.h>

class MyObject {
    // handles
    // ???
    // GLuint vao_id;
    // vertex buffer obj
    GLuint vbo_id;
    // elements buffer obj
    GLuint ebo_id;
    // elements buffer obj size
    unsigned int ebo_size;
    // shaders
    GLuint prog_id;
    // texture id
    GLuint tex_id;
    // uniforms
    // time
    GLuint time_id;
    // MVP
    GLuint mat_model;
    GLuint mat_view;
    GLuint mat_proj;
    // light position
    GLuint light_pos;
    GLuint eye_pos;

public:
    MyObject(GLuint vbo_id, GLuint ebo_id, unsigned int ebo_size, GLuint prog_id):
    vbo_id(vbo_id), ebo_id(ebo_id), ebo_size(ebo_size), prog_id(prog_id) {}

    void BindUniforms();
    void BindTex(const char* path);
    void Draw();
};
