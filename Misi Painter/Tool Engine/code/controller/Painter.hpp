/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 22/05/2024

#pragma once

#include "../API.hpp"
#include "../model/Canvas.hpp"
#include "../controller/ImageStream.hpp"

namespace misi
{
    /// @brief class that encapsulates the tools canvas & relevant funtions
    class API Painter
    {
        Canvas * canvas;
        ImageStreamer*  streamer;

    public:

        /// @brief Constructor to initialize the Painter with a canvas of given dimensions
        /// @param width The width of the canvas
        /// @param height The height of the canvas
        Painter(int width, int heigh)
        {
            canvas = new Canvas(width, heigh);  
            streamer = nullptr;
        }

        /// @brief Creates an ImageStreamer for saving and reading images
        /// @param filename The name of the file to be used by the ImageStreamer
        void CreateStreamer(const std::string& filename)
        {
            streamer = new ImageStreamer( filename, canvas->get_width(), canvas->get_height());
        }

        /// @brief Creates a new canvas with specified dimensions
        /// @param height The height of the new canvas
        /// @param width The width of the new canvas
        void CreateCanvas(int height, int width);

        /// @brief Clears the canvas
        void Clear();

        /// @brief Sets the color of a pixel at specified coordinates
        /// @param X The x coordinate of the pixel
        /// @param y The y coordinate of the pixel
        /// @param R The red component of the color
        /// @param G The green component of the color
        /// @param B The blue component of the color
        /// @param A The alpha component of the color
        void SetPixelColor(int X, int y , int R, int G, int B, int A);

        /// @brief Saves the current canvas to a file using the ImageStreamer
        void SafeFile()
        {
            streamer->GenerateImage(canvas->Getbuffer());
        }


        /// @brief Reads an image from a file into the canvas using the ImageStreamer
        void ReadFile()
        {
            canvas->Setbuffer(streamer->ReadImage());
        }

        /// @brief Gets the canvas object
        /// @return A pointer to the canvas object
        Canvas* GetCanvas()
        {
            return canvas;
        }

        /// @brief Gets the file path from the ImageStreamer
        /// @return The file path as a string
        std::string GetPath()
        {
            return streamer->GetPath();
        }

        
        ~Painter()
        {
            delete canvas;
            delete streamer;
        }
    };



}
