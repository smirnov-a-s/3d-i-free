#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <math.h>
#include <vector>

namespace MyMath {

// Vec2 stuff
class Vec2 {
  public:
    float x;
    float y;

    Vec2() { x = 0; y = 0; }
    Vec2(float x, float y) : x(x), y(y) {}

    Vec2& operator+=(Vec2 v) { x += v.x; y += v.y; return *this; }
    Vec2& operator-=(Vec2 v) { x -= v.x; y -= v.y; return *this; }

    Vec2& operator*=(float c) { x *= c; y *= c; return *this; }
    Vec2& operator/=(float c) { x /= c; y /= c; return *this; }

    float Length() { return sqrt(x * x + y * y); }
};

Vec2 operator-(Vec2 v);
Vec2 operator-(Vec2 v1, Vec2 v2);
Vec2 operator+(Vec2 v1, Vec2 v2);

Vec2 operator*(Vec2 v, float c);
Vec2 operator/(Vec2 v, float c);

float Dot(const Vec2& v1, const Vec2& v2);

// Vec3 stuff
class Vec3 {
  public:
    float x;
    float y;
    float z;

    Vec3() { x = 0; y = 0; z = 0; }
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    Vec3& operator+=(Vec3 v) { x += v.x; y += v.y; z += v.z; return *this; }
    Vec3& operator-=(Vec3 v) { x -= v.x; y -= v.y; z -= v.z; return *this; }

    Vec3& operator*=(float c) { x *= c; y *= c; z *= c; return *this; }
    Vec3& operator/=(float c) { x /= c; y /= c; z /= c; return *this; }

    float Length() { return sqrt(x * x + y * y + z * z); }
};

Vec3 operator-(Vec3 v);
Vec3 operator-(Vec3 v1, Vec3 v2);
Vec3 operator+(Vec3 v1, Vec3 v2);

Vec3 operator*(Vec3 v, float c);
Vec3 operator/(Vec3 v, float c);

float Dot(const Vec3& v1, const Vec3& v2);
Vec3 Cross(const Vec3& v1, const Vec3& v2);
Vec3 Normalize(Vec3& v);

class Vec4 {
  public:
    float x;
    float y;
    float z;
    float w;

    Vec4() { x = 0; y = 0; z = 0; w = 0; }
    Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    Vec4& operator+=(Vec4 v) { x += v.x; y += v.y; z += v.z; w += v.w; return *this; }
    Vec4& operator-=(Vec4 v) { x -= v.x; y -= v.y; z += v.z; w += v.w; return *this; }

    Vec4& operator*=(float c) { x *= c; y *= c; z *= c; w *= c; return *this; }
    Vec4& operator/=(float c) { x /= c; y /= c; z /= c; w /= c; return *this; }

    float& operator[](int i)
    {
        switch (i)
        {
            case 0:
                return this->x;
                break;
            case 1:
                return this->y;
                break;
            case 2:
                return this->z;
                break;
        }

        return this->w;
    }

    const float Length() const { return sqrt(x * x + y * y + z * z + w * w); }
};

Vec4 operator-(Vec4 v);
Vec4 operator-(Vec4 v1, Vec4 v2);
Vec4 operator+(Vec4 v1, Vec4 v2);

Vec4 operator*(Vec4 v, float c);
Vec4 operator/(Vec4 v, float c);

float Dot(const Vec4& v1, const Vec4& v2);

class Mat4 {
    std::vector<float> m;
  public:
    Mat4();

    float* operator[](int i) { return &m[4 * i]; }

    Mat4& operator+=(Mat4 mat) {
        int k = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                m[k++] += mat[i][j];
            }
        }

        return *this;
    }

    Mat4& operator-=(Mat4 mat)
    {
        int k = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                m[k++] -= mat[i][j];
            }
        }

        return *this;
    }

    Mat4& operator*=(float c)
    {
        for (int i = 0; i < 16; i++) {
            m[i] *= c;
        }

        return *this;
    }

    Mat4& operator/=(float c)
    {
        for (int i = 0; i < 16; i++) {
            m[i] /= c;
        }

        return *this;
    }
};

Mat4 operator-(Mat4 m1, Mat4 v2);
Mat4 operator+(Mat4 m1, Mat4 v2);

Mat4 operator*(Mat4 m, float c);
Vec4 operator*(Mat4 m, Vec4 v);
Mat4 operator/(Mat4 m, float c);

Mat4 Translate(float tx, float ty, float tz);
Mat4 Scale(float sx, float sy, float sz);

// void Rotate(float angle_in_degr, glm::vec3& axis);

// view_matrix = glm::lookAt(camera_pos, camera_look_at, camera_head);
// project_matrix = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

// glm::mat4 proj_m = glm::perspective(fov, aspect, near, far);

Mat4 Perspective(float fov, float aspect, float near, float far);

// glm::mat4 loot_at_m = glm::lookAt(eye, center, up);

Mat4 LookAt(Vec3& eye, Vec3& center, Vec3& up);

}

#endif
