#ifndef VERT_BUF_DATA_H
#define VERT_BUF_DATA_H

#include <vector>
#include <GL/glew.h>

#define VERT_POS_SIZE        3
#define VERT_COLOR_SIZE      3
#define VERT_TEX_COORD_SIZE  2
#define VERT_NORMAL_SIZE     3
#define VERT_BINORMAL_SIZE   3
#define VERT_TANGENT_SIZE    3

enum AttribIds {
    POS = 0,
    COL,
    TEXCOORD,
    NORMAL,
    BINORMAL,
    TANGENT
};

#pragma pack(4)
struct Vertex {
    float pos[VERT_POS_SIZE];
    float col[VERT_COLOR_SIZE];
    float tex_coord[VERT_TEX_COORD_SIZE];
    float normal[VERT_NORMAL_SIZE];
    float binormal[VERT_BINORMAL_SIZE];
    float tangent[VERT_TANGENT_SIZE];
};
#pragma pack()

class Geometry {
    std::vector<Vertex> vert_data;
    std::vector<unsigned int> ind_buf;

    GLuint vbo_id;
    GLuint ebo_id;

public:
    Geometry(const std::vector<Vertex>& vert_data, const std::vector<unsigned int>& ind_buf): vert_data(vert_data), ind_buf(ind_buf) {}
    Geometry(const float* data, unsigned int num_vert, int* elems, unsigned int num_elems);

    const GLuint GetVertexBufId() const { return vbo_id; }
    const GLuint GetElemBufId() const { return ebo_id; }
    const GLuint GetElemBufSize() const { return ind_buf.size(); }

    void LoadData();
    void LogVertexData();
};

#endif
