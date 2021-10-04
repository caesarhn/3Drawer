#version 130

out vec4 color;
in vec3 col;
in vec3 norm;
in vec3 fragPos;

void main() {
	vec3 lPos = vec3(3.0, 3.0, 24.0);

	vec3 colob = col;
	float ambientS = 0.2;
	float diffS = 0.8;

	vec3 ambient = ambientS * colob;
	vec3 diffCol = diffS * vec3(1.0, 1.0, 1.0);

	vec3 norms = normalize(norm);
	vec3 lightDir = normalize(lPos - fragPos);
	float diff = max(dot(norms, lightDir), 0.0);
	vec3 diffuse = diff * diffCol;

	vec3 result = (ambient + diffuse) * colob;
	//vec3 result = (ambient + diffuse) * texture(s_texture, tex_coordinate);
	color = vec4(result, 1.0);
}