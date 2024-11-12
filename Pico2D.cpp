#include <stdio.h>
#include "pico/stdlib.h"
#include "Engine/Display/ST7735.h"
#include "Engine/BufferedWindow/BufferedWindow.h"

int main() {
    stdio_init_all();
    
    ST7735 dis = ST7735(SCK, MOSI, CS, RST, DC);
    BufferedWindow wnd = BufferedWindow(&dis, 130, 129);
    wnd.fill_screen(0xf800);

    for(;;){
        // loop

        wnd.draw();
    }
    return 0;
}
