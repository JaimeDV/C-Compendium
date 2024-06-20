/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 22/05/2024

#pragma once

#include "../../../libraries/lodepng-master/lodepng.h"
#include <iostream>
#include <vector>
#include <ostream>
#include "../model/Color.hpp"

namespace misi
{
    /// @brief Parser class, creates & reads png files
    class ImageStreamer
    {

        unsigned height;
        unsigned width;

        std::string filepath;

        public:
        
       /// @brief Constructor to initialize the ImageStreamer with a file path and image dimensions
       /// @param filename The file path of the image
       /// @param given_width The width of the image
       /// @param given_height The height of the image
        ImageStreamer(const std::string& filename, unsigned given_width, unsigned given_height)
        {
            filepath = filename;
            height = given_height;
            width = given_width;
        }

        /// @brief Generates an image file from the provided color buffer
        /// @param colorbuffer A vector containing the color data for the image
        void GenerateImage(std::vector< Color > colorbuffer);


        /// @brief Reads the image file and returns a color buffer
        /// @return A vector containing the color data read from the image file
        std::vector< Color > ReadImage();

        /// @brief Sets the file path for the image
        /// @param filename The new file path for the image
        void SetPath(const std::string& filename)
        {
            filepath = filename;
        }

        /// @brief Gets the file path of the image
        /// @return The file path as a string
        std::string GetPath()
        {
            return filepath;
        }

    };


}