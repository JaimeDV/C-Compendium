/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 12/05/2024

#pragma once
#include "Render_Node.hpp"
#include "Body.hpp"
#include "Light.hpp"
#include "SFML/Window.hpp"
#include "InputManager.hpp"
#include "ParticleSystem.hpp"

namespace misi
{
    class ColisionChecker;
    class InputManager;
    class Tank;

    /// @brief Class that houses the physical world and the window/render kernel
    class Scene : public Message_Listener
    {
        vector<shared_ptr<PhysicBody>> modelList;  // Vector to hold all physical body models in the scene
        shared_ptr<Render_Node> renderScene = make_shared<Render_Node>(); // Render node for the scene
        shared_ptr<sf::Window> window;  // Pointer to the SFML window
        btVector3 gravityForce; // Vector representing the force of gravity in the scene
        btDiscreteDynamicsWorld worldReference;  // Reference to the Bullet Physics world
        btDefaultCollisionConfiguration collisionConfiguration;  // Collision configuration for Bullet Physics
        btCollisionDispatcher collisionDispatcher;  // Collision dispatcher for Bullet Physics
        btDbvtBroadphase overlappingPairCache;  // Broadphase collision detection for Bullet Physics
        btSequentialImpulseConstraintSolver constraintSolver;  // Solver for physics constraints
        shared_ptr<ColisionChecker> colisionManager;  // Collision checker for managing collisions
        shared_ptr<InputManager> inputManager;  // Input manager for handling user input
        shared_ptr<Tank> mainPlayer;  // Pointer to the main player object
        vector<shared_ptr<Message_Dispacher>> messagers;  // Vector to hold all message dispatchers in the scene
        bool running = false;  // Flag indicating whether the scene is running
        float sensitivity = 1.f;  // Sensitivity value for input handling
        shared_ptr<ParticleSystem> particleSystem = nullptr;  // Pointer to the particle system in the scene

    public:
        /// @brief Constructor for Scene
        /// @param width The width of the window
        /// @param height The height of the window
        Scene(unsigned width, unsigned height);

        /// @brief Add a physical body model to the scene
        /// @param model Shared pointer to the PhysicBody to be added
        void addModel(shared_ptr<PhysicBody> model);

        /// @brief Render the scene
        void Render();

        /// @brief Check if a physical body is a sphere
        /// @param obj Shared pointer to the PhysicBody to be checked
        /// @return True if the object is a PhysicSphere, false otherwise
        bool IsPhysicSphere(const std::shared_ptr<PhysicBody>& obj);

        /// @brief Create the render scene
        /// @return Shared pointer to the Render_Node created
        shared_ptr<Render_Node> CreateScene();

        /// @brief Configure the render scene
        /// @param scene Reference to the Render_Node to be configured
        void ConfigureScene(Render_Node& scene);

        /// @brief Reset the viewport of the window
        /// @param window Reference to the SFML window
        /// @param scene Reference to the Render_Node
        void ResetViewport(const sf::Window& window, Render_Node& scene);

        /// @brief Instantiate the SFML window
        /// @param width The width of the window
        /// @param height The height of the window
        void InstantiateWindow(int width, int height);

        /// @brief Remove a physical body model from the scene
        /// @param model Shared pointer to the PhysicBody to be removed
        void RemoveModel(shared_ptr<PhysicBody> model);

        /// @brief Add an input manager to the scene
        /// @param inputer Shared pointer to the InputManager to be added
        void AddInputManager(shared_ptr<InputManager> inputer)
        {
            inputManager = inputer;
        }

        /// @brief Move the camera in the scene
        /// @param scene Reference to the Render_Node
        /// @param direction The direction vector for the camera movement
        void MoveCamera(Render_Node& scene, glt::Vector3 direction);

        /// @brief Handle messages in the scene
        /// @param message The message to be handled
        virtual void handle(const Message& message) override;

        /// @brief Set the sensitivity for input handling
        /// @param value The new sensitivity value
        void SetSensitivity(float value)
        {
            sensitivity = value;
        }

        /// @brief Add a model listener to the scene
        /// @param listener Shared pointer to the PhysicBody to be added as a listener
        void AddModelListener(shared_ptr<PhysicBody> listener);

        /// @brief Add a message dispatcher to the scene
        /// @param given_m Shared pointer to the Message_Dispacher to be added
        void AddMeseenger(shared_ptr<Message_Dispacher> given_m)
        {
            messagers.push_back(given_m);
        }

        /// @brief Add the main player object to the scene
        /// @param given_player Shared pointer to the Tank to be added as the main player
        void AddMainPlayer(shared_ptr<Tank> given_player)
        {
            mainPlayer = given_player;
        }

        /// @brief Add a particle system to the scene
        /// @param given_particleSystem Shared pointer to the ParticleSystem to be added
        void AddParticleSystem(shared_ptr<ParticleSystem> given_particleSystem)
        {
            particleSystem = given_particleSystem;
        }
    };
}
