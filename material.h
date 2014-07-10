class Material {
    GLuint prog_id;
public:
    Material(const char* vert_fpath, const char* frag_fpath);
    GLuint GetProgId() { return prog_id; }
};
