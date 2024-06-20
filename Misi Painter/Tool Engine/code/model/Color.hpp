/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 22/05/2024

#pragma once

#include <cstdint>

namespace misi
{
    /// @brief util class that defines the struct Color, a RGBA32 pixel format
    struct Color       
    {
        uint8_t components[4];

        Color()
        {
            components[0] = 255;
            components[1] = 255;
            components[2] = 255;
            components[3] = 255;
        }

        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
        {
            components[0] = r;
            components[1] = g;
            components[2] = b;
            components[3] = a;
        }
    };

}
