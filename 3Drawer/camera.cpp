#include "camera.h"
#include <GL/glew.h>
#include <iostream>
#include <iomanip>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtx/transform.hpp>

void camera::setCameraCanMove(bool value) {
    cameraCanMove = value;
}
void camera::setCameraMoveForward(bool value) {
    cameraMoveForward = value;
}
void camera::setCameraMoveBackward(bool value) {
    cameraMoveBackward = value;
}
void camera::setCameraMoveRight(bool value) {
    cameraMoveRight = value;
}
void camera::setCameraMoveLeft(bool value) {
    cameraMoveLeft = value;
}

// Set Camera position manual
void camera::setCameraPos(float PosX, float PosY, float PosZ,
							float LookX, float LookY, float LookZ) {
	
	float cameraPosX = PosX;
	float cameraPosY = PosY;
	float cameraPosZ = PosZ;

	float cameraLookX = LookX;
	float cameraLookY = LookY;
	float cameraLookZ = LookZ;
}

// Initialize camera
void camera::cameraInit(int width, int height, unsigned int programID) {
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);

	glm::mat4 View = glm::lookAt(
		glm::vec3(cameraPosX, cameraPosY, cameraPosZ),
		glm::vec3(cameraLookX, cameraLookY, cameraLookZ),
		glm::vec3(0, 0, 1)
	);

	glm::mat4 Model = glm::mat4(1.0f);

	glm::mat4 mvp = Model * Projection * View;
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);
}

// Move just position camera
void camera::cameraMovement(double xpos, double ypos) {
    if (x < xpos) {
        cameraPosX = cameraPosX - movement;
        //cpos_y = cpos_y - movement;
    }

    else if (x > xpos) {
        cameraPosX = cameraPosX + movement;
        //cpos_y = cpos_y + movement;
    }

    else {
        cameraPosX = cameraPosX;
        //cpos_y = cpos_y;
    }
    x = xpos;

    if (y < ypos) {
        //cpos_x = cpos_x - movement;
        cameraPosY = cameraPosY + movement;
    }
    else if (y > ypos) {
        //cpos_x = cpos_x + movement;
        cameraPosY = cameraPosY - movement;
    }

    else {
        //cpos_x = cpos_x;
        cameraPosY = cameraPosY;
    }
    y = ypos;
}

// Call the initialize of camera 
void camera::camcamera( int width, int height, unsigned int programID) {
	//setCameraPos(PosX, PosY, PosZ, LookX, LookY, LookZ);
	cameraInit(width, height, programID);
}

// Rotation matrix in Z axis
void camera::rotationz(float angle) {
    float cosangle = glm::cos(angle);
    float sinangle = glm::sin(angle);
    
    rotz[0][0] = cosangle;
    rotz[0][1] = -sinangle;
    rotz[0][2] = 0.0f;

    rotz[1][0] = sinangle;
    rotz[1][1] = cosangle;
    rotz[1][2] = 0.0f;
    
    rotz[2][0] = 0.0f;
    rotz[2][1] = 0.0f;
    rotz[2][2] = 1.0f;
}

// Rotation matrix in XY axis (ERROR)
void camera::rotationxy(float angle) {
    float cosangle = glm::cos(angle);
    float sinangle = glm::sin(angle);

    rotx[0][0] = cosangle;
    rotx[0][1] = 0.0f;
    rotx[0][2] = 0.0f;

    rotx[1][0] = 0.0f;
    rotx[1][1] = cosangle;
    rotx[1][2] = 0.0f;

    rotx[2][0] = 0.0f;
    rotx[2][1] = 0.0f;
    rotx[2][2] = (cosangle*cosangle);
}

// Rotation matrix in Y axis
void camera::rotationy(float angle) {
    float cosangle = glm::cos(angle);
    float sinangle = glm::sin(angle);

    roty[0][0] = cosangle;
    roty[0][1] = 0.0f;
    roty[0][2] = sinangle;

    roty[1][0] = 0.0f;
    roty[1][1] = 1.0f;
    roty[1][2] = 0.0f;

    roty[2][0] = -sinangle;
    roty[2][1] = 0.0f;
    roty[2][2] = cosangle;
}

void camera::cameraFpsRotation(float xx, double xpos, double ypos) {
    cam[0] = originCameraLookX;
    cam[1] = originCameraLookY;
    cam[2] = originCameraLookZ;

    // check when button press to move camera
    if (cameraCanMove == true && cameraMoveForward == true) {
        cam[0] = cam[0] + camMove;
        bufferCameraPosX = +camMove;
        bufferCameraPosY = 0.0f;
        bufferCameraPosZ = 0.0f;

        //std::cout << "camera moved forward" << std::endl;
    }
    else if (cameraCanMove == true && cameraMoveLeft == true) {
        cam[1] = cam[1] + camMove;
        bufferCameraPosX = 0.0f;
        bufferCameraPosY =  + camMove;
        bufferCameraPosZ = 0.0f;
    }
    else if (cameraCanMove == true && cameraMoveRight == true) {
        cam[1] = cam[1] - camMove;
        bufferCameraPosX = 0.0f;
        bufferCameraPosY = - camMove;
        bufferCameraPosZ = 0.0f;
    }
    else if (cameraCanMove == true && cameraMoveBackward == true) {
        cam[0] = cam[0] - camMove;
        bufferCameraPosX = - camMove;
        bufferCameraPosY = 0.0f;
        bufferCameraPosZ = 0.0f;
    }
    else {
        bufferCameraPosX = 0.0f;
        bufferCameraPosY = 0.0f;
        bufferCameraPosZ = 0.0f;
    }

    //std::cout << "posisi camera  " << cameraPosX << cameraPosY<< cameraPosZ << std::endl;
    //std::cout << "posisi lihat  " << cameraLookX<<" " << cameraLookY <<"  " <<cameraLookZ << std::endl;
    
    // First rotation step for fps camera in Y axis
    if (y < ypos && -1.57f < rotation < 1.57f) {
        rotation = rotation + xx;

    }
    else if (y > ypos && -1.57 < rotation < 1.57f) {
        rotation = rotation - xx;
    }
    else if (rotation > 1.57f) {
        rotation = 1.57f;
    }
    else if (rotation < - 1.57f) {
        rotation = -1.57f;
    }
    else {
        rotation = rotation;
    }
    y = ypos;

    rotationy(rotation);
    for (int i = 0; i < 3; i++) {
        rcam[i] = (roty[i][0] * cam[0]) + (roty[i][1] * cam[1]) + (roty[i][2] * cam[2]);
        bCameraPos[i] = (roty[i][0] * bufferCameraPosX) + (roty[i][1] * bufferCameraPosY) + (roty[i][2] * bufferCameraPosZ);
    }
    cam[0] = rcam[0];
    cam[1] = rcam[1];
    cam[2] = rcam[2];
    bufferCameraPosX = bCameraPos[0];
    bufferCameraPosY = bCameraPos[1];
    bufferCameraPosZ = bCameraPos[2];

    // Second rotations steps for fps camera in Z axis
    if (x < xpos && -6.28f < rotations < 6.28f) {
        rotations = rotations - xx;
    }
    else if (x > xpos && -6.28f < rotations < 6.28f) {
        rotations = rotations + xx;
    }
    else if (rotations > 6.28f || rotations < -6.28f) {
        rotations = 0.0f;
    }
    else {
        rotations = rotations;
    }
    x = xpos;

    rotationz(rotations);
    for (int i = 0; i < 3; i++) {
        rcam[i] = (rotz[i][0] * cam[0]) + (rotz[i][1] * cam[1]) + (rotz[i][2] * cam[2]);
        bCameraPos[i] = (rotz[i][0] * bufferCameraPosX) + (rotz[i][1] * bufferCameraPosY) + (rotz[i][2] * bufferCameraPosZ);
    }

    // Translate rotated camera to the position
    cameraLookX = rcam[0] + cameraPosX;
    cameraLookY = rcam[1] + cameraPosY;
    cameraLookZ = rcam[2] + cameraPosZ;
    
    cameraPosX = bCameraPos[0] + cameraPosX;
    cameraPosY = bCameraPos[1] + cameraPosY;
    cameraPosZ = bCameraPos[2] + cameraPosZ;
}
