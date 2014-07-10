#include "geometry.h"

#define BUFFER_OFFSET(x) ((const void*) (x))

// put enable arrtib somewhere else
void Geometry::LoadData()
{
    int data_size = 0;

    // vertex buffer
    glGenBuffers(1, &vbo_id);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
    data_size = vert_data.size() * sizeof(Vertex);
    glBufferData(GL_ARRAY_BUFFER, data_size, &vert_data[0], GL_STATIC_DRAW);

    int offset = 0;

    // vertex attributes
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

    // index buffer
    glGenBuffers(1, &ebo_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);
    data_size = ind_buf.size() * sizeof(unsigned int);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data_size, &ind_buf[0], GL_STATIC_DRAW);
}

void Geometry::LogVertexData()
{
    printf("vbo_id = %d\n", vbo_id);
    printf("ebo_id = %d\n", ebo_id);

    printf("num_vert = %lu\n", vert_data.size());
    printf("num_elems = %lu\n", ind_buf.size());

    float* tmp = (float*) &vert_data[0];
    for (int i = 0; i < vert_data.size(); i++) {
        printf("v%d :\n", i);

        printf("pos: %f ",*tmp);
        tmp++;
        printf("%f ",*tmp);
        tmp++;
        printf("%f\n",*tmp);
        tmp++;

        printf("col: %f ",*tmp);
        tmp++;
        printf("%f ",*tmp);
        tmp++;
        printf("%f\n",*tmp);
        tmp++;

        printf("tex_coord: %f ",*tmp);
        tmp++;
        printf("%f\n",*tmp);
        tmp++;

        printf("norm: %f ",*tmp);
        tmp++;
        printf("%f ",*tmp);
        tmp++;
        printf("%f\n",*tmp);
        tmp++;

        printf("binorm: %f ",*tmp);
        tmp++;
        printf("%f ",*tmp);
        tmp++;
        printf("%f\n",*tmp);
        tmp++;

        printf("tang: %f ",*tmp);
        tmp++;
        printf("%f ",*tmp);
        tmp++;
        printf("%f\n",*tmp);
        tmp++;
    }
}
