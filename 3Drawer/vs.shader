 #version 130

in vec3 position;
in vec3 colour;
in vec3 normal;

out vec3 col;
out vec3 norm;
out vec3 fragPos;

void main() {
	gl_Position = gl_ModelViewProjectionMatrix * vec4 (position, 1.0);
	//gl_Position = vec4(position, 0.0);
	col = colour;
	norm = normal;
	fragPos = vec4 (position, 1.0).xyz;
}