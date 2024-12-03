#include "pico/stdlib.h"
#include <time.h>
#include <stdio.h>

#include "Engine/Drivers/DisplayDriver/ST7735.h"
#include "Engine/Canvas/BufferedCanvas.h"
#include "Engine/Renderer/BasicRenderer.h"

int main() {
    stdio_init_all();

    Display& display = ST7735::getInstance();
    Canvas* canvas = new BufferedCanvas(display.get_width(), display.get_height());
    
    /* test sprite */
    const uint16_t sprite[8] = {
        0xffff, 0xf10f, 
        0xabc1, 0x11fb,
        0x1111, 0x1212,
        0x1444, 0x1BCA
    };

    canvas->fill(0xf800);
    canvas->set_pixel(10, 25, 0xFFFF);
    canvas->set_pixel(56, 100, 0x1fA0);

    canvas->draw_sprite(78, 78, 4, 2, sprite);

    BasicRenderer* renderer = new BasicRenderer(*canvas, display);

    for(;;){
        renderer->Render();
    }

    return 0;
}
