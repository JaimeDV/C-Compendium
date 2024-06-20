/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 22/05/2024

#include "Painter.hpp"

namespace misi
{

    void Painter::Clear()
    {
        const unsigned size = canvas->get_width() * canvas->get_height();
        const Color    color{ 0, 0, 0, 255 };

        for (unsigned offset = 0; offset < size; ++offset)
        {
            canvas->set_pixel (offset, color);
        }
    }

    void Painter::CreateCanvas(int width, int height)
    {
        canvas = new Canvas(width, height);
        Clear();
    }

    void Painter::SetPixelColor(int x, int y, int R, int G, int B, int A)
    {
        Color pixelColor(static_cast<uint8_t>(R), static_cast<uint8_t>(G), static_cast<uint8_t>(B), static_cast<uint8_t>(A));

        canvas->set_pixel(x, y, pixelColor);
    }

}
