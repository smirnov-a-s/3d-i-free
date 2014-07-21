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

// vector to light src
out vec3 v_light;
out vec3 v_eye;

uniform float time;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projMatrix;

uniform vec3 lightPos;
uniform vec3 eyePos;

void main()
{
        mat4 mvp = projMatrix * viewMatrix * modelMatrix;
        vec4 pos = mvp * vec4(vPos, 1);

        v_light = normalize(lightPos - vec3(pos));
        v_eye = normalize(eyePos - vec3(pos));

        fNormal = mat3(modelMatrix) * vNormal;
        fBinormal = mat3(modelMatrix) * vBinormal;
        fTangent = mat3(modelMatrix) * vTangent;

        vec3 v;
	v.x = dot(v_light, fTangent);
	v.y = dot(v_light, fBinormal);
	v.z = dot(v_light, fNormal);

	v_light = normalize(v);

        // v.x = dot(v_eye, fTangent);
        // v.y = dot(v_eye, fBinormal);
	// v.z = dot(v_eye, fNormal);

	// v_eye = normalize(v);

        fTexCoord = vTexCoord;

        gl_Position = pos;
}
