
/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 15/05/2024
/// @brief Class that implements the classes defined at Key.hpp

#include "../Headers/Key.hpp"
namespace misi
{
    void Key::HandleColision(btCollisionObject* object_a, btCollisionObject* object_b)
    {
        if (IsSelf(object_a) && IsPlayer(object_b))
        {
            TriggerKey();
            DisableModel();
        }
        else if (IsSelf(object_b) && IsPlayer(object_a))
        {
            TriggerKey();
            DisableModel();
        }
    }

    bool Key::IsSelf(btCollisionObject* object)
    {
        if (object->getBroadphaseHandle() == body->getBroadphaseHandle())
        {
            return true;
        }
        return false;
    }

    bool Key::IsPlayer(btCollisionObject* object)
    {
        if (object->getBroadphaseHandle() == player->Getbody()->getBroadphaseHandle())
        {
            return true;
        }
        return false;
    }

    void Key::TriggerKey()
    {
        std::map<std::string, parameter> parameters;
        Message input_message("Door", parameters);
        misi::parameter param(0);
        input_message.set_id("Door");
        parameters.clear();
        parameters.insert(std::make_pair(std::string("Open"), param));
        input_message.set_params(parameters);
        message_dispacher->send(input_message);
    }

}

