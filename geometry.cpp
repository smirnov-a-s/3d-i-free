#include "geometry.h"

#define BUFFER_OFFSET(x) ((const void*) (x))

Geometry::Geometry(const std::vector<Vertex>& vert_buf, const std::vector<unsigned int>& ind_buf):
    vert_buf(vert_buf), ind_buf(ind_buf)
{
    glGenBuffers(1, &vert_buf_id);
    glGenBuffers(1, &ind_buf_id);

    LoadData();
}

void Geometry::LoadData()
{
    int data_size = 0;

    glBindBuffer(GL_ARRAY_BUFFER, vert_buf_id);
    data_size = vert_buf.size() * sizeof(Vertex);
    glBufferData(GL_ARRAY_BUFFER, data_size, &vert_buf[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ind_buf_id);
    data_size = ind_buf.size() * sizeof(unsigned int);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data_size, &ind_buf[0], GL_STATIC_DRAW);
}

void Geometry::PrintVertData()
{
    printf("vert_buf_id = %d\n", vert_buf_id);
    printf("ind_buf_id = %d\n", ind_buf_id);

    printf("num_vert = %lu\n", vert_buf.size());
    printf("num_elems = %lu\n", ind_buf.size());

    float* tmp = (float*) &vert_buf[0];
    for (int i = 0; i < vert_buf.size(); i++) {
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
