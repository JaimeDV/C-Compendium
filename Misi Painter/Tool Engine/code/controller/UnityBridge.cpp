/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 22/05/2024

#include <list>
#include <memory>
#include "UnityBridge.hpp"

using namespace std;

namespace 
{

    struct
    {
        misi::Painter*  painter;
    }
    memory_handler;
}

extern "C"
{


    void* CreateCanvas(int width, int heigh, char* path)
    {
        auto Painter = new misi::Painter( width, heigh);


        if (Painter != nullptr)
        {
            memory_handler.painter = Painter;
        }

        Painter->CreateStreamer(path);

        return Painter;
    }

    void CleanCanvas()
    {
        memory_handler.painter->Clear();
    }

    int GetPixelR(int x , int y)
    {
        return memory_handler.painter->GetCanvas()->get_pixel(x, y)->components[0];
    }

    int GetPixelG(int x, int y)
    {
        return memory_handler.painter->GetCanvas()->get_pixel(x, y)->components[1];
    }

    int GetPixelB(int x, int y)
    {
        return memory_handler.painter->GetCanvas()->get_pixel(x, y)->components[2];
    }

    int GetPixelA(int x, int y)
    {
        return memory_handler.painter->GetCanvas()->get_pixel(x, y)->components[3];
    }

    void SetPixel(int X, int y, int R, int G, int B, int A)
    {
        memory_handler.painter->SetPixelColor(X, y, R, G, B, A);
    }

    void SafeImage()
    {
        memory_handler.painter->SafeFile();
    }

    void ReadFile()
    {
        memory_handler.painter->ReadFile();
    }

    const char* ReturnPath()
    {
        static std::string path; // Static variable to hold the string
        path = memory_handler.painter->GetPath(); // Update the path
        return path.c_str(); // Return the pointer to the buffer of the static stringreturn memory_handler.painter->GetPath().c_str();
    }

    
}
