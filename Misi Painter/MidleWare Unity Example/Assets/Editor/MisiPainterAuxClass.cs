using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
using UnityEngine;


/// @copyright © 2024+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 23/05/2024
/// @brief Handles the bridge between c++ Y c# allowing the ui to access the funtions in the c++ file.

public class MisiPainterAuxClass
{

#if UNITY_IPHONE
        const string DllName = "__Internal";
#else
    const string DllName = "Tool Engine";
#endif

    // pointer to the backend class painter
    private IntPtr unmanagedInstance;


    /// @brief Base Constructor for MisiPainterAuxClass. Instantiates a canvas with the given dimensions and path.
    /// @param height The height of the canvas.
    /// @param width The width of the canvas.
    /// @param path The file path to the image.
    public MisiPainterAuxClass(int heigh, int width, string path)
    {
        InstantiateCanvas( heigh,  width,  path);
    }

    /// @brief Instantiates the canvas by calling the CreateCanvas method from backend.
    /// @param height The height of the canvas.
    /// @param width The width of the canvas.
    /// @param path The file path to the image.
    void InstantiateCanvas(int heigh, int width, string path)
    {
        string fileName = Path.GetFileName(path);
        unmanagedInstance = CreateCanvas(heigh, width, fileName);
        Debug.Log("Canvas created with instance: " + unmanagedInstance.ToString());
    }


    /// @brief Sets the color of a specific pixel on the canvas.
    /// @param x The x-coordinate of the pixel.
    /// @param y The y-coordinate of the pixel.
    /// @param R The red component of the color.
    /// @param G The green component of the color.
    /// @param B The blue component of the color.
    /// @param A The alpha (transparency) component of the color.
    public void SetPixelColor(int x, int y, int R, int G, int B, int A)
    {
        SetPixel(x, y, R, G,B, A);
    }

    /// @brief Cleans a specific pixel on the canvas by setting it to white.
    /// @param x The x-coordinate of the pixel.
    /// @param y The y-coordinate of the pixel.
    public void CleanPixel(int x, int y)
    {
        SetPixel(x, y, 255, 255, 255, 255);
    }


    /// @brief Gets the 3 color componets of a specific pixel on the canvas.
    /// @param x The x-coordinate of the pixel.
    /// @param y The y-coordinate of the pixel.
    /// @return A list of integers representing the RGBA components of the pixel color.
    public List<int> GetPixelColor(int x, int y)
    {
        List<int> colors = new List<int>();
        colors.Add(GetPixelR(x, y));
        colors.Add(GetPixelG(x, y));
        colors.Add(GetPixelB(x, y));
        colors.Add(GetPixelA(x, y));

        return colors;
    }


    /// @brief Unimplemented due to time constraints. given a path loads an image into the pixel buffer & then sets the canvas grid the same value
    /// @param path absoloute path to the png file. It has to include the .png
    public void LoadFile(string path)
    {

        //string fileName = Path.GetFileName(path);
        //string actualPath = path;

        ////move it so c++ can read it
        //MoveFile(actualPath, path);

        //ReadFile();

        //MoveFile(actualPath, path);
    }

    /// @brief Generates an png image from the canvas and saves it to the specified path.
    /// @param path The file path where the image will be saved.
    public void GenerateImage(string path)
    {

        string fileName = Path.GetFileName(path);
        string actualPath = path;

        SafeImage();

        MoveFile(fileName, path);
    }

    /// @brief Since the bridges crashes when trying to pass paths. c++ generates the image at root and then is moved by c#. It can't move files to C: or rewrite
    /// @param sourcePath location where the image is currently located at
    /// @param destinationPath new location of the file
    public void MoveFile(string sourcePath, string destinationPath)
    {
        try
        {
            // Ensure the directory exists
            Directory.CreateDirectory(Path.GetDirectoryName(destinationPath));

            // Move the file to the desired location
            File.Move(sourcePath, destinationPath);
            Debug.Log("File moved to: " + destinationPath);
        }
        catch (Exception ex)
        {
            Debug.LogError("Error moving file: " + ex.Message);
        }
    }


    /// @brief Debug only, prints the canvas status
    public void ReadAllPixels()
    {
        // Iterate through all pixels in the canvas
        for (int y = 0; y < 10; y++)
        {
            for (int x = 0; x < 10; x++)
            {
                // Read pixel values
                int r = GetPixelR(x, y);
                int g = GetPixelG(x, y);
                int b = GetPixelB(x, y);
                int a = GetPixelA(x, y);

                // Output pixel values
                Debug.Log("Pixel at (" + x + ", " + y + "): R=" + r + ", G=" + g + ", B=" + b + ", A=" + a);
            }
        }
    }

    #region DllImports

    [DllImport(DllName)] private static extern IntPtr CreateCanvas(int width, int height, string path);
    [DllImport(DllName)] private static extern void CleanCanvas();
    [DllImport(DllName)] private static extern IntPtr ReturnPath();

    [DllImport(DllName)] private static extern int GetPixelR(int x, int y);
    [DllImport(DllName)] private static extern int GetPixelG(int x, int y);
    [DllImport(DllName)] private static extern int GetPixelB(int x, int y);
    [DllImport(DllName)] private static extern int GetPixelA(int x, int y);
    [DllImport(DllName)] private static extern void SetPixel(int X, int y, int R, int G, int B, int A);
    [DllImport(DllName)] private static extern void SafeImage();
    [DllImport(DllName)] private static extern void ReadFile();

    #endregion

}
