/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 03/03/2024
/// @brief implementation of turret.hpp funtions

#include "../Headers/Turret.hpp"
#include "../Headers/Scene.hpp"
#include "../Headers/Collision.hpp"
namespace misi
{
    BackGround::BackGround(Scene* given_Scene) //also adds ground
    {
        fatherScene = given_Scene;
        fatherScene->getMessenger()->add(*this, "Turret");
        physicWorld* world = fatherScene->getPhysicWorld();
        PhysicEdge* ground = new PhysicEdge(b2Vec2(0.f, 0.3f), b2_staticBody, 0.0f,
            1.00f, 0.50f, 0.50f, world, b2Vec2(0.f, 2.f), b2Vec2(3, 2.f), false, CollisionListener::ground,
            CollisionListener::ground + CollisionListener::player);

        MultiShapeObject* background = new MultiShapeObject(ground);

        //isle 1
        background->AddEdgeFixture(b2Vec2(3.f, 2.f), b2Vec2(3.4f, 1.6f), 1.00f, 0.50f, 0.50f);
        background->AddEdgeFixture(b2Vec2(3.4f, 1.6f), b2Vec2(3.8f, 1.3f), 1.00f, 0.50f, 0.50f);
        background->AddEdgeFixture(b2Vec2(3.8f, 1.3f), b2Vec2(4.4f, 1), 1.00f, 0.50f, 0.50f);
        background->AddEdgeFixture(b2Vec2(4.4f, 1), b2Vec2(5, 0.9f), 1.00f, 0.50f, 0.50f);
        background->AddEdgeFixture(b2Vec2(5, 0.9f), b2Vec2(7, 0.9f), 1.00f, 0.50f, 0.50f);
        background->AddEdgeFixture(b2Vec2(7, 0.9f), b2Vec2(9, 1.4f), 1.00f, 0.50f, 0.50f);
        background->AddEdgeFixture(b2Vec2(9, 1.4f), b2Vec2(9, -4), 1.00f, 0.50f, 0.50f);
        //isle 2
        background->AddEdgeFixture(b2Vec2(11, 0.6f), b2Vec2(20, 1), 1.00f, 0.50f, 0.50f);
        background->AddEdgeFixture(b2Vec2(11, 0.6f), b2Vec2(11, -4), 1.00f, 0.50f, 0.50f);

        PhysicPolygon* rightLimit = new PhysicPolygon(b2Vec2(12.2f, 4), b2_staticBody, 0,
            1.00f, 0.50f, 0.50f, world, true, b2Vec2(6, 10), true, CollisionListener::ground,
            CollisionListener::ground + CollisionListener::player);
        fatherScene->getCollisionController()->addListener(rightLimit->getBody(), "Crate Trigger");

        PhysicPolygon* righStoptLimit = new PhysicPolygon(b2Vec2(12.6f, 4), b2_staticBody, 0,
            1.00f, 0.50f, 0.50f, world, true, b2Vec2(6, 10), false, CollisionListener::ground,
            CollisionListener::ground + CollisionListener::player);
        //void trigger
        PhysicPolygon* cube = new PhysicPolygon(b2Vec2(5, -1), b2_staticBody, 0,
            1.00f, 0.50f, 0.50f, world, true, b2Vec2(10, 0.2f), true, CollisionListener::trigger, CollisionListener::player);
        fatherScene->getCollisionController()->addListener(cube->getBody(), "void Trigger");
        //end
        PhysicPolygon* endPlataformR = new PhysicPolygon(b2Vec2(-3, 8), b2_staticBody, -40,
            0.2f, 0.20f, 0.20f, world, true, b2Vec2(.5f, .05f), false, CollisionListener::ground,
            CollisionListener::ground + CollisionListener::player);
        PhysicPolygon* endPlataformL = new PhysicPolygon(b2Vec2(7.6f, -2.4f), b2_staticBody, 40,
            0.2f, 0.20f, 0.20f, world, true, b2Vec2(.5f, .05f), false, CollisionListener::ground,
            CollisionListener::ground + CollisionListener::player);
        PhysicPolygon* endPlataformRunway = new PhysicPolygon(b2Vec2(3.531f, 2.63f), b2_staticBody, 0,
            0.2f, 0.20f, 0.20f, world, true, b2Vec2(1.8f, .05f), false, CollisionListener::ground,
            CollisionListener::ground + CollisionListener::player);

        PhysicPolygon* endTrigger = new PhysicPolygon(b2Vec2(2.3f, 2.5f), b2_staticBody, 0,
            1.00f, 0.50f, 0.50f, world, true, b2Vec2(.6f, 0.5f), true, CollisionListener::trigger,
            CollisionListener::ground+ CollisionListener::player);
        fatherScene->getCollisionController()->addListener(endTrigger->getBody(), "Particle Trigger");

        //Torreta
        PhysicPolygon* turretStick = new PhysicPolygon(b2Vec2(7.80f, 1.2f), b2_dynamicBody, 0,
            1.00f, 0.50f, 0.50f, world, true, b2Vec2(.1f, 1), false, CollisionListener::backGround,
            CollisionListener::ground + CollisionListener::backGround);

        PhysicPolygon* Aux = new PhysicPolygon(b2Vec2(7.80f, 1), b2_dynamicBody, 0,
            1.00f, 0.50f, 0.50f, world, true, b2Vec2(.1f, 1), false, CollisionListener::backGround,
            CollisionListener::ground + CollisionListener::backGround);

        PhysicSphere* turretJoint = new PhysicSphere(b2Vec2(15.59f, 3.2f), b2_dynamicBody, 0.0f,
            0.2f, 0.20f, 0.20f, world, .1f, true, CollisionListener::ground,
            CollisionListener::ground + CollisionListener::backGround);

        PhysicPolygon* turretclaw = new PhysicPolygon(b2Vec2(7.8f, 1.7f), b2_dynamicBody, 0,
            0.2f, 0.20f, 0.20f, world, true, b2Vec2(.8f, .05f), false, CollisionListener::ground,
            CollisionListener::ground + CollisionListener::backGround);

        PhysicPolygon* turretclawclawRWall = new PhysicPolygon(b2Vec2(7.4f, 1.8f), b2_dynamicBody, 0,
            0.2f, 0.20f, 0.20f, world, true, b2Vec2(.05f, 0.2f), false, CollisionListener::ground,
            CollisionListener::ground + CollisionListener::backGround);

        PhysicPolygon* turretclawclawLWall = new PhysicPolygon(b2Vec2(8.18f, 1.8f), b2_dynamicBody, 0,
            0.2f, 0.20f, 0.20f, world, true, b2Vec2(.05f, 0.2f), false, CollisionListener::ground,
            CollisionListener::ground + CollisionListener::backGround);

        PhysicPolygon* turretAuxJoint = new PhysicPolygon(b2Vec2(7.80f, 1.65f), b2_dynamicBody, 0,
            1.00f, 0.50f, 0.50f, world, true, b2Vec2(.1f, .1f), false, CollisionListener::ground,
            CollisionListener::ground + CollisionListener::backGround);

        MultiShapeObject* turretClaw = new MultiShapeObject(turretclaw);

        MultiShapeObject* turretAnchor = new MultiShapeObject(turretStick);
        turretClaw->AddWeldJoint(turretclawclawRWall->getBody());
        turretClaw->AddWeldJoint(turretclawclawLWall->getBody());
        turretClaw->AddMotorJoint(turretJoint->getBody());
        turretClaw->AddRevoluteJoint(turretAuxJoint->getBody());

        turretAnchor->AddRevoluteJoint(turretAuxJoint->getBody());

        background->AddWeldJoint(turretStick->getBody());
        background->AddWeldJoint(Aux->getBody());
        ClawPointer = turretClaw;

             new PhysicSphere(b2Vec2(15.5f, 5), b2_dynamicBody, 0.0f,
             0.50f, 0.50f, 0.50f, world, .2f, false, CollisionListener::ground, 
                 CollisionListener::ground + CollisionListener::player+ CollisionListener::trigger);

             new PhysicSphere(b2Vec2(15.3f, 5), b2_dynamicBody, 0.0f,
                 0.50f, 0.50f, 0.50f, world, .2f, false, CollisionListener::ground,
                 CollisionListener::ground + CollisionListener::player+ CollisionListener::trigger);
            
           
             new PhysicSphere(b2Vec2(15.7f, 5), b2_dynamicBody, 0.0f,
                 0.50f, 0.50f, 0.50f, world, .2f, false, CollisionListener::ground,
                 CollisionListener::ground + CollisionListener::player);
             new PhysicSphere(b2Vec2(15.8f, 5), b2_dynamicBody, 0.0f,
                 0.50f, 0.50f, 0.50f, world, .2f, false, CollisionListener::ground,
                 CollisionListener::ground + CollisionListener::player+ CollisionListener::trigger);

           

        //raising plataform

        PhysicPolygon* Plataform = new PhysicPolygon(b2Vec2(5, -1.6f), b2_staticBody, 0,
            0.2f, 0.20f, 0.20f, world, true, b2Vec2(0.98f, .1f), false, CollisionListener::ground,
             CollisionListener::player);

        //PhysicPolygon* PlataformStick = new PhysicPolygon(b2Vec2(5, -2), b2_dynamicBody, 0,
        //    0.2f, 0.20f, 0.20f, world, true, b2Vec2(.1f, 3), false, CollisionListener::ground,
        //    CollisionListener::ground + CollisionListener::player);

        //PhysicPolygon* PlataformSupport = new PhysicPolygon(b2Vec2(5, -4), b2_staticBody, 0,
        //    0.2f, 0.20f, 0.20f, world, true, b2Vec2(0.98f, .1f), false, CollisionListener::ground,
        //    CollisionListener::ground + CollisionListener::player);

        MultiShapeObject* raisingPlataform = new MultiShapeObject(Plataform);

       /* raisingPlataform->AddpPulleyJoint(PlataformStick->getBody()); 
        raisingPlataform->AddpPulleyJoint(PlataformSupport->getBody());*/
        movingPlataform = Plataform;
        fatherScene->getCollisionController()->addListener(Plataform->getBody(), "Plataform");
    }

    void BackGround::handle(const Message& message)
    {
        std::string key;
        parameter value;
        for (const auto& entry : message.parameters) {
            key = entry.first;
            value = entry.second;
        }
        if (key == "spin")
        {
            ClawPointer->AddSpeed(5000);
            putPlataform();
        }
    }
    BackGround::~BackGround()
    {
        delete ClawPointer;
    }
}