/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 22/05/2024

#pragma once

#include "Color.hpp"
#include <vector>

namespace misi
{

    /// @brief container class that operates the canvas image color buffer  
    class Canvas
    {

        unsigned width;
        unsigned height;

        std::vector< Color > buffer;//main color buffer

    public:

        /// @brief Constructor to initialize the canvas with given width and height
        /// @param given_width The width of the canvas
        /// @param given_height The height of the canvas
        Canvas(unsigned given_width, unsigned given_height)
        :
            width(given_width),
            height(given_height),
            buffer(given_width* given_height)
        {

        }

        /// @brief Gets the width of the canvas
        /// @return The width of the canvas
        unsigned get_width() const
        {
            return width;
        }

        /// @brief Gets the height of the canvas
        /// @return The height of the canvas
        unsigned get_height() const
        {
            return height;
        }

        /// @brief Gets the color buffer of the canvas
        /// @return The color buffer of the canvas
        std::vector< Color >  Getbuffer()
        {
            return buffer;
        }

        /// @brief Sets the color buffer of the canvas
        /// @param newBuffer The new color buffer to be set
        void Setbuffer(std::vector< Color > newBuffer)
        {
            buffer=newBuffer;
        }

        /// @brief Gets the color of the pixel at the specified coordinates
        /// @param x The x coordinate of the pixel
        /// @param y The y coordinate of the pixel
        /// @return A pointer to the color of the pixel, or nullptr if the coordinates are out of bounds
        const Color * get_pixel(int x, int y) const
        {
            if (x >= 0 && x < int(width) && y >= 0 && y < int(height))
            {
                return &buffer[y * width + x];
            }
            else
                return nullptr;
        }

        /// @brief Sets the color of the pixel at the specified coordinates
        /// @param x The x coordinate of the pixel
        /// @param y The y coordinate of the pixel
        /// @param color The color to set the pixel to
        void set_pixel(int x, int y, const Color& color)
        {
            if (x >= 0 && x < int(width) && y >= 0 && y < int(height))
            {
                buffer[y * width + x] = color;
            }
        }

        /// @brief Sets the color of the pixel at the specified offset in the buffer
        /// @param offset The offset in the buffer
        /// @param color The color to set the pixel to
        void set_pixel(unsigned offset, const Color & color)
        {
            if (offset < width * height)
            {
                buffer[offset] = color;
            }
        }

    };


}
