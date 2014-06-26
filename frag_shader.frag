#version 330 core
#define M_PI 3.1415926535897932384626433832795
#define FREQ 1.0

in vec2 pos;

// Ouput data
out vec3 color;

uniform float time;

#define R 0.2

void main()
{
        float x = pos.x - 0.5;
        x *= x;

        float y = pos.y - 0.5;
        y *= y;

        if (sqrt(x + y) < R)
                color = vec3(1.0, 0.0, 0.0);
        else
                color = vec3(1.0, 1.0, 1.0);

}
