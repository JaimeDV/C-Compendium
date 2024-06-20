
/// @copyright � 2023+ Jaime d�az vi�itez
/// @author Author: Jaime D�az Vi�itez
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

