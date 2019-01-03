#ifndef _FLIPDOT_FRAMEBUFFER_H
#define _FLIPDOT_FRAMEBUFFER_H

#include <Flipdot_Control.h>

class Flipdot_Framebuffer : public Flipdot_Control
{
  public:
    Flipdot_Framebuffer(Flipdot_Control control, uint8_t displayWidth, uint8_t displayHeight);
    void flipToBlack(uint8_t x, uint8_t y);
    void flipToColor(uint8_t x, uint8_t y);
  private:
    void initialize();
    void isPointInRange(uint8_t x, uint8_t y);
};

#endif