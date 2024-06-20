/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 03/03/2024
/// @brief implementation of car.hpp funtions

#include "../Headers/Car.hpp"
#include "../Headers/Scene.hpp"
#include "../Headers/Collision.hpp"
namespace misi
{
	Car::Car(Scene* given_Scene)
	{
        fatherScene = given_Scene;
        fatherScene->getMessenger()->add(*this, "Player");
        physicWorld* world = fatherScene->getPhysicWorld();

        PhysicSphere* wheel1 = new PhysicSphere(b2Vec2(0.8f, 2.75f), b2_dynamicBody, 0.0f,
            0.50f, 0.50f, 0.50f, world, .2f, false, CollisionListener::player, CollisionListener::player+
            CollisionListener::ground+ CollisionListener::trigger);

        car.push_back(wheel1);

        fatherScene->getCollisionController()->addListener(wheel1->getBody(),"Car");
        PhysicSphere* wheel2 = new PhysicSphere(b2Vec2(2.4f, 2.75f), b2_dynamicBody, 0.0f,
            0.50f, 0.50f, 0.50f, world, .2f, false,  CollisionListener::player, CollisionListener::player +
            CollisionListener::ground + CollisionListener::trigger);
        fatherScene->getCollisionController()->addListener(wheel2->getBody(), "Car");
        car.push_back(wheel2);

        PhysicSphere* clawJoint = new PhysicSphere(b2Vec2(0.8f, 3.2f), b2_dynamicBody, 0.0f,
            0.50f, 0.50f, 0.50f, world, .1f, false,  CollisionListener::player, CollisionListener::player +
            CollisionListener::ground + CollisionListener::trigger);
        car.push_back(clawJoint);
        PhysicPolygon* chasis = new PhysicPolygon(b2Vec2(0.8f, 1.5f), b2_dynamicBody, 0,
            1.00f, 0.50f, 0.50f, world, true, b2Vec2(.8f, .2f), false, + CollisionListener::player, CollisionListener::player +
            CollisionListener::ground + CollisionListener::trigger);
        fatherScene->getCollisionController()->addListener(chasis->getBody(), "Car");
        car.push_back(chasis);
        PhysicPolygon* claw = new PhysicPolygon(b2Vec2(0.8f, 1.6f), b2_dynamicBody, 0,
            0.2f, 0.20f, 0.20f, world, true, b2Vec2(.8f, .05f), false,  CollisionListener::player, CollisionListener::player +
            CollisionListener::ground + CollisionListener::trigger);
        car.push_back(claw);
        PhysicPolygon* clawRWall = new PhysicPolygon(b2Vec2(0.4f, 1.7f), b2_dynamicBody, 0,
            0.2f, 0.20f, 0.20f, world, true, b2Vec2(.05f, 0.2f), false,  CollisionListener::player, CollisionListener::player +
            CollisionListener::ground + CollisionListener::trigger);
        car.push_back(clawRWall);
        PhysicPolygon* clawLWall = new PhysicPolygon(b2Vec2(1.18f, 1.7f), b2_dynamicBody, 0,
            0.2f, 0.20f, 0.20f, world, true, b2Vec2(.05f, 0.2f), false, CollisionListener::player, CollisionListener::player+
            CollisionListener::ground+ CollisionListener::trigger);
        car.push_back(clawLWall);
        MultiShapeObject* car = new MultiShapeObject(chasis);
        MultiShapeObject* carClaw = new MultiShapeObject(claw);
        carPointer = car;
        carClawPointer = carClaw;

        carClaw->AddWeldJoint(clawRWall->getBody());
        carClaw->AddWeldJoint(clawLWall->getBody());
        carClaw->AddMotorJoint(clawJoint->getBody());


        car->AddMotorJoint(wheel1->getBody());
        car->AddMotorJoint(wheel2->getBody());
        car->AddRevoluteJoint(clawJoint->getBody());
	}

    void Car::handle(const Message& message)
    {
        std::string key;
        parameter value;
        for (const auto& entry : message.parameters) {
            key = entry.first;
            value = entry.second;
        }
        if (key == "Move Left")
        {
            carPointer->AddSpeed(30);
            carClawPointer->AddSpeed(0);
        }
        if (key == "Reset")
        {
            Reset();
        }
        if (key == "Move Right")
        {
            carPointer->AddSpeed(-30);
            carClawPointer->AddSpeed(0);
        }
        if (key == "Stop")
        {
            carPointer->AddSpeed(0);
            carClawPointer->AddSpeed(0);
        }
        if (key == "Special Move")
        {
            if (!retractedClaw)
            {
                carClawPointer->AddSpeed(-600);
                retractedClaw = true;
            }
            else
            {
                carClawPointer->AddSpeed(800);
                retractedClaw = false;
            }
        }
        if (key == "Reset")
        {
            Reset();
        }
    }
    void Car::Reset()
    {
        car[0]->getBody()->SetTransform(b2Vec2(0.8f, 2.75f), 0);
        car[1]->getBody()->SetTransform(b2Vec2(2.4f, 2.75f), 0);
        car[2]->getBody()->SetTransform(b2Vec2(0.8f, 3.2f), 0);
        car[3]->getBody()->SetTransform(b2Vec2(0.8f, 1.5f), 0);
        car[4]->getBody()->SetTransform(b2Vec2(0.8f, 1.6f), 0);
        car[5]->getBody()->SetTransform(b2Vec2(0.4f, 1.7f), 0);
        car[6]->getBody()->SetTransform(b2Vec2(1.18f, 1.7f), 0);
        carPointer->AddSpeed(0);
        carClawPointer->AddSpeed(0);
    }
    Car::~Car()
    {
        delete carPointer;
        delete carClawPointer;
    }
}