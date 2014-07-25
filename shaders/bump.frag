#version 330 core

in vec3 fPos;
in vec3 fColor;
in vec2 fTexCoord;
in vec3 fNormal;
in vec3 fBinormal;
in vec3 fTangent;

in vec3 v_light;
in vec3 v_eye;

out vec3 color;

uniform float time;

uniform vec3 lightPos;
uniform vec3 eyePos;

// uniform sampler2D myTextureSampler;

uniform sampler2D texture0;
uniform sampler2D texture1;

#define SPECPOW 35.0

void main()
{
    // vec3 normal = 2.0 * texture(myTextureSampler, fTexCoord).rgb - 1.0;
    vec3 normal = 2.0 * texture(texture1, fTexCoord).rgb - 1.0;

    normal = normalize(normal);

    float lambert = max(dot(normal, v_light), 0.0);
    // float lambert = max(dot(fNormal, v_light), 0.0);

    float blinn = dot(v_light, normalize(v_eye + fNormal));

    float phong = dot(v_light, reflect(-v_eye, normal));

    float spec = pow(max(phong, 0), SPECPOW);

    color = texture(texture0, fTexCoord).rgb;
    // color = vec3(0.5, 0.5, 0.5);

    color *= lambert;
    color += spec;
}
