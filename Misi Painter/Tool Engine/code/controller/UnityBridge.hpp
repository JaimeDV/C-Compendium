
/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 22/05/2024
/// @brief Bridge class, allows unity to access the defined funtions
#pragma once

#include "Painter.hpp"

#define EXPORTED_FUNCTION __declspec(dllexport)

extern "C"
{

    EXPORTED_FUNCTION void* CreateCanvas(int width, int heigh, char* path);
    EXPORTED_FUNCTION void CleanCanvas();
    EXPORTED_FUNCTION const char* ReturnPath();
    EXPORTED_FUNCTION int GetPixelR(int x, int y);
    EXPORTED_FUNCTION int GetPixelG(int x, int y);
    EXPORTED_FUNCTION int GetPixelB(int x, int y);
    EXPORTED_FUNCTION int GetPixelA(int x, int y);
    EXPORTED_FUNCTION void SetPixel(int X, int y, int R, int G, int B, int A);
    EXPORTED_FUNCTION void SafeImage();
    EXPORTED_FUNCTION void ReadFile();
}
