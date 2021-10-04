#version 130

out vec4 color;
in vec3 col;
in vec3 norm;
in vec3 fragPos;
in vec3 light;

void main() {
	// Posisi Cahaya
	vec3 lPos = light;
	//vec3 lPos = vec3(10.0, 10.0, 10.0);

	// Warna Benda
	vec3 colob = col;
	//vec3 colob = norm;
	//vec3 colob = vec3(0.3, 0.3, 0.3);

	// Kecerahan Cahaya
	float ambientS = 0.3;
	float diffS = 0.95;

	// Jenis Cahaya
	vec3 ambient = ambientS * colob;
	vec3 diffCol = diffS * vec3(1.0, 1.0, 1.0);

	// Perhitungan Cahaya
	vec3 norms = normalize(norm);
	//vec3 lightDir = normalize(lPos - fragPos);
	vec3 lightDir = normalize(lPos);
	float diff = max(dot(norms, lightDir), 0.0);
	vec3 diffuse = diff * diffCol;

	vec3 result = (ambient + diffuse) * colob;
	//vec3 result = (ambient + diffuse) * texture(s_texture, tex_coordinate);
	color = vec4(result, 1.0);
}