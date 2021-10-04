#version 130

in vec3 position;
in vec3 colour;
in vec3 normal;

uniform mat4 MVP;
uniform vec3 translate;
uniform vec3 lght;
uniform vec3 scale;
uniform mat4 rotate;

out vec3 col;
out vec3 norm;
out vec3 fragPos;
out vec3 light;

void main() {
	mat4 transform = mat4(vec4(scale.x, 0.0, 0.0, 0.0), vec4(0.0, scale.y, 0.0, 0.0), vec4(0.0, 0.0, scale.z, 0.0), vec4(translate, 1.0));
	vec4 object = transform * vec4(position, 1.0);
	vec4 tnormal = transform * vec4(normal, 1.0);

	gl_Position = MVP * object;
	//gl_Position = MVP * vec4(position, 1.0);
	col = colour;
	norm = tnormal.xyz;
	//norm = normal;
	fragPos = object.xyz;
	//fragPos = vec4(position, 1.0).xyz;

	light = lght;
}	