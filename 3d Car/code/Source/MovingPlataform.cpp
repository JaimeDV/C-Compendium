
/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 15/05/2024
/// @brief Class that implements the classes defined at movingPlataform.hpp

#include "../Headers/MovingPlataform.hpp"
namespace misi
{
    void MovingPlataform::ModelAction()
    {
        DisableGravity();
        SetVelocity(btVector3(moveSpeed, 0, 0));
        LockRotation();
        Wait();
    }
    

    void MovingPlataform::Wait()
    {
        waitTimeAux--;
        if (waitTimeAux <= 0)
        {
            waitTimeAux = waitTime;
            moveSpeed *= -1;
        }
       
    }

}

