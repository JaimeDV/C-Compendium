/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 22/05/2024

#include "ImageStream.hpp"

namespace misi
{
        void ImageStreamer::GenerateImage(std::vector< Color > colorbuffer)
        {
           
            // Ensure the colorbuffer size matches the expected image size
            if (colorbuffer.size() != width * height) {
                throw std::runtime_error("Color buffer size does not match the expected image size.");
            }

            // Create an 8-bit RGBA (RGB + alpha) image
            unsigned char* imageBuffer = new unsigned char[width * height * 4];

            for (unsigned y = 0; y < height; ++y) {
                for (unsigned x = 0; x < width; ++x) {
                    int offset = y * width + x;
                    // Copy RGBA values from the colorbuffer to the imageBuffer
                    imageBuffer[4 * offset + 0] = colorbuffer[offset].components[0]; // Red
                    imageBuffer[4 * offset + 1] = colorbuffer[offset].components[1]; // Green
                    imageBuffer[4 * offset + 2] = colorbuffer[offset].components[2]; // Blue
                    imageBuffer[4 * offset + 3] = colorbuffer[offset].components[3]; // Alpha
                }
            }

            // Save the image as a PNG file
            unsigned error = lodepng::encode(filepath, imageBuffer, width, height);

            // Check if there was an error in encoding
            if (error) {
                delete[] imageBuffer; // Clean up before throwing
                throw std::runtime_error("Error encoding PNG: " + std::string(lodepng_error_text(error)));
            }

            // Free memory
            delete[] imageBuffer;
        }


        std::vector< Color > ImageStreamer::ReadImage()
        {
            // Initialize the vector to store the loaded image data
            std::vector<unsigned char> imageData;

            std::vector< Color > imageColor;

            unsigned int width, height;

            // Load the PNG file into imageData
            unsigned int error = lodepng::decode(imageData, width, height, filepath.c_str());

            if (error) {
                std::cout << "Error loading the PNG file: " << lodepng_error_text(error) << std::endl;
                return imageColor;
            }

            for (size_t y = 0; y < height; ++y) {
                for (size_t x = 0; x < width; ++x) {
                    size_t i = (y * width + x) * 4;
                    unsigned char r = imageData[i + 0]; // Red
                    unsigned char g = imageData[i + 1]; // Green
                    unsigned char b = imageData[i + 2]; // Blue
                    unsigned char a = imageData[i + 3]; // Alpha

                    Color pixelColor;
                    pixelColor.components[0] = static_cast<uint8_t>(r);
                    pixelColor.components[0] = static_cast<uint8_t>(g);
                    pixelColor.components[0] = static_cast<uint8_t>(b);
                    pixelColor.components[0] = static_cast<uint8_t>(a);
                    imageColor.push_back(pixelColor);

                }
            }

            return imageColor;
        }
}