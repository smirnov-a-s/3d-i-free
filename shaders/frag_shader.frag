#version 330 core

in vec3 fPos;
in vec3 fColor;
in vec2 fTexCoord;
in vec3 fNormal;
in vec3 fBinormal;
in vec3 fTangent;

in vec3 v_light;

out vec3 color;

uniform float time;

uniform vec3 lightPos;
uniform vec3 eyePos;

uniform sampler2D myTextureSampler;

#define M_PI 3.1415926535897932384626433832795
// #define FREQ 1.0
// #define R 0.2


void main()
{
        float lambert = max(dot(fNormal, v_light), 0.0);

        color = texture(myTextureSampler, fTexCoord).rgb;
        // color = vec3(1.0, 0.0, 0.0);
        color *= lambert;
}
