
//unused, bfeore using unity this was the ui proyect 

#include "Painter.hpp"



int main()
{

    misi::Painter * paint = new misi::Painter(10, 10);

    paint->CreateStreamer("../Pirulos.png");
    paint->SetPixelColor(3, 3, 3, 3, 3,3);

    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10;j++)
        {
            // Read pixel color at position (i, j)
            int r, g, b, a;
            paint->GetCanvas()->get_pixel(i,j);

            const misi::Color* pixel = paint->GetCanvas()->get_pixel(i, j);

            std::cout << "Pixel at (" << i << ", " << j << "): R=" << static_cast<int>(pixel->components[0])
                << ", G=" << static_cast<int>(pixel->components[1])
                << ", B=" << static_cast<int>(pixel->components[2])
                << ", A=" << static_cast<int>(pixel->components[3]) << std::endl;
        }
    }
    paint->SafeFile();
    return 0;
}
