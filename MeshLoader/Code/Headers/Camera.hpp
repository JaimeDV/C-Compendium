/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 25s/04/2024
/// @brief Camera class, a moveable object that cast the proyection for the scene
#pragma once

#include "node.hpp"
#include "SFML/Window.hpp"
namespace misi
{
    class Camera: public Node
    {
        float sensitivity;//amount that the camera translates when you try to move it.
        float fov;//aperture of the camera cone 
        float nearD;//position of the near Plane
        float farD;//position of the farPlane
        Matrix44 projection;//proyected matrix resulting from the camera 
        unsigned width;//Viewport width
        unsigned height;//Viewport height
        Matrix44 cameraTransform;//Transformation info adapted to the camera (proyection & no scale)
        float nearCap; //hard limit of zoom to avoid weird behaviour
        public:


            Camera(float sensitivity, float fov, float nearD, float farD, unsigned width,
                unsigned height);

            /// @brief Gets the inverse of the current transformation matrix.
            /// @return The inverse of the transformation matrix.
            Matrix44 GetInverse()
            {
                return inverse(GetTransform());
            }

            /// @brief Gets the projection matrix used for projecting 3D objects onto a 2D plane.
            /// @return The projection matrix.
            Matrix44 GetProjection()
            {
                return projection;
            }

            /// @brief Gets the near clipping plane distance.
            /// @return The near clipping plane distance.
            float GetNear()
            {
                return nearD;
            }

            /// @brief Gets the far clipping plane distance.
            /// @return The far clipping plane distance.
            float GetFar()
            {
                return farD;
            }
            ///@brief sets the proyection matrix
            void SetProyection();

            ///@brief starts reading player inputs
            void Update();

            ///@brief displace the camera on the positive x axis
            void MoveCameraRight();

            ///@brief displace the camera on the negative y axis
            void MoveCameraUP();

            ///@brief displace the camera on the negative x axis
            void MoveCameraLeft();

            ///@brief displace the camera on the positve y axis
            void MoveCameraDown();

            ///@brief displace the camera on the positive z axis
            void MoveCameraBackward();

            ///@brief displace the camera on the negaive z axis
            void MoveCameraForward();

    };
}
