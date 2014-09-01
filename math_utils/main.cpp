#include <stdio.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "math_utils.h"

void print_mat(const glm::mat4& m)
{
    printf("glm_mat4 = \n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%f ", m[i][j]);
        }
        printf("\n");
    }
}

void print_mat(MyMath::Mat4& m)
{
    printf("my_mat4 = \n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%f ", m[i][j]);
        }
        printf("\n");
    }
}

void print_vec(const glm::vec4& v)
{
    printf("glm_vec4 = \n");
    for (int i = 0; i < 4; i++)
        printf("%f ", v[i]);

    printf("| %f ", glm::length(v));

    printf("\n");
}

void print_vec(const glm::vec3& v)
{
    printf("glm_vec3 = \n");
    for (int i = 0; i < 3; i++)
        printf("%f ", v[i]);

    printf("| %f ", glm::length(v));

    printf("\n");
}

void print_vec(const MyMath::Vec4& v)
{
    printf("my_vec4 = \n");
    printf("%f %f %f %f | %f\n", v.x, v.y, v.z, v.w, v.Length());
}

void print_vec(MyMath::Vec3& v)
{
    printf("my_vec3 = \n");
    printf("%f %f %f | %f\n", v.x, v.y, v.z, v.Length());
}

MyMath::Mat4 LookAt(MyMath::Vec3& my_eye, glm::vec3 eye, MyMath::Vec3& my_center, glm::vec3 center, MyMath::Vec3& my_up, glm::vec3 up)
{
    // detail::tvec3<T, P> f(normalize(center - eye));
    // detail::tvec3<T, P> s(normalize(cross(f, up)));
    // detail::tvec3<T, P> u(cross(s, f));

    // detail::tmat4x4<T, P> Result(1);
    // Result[0][0] = s.x;
    // Result[1][0] = s.y;
    // Result[2][0] = s.z;
    // Result[0][1] = u.x;
    // Result[1][1] = u.y;
    // Result[2][1] = u.z;
    // Result[0][2] =-f.x;
    // Result[1][2] =-f.y;
    // Result[2][2] =-f.z;
    // Result[3][0] =-dot(s, eye);
    // Result[3][1] =-dot(u, eye);
    // Result[3][2] = dot(f, eye);

    MyMath::Mat4 m;

    MyMath::Vec3 my_f;
    glm::vec3 f;

    MyMath::Vec3 my_s;
    glm::vec3 s;

    MyMath::Vec3 my_u;
    glm::vec3 u;

    f = center - eye;
    f = glm::normalize(f);

    my_f = my_center - my_eye;
    my_f = Normalize(my_f);

    print_vec(f);
    print_vec(my_f);

    // s = Cross(f, up);
    // s = Normalize(s);

    // u = Cross(s, f);

    // m[0][0] = s.x;
    // m[1][0] = s.y;
    // m[2][0] = s.z;
    // m[0][1] = u.x;
    // m[1][1] = u.y;
    // m[2][1] = u.z;
    // m[0][2] =-f.x;
    // m[1][2] =-f.y;
    // m[2][2] =-f.z;
    // m[3][0] =-Dot(s, eye);
    // m[3][1] =-Dot(u, eye);
    // m[3][2] = Dot(f, eye);

    // Vec3 x;
    // Vec3 y;
    // Vec3 z;

    // z = eye - center;
    // z = Normalize(z);
    // y = up;
    // x = Cross(y, z);
    // y = Cross(z, x);
    // x = Normalize(x);
    // y = Normalize(y);

    // m[0][0] = x.x;
    // m[1][0] = x.y;
    // m[2][0] = x.z;
    // m[3][0] = -Dot(x, eye);
    // m[0][1] = y.x;
    // m[1][1] = y.y;
    // m[2][1] = y.z;
    // m[3][1] = -Dot(y, eye);
    // m[0][2] = z.x;
    // m[1][2] = z.y;
    // m[2][2] = z.z;
    // m[3][2] = -Dot(z, eye);
    // m[0][3] = 0.0f;
    // m[1][3] = 0.0f;
    // m[2][3] = 0.0f;
    // m[3][3] = 1.0f;

    return m;
}

int main(void)
{
    // glm::vec4 glm_v1(0.7f, 5.0f, 3.0f, 1.0f);
    // glm::vec4 glm_v2(-1.0f, -3.0f, -0.38f, 1.0f);

    // MyMath::Vec4 v1(0.7f, 5.0f, 3.0f, 1.0f);
    // MyMath::Vec4 v2(-1.0f, -3.0f, -0.38f, 1.0f);

    // print_vec(glm_v1);
    // print_vec(glm_v2);
    // print_vec(v1);
    // print_vec(v2);

    // glm_v1 = -glm_v1;
    // glm_v1 -= glm_v2;
    // glm_v1 = glm_v1 - glm_v2;

    // glm_v1 += glm_v2;
    // glm_v1 = glm_v1 + glm_v2;

    // glm_v1 *= 2.0f;
    // glm_v1 = glm_v1 * 2.0f;

    // glm_v1 /= 2.0f;
    // glm_v1 = glm_v1 / 2.0f;

    // float dotp = glm::dot(glm_v1, glm_v2);
    // glm::vec3 glm_crs = glm::cross(glm_v1, glm_v2);

    // printf("dot = %f\n", dotp);
    // printf("cross = (%f, %f, %f) \n", glm_crs.x, glm_crs.y, glm_crs.z);

    // v1 = -v1;
    // v1 -= v2;
    // v1 = v1 - v2;

    // v1 += v2;
    // v1 = v1 + v2;

    // v1 *= 2.0f;
    // v1 = v1 * 2.0f;

    // v1 /= 2.0f;
    // v1 = v1 / 2.0f;

    // printf("(%f, %f)\n", v1.x, v1.y);
    // dotp = Dot(v1, v2);
    // MyMath::Vec3 my_crs = Cross(v1, v2);

    // printf("dot = %f\n", dotp);
    // printf("cross = (%f, %f, %f) \n", my_crs.x, my_crs.y, my_crs.z);

    printf("matricies:\n");

    glm::mat4 m = glm::mat4(1.0f);
    glm::vec4 tv(1.0f, 2.0f, 3.0f, 1.0f);

    MyMath::Mat4 my_m;
    MyMath::Vec4 my_tv(1.0f, 2.0f, 3.0f, 1.0f);

    print_vec(tv);
    print_vec(my_tv);

    print_mat(m);
    print_mat(my_m);

    // m = m + m;
    // my_m = my_m + my_m;

    // m = m - m;
    // my_m = my_m - my_m;

    // m = m / 2.0f;
    // my_m = my_m / 2.0f;

    // tv = m * tv;
    // my_tv = my_m * my_tv;

    print_vec(tv);
    print_vec(my_tv);

    float tx = 5.0f;
    float ty = 5.0f;
    float tz = 5.0f;

    glm::mat4 glm_tr_m = glm::translate(m, glm::vec3(tx, ty, tz));
    MyMath::Mat4 my_tr_m = MyMath::Translate(tx, ty, tz);

    print_mat(glm_tr_m);
    print_mat(my_tr_m);

    tv =  glm_tr_m * tv;
    my_tv = my_tr_m * my_tv;

    print_vec(tv);
    print_vec(my_tv);

    printf("projection matrix:\n");

    // glm::perspective(const T &fovy, const T &aspect, const T &zNear, const T &zFar);

    float fov = 45.0f;
    float aspect = 4.0f / 3.0f;
    float near = 0.1f;
    float far = 100.0f;

    // float frustumDepth = far - near;
    // float oneOverDepth = 1.0f / frustumDepth;

    glm::mat4 proj_m = glm::perspective(fov, aspect, near, far);
    print_mat(proj_m);

    MyMath::Mat4 my_proj_m = MyMath::Perspective(fov, aspect, near, far);
    print_mat(my_proj_m);

    // glm::lookAt(const detail::tvec3<T, P> &eye, const detail::tvec3<T, P> &center, const detail::tvec3<T, P> &up);

    glm::vec3 eye(1.0f, 10.0f, -5.0f);
    glm::vec3 center(1.0f, 1.0f, 1.0f);
    glm::vec3 up(0.0f, 1.0f, 0.0f);

    glm::mat4 look_at_m = glm::lookAt(eye, center, up);

    print_mat(look_at_m);

    MyMath::Vec3 my_eye(1.0f, 10.0f, -5.0f);
    MyMath::Vec3 my_center(1.0f, 1.0f, 1.0f);
    MyMath::Vec3 my_up(0.0f, 1.0f, 0.0f);

    MyMath::Mat4 my_look_at_m = MyMath::LookAt(my_eye, my_center, my_up);

    print_mat(my_look_at_m);
    // LookAt(my_eye, eye, my_center, center, my_up, up);

    // float tmp1 = 1.0f / (tan(fov * 0.5f * (float) M_PI / 180.0f));
    // printf("tmp1 = %f\n", tmp1);

    // float tmp2 = tmp1 / aspect;
    // printf("tmp2 = %f\n", tmp2);

    // // float tmp3 = -far * oneOverDepth;
    // float tmp3 = (far + near) / (near - far);
    // printf("tmp3 = %f\n", tmp3);

    // float tmp4 = 2 * far * near / (near - far);
    // printf("tmp4 = %f\n", tmp4);

    // project_matrix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

    return 0;
}
