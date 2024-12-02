#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "pico/stdlib.h"

/*
Interface for display
*/
class Display {
public:
    virtual ~Display() = default;
    
    /*
    draws a buffer to the display
    */
    virtual void flush(uint8_t width, uint8_t height, const uint16_t* buffer) = 0; 
};

#endif