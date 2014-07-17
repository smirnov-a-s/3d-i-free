#ifndef MATERIAL_H
#define MATERIAL_H

class Material {
    GLuint prog_id;
public:
    Material(const char* vert_fpath, const char* frag_fpath);
    GLuint GetProgId() const { return prog_id; }
};

#endif
