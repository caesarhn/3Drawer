#pragma once

#include "mouse.h"
#include <iostream>
#include <string.h>

void mouseStatus::setMouseStatus(std::string setStatus) {
	mosStatus = setStatus;
}

std::string mouseStatus::getMouseStatus() {
	return mosStatus;
}