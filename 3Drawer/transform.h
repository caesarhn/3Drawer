#pragma once
#include <GL/glew.h>

class transform {
private:
	int i;
	unsigned int program;

	unsigned int trslt;
	unsigned int scld;
	unsigned int rtt;
	GLuint Matrixs;
	GLuint Matrixr;

public:
	void transformInit(unsigned int programID);
	void tranlate(float x, float y, float z);
	void scaled(float x, float y, float z);
	void rotate(float x, float y, float z, float deg);
	void defaultTransform();

};