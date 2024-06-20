
/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
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

