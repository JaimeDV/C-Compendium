/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 15/05/2024


#pragma once
#include "Plane.hpp"
#include "Message.hpp"
/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 15/05/2024


#pragma once
#include "Plane.hpp"
#include "Message.hpp"
namespace misi
{
    /// @brief Class that creates a physicbody acting as a key, checks collisions and if the player collides sends a message to the corresponding door
    class Key : public PhysicPlane
    {

        shared_ptr <PhysicBody> player; // Pointer to the player physic body
        shared_ptr<Message_Dispacher> message_dispacher; // Pointer to the message dispatcher

    public:

        /// @brief Constructor for Key
        /// @param given_rotation The initial rotation of the key
        /// @param given_mass The mass of the key
        /// @param given_inertia The inertia of the key
        /// @param given_restitution The restitution value of the key
        /// @param given_type The type of the key
        /// @param given_origin The initial origin of the key
        /// @param scale The scale of the key model
        Key(btVector3 given_rotation, float given_mass, btVector3 given_inertia, float given_restitution, ObjectType given_type,
            btVector3 given_origin, btVector3 scale) : PhysicPlane(given_rotation, given_mass, given_inertia, given_restitution, given_type, given_origin, scale)
        {
        }

        /// @brief Destructor only exist to make polymorphic
        virtual ~Key() {}

        /// @brief Handle collision between 2  objects
        /// @param object_a The first collision object
        /// @param object_b The second collision object
        virtual void HandleColision(btCollisionObject* object_a, btCollisionObject* object_b);

        /// @brief Check if the collision is with itself
        /// @param object_a The collision object
        /// @return True if the collision is with itself, false otherwise
        bool IsSelf(btCollisionObject* object_a);

        /// @brief Check if the collision is with the player
        /// @param object_a The collision object
        /// @return True if the collision is with the player, false otherwise
        bool IsPlayer(btCollisionObject* object_a);

        /// @brief Add the player reference to the key
        /// @param given_player Pointer to the player physic body
        void AddPlayer(shared_ptr <PhysicBody> given_player)
        {
            player = given_player;
        }

        /// @brief Add the message dispatcher to the key
        /// @param given_messenger Pointer to the message dispatcher
        void AddMesenger(shared_ptr<Message_Dispacher> given_messenger)
        {
            message_dispacher = given_messenger;
        }

        /// @brief Trigger the key
        void TriggerKey();

    };
}
