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
    vert_data[0].binormal[0] = 0.0f;
    vert_data[0].binormal[1] = 0.0f;
    vert_data[0].binormal[2] = 0.0f;

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
    vert_data[1].binormal[0] = 0.0f;
    vert_data[1].binormal[1] = 0.0f;
    vert_data[1].binormal[2] = 0.0f;

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
    vert_data[2].binormal[0] = 0.0f;
    vert_data[2].binormal[1] = 0.0f;
    vert_data[2].binormal[2] = 0.0f;

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
    vert_data[0].binormal[0] = 0.0f;
    vert_data[0].binormal[1] = 0.0f;
    vert_data[0].binormal[2] = 0.0f;

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
    vert_data[1].binormal[0] = 0.0f;
    vert_data[1].binormal[1] = 0.0f;
    vert_data[1].binormal[2] = 0.0f;

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
    vert_data[2].binormal[0] = 0.0f;
    vert_data[2].binormal[1] = 0.0f;
    vert_data[2].binormal[2] = 0.0f;

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
    vert_data[3].binormal[0] = 0.0f;
    vert_data[3].binormal[1] = 0.0f;
    vert_data[3].binormal[2] = 0.0f;

    return Geometry(vert_data, ind_buf);
}

Geometry GenCube()
{
    std::vector<Vertex> vert_data(24);
    std::vector<unsigned int> ind_buf({0, 1, 2, 1, 3, 2});

    // vertex 0
    vert_data[0].pos[0] =       -1.0f; // position
    vert_data[0].pos[1] =       -1.0f;
    vert_data[0].pos[2] =        1.0f;
    vert_data[0].col[0] =        1.0f; // color
    vert_data[0].col[1] =        0.0f;
    vert_data[0].col[2] =        0.0f;
    vert_data[0].tex_coord[0] =  0.0f; // tex coord
    vert_data[0].tex_coord[1] =  0.0f;
    vert_data[0].normal[0] =    -1.0f; // normal (x)
    vert_data[0].normal[1] =     0.0f;
    vert_data[0].normal[2] =     0.0f;
    vert_data[0].binormal[0] =   0.0f; // binormal
    vert_data[0].binormal[1] =   0.0f;
    vert_data[0].binormal[2] =   0.0f;
    vert_data[0].binormal[0] =   0.0f; // tangent
    vert_data[0].binormal[1] =   0.0f;
    vert_data[0].binormal[2] =   0.0f;

    // vertex 1
    vert_data[1].pos[0] =       -1.0f; // position
    vert_data[1].pos[1] =       -1.0f;
    vert_data[1].pos[2] =        1.0f;
    vert_data[1].col[0] =        1.0f; // color
    vert_data[1].col[1] =        0.0f;
    vert_data[1].col[2] =        0.0f;
    vert_data[1].tex_coord[0] =  0.0f; // tex coord
    vert_data[1].tex_coord[1] =  0.0f;
    vert_data[1].normal[0] =     0.0f; // normal (y)
    vert_data[1].normal[1] =    -1.0f;
    vert_data[1].normal[2] =     0.0f;
    vert_data[1].binormal[0] =   0.0f; // binormal
    vert_data[1].binormal[1] =   0.0f;
    vert_data[1].binormal[2] =   0.0f;
    vert_data[1].binormal[0] =   0.0f; // tangent
    vert_data[1].binormal[1] =   0.0f;
    vert_data[1].binormal[2] =   0.0f;

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
    vert_data[2].binormal[0] =   0.0f; // binormal
    vert_data[2].binormal[1] =   0.0f;
    vert_data[2].binormal[2] =   0.0f;
    vert_data[2].binormal[0] =   0.0f; // tangent
    vert_data[2].binormal[1] =   0.0f;
    vert_data[2].binormal[2] =   0.0f;

    // vertex 3
    vert_data[3].pos[0] =        1.0f; // position
    vert_data[3].pos[1] =       -1.0f;
    vert_data[3].pos[2] =        1.0f;
    vert_data[3].col[0] =        1.0f; // color
    vert_data[3].col[1] =        0.0f;
    vert_data[3].col[2] =        0.0f;
    vert_data[3].tex_coord[0] =  1.0f; // tex coord
    vert_data[3].tex_coord[1] =  0.0f;
    vert_data[3].normal[0] =     1.0f; // normal (x)
    vert_data[3].normal[1] =     0.0f;
    vert_data[3].normal[2] =     0.0f;
    vert_data[3].binormal[0] =   0.0f; // binormal
    vert_data[3].binormal[1] =   0.0f;
    vert_data[3].binormal[2] =   0.0f;
    vert_data[3].binormal[0] =   0.0f; // tangent
    vert_data[3].binormal[1] =   0.0f;
    vert_data[3].binormal[2] =   0.0f;

    // vertex 4
    vert_data[4].pos[0] =        1.0f; // position
    vert_data[4].pos[1] =       -1.0f;
    vert_data[4].pos[2] =        1.0f;
    vert_data[4].col[0] =        1.0f; // color
    vert_data[4].col[1] =        0.0f;
    vert_data[4].col[2] =        0.0f;
    vert_data[4].tex_coord[0] =  1.0f; // tex coord
    vert_data[4].tex_coord[1] =  0.0f;
    vert_data[4].normal[0] =     0.0f; // normal (y)
    vert_data[4].normal[1] =     1.0f;
    vert_data[4].normal[2] =     0.0f;
    vert_data[4].binormal[0] =   0.0f; // binormal
    vert_data[4].binormal[1] =   0.0f;
    vert_data[4].binormal[2] =   0.0f;
    vert_data[4].binormal[0] =   0.0f; // tangent
    vert_data[4].binormal[1] =   0.0f;
    vert_data[4].binormal[2] =   0.0f;

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
    vert_data[5].binormal[0] =   0.0f; // binormal
    vert_data[5].binormal[1] =   0.0f;
    vert_data[5].binormal[2] =   0.0f;
    vert_data[5].binormal[0] =   0.0f; // tangent
    vert_data[5].binormal[1] =   0.0f;
    vert_data[5].binormal[2] =   0.0f;

    // vertex 6
    vert_data[6].pos[0] =       -1.0f; // position
    vert_data[6].pos[1] =        1.0f;
    vert_data[6].pos[2] =        1.0f;
    vert_data[6].col[0] =        1.0f; // color
    vert_data[6].col[1] =        0.0f;
    vert_data[6].col[2] =        0.0f;
    vert_data[6].tex_coord[0] =  0.0f; // tex coord
    vert_data[6].tex_coord[1] =  1.0f;
    vert_data[6].normal[0] =    -1.0f; // normal (x)
    vert_data[6].normal[1] =     0.0f;
    vert_data[6].normal[2] =     0.0f;
    vert_data[6].binormal[0] =   0.0f; // binormal
    vert_data[6].binormal[1] =   0.0f;
    vert_data[6].binormal[2] =   0.0f;
    vert_data[6].binormal[0] =   0.0f; // tangent
    vert_data[6].binormal[1] =   0.0f;
    vert_data[6].binormal[2] =   0.0f;

    // vertex 7
    vert_data[7].pos[0] =       -1.0f; // position
    vert_data[7].pos[1] =        1.0f;
    vert_data[7].pos[2] =        1.0f;
    vert_data[7].col[0] =        1.0f; // color
    vert_data[7].col[1] =        0.0f;
    vert_data[7].col[2] =        0.0f;
    vert_data[7].tex_coord[0] =  0.0f; // tex coord
    vert_data[7].tex_coord[1] =  1.0f;
    vert_data[7].normal[0] =     0.0f; // normal (y)
    vert_data[7].normal[1] =     1.0f;
    vert_data[7].normal[2] =     0.0f;
    vert_data[7].binormal[0] =   0.0f; // binormal
    vert_data[7].binormal[1] =   0.0f;
    vert_data[7].binormal[2] =   0.0f;
    vert_data[7].binormal[0] =   0.0f; // tangent
    vert_data[7].binormal[1] =   0.0f;
    vert_data[7].binormal[2] =   0.0f;

    // vertex 8
    vert_data[8].pos[0] =       -1.0f; // position
    vert_data[8].pos[1] =        1.0f;
    vert_data[8].pos[2] =        1.0f;
    vert_data[8].col[0] =        1.0f; // color
    vert_data[8].col[1] =        0.0f;
    vert_data[8].col[2] =        0.0f;
    vert_data[8].tex_coord[0] =  0.0f; // tex coord
    vert_data[8].tex_coord[1] =  0.0f;
    vert_data[8].normal[0] =     0.0f; // normal (z)
    vert_data[8].normal[1] =     0.0f;
    vert_data[8].normal[2] =     1.0f;
    vert_data[8].binormal[0] =   0.0f; // binormal
    vert_data[8].binormal[1] =   0.0f;
    vert_data[8].binormal[2] =   0.0f;
    vert_data[8].binormal[0] =   0.0f; // tangent
    vert_data[8].binormal[1] =   0.0f;
    vert_data[8].binormal[2] =   0.0f;

    // vertex 9
    vert_data[8].pos[0] =        1.0f; // position
    vert_data[8].pos[1] =        1.0f;
    vert_data[8].pos[2] =        1.0f;
    vert_data[8].col[0] =        1.0f; // color
    vert_data[8].col[1] =        0.0f;
    vert_data[8].col[2] =        0.0f;
    vert_data[8].tex_coord[0] =  1.0f; // tex coord
    vert_data[8].tex_coord[1] =  1.0f;
    vert_data[8].normal[0] =     1.0f; // normal (x)
    vert_data[8].normal[1] =     0.0f;
    vert_data[8].normal[2] =     0.0f;
    vert_data[8].binormal[0] =   0.0f; // binormal
    vert_data[8].binormal[1] =   0.0f;
    vert_data[8].binormal[2] =   0.0f;
    vert_data[8].binormal[0] =   0.0f; // tangent
    vert_data[8].binormal[1] =   0.0f;
    vert_data[8].binormal[2] =   0.0f;

    // vertex 10
    vert_data[10].pos[0] =        1.0f; // position
    vert_data[10].pos[1] =        1.0f;
    vert_data[10].pos[2] =        1.0f;
    vert_data[10].col[0] =        1.0f; // color
    vert_data[10].col[1] =        0.0f;
    vert_data[10].col[2] =        0.0f;
    vert_data[10].tex_coord[0] =  1.0f; // tex coord
    vert_data[10].tex_coord[1] =  1.0f;
    vert_data[10].normal[0] =     0.0f; // normal (y)
    vert_data[10].normal[1] =     1.0f;
    vert_data[10].normal[2] =     0.0f;
    vert_data[10].binormal[0] =   0.0f; // binormal
    vert_data[10].binormal[1] =   0.0f;
    vert_data[10].binormal[2] =   0.0f;
    vert_data[10].binormal[0] =   0.0f; // tangent
    vert_data[10].binormal[1] =   0.0f;
    vert_data[10].binormal[2] =   0.0f;

    // vertex 11
    vert_data[10].pos[0] =        1.0f; // position
    vert_data[10].pos[1] =        1.0f;
    vert_data[10].pos[2] =        1.0f;
    vert_data[10].col[0] =        1.0f; // color
    vert_data[10].col[1] =        0.0f;
    vert_data[10].col[2] =        0.0f;
    vert_data[10].tex_coord[0] =  1.0f; // tex coord
    vert_data[10].tex_coord[1] =  1.0f;
    vert_data[10].normal[0] =     0.0f; // normal (z)
    vert_data[10].normal[1] =     0.0f;
    vert_data[10].normal[2] =     1.0f;
    vert_data[10].binormal[0] =   0.0f; // binormal
    vert_data[10].binormal[1] =   0.0f;
    vert_data[10].binormal[2] =   0.0f;
    vert_data[10].binormal[0] =   0.0f; // tangent
    vert_data[10].binormal[1] =   0.0f;
    vert_data[10].binormal[2] =   0.0f;

    return Geometry(vert_data, ind_buf);
}

Geometry GenSphere()
{
    std::vector<Vertex> vert_data(24);
    std::vector<unsigned int> ind_buf({0, 1, 2, 1, 3, 2});

    return Geometry(vert_data, ind_buf);
}
