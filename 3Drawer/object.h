#pragma once


class kubus {
private:
	// buffer component
	unsigned int bufff;
	unsigned int indc;

	// Color Storage
	float colorr = 0.5f;
	float colorg = 0.7f;
	float colorb = 0.9f;

public:
	void make();
	void render();
	void translate();
};

class objectBase {
private:
	// Buffer component
	unsigned int VAOline;

	unsigned int lineBuff;

	// color storage
	float colorLine[3];

	void lineColorInit(float colr, float colg, float colb);
	void lineObjectInit();
	void lineInit();

public:
	void allInit();
	void lineRender();

};