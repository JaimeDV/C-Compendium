
/// @copyright � 2023+ Jaime d�az vi�itez
/// @author Author: Jaime D�az Vi�itez
/// pamecin@gmail.com
/// @date 15/05/2024
/// @brief Class that implements the classes defined at Door.hpp

#include "../Headers/Door.hpp"
namespace misi
{
    
    void Door::handle(const Message& message)
    {
        std::string key;
        parameter value;
        for (const auto& entry : message.parameters) {
            key = entry.first;
            value = entry.second;
        }
        if (key == "Open")
        {
            doormodel->Trigger();
        }
        
    }

    void DoorModel::Trigger()
    {
        trigered = true;
    }
}

