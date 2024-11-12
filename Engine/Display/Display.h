#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "pico/stdlib.h"

/*
Interface for display
*/
class Display {
public:
    virtual ~Display() = default;
    
    virtual void fill_screen(uint8_t width, uint8_t height, uint16_t color) = 0;
    virtual void draw_pixel(uint8_t x, uint8_t y, uint16_t color) = 0;
    virtual void draw_line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color) = 0;
    virtual void draw_sprite(uint8_t x, uint8_t y, uint8_t width, uint8_t height, const uint16_t* sprite) = 0; 
};

#endif