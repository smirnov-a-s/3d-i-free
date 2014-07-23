#include "vert_buf_data.h"

Geometry GenTriangle()
{
    std::vector<Vertex> vert_data(3);
    std::vector<unsigned int> ind_buf({0, 1, 2});

    // vertex 0
    // position
    vert_data[0].pos[0] = -1.0f;
    vert_data[0].pos[1] = -1.0f;
    vert_data[0].pos[2] =  0.0f;
    // color
    vert_data[0].col[0] = 1.0f;
    vert_data[0].col[1] = 0.0f;
    vert_data[0].col[2] = 0.0f;
    // tex coord
    vert_data[0].tex_coord[0] = 0.0f;
    vert_data[0].tex_coord[1] = 0.0f;
    // normal
    vert_data[0].normal[0] = 0.0f;
    vert_data[0].normal[1] = 0.0f;
    vert_data[0].normal[2] = 1.0f;
    // binormal
    vert_data[0].binormal[0] = 0.0f;
    vert_data[0].binormal[1] = 0.0f;
    vert_data[0].binormal[2] = 0.0f;
    // tangent
    vert_data[0].tangent[0] = 0.0f;
    vert_data[0].tangent[1] = 0.0f;
    vert_data[0].tangent[2] = 0.0f;

    // vertex 1
    // position
    vert_data[1].pos[0] =  1.0f;
    vert_data[1].pos[1] = -1.0f;
    vert_data[1].pos[2] =  0.0f;
    // color
    vert_data[1].col[0] = 1.0f;
    vert_data[1].col[1] = 0.0f;
    vert_data[1].col[2] = 0.0f;
    // tex coord
    vert_data[1].tex_coord[0] = 1.0f;
    vert_data[1].tex_coord[1] = 0.0f;
    // normal
    vert_data[1].normal[0] = 0.0f;
    vert_data[1].normal[1] = 0.0f;
    vert_data[1].normal[2] = 1.0f;
    // binormal
    vert_data[1].binormal[0] = 0.0f;
    vert_data[1].binormal[1] = 0.0f;
    vert_data[1].binormal[2] = 0.0f;
    // tangent
    vert_data[1].tangent[0] = 0.0f;
    vert_data[1].tangent[1] = 0.0f;
    vert_data[1].tangent[2] = 0.0f;

    // vertex 2
    // position
    vert_data[2].pos[0] = -1.0f;
    vert_data[2].pos[1] =  1.0f;
    vert_data[2].pos[2] =  0.0f;
    // color
    vert_data[2].col[0] = 1.0f;
    vert_data[2].col[1] = 0.0f;
    vert_data[2].col[2] = 0.0f;
    // tex coord
    vert_data[2].tex_coord[0] = 0.0f;
    vert_data[2].tex_coord[1] = 1.0f;
    // normal
    vert_data[2].normal[0] = 0.0f;
    vert_data[2].normal[1] = 0.0f;
    vert_data[2].normal[2] = 1.0f;
    // binormal
    vert_data[2].binormal[0] = 0.0f;
    vert_data[2].binormal[1] = 0.0f;
    vert_data[2].binormal[2] = 0.0f;
    // tangent
    vert_data[2].tangent[0] = 0.0f;
    vert_data[2].tangent[1] = 0.0f;
    vert_data[2].tangent[2] = 0.0f;

    return Geometry(vert_data, ind_buf);
}

Geometry GenSquare()
{
    std::vector<Vertex> vert_data(4);
    std::vector<unsigned int> ind_buf({0, 1, 2, 1, 3, 2});

    // vertex 0
    // position
    vert_data[0].pos[0] = -1.0f;
    vert_data[0].pos[1] = -1.0f;
    vert_data[0].pos[2] =  0.0f;
    // color
    vert_data[0].col[0] = 1.0f;
    vert_data[0].col[1] = 0.0f;
    vert_data[0].col[2] = 0.0f;
    // tex coord
    vert_data[0].tex_coord[0] = 0.0f;
    vert_data[0].tex_coord[1] = 0.0f;
    // normal
    vert_data[0].normal[0] = 0.0f;
    vert_data[0].normal[1] = 1.0f;
    vert_data[0].normal[2] = 0.0f;
    // binormal
    vert_data[0].binormal[0] = 0.0f;
    vert_data[0].binormal[1] = 0.0f;
    vert_data[0].binormal[2] = 0.0f;
    // tangent
    vert_data[0].tangent[0] = 0.0f;
    vert_data[0].tangent[1] = 0.0f;
    vert_data[0].tangent[2] = 0.0f;

    // vertex 1
    // position
    vert_data[1].pos[0] =  1.0f;
    vert_data[1].pos[1] = -1.0f;
    vert_data[1].pos[2] =  0.0f;
    // color
    vert_data[1].col[0] = 1.0f;
    vert_data[1].col[1] = 0.0f;
    vert_data[1].col[2] = 0.0f;
    // tex coord
    vert_data[1].tex_coord[0] = 1.0f;
    vert_data[1].tex_coord[1] = 0.0f;
    // normal
    vert_data[1].normal[0] = 0.0f;
    vert_data[1].normal[1] = 1.0f;
    vert_data[1].normal[2] = 0.0f;
    // binormal
    vert_data[1].binormal[0] = 0.0f;
    vert_data[1].binormal[1] = 0.0f;
    vert_data[1].binormal[2] = 0.0f;
    // tangent
    vert_data[1].tangent[0] = 0.0f;
    vert_data[1].tangent[1] = 0.0f;
    vert_data[1].tangent[2] = 0.0f;

    // vertex 2
    // position
    vert_data[2].pos[0] = -1.0f;
    vert_data[2].pos[1] =  1.0f;
    vert_data[2].pos[2] =  0.0f;
    // color
    vert_data[2].col[0] = 1.0f;
    vert_data[2].col[1] = 0.0f;
    vert_data[2].col[2] = 0.0f;
    // tex coord
    vert_data[2].tex_coord[0] = 0.0f;
    vert_data[2].tex_coord[1] = 1.0f;
    // normal
    vert_data[2].normal[0] = 0.0f;
    vert_data[2].normal[1] = 1.0f;
    vert_data[2].normal[2] = 0.0f;
    // binormal
    vert_data[2].binormal[0] = 0.0f;
    vert_data[2].binormal[1] = 0.0f;
    vert_data[2].binormal[2] = 0.0f;
    // tangent
    vert_data[2].tangent[0] = 0.0f;
    vert_data[2].tangent[1] = 0.0f;
    vert_data[2].tangent[2] = 0.0f;

    // vertex 3
    // position
    vert_data[3].pos[0] =  1.0f;
    vert_data[3].pos[1] =  1.0f;
    vert_data[3].pos[2] =  0.0f;
    // color
    vert_data[3].col[0] = 1.0f;
    vert_data[3].col[1] = 0.0f;
    vert_data[3].col[2] = 0.0f;
    // tex coord
    vert_data[3].tex_coord[0] = 1.0f;
    vert_data[3].tex_coord[1] = 1.0f;
    // normal
    vert_data[3].normal[0] = 0.0f;
    vert_data[3].normal[1] = 1.0f;
    vert_data[3].normal[2] = 0.0f;
    // binormal
    vert_data[3].binormal[0] = 0.0f;
    vert_data[3].binormal[1] = 0.0f;
    vert_data[3].binormal[2] = 0.0f;
    // tangent
    vert_data[3].tangent[0] = 0.0f;
    vert_data[3].tangent[1] = 0.0f;
    vert_data[3].tangent[2] = 0.0f;

    return Geometry(vert_data, ind_buf);
}

Geometry GenCube()
{
    std::vector<Vertex> vert_data(24);
    std::vector<unsigned int> ind_buf({2, 11, 8,
                                       2, 5, 11,

                                       3, 15, 9,
                                       3, 12, 15,

                                       14, 23, 17,
                                       14, 20, 23,

                                       18, 6, 21,
                                       18, 0, 6,

                                       19, 4, 1,
                                       19, 13, 4,

                                       7, 16, 22,
                                       7, 10, 16});

    // vertex 0
    vert_data[0].pos[0] =       -1.0f; // position
    vert_data[0].pos[1] =       -1.0f;
    vert_data[0].pos[2] =        1.0f;
    vert_data[0].col[0] =        1.0f; // color
    vert_data[0].col[1] =        0.0f;
    vert_data[0].col[2] =        0.0f;
    vert_data[0].tex_coord[0] =  1.0f; // tex coord
    vert_data[0].tex_coord[1] =  0.0f;
    vert_data[0].normal[0] =    -1.0f; // normal (x)
    vert_data[0].normal[1] =     0.0f;
    vert_data[0].normal[2] =     0.0f;
    vert_data[0].tangent[0] =   0.0f; // binormal
    vert_data[0].tangent[1] =   0.0f;
    vert_data[0].tangent[2] =   1.0f;
    vert_data[0].binormal[0] =    0.0f; // tangent
    vert_data[0].binormal[1] =    1.0f;
    vert_data[0].binormal[2] =    0.0f;

    // vertex 1
    vert_data[1].pos[0] =       -1.0f; // position
    vert_data[1].pos[1] =       -1.0f;
    vert_data[1].pos[2] =        1.0f;
    vert_data[1].col[0] =        1.0f; // color
    vert_data[1].col[1] =        0.0f;
    vert_data[1].col[2] =        0.0f;
    vert_data[1].tex_coord[0] =  0.0f; // tex coord
    vert_data[1].tex_coord[1] =  1.0f;
    vert_data[1].normal[0] =     0.0f; // normal (y)
    vert_data[1].normal[1] =    -1.0f;
    vert_data[1].normal[2] =     0.0f;
    vert_data[1].tangent[0] =   0.0f; // binormal
    vert_data[1].tangent[1] =   0.0f;
    vert_data[1].tangent[2] =  -1.0f;
    vert_data[1].binormal[0] =    0.0f; // tangent
    vert_data[1].binormal[1] =    1.0f;
    vert_data[1].binormal[2] =    0.0f;

    // vertex 2
    vert_data[2].pos[0] =       -1.0f; // position
    vert_data[2].pos[1] =       -1.0f;
    vert_data[2].pos[2] =        1.0f;
    vert_data[2].col[0] =        1.0f; // color
    vert_data[2].col[1] =        0.0f;
    vert_data[2].col[2] =        0.0f;
    vert_data[2].tex_coord[0] =  0.0f; // tex coord
    vert_data[2].tex_coord[1] =  0.0f;
    vert_data[2].normal[0] =     0.0f; // normal (z)
    vert_data[2].normal[1] =     0.0f;
    vert_data[2].normal[2] =     1.0f;
    vert_data[2].tangent[0] =   1.0f; // binormal
    vert_data[2].tangent[1] =   0.0f;
    vert_data[2].tangent[2] =   0.0f;
    vert_data[2].binormal[0] =    0.0f; // tangent
    vert_data[2].binormal[1] =    1.0f;
    vert_data[2].binormal[2] =    0.0f;

    // vertex 3
    vert_data[3].pos[0] =        1.0f; // position
    vert_data[3].pos[1] =       -1.0f;
    vert_data[3].pos[2] =        1.0f;
    vert_data[3].col[0] =        1.0f; // color
    vert_data[3].col[1] =        0.0f;
    vert_data[3].col[2] =        0.0f;
    vert_data[3].tex_coord[0] =  0.0f; // tex coord
    vert_data[3].tex_coord[1] =  0.0f;
    vert_data[3].normal[0] =     1.0f; // normal (x)
    vert_data[3].normal[1] =     0.0f;
    vert_data[3].normal[2] =     0.0f;
    vert_data[3].tangent[0] =   0.0f; // binormal
    vert_data[3].tangent[1] =   0.0f;
    vert_data[3].tangent[2] =  -1.0f;
    vert_data[3].binormal[0] =    0.0f; // tangent
    vert_data[3].binormal[1] =    1.0f;
    vert_data[3].binormal[2] =    0.0f;

    // vertex 4
    vert_data[4].pos[0] =        1.0f; // position
    vert_data[4].pos[1] =       -1.0f;
    vert_data[4].pos[2] =        1.0f;
    vert_data[4].col[0] =        1.0f; // color
    vert_data[4].col[1] =        0.0f;
    vert_data[4].col[2] =        0.0f;
    vert_data[4].tex_coord[0] =  1.0f; // tex coord
    vert_data[4].tex_coord[1] =  1.0f;
    vert_data[4].normal[0] =     0.0f; // normal (y)
    vert_data[4].normal[1] =    -1.0f;
    vert_data[4].normal[2] =     0.0f;
    vert_data[4].tangent[0] =   0.0f; // binormal
    vert_data[4].tangent[1] =   0.0f;
    vert_data[4].tangent[2] =  -1.0f;
    vert_data[4].binormal[0] =    1.0f; // tangent
    vert_data[4].binormal[1] =    0.0f;
    vert_data[4].binormal[2] =    0.0f;

    // vertex 5
    vert_data[5].pos[0] =        1.0f; // position
    vert_data[5].pos[1] =       -1.0f;
    vert_data[5].pos[2] =        1.0f;
    vert_data[5].col[0] =        1.0f; // color
    vert_data[5].col[1] =        0.0f;
    vert_data[5].col[2] =        0.0f;
    vert_data[5].tex_coord[0] =  1.0f; // tex coord
    vert_data[5].tex_coord[1] =  0.0f;
    vert_data[5].normal[0] =     0.0f; // normal (z)
    vert_data[5].normal[1] =     0.0f;
    vert_data[5].normal[2] =     1.0f;
    vert_data[5].tangent[0] =   1.0f; // binormal
    vert_data[5].tangent[1] =   0.0f;
    vert_data[5].tangent[2] =   0.0f;
    vert_data[5].binormal[0] =    0.0f; // tangent
    vert_data[5].binormal[1] =    1.0f;
    vert_data[5].binormal[2] =    0.0f;

    // vertex 6
    vert_data[6].pos[0] =       -1.0f; // position
    vert_data[6].pos[1] =        1.0f;
    vert_data[6].pos[2] =        1.0f;
    vert_data[6].col[0] =        1.0f; // color
    vert_data[6].col[1] =        0.0f;
    vert_data[6].col[2] =        0.0f;
    vert_data[6].tex_coord[0] =  1.0f; // tex coord
    vert_data[6].tex_coord[1] =  1.0f;
    vert_data[6].normal[0] =    -1.0f; // normal (x)
    vert_data[6].normal[1] =     0.0f;
    vert_data[6].normal[2] =     0.0f;
    vert_data[6].tangent[0] =   0.0f; // binormal
    vert_data[6].tangent[1] =   0.0f;
    vert_data[6].tangent[2] =   1.0f;
    vert_data[6].binormal[0] =    0.0f; // tangent
    vert_data[6].binormal[1] =    1.0f;
    vert_data[6].binormal[2] =    0.0f;

    // vertex 7
    vert_data[7].pos[0] =       -1.0f; // position
    vert_data[7].pos[1] =        1.0f;
    vert_data[7].pos[2] =        1.0f;
    vert_data[7].col[0] =        1.0f; // color
    vert_data[7].col[1] =        0.0f;
    vert_data[7].col[2] =        0.0f;
    vert_data[7].tex_coord[0] =  0.0f; // tex coord
    vert_data[7].tex_coord[1] =  0.0f;
    vert_data[7].normal[0] =     0.0f; // normal (y)
    vert_data[7].normal[1] =     1.0f;
    vert_data[7].normal[2] =     0.0f;
    vert_data[7].tangent[0] =   1.0f; // binormal
    vert_data[7].tangent[1] =   0.0f;
    vert_data[7].tangent[2] =   0.0f;
    vert_data[7].binormal[0] =    0.0f; // tangent
    vert_data[7].binormal[1] =    0.0f;
    vert_data[7].binormal[2] =   -1.0f;

    // vertex 8
    vert_data[8].pos[0] =       -1.0f; // position
    vert_data[8].pos[1] =        1.0f;
    vert_data[8].pos[2] =        1.0f;
    vert_data[8].col[0] =        1.0f; // color
    vert_data[8].col[1] =        0.0f;
    vert_data[8].col[2] =        0.0f;
    vert_data[8].tex_coord[0] =  0.0f; // tex coord
    vert_data[8].tex_coord[1] =  1.0f;
    vert_data[8].normal[0] =     0.0f; // normal (z)
    vert_data[8].normal[1] =     0.0f;
    vert_data[8].normal[2] =     1.0f;
    vert_data[8].tangent[0] =   1.0f; // binormal
    vert_data[8].tangent[1] =   0.0f;
    vert_data[8].tangent[2] =   0.0f;
    vert_data[8].binormal[0] =    0.0f; // tangent
    vert_data[8].binormal[1] =    1.0f;
    vert_data[8].binormal[2] =    0.0f;

    // vertex 9
    vert_data[9].pos[0] =        1.0f; // position
    vert_data[9].pos[1] =        1.0f;
    vert_data[9].pos[2] =        1.0f;
    vert_data[9].col[0] =        1.0f; // color
    vert_data[9].col[1] =        0.0f;
    vert_data[9].col[2] =        0.0f;
    vert_data[9].tex_coord[0] =  0.0f; // tex coord
    vert_data[9].tex_coord[1] =  1.0f;
    vert_data[9].normal[0] =     1.0f; // normal (x)
    vert_data[9].normal[1] =     0.0f;
    vert_data[9].normal[2] =     0.0f;
    vert_data[9].tangent[0] =   0.0f; // binormal
    vert_data[9].tangent[1] =   0.0f;
    vert_data[9].tangent[2] =  -1.0f;
    vert_data[9].binormal[0] =    0.0f; // tangent
    vert_data[9].binormal[1] =    1.0f;
    vert_data[9].binormal[2] =    0.0f;

    // vertex 10
    vert_data[10].pos[0] =        1.0f; // position
    vert_data[10].pos[1] =        1.0f;
    vert_data[10].pos[2] =        1.0f;
    vert_data[10].col[0] =        1.0f; // color
    vert_data[10].col[1] =        0.0f;
    vert_data[10].col[2] =        0.0f;
    vert_data[10].tex_coord[0] =  1.0f; // tex coord
    vert_data[10].tex_coord[1] =  0.0f;
    vert_data[10].normal[0] =     0.0f; // normal (y)
    vert_data[10].normal[1] =     1.0f;
    vert_data[10].normal[2] =     0.0f;
    vert_data[10].tangent[0] =   1.0f; // binormal
    vert_data[10].tangent[1] =   0.0f;
    vert_data[10].tangent[2] =   0.0f;
    vert_data[10].binormal[0] =    0.0f; // tangent
    vert_data[10].binormal[1] =    0.0f;
    vert_data[10].binormal[2] =   -1.0f;

    // vertex 11
    vert_data[11].pos[0] =        1.0f; // position
    vert_data[11].pos[1] =        1.0f;
    vert_data[11].pos[2] =        1.0f;
    vert_data[11].col[0] =        1.0f; // color
    vert_data[11].col[1] =        0.0f;
    vert_data[11].col[2] =        0.0f;
    vert_data[11].tex_coord[0] =  1.0f; // tex coord
    vert_data[11].tex_coord[1] =  1.0f;
    vert_data[11].normal[0] =     0.0f; // normal (z)
    vert_data[11].normal[1] =     0.0f;
    vert_data[11].normal[2] =     1.0f;
    vert_data[11].tangent[0] =   1.0f; // binormal
    vert_data[11].tangent[1] =   0.0f;
    vert_data[11].tangent[2] =   0.0f;
    vert_data[11].binormal[0] =    0.0f; // tangent
    vert_data[11].binormal[1] =    1.0f;
    vert_data[11].binormal[2] =    0.0f;

    // vertex 12
    vert_data[12].pos[0] =        1.0f; // position
    vert_data[12].pos[1] =       -1.0f;
    vert_data[12].pos[2] =       -1.0f;
    vert_data[12].col[0] =        1.0f; // color
    vert_data[12].col[1] =        0.0f;
    vert_data[12].col[2] =        0.0f;
    vert_data[12].tex_coord[0] =  1.0f; // tex coord
    vert_data[12].tex_coord[1] =  0.0f;
    vert_data[12].normal[0] =     1.0f; // normal (x)
    vert_data[12].normal[1] =     0.0f;
    vert_data[12].normal[2] =     0.0f;
    vert_data[12].tangent[0] =   0.0f; // binormal
    vert_data[12].tangent[1] =   0.0f;
    vert_data[12].tangent[2] =  -1.0f;
    vert_data[12].binormal[0] =    0.0f; // tangent
    vert_data[12].binormal[1] =    1.0f;
    vert_data[12].binormal[2] =    0.0f;

    // vertex 13
    vert_data[13].pos[0] =        1.0f; // position
    vert_data[13].pos[1] =       -1.0f;
    vert_data[13].pos[2] =       -1.0f;
    vert_data[13].col[0] =        1.0f; // color
    vert_data[13].col[1] =        0.0f;
    vert_data[13].col[2] =        0.0f;
    vert_data[13].tex_coord[0] =  1.0f; // tex coord
    vert_data[13].tex_coord[1] =  0.0f;
    vert_data[13].normal[0] =     0.0f; // normal (y)
    vert_data[13].normal[1] =    -1.0f;
    vert_data[13].normal[2] =     0.0f;
    vert_data[13].tangent[0] =   0.0f; // binormal
    vert_data[13].tangent[1] =   0.0f;
    vert_data[13].tangent[2] =  -1.0f;
    vert_data[13].binormal[0] =    1.0f; // tangent
    vert_data[13].binormal[1] =    0.0f;
    vert_data[13].binormal[2] =    0.0f;

    // vertex 14
    vert_data[14].pos[0] =        1.0f; // position
    vert_data[14].pos[1] =       -1.0f;
    vert_data[14].pos[2] =       -1.0f;
    vert_data[14].col[0] =        1.0f; // color
    vert_data[14].col[1] =        0.0f;
    vert_data[14].col[2] =        0.0f;
    vert_data[14].tex_coord[0] =  0.0f; // tex coord
    vert_data[14].tex_coord[1] =  0.0f;
    vert_data[14].normal[0] =     0.0f; // normal (z)
    vert_data[14].normal[1] =     0.0f;
    vert_data[14].normal[2] =    -1.0f;
    vert_data[14].tangent[0] =  -1.0f; // binormal
    vert_data[14].tangent[1] =   0.0f;
    vert_data[14].tangent[2] =   0.0f;
    vert_data[14].binormal[0] =    0.0f; // tangent
    vert_data[14].binormal[1] =    1.0f;
    vert_data[14].binormal[2] =    0.0f;

    // vertex 15
    vert_data[15].pos[0] =        1.0f; // position
    vert_data[15].pos[1] =        1.0f;
    vert_data[15].pos[2] =       -1.0f;
    vert_data[15].col[0] =        1.0f; // color
    vert_data[15].col[1] =        0.0f;
    vert_data[15].col[2] =        0.0f;
    vert_data[15].tex_coord[0] =  1.0f; // tex coord
    vert_data[15].tex_coord[1] =  1.0f;
    vert_data[15].normal[0] =     1.0f; // normal (x)
    vert_data[15].normal[1] =     0.0f;
    vert_data[15].normal[2] =     0.0f;
    vert_data[15].tangent[0] =   0.0f; // binormal
    vert_data[15].tangent[1] =   0.0f;
    vert_data[15].tangent[2] =  -1.0f;
    vert_data[15].binormal[0] =    0.0f; // tangent
    vert_data[15].binormal[1] =    1.0f;
    vert_data[15].binormal[2] =    0.0f;

    // vertex 16
    vert_data[16].pos[0] =        1.0f; // position
    vert_data[16].pos[1] =        1.0f;
    vert_data[16].pos[2] =       -1.0f;
    vert_data[16].col[0] =        1.0f; // color
    vert_data[16].col[1] =        0.0f;
    vert_data[16].col[2] =        0.0f;
    vert_data[16].tex_coord[0] =  1.0f; // tex coord
    vert_data[16].tex_coord[1] =  1.0f;
    vert_data[16].normal[0] =     0.0f; // normal (y)
    vert_data[16].normal[1] =     1.0f;
    vert_data[16].normal[2] =     0.0f;
    vert_data[16].tangent[0] =   1.0f; // binormal
    vert_data[16].tangent[1] =   0.0f;
    vert_data[16].tangent[2] =   0.0f;
    vert_data[16].binormal[0] =    0.0f; // tangent
    vert_data[16].binormal[1] =    0.0f;
    vert_data[16].binormal[2] =   -1.0f;

    // vertex 17
    vert_data[17].pos[0] =        1.0f; // position
    vert_data[17].pos[1] =        1.0f;
    vert_data[17].pos[2] =       -1.0f;
    vert_data[17].col[0] =        1.0f; // color
    vert_data[17].col[1] =        0.0f;
    vert_data[17].col[2] =        0.0f;
    vert_data[17].tex_coord[0] =  0.0f; // tex coord
    vert_data[17].tex_coord[1] =  1.0f;
    vert_data[17].normal[0] =     0.0f; // normal (z)
    vert_data[17].normal[1] =     0.0f;
    vert_data[17].normal[2] =    -1.0f;
    vert_data[17].tangent[0] =  -1.0f; // binormal
    vert_data[17].tangent[1] =   0.0f;
    vert_data[17].tangent[2] =   0.0f;
    vert_data[17].binormal[0] =    0.0f; // tangent
    vert_data[17].binormal[1] =    1.0f;
    vert_data[17].binormal[2] =    0.0f;

    // vertex 18
    vert_data[18].pos[0] =       -1.0f; // position
    vert_data[18].pos[1] =       -1.0f;
    vert_data[18].pos[2] =       -1.0f;
    vert_data[18].col[0] =        1.0f; // color
    vert_data[18].col[1] =        0.0f;
    vert_data[18].col[2] =        0.0f;
    vert_data[18].tex_coord[0] =  0.0f; // tex coord
    vert_data[18].tex_coord[1] =  0.0f;
    vert_data[18].normal[0] =    -1.0f; // normal (x)
    vert_data[18].normal[1] =     0.0f;
    vert_data[18].normal[2] =     0.0f;
    vert_data[18].tangent[0] =   0.0f; // binormal
    vert_data[18].tangent[1] =   0.0f;
    vert_data[18].tangent[2] =   1.0f;
    vert_data[18].binormal[0] =    0.0f; // tangent
    vert_data[18].binormal[1] =    1.0f;
    vert_data[18].binormal[2] =    0.0f;

    // vertex 19
    vert_data[19].pos[0] =       -1.0f; // position
    vert_data[19].pos[1] =       -1.0f;
    vert_data[19].pos[2] =       -1.0f;
    vert_data[19].col[0] =        1.0f; // color
    vert_data[19].col[1] =        0.0f;
    vert_data[19].col[2] =        0.0f;
    vert_data[19].tex_coord[0] =  0.0f; // tex coord
    vert_data[19].tex_coord[1] =  0.0f;
    vert_data[19].normal[0] =     0.0f; // normal (y)
    vert_data[19].normal[1] =    -1.0f;
    vert_data[19].normal[2] =     0.0f;
    vert_data[19].tangent[0] =   0.0f; // binormal
    vert_data[19].tangent[1] =   0.0f;
    vert_data[19].tangent[2] =  -1.0f;
    vert_data[19].binormal[0] =    1.0f; // tangent
    vert_data[19].binormal[1] =    0.0f;
    vert_data[19].binormal[2] =    0.0f;

    // vertex 20
    vert_data[20].pos[0] =       -1.0f; // position
    vert_data[20].pos[1] =       -1.0f;
    vert_data[20].pos[2] =       -1.0f;
    vert_data[20].col[0] =        1.0f; // color
    vert_data[20].col[1] =        0.0f;
    vert_data[20].col[2] =        0.0f;
    vert_data[20].tex_coord[0] =  1.0f; // tex coord
    vert_data[20].tex_coord[1] =  0.0f;
    vert_data[20].normal[0] =     0.0f; // normal (z)
    vert_data[20].normal[1] =     0.0f;
    vert_data[20].normal[2] =    -1.0f;
    vert_data[20].tangent[0] =  -1.0f; // binormal
    vert_data[20].tangent[1] =   0.0f;
    vert_data[20].tangent[2] =   0.0f;
    vert_data[20].binormal[0] =    0.0f; // tangent
    vert_data[20].binormal[1] =    1.0f;
    vert_data[20].binormal[2] =    0.0f;

    // vertex 21
    vert_data[21].pos[0] =       -1.0f; // position
    vert_data[21].pos[1] =        1.0f;
    vert_data[21].pos[2] =       -1.0f;
    vert_data[21].col[0] =        1.0f; // color
    vert_data[21].col[1] =        0.0f;
    vert_data[21].col[2] =        0.0f;
    vert_data[21].tex_coord[0] =  0.0f; // tex coord
    vert_data[21].tex_coord[1] =  1.0f;
    vert_data[21].normal[0] =    -1.0f; // normal (x)
    vert_data[21].normal[1] =     0.0f;
    vert_data[21].normal[2] =     0.0f;
    vert_data[21].tangent[0] =   0.0f; // binormal
    vert_data[21].tangent[1] =   0.0f;
    vert_data[21].tangent[2] =   1.0f;
    vert_data[21].binormal[0] =    0.0f; // tangent
    vert_data[21].binormal[1] =    1.0f;
    vert_data[21].binormal[2] =    0.0f;

    // vertex 22
    vert_data[22].pos[0] =       -1.0f; // position
    vert_data[22].pos[1] =        1.0f;
    vert_data[22].pos[2] =       -1.0f;
    vert_data[22].col[0] =        1.0f; // color
    vert_data[22].col[1] =        0.0f;
    vert_data[22].col[2] =        0.0f;
    vert_data[22].tex_coord[0] =  0.0f; // tex coord
    vert_data[22].tex_coord[1] =  1.0f;
    vert_data[22].normal[0] =     0.0f; // normal (y)
    vert_data[22].normal[1] =     1.0f;
    vert_data[22].normal[2] =     0.0f;
    vert_data[22].tangent[0] =   1.0f; // binormal
    vert_data[22].tangent[1] =   0.0f;
    vert_data[22].tangent[2] =   0.0f;
    vert_data[22].binormal[0] =    0.0f; // tangent
    vert_data[22].binormal[1] =    0.0f;
    vert_data[22].binormal[2] =   -1.0f;

    // vertex 23
    vert_data[23].pos[0] =       -1.0f; // position
    vert_data[23].pos[1] =        1.0f;
    vert_data[23].pos[2] =       -1.0f;
    vert_data[23].col[0] =        1.0f; // color
    vert_data[23].col[1] =        0.0f;
    vert_data[23].col[2] =        0.0f;
    vert_data[23].tex_coord[0] =  1.0f; // tex coord
    vert_data[23].tex_coord[1] =  1.0f;
    vert_data[23].normal[0] =     0.0f; // normal (z)
    vert_data[23].normal[1] =     0.0f;
    vert_data[23].normal[2] =    -1.0f;
    vert_data[23].tangent[0] =  -1.0f; // binormal
    vert_data[23].tangent[1] =   0.0f;
    vert_data[23].tangent[2] =   0.0f;
    vert_data[23].binormal[0] =    0.0f; // tangent
    vert_data[23].binormal[1] =    1.0f;
    vert_data[23].binormal[2] =    0.0f;

    return Geometry(vert_data, ind_buf);
}

Geometry GenSphere()
{
    std::vector<Vertex> vert_data(24);
    std::vector<unsigned int> ind_buf({0, 1, 2, 1, 3, 2});

    return Geometry(vert_data, ind_buf);
}
