#include "transform.h"
#include <GL/glew.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtx/transform.hpp>

void transform::transformInit(unsigned int programID) {
	program = programID;
	trslt = glGetUniformLocation(program, "translate");
	scld = glGetUniformLocation(program, "scale");
	rtt = glGetUniformLocation(program, "rotate");

	defaultTransform();
}

void transform::tranlate(float x, float y, float z) {
	glUniform3f(trslt, x, y, z);
}

void transform::rotate(float x, float y, float z, float angle) {
	glUniform3f(trslt, x, y, z);
}

void transform::scaled(float x, float y, float z) {
	glUniform3f(scld, x, y, z);
}

void transform::defaultTransform() {
	tranlate(0.0f, 0.0f, 0.0f);
	scaled(1.0f, 1.0f, 1.0f);
	rotate(0.0f, 0.0f, 0.0f, 0.0f);
}
