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
        mat4 mv = viewMatrix * modelMatrix;

        vec4 pos = mv * vec4(vPos, 1);

        v_light = normalize(lightPos - vec3(pos));
        v_eye = normalize(eyePos - vec3(pos));

        fNormal = normalize(vec3(modelMatrix * vec4(vNormal, 0)));
        fBinormal = normalize(vec3(modelMatrix * vec4(vBinormal, 0)));
        fTangent = normalize(vec3(modelMatrix * vec4(vTangent, 0)));

        mat3 tbn = mat3
                (
                        fTangent.x,  fTangent.y,  fTangent.z,
                        fBinormal.x, fBinormal.y, fBinormal.z,
                        fNormal.x,   fNormal.y,   fNormal.z
                );


        // v_light = normalize(tbn * v_light);
	// v_eye = normalize(tbn * v_eye);
        v_light = normalize(v_light * tbn);
	v_eye = normalize(v_eye * tbn);

        fTexCoord = vTexCoord;

        gl_Position = projMatrix * pos;
}
