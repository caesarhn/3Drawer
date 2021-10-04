#include "mob1.h"
#include <stdlib.h>
#include <time.h>

float startx = 0.0f;
float starty = 0.0f;

float MOB1::mesh[] = {
		startx - 0.0f, starty - 3.0f, 0.5f,		0.6f, 0.3f, 0.3f,		0.0f, 0.0f, 1.0f,
		startx - 0.0f, starty + 3.0f, 0.5f,		0.3f, 0.6f, 0.3f,		0.0f, 0.0f, 1.0f,
		startx - 6.0f, starty - 3.0f, 0.5f,		0.3f, 0.3f, 0.9f,		0.0f, 0.0f, 1.0f,

		startx - 6.0f, starty - 3.0f, 0.5f,		0.3f, 0.3f, 0.6f,		0.0f, 0.0f, 1.0f,
		startx - 0.0f, starty - 3.0f, 0.5f,		0.6f, 0.3f, 0.3f,		0.0f, 0.0f, 1.0f,
		startx - 0.0f, starty + 3.0f, 0.5f,		0.3f, 0.6f, 0.3f,		0.0f, 0.0f, 1.0f
};

int MOB1::getMobsize() {
	int meshs = sizeof(MOB1::mesh) / sizeof(float);
	
	return meshs;
}

void MOB1::MobMovement() {
	startx += 1;

	float mesh[18] = {
		startx - 0.0f, starty - 1.0f, 0.5f,
		startx - 0.0f, starty + 1.0f, 0.5f,
		startx + 1.0f, starty + 1.0f, 0.5f,

		startx - 0.0f, starty - 1.0f, 0.5f,
		startx - 0.0f, starty + 1.0f, 0.5f,
		startx - 1.0f, starty - 1.0f, 0.5f
	};
}
void MOB1::MobStart(float x, float y) {
	startx = x;
	starty = y;


}