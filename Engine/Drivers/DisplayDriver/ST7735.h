// Iosif Vieru

#include "pico/stdlib.h"
#include "Display.h"

#define SCK 18
#define MOSI 19
#define CS 17
#define RST 21
#define DC 20

#define ST7735_CASET 0x2A
#define ST7735_RASET 0x2B
#define ST7735_RAMWR 0x2C

/*
Implements Display interface.
*/
class ST7735: public Display {
private:
    uint8_t sck_pin;
    uint8_t mosi_pin;
    uint8_t cs;
    uint8_t rst;
    uint8_t dc;

    inline void set_mosi(bool level);
    inline void set_sck(bool level);
    inline void set_cs(bool level);
    inline void set_dc(bool level);
    inline void set_rst(bool level);

    inline void send_byte(uint8_t byte);

    void send_command(uint8_t command);
    void send_data(uint8_t data);
    void reset();
    void set_addr_window(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);

    inline void send_color(uint16_t color);

public:
    // constructor
    ST7735(
        uint8_t sck_pin,
        uint8_t mosi_pin,
        uint8_t cs,
        uint8_t rst,
        uint8_t dc
    );

    ~ST7735();

    /*
        Display interface implementation
    */
    virtual void flush(uint8_t width, uint8_t height, const uint16_t* buffer) = 0;
};