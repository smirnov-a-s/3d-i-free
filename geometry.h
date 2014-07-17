#ifndef GEOMETRY_H
#define GEOMETRY_H

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
    std::vector<Vertex> vert_buf;
    std::vector<unsigned int> ind_buf;

    GLuint vert_buf_id;
    GLuint ind_buf_id;

    void LoadData();
public:
    Geometry(const std::vector<Vertex>& vert_buf, const std::vector<unsigned int>& ind_buf);

    void PrintVertData();

    GLuint GetVertBufId() const { return vert_buf_id; }
    GLuint GetIndBufId() const { return ind_buf_id; }

    int GetIndBufSize() const { return ind_buf.size(); }
};

#endif
