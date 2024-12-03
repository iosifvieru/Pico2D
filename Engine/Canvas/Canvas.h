#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <cstdint>

/* 
Abstract canvas class.
*/
class Canvas {
public:
    /* returns the canvas buffer */
    virtual uint16_t* get_buffer() = 0;

    /* fills the canvas with a certain color */
    virtual void fill(uint16_t color) = 0;

    /* sets a certain pixel's color */
    virtual void set_pixel(uint16_t x, uint16_t y, uint16_t color) = 0;

    /* gets the color of a pixel */
    virtual uint16_t get_pixel(uint16_t x, uint16_t y) = 0;

    /* draws a sprite to a certain x, y position. */
    virtual void draw_sprite(uint16_t x, uint16_t y, uint16_t sprite_width, uint16_t sprite_height, const uint16_t* sprite) = 0;

    /* draw a line to the canvas */
    virtual void draw_line(uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end, uint16_t color) = 0;

    /* TODO: 
    - draw rect,
    - fill rect,

    - draw circle,
    - fill circle,
    
    brainstorming for other possible functionalities.
    */
};

#endif