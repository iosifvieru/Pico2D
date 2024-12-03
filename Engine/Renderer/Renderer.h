#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "Engine/Drivers/DisplayDriver/Display.h"
#include "Engine/Canvas/Canvas.h"
#include "Engine/Logger/Logger.h"

/*
Renderer class.
it has a canvas and a display.
*/
class Renderer {
protected:
    Canvas& canvas;
    Display& display;
public:
    Renderer(Canvas& canvas, Display& display)
        : canvas(canvas), display(display)  {
        
        Logger::log("Renderer initialized.");
    }
    
    virtual void Render() = 0;
};

#endif