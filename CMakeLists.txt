# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NEVER EDIT THE NEXT LINES for Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.0.0)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Pico2D C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(Pico2D
        main.cpp 
        Engine/Drivers/DisplayDriver/ST7735.cpp
        Engine/Canvas/BufferedCanvas.cpp
        Engine/Renderer/BasicRenderer.cpp
        )

pico_set_program_name(Pico2D "Pico2D")
pico_set_program_version(Pico2D "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Pico2D 0)
pico_enable_stdio_usb(Pico2D 1)

# Add the standard library to the build
target_link_libraries(Pico2D
        pico_stdlib
        hardware_spi)

# Add the standard include files to the build
target_include_directories(Pico2D PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

if(DEFINED _LOG_)
    add_compile_definitions(_LOG_)
endif()

pico_add_extra_outputs(Pico2D)

