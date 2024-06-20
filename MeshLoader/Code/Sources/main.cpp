/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 16/04/2024
/// @brief Main class


//#include <cassert>
//#include <cmath>
//#include "../Headers/Math.hpp"
//#include "../Headers/view.hpp"
//#include <assimp/Importer.hpp>
//#include <assimp/scene.h>
//#include <assimp/postprocess.h>

#include "../Headers/Scene.hpp"
using namespace misi;

Scene* CreateScene()
{
    constexpr unsigned window_width = 800u;
    constexpr unsigned window_height = 600u;


    Scene* mainScene = new Scene(window_width, window_height, 0.5f);


    Model* snowModel = new Model("../../Assets/SnowScene.obj", window_width, window_height,
        0.f, 1.f, math::Vector3f{ 0.f, 0.f, -10.f }, mainScene->GetColorBuffer(), mainScene->GetRasterizer());


    Model* penguinModel = new Model("../../Assets/Lowpolypenguin.obj", window_width, window_height,
        0, 0.5, math::Vector3f{ 1.f, -0.2f, -5.f }, mainScene->GetColorBuffer(), mainScene->GetRasterizer());

    snowModel->SetScale(0.5f);

    Model* planetoid = new Model("../../Assets/SnowScene.obj", window_width, window_height,
        0.f, 0.5f, math::Vector3f{ 0.f, 0.f, -10.f }, mainScene->GetColorBuffer(), mainScene->GetRasterizer());

    snowModel->SetRotationSpeed(0.025f);

    planetoid->SetRotationSpeed(-0.025f);

    penguinModel->SetFather(snowModel);

    planetoid->SetFather(snowModel);

    mainScene->AddModel(snowModel);

    mainScene->AddModel(penguinModel);

    mainScene->AddModel(planetoid);

    return mainScene;
}
int main()
{

    Scene* mainScene = CreateScene();

    mainScene->Run();
    

}
