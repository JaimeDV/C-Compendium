/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 20/04/2024
/// @brief base class that stores mesh data 
#pragma once
#include "math.hpp"
#include <vector>
using namespace math;
namespace misi
{
    class Node
    {

        private:
        Node* father=nullptr; //reference to the father Node 
        float angle = 0;//vertex rotation value
        float scaleFactor = 1;//vertex scale value
        math::Vector3f position = math::Vector3f(0.0f, 0.0f, 0.0f);//vertex value info
        Matrix44 transformation; //matrix containing all the transformations

        public:

        /// @brief Gets the transformation matrix of the object.
        /// @return The transformation matrix.
        Matrix44 GetTransform()
        {
            return transformation;
        }

        /// @brief Sets the scale of the object.
        /// @param scale The scale value.
        void SetScale(float scale);

        /// @brief Sets the angle of the object.
        /// @param givenAngle The angle value.
        void SetAngle(float givenAngle);

        /// @brief Sets the position of the object.
        /// @param given_position The position value.
        void SetPosition(math::Vector3f given_position);

        /// @brief Gets the position of the object.
        /// @return The position vector.
        math::Vector3f GetPosition()
        {
            return position;
        }

        /// @brief Gets the angle of the object.
        /// @return The angle value.
        float GetAngle()
        {
            return angle;
        }

        /// @brief Gets the scale of the object.
        /// @return The scale value.
        float GetScale()
        {
            return scaleFactor;
        }

        /// @brief Sets the parent node of the current node and updates the transformation. it doesn't take into account if the father has a father
        /// @param fatherNode A pointer to the parent node.
        void SetFather(Node* fatherNode)
        {
            father = fatherNode;
            transformation = fatherNode->GetTransform() * transformation;
            SetMatrix();     
        }
        /// @brief Gets the parent node of the current node.
        /// @return A pointer to the parent node.
        Node* GetFather()
        {
            return father;
        }

        /// @brief Sets the transformation matrix using the father node
        void SetMatrix()
        {
            Matrix44 identity(1.f);
            Matrix44 scaling = scale(identity, scaleFactor);
            Matrix44 rotation_y = rotate_around_y(identity, angle);
            Matrix44 translation = translate(identity, position);
            transformation = translation * rotation_y * scaling;
            if (father)
            {
                transformation *= GetFather()->GetTransform();
            }
        }

    };
}