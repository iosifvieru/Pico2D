#include "BasicRenderer.h"


BasicRenderer::BasicRenderer(Canvas& canvas, Display& display)
    : Renderer(canvas, display) {
        Logger::log("BasicRenderer().");
}

void BasicRenderer::Render(){
    // draw
    display.flush(canvas.get_buffer());

    Logger::log("Renderer...");
}