
/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 18/05/2024
/// @brief Class that implements the classes defined at tank.hpp

#include "../Headers/Tank.hpp"
namespace misi
{
    void Tank::ModelAction()
    {
       /* DisableGravity();*/
        SetVelocity(moveSpeed);
        LockRotation();
    }


    
}

