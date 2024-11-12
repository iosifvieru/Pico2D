#ifndef _BUFFERED_WINDOW_H_
#define _BUFFERED_WINDOW_H_

#include "Engine/Display/Display.h"
#include "pico/stdlib.h"
#include <cstdint>

class BufferedWindow {
private:
    Display* display;
    int width, height;
    
    // double buffered
    uint16_t *back_buffer;
    uint16_t *front_buffer;
public:
    BufferedWindow(Display* display, int width, int height);
    ~BufferedWindow();

    void set_pixel(uint8_t x, uint8_t y, uint16_t color);
    void fill_screen(uint16_t color);

    void draw_line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color);
    
    void update();
    void draw();
};

#endif