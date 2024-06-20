#include "../Headers/Camera.hpp"

namespace misi
{
    Camera::Camera(float given_sensitivity, float given_fov, float given_nearD, float given_farD, unsigned given_width,
        unsigned given_height) :sensitivity(given_sensitivity), fov(given_fov), nearD(given_nearD), farD(given_farD),
        height(given_height), width(given_width)
    {
        SetMatrix();
        SetProyection();
        nearCap = -6.f;//hardcoded at the moment.
    }

    void Camera::SetProyection()
    {
      projection = perspective(fov, nearD, farD, static_cast<float>(width) / static_cast<float>(height));
    }

    void Camera::Update()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            MoveCameraUP();
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            MoveCameraDown();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            MoveCameraLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            MoveCameraRight();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            MoveCameraBackward();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            MoveCameraForward();
        }
    }

    void Camera::MoveCameraDown()
    {
        SetPosition(math::Vector3f{ GetPosition().x,GetPosition().y + sensitivity, GetPosition().z });
    }
    void Camera::MoveCameraUP()
    {
        SetPosition(math::Vector3f{ GetPosition().x,GetPosition().y-sensitivity, GetPosition().z });
    }
    void Camera::MoveCameraRight()
    {
        SetPosition(math::Vector3f{ GetPosition().x+sensitivity,GetPosition().y, GetPosition().z });
    }
    void Camera::MoveCameraLeft()
    {
        SetPosition(math::Vector3f{ GetPosition().x-sensitivity,GetPosition().y, GetPosition().z });
    }
    void Camera::MoveCameraBackward()
    {
        SetPosition(math::Vector3f{ GetPosition().x,GetPosition().y, GetPosition().z+sensitivity });
    }
    void Camera::MoveCameraForward()
    {
        if (GetPosition().z + sensitivity> nearCap)
        {
            SetPosition(math::Vector3f{ GetPosition().x,GetPosition().y, GetPosition().z - sensitivity });
        }
    }
}