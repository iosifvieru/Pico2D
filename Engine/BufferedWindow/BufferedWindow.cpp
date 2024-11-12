
#include "BufferedWindow.h"
#include <stdio.h>
#include "string.h"
#include <iostream>

BufferedWindow::BufferedWindow(Display* display, int width, int height) {
    if(display == nullptr){
        printf("GameWindow: display is nullptr.");
        return;
    }

    this->display = display;
    this->width = width;
    this->height = height;

    this->back_buffer = new uint16_t[this->width*this->height];
    this->front_buffer = new uint16_t[this->width*this->height];

    this->fill_screen(0x0000);
}

BufferedWindow::~BufferedWindow(){
    if(this->display == nullptr){
        return;
    }

    delete[] display;

    if(this->back_buffer == nullptr){
        return;
    }

    delete[] this->back_buffer;

    if(this->front_buffer == nullptr){
        return;
    }

    delete[] this->front_buffer;
}

void BufferedWindow::set_pixel(uint8_t x, uint8_t y, uint16_t color){
    if(x > width){
        return;
    }

    if(y > height) {
        return;
    }

    this->back_buffer[x* width + y] = color;
}

void BufferedWindow::draw_line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color){

}

void BufferedWindow::update(){
    
}

void BufferedWindow::draw(){
    display->draw_sprite(0, 0, this->width, this->height, front_buffer);

    /* swapping the buffers */
    uint16_t *temp;
    temp = front_buffer;
    front_buffer = back_buffer;
    back_buffer = temp;
}

void BufferedWindow::fill_screen(uint16_t color){
    for (int i = 0; i < width * height; i++) {
        back_buffer[i] = color;
        front_buffer[i] = color;
    }
}