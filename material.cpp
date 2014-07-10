#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <GL/glew.h>

#include "material.h"

Material::Material(const char* vert_fpath, const char* frag_fpath)
{
    // create ids
    GLuint v_id = glCreateShader(GL_VERTEX_SHADER);
    GLuint f_id = glCreateShader(GL_FRAGMENT_SHADER);

    // get sources
    std::string v_sources = "";
    std::ifstream v_file(vert_fpath);

    if (v_file.is_open()) {
        std::string line = "";
        while (getline(v_file, line)) {
            v_sources += line;
            v_sources += "\n";
        }
        v_file.close();
    } else {
        printf("Can't open %s!", vert_fpath);
        prog_id = 0;
    }

    std::string f_sources = "";
    std::ifstream f_file(frag_fpath);

    if (f_file.is_open()) {
        std::string line = "";
        while (getline(f_file, line)) {
            f_sources += line;
            f_sources += "\n";
        }
        f_file.close();
    } else {
        printf("Can't open %s!", frag_fpath);
        prog_id = 0;
    }

    // compile
    GLint res = GL_FALSE;
    int info_log_len = 0;

    printf("Compiling shader: %s\n", vert_fpath);
    char const* v_sources_ptr = v_sources.c_str();
    int len = v_sources.length();

    glShaderSource(v_id, 1, (const GLchar **)&v_sources_ptr, &len);
    glCompileShader(v_id);

    // check vertex shader
    glGetShaderiv(v_id, GL_COMPILE_STATUS, &res);
    glGetShaderiv(v_id, GL_INFO_LOG_LENGTH, &info_log_len);

    if (info_log_len > 0) {
        std::vector<char> v_error_message(info_log_len + 1);
        glGetShaderInfoLog(v_id, info_log_len, NULL, &v_error_message[0]);
        printf("%s\n", &v_error_message[0]);
    }

    printf("Compiling shader: %s\n", frag_fpath);

    char const* f_sources_ptr = f_sources.c_str();
    len = f_sources.length();

    glShaderSource(f_id, 1, (const GLchar **)&f_sources_ptr, &len);
    glCompileShader(f_id);

    // check vertex shader
    glGetShaderiv(f_id, GL_COMPILE_STATUS, &res);
    glGetShaderiv(f_id, GL_INFO_LOG_LENGTH, &info_log_len);

    if (info_log_len > 0) {
        std::vector<char> f_error_message(info_log_len + 1);
        glGetShaderInfoLog(f_id, info_log_len, NULL, &f_error_message[0]);
        printf("%s\n", &f_error_message[0]);
    }

    // link
    printf("Linking program...\n");

    prog_id = glCreateProgram();

    glAttachShader(prog_id, v_id);
    glAttachShader(prog_id, f_id);

    glLinkProgram(prog_id);

    // check
    glGetProgramiv(prog_id, GL_LINK_STATUS, &res);
    glGetProgramiv(prog_id, GL_INFO_LOG_LENGTH, &info_log_len);

    if (info_log_len > 0) {
        std::vector<char> prog_error_message(info_log_len + 1);
        glGetProgramInfoLog(prog_id, info_log_len, NULL, &prog_error_message[0]);
        printf("%s\n", &prog_error_message[0]);
    }

    // glDeleteShader(v_id);
    // glDeleteShader(f_id);
}
