#version 330 core

layout(location = 0) in vec3 vPos;
// layout(location = 1) in vec3 vColor;
layout(location = 1) in vec2 texCoord;

// out vec3 fColor;
out vec2 pos;

uniform mat4 mvp;
uniform float time;

void main()
{
	// output position of the vertex, in clip space : MVP * position
        vec3 v = vPos;

        if (v.x == 0.5)
                v.z += (sin(time))/5.0;

        if (v.x == 0)
                v.z += (cos(time))/4.0;

        if (v.x == -0.5)
                v.z += cos(time)/3.0;

        if (v.x == -1)
                v.z += sin(time)/3.0;

        gl_Position =  mvp * vec4(v, 1);
        // gl_Position = vec4(v, 1);

	pos = texCoord;
}
