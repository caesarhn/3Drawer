#pragma once

#include <string.h>

class camera {
private:
	// boolean
	bool cameraCanMove = false;
	bool cameraMoveForward = false;
	bool cameraMoveBackward = false;
	bool cameraMoveRight = false;
	bool cameraMoveLeft = false;

	// variable as parameter
	double x = 0, y = 0;
	double xpos = 0, ypos = 0;
	float movement = 0.2f;
	float num[2];
	float rotation = 0.0f;
	float rotations = 0.0f;

	// camera position and camera look position
	float cameraPosX = -15.0f;
	float cameraPosY = 1.0f;
	float cameraPosZ = 1.0f;

	float originCameraLookX = 2.0f;
	float originCameraLookY = 0.0f;
	float originCameraLookZ = 0.0f;

	float cameraLookX = 1.0f;
	float cameraLookY = 1.0f;
	float cameraLookZ = 1.0f;

	float bufferCameraLookX = 0.0f;
	float bufferCameraPosX = 0.0f;
	float bufferCameraPosY = 0.0f;
	float bufferCameraPosZ = 0.0f;

	// camera mevment
	float camMove = 0.1f;

	// variable to calculate camera rotation
	float cam[3];
	float rcam[3];
	float bCameraPos[3];
	float rotz[3][3];
	float rotx[3][3];
	float roty[3][3];

	void cameraInit(int width, int height, unsigned int program);
	

public:
	void setCameraCanMove(bool value);
	void setCameraMoveForward(bool value);
	void setCameraMoveBackward(bool value);
	void setCameraMoveRight(bool value);
	void setCameraMoveLeft(bool value);
	void setCameraPos(float cameraPosX, float cameraPosY, float cameraPosZ,
						float cammeraLookX, float cameraLookY, float cameraLookZ);
	void rotationz(float angle);
	void rotationxy(float angle);
	void rotationy(float angle);

	void camcamera(int width, int height, unsigned int program);
	void cameraMovement(double cpos_x, double cpos_y);
	void cameraFpsRotation(float xx, double xpos, double ypos);
	void cameraFpsRotation2(float xx, double xpos, double ypos);

};