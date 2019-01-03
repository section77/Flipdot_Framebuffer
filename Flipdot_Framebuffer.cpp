#include "Flipdot_Framebuffer.h"

Flipdot_Control control;

uint8_t displayWidth;
uint8_t displayHeight;

bool buffer[][];

Flipdot_Framebuffer::Flipdot_Framebuffer(Flipdot_Control control, uint8_t displayWidth, uint8_t displayHeight) {
	this->control = control;
	this->displayWidth = displayWidth;
	this->displayHeight = displayHeight;
	this->buffer = array[displayWidth][displayHeight]; // FIXME use correct data structure

	Flipdot_Framebuffer::initialize();
}

void Flipdot_Framebuffer::initialize() {
	for (int x = 0; x < displayWidth; x++) {
		for (int y = 0; y < displayHeight; y++) {
			control.flipToBlack(x, y);
			buffer[x][y] = false;
		}
	}
}

bool Flipdot_Krueger::isPointInRange(uint8_t x, uint8_t y) {
  if (x < 0 || x >= displayWidth) {
    return false;
  }

  if (y < 0 || y >= displayHeight) {
    return false;
  }

  return true;
}

void Flipdot_Framebuffer::flipToBlack(uint8_t x, uint8_t y) {
	if (!isPointInRange(x, y)) {
	  	return;
	}

	bool showsColor = buffer[x][y];
	if (showsColor) {
		control.flipToBlack(x, y);
		buffer[x][y] = false;
	}
}

void Flipdot_Framebuffer::flipToColor(uint8_t x, uint8_t y) {
	if (!isPointInRange(x, y)) {
	  	return;
	}

	bool showsColor = buffer[x][y];
	if (!showsColor) {
		control.flipToColor(x, y);
		buffer[x][y] = true;
	}
}