#version 330 core

layout(location = 0) in vec3 vPos;
layout(location = 1) in vec3 vColor;
layout(location = 2) in vec2 vTexCoord;
layout(location = 3) in vec3 vNormal;
layout(location = 4) in vec3 vBinormal;
layout(location = 5) in vec3 vTangent;

out vec3 fPos;
out vec3 fColor;
out vec2 fTexCoord;
out vec3 fNormal;
out vec3 fBinormal;
out vec3 fTangent;

uniform float time;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projMat;

uniform mat4 lightPos;
uniform mat4 eyePos;

void main()
{
        // vec3 v = vPos;

        // v.z *= sin(time);
        // v.x *= cos(time);

        // gl_Position =  mvp * vec4(v, 1);
        gl_Position = vec4(vPos, 1);

	fTexCoord = vTexCoord;
}
