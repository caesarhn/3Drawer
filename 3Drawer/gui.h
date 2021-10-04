#pragma once
#include <GL/glew.h>
#include <string.h>

class menuBar {
private:
	float xBar = 0.0f;
	float yBar = 0.0f;
	float widthBar = 1920.0f;
	float heightBar = 20.0f;

	bool my_tool_activate = false;

	void test();
public:
	void menubarRender();

};

class resourceWindow {
private:
	float positionx = 0.0f;
	float positiony = 0.0f;
	float widthBar = 1920.0f;
	float heightBar = 200.0f;

	//size icon for resource
	float sizeIconResource = 40.0f;

	//icon for resource
	ImTextureID icon;

	void sizeWindow(int width, int height);
public:
	void resourceWindowRender(int windowWidth, int windowHeight, int posy);

};

class GUI {
	unsigned char* data = new unsigned char[100 * 100 * 3];
public:
	GUI() {
		
	}
	void mainRender();
	void menuRender();
	void toolsRender();
};
