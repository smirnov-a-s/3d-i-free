#include "math_utils.h"

namespace MyMath {

Vec2 operator-(Vec2 v)
{
    return {-v.x, -v.y};
}

Vec2 operator-(Vec2 v1, Vec2 v2)
{
    return v1 -= v2;
}

Vec2 operator+(Vec2 v1, Vec2 v2)
{
    return v1 += v2;
}

Vec2 operator*(Vec2 v, float c)
{
    return v *= c;
}

Vec2 operator/(Vec2 v, float c)
{
    return v /= c;
}

float Dot(const Vec2& v1, const Vec2& v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

Vec3 operator-(Vec3 v)
{
    return {-v.x, -v.y, -v.z};
}

Vec3 operator-(Vec3 v1, Vec3 v2)
{
    return v1 -= v2;
}

Vec3 operator+(Vec3 v1, Vec3 v2)
{
    return v1 += v2;
}

Vec3 operator*(Vec3 v, float c)
{
    return v *= c;
}

Vec3 operator/(Vec3 v, float c)
{
    return v /= c;
}

float Dot(const Vec3& v1, const Vec3& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vec3 Cross(const Vec3& v1, const Vec3& v2)
{
    return { v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x };
}

Vec3 Normalize(Vec3& v)
{
    Vec3 norm_v;

    float len = v.Length();

    norm_v.x = v.x / len;
    norm_v.y = v.y / len;
    norm_v.z = v.z / len;

    return norm_v;
}

Vec4 operator-(Vec4 v)
{
    return {-v.x, -v.y, -v.z, -v.w};
}

Vec4 operator-(Vec4 v1, Vec4 v2)
{
    return v1 -= v2;
}

Vec4 operator+(Vec4 v1, Vec4 v2)
{
    return v1 += v2;
}

Vec4 operator*(Vec4 v, float c)
{
    return v *= c;
}

Vec4 operator/(Vec4 v, float c)
{
    return v /= c;
}

float Dot(const Vec4& v1, const Vec4& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

Mat4::Mat4()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j)
                m.push_back(1.0f);
            else
                m.push_back(0.0f);
        }
    }
}

Mat4 operator-(Mat4 m1, Mat4 m2)
{
    return m1 -= m2;
}

Mat4 operator+(Mat4 m1, Mat4 m2)
{
    return m1 += m2;
}

Vec4 operator*(Mat4 m, Vec4 v)
{
    Vec4 tmp;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tmp[i] += m[i][j] * v[j];
        }
    }

    return tmp;
}

Mat4 operator/(Mat4 m, float c)
{
    return m /= c;
}

Mat4 Translate(float tx, float ty, float tz)
{
    Mat4 m;

    m[0][3] = tx;
    m[1][3] = ty;
    m[2][3] = tz;

    return m;
}

Mat4 Scale(float sx, float sy, float sz)
{
    Mat4 m;

    m[0][0] = sx;
    m[1][1] = sy;
    m[2][2] = sz;

    return m;
}

Mat4 Perspective(float fov, float aspect, float near, float far)
{

    Mat4 m;
    m[1][1] = 1.0f / (tan(fov * 0.5f * (float) M_PI / 180.0f));
    m[0][0] = m[1][1] / aspect;
    m[2][2] = (far + near) / (near - far);
    m[2][3] = -1.0f;
    m[3][2] = 2 * far * near / (near - far);

    return m;
}

Mat4 LookAt(Vec3& eye, Vec3& center, Vec3& up)
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

    Mat4 m;

    Vec3 f;
    Vec3 s;
    Vec3 u;

    f = center - eye;
    f = Normalize(f);

    s = Cross(f, up);
    s = Normalize(s);

    u = Cross(s, f);

    m[0][0] = s.x;
    m[1][0] = s.y;
    m[2][0] = s.z;
    m[0][1] = u.x;
    m[1][1] = u.y;
    m[2][1] = u.z;
    m[0][2] =-f.x;
    m[1][2] =-f.y;
    m[2][2] =-f.z;
    m[3][0] =-Dot(s, eye);
    m[3][1] =-Dot(u, eye);
    m[3][2] = Dot(f, eye);

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

}
