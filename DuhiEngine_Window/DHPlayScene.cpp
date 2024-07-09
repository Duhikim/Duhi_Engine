#include "DHPlayScene.h"
#include "DHGameObject.h"
#include "DHGameObject2p.h"
#include "DHDinoObject.h"

namespace dh {
    PlayScene::PlayScene()
    {
    }
    PlayScene::~PlayScene()
    {
    }
    void PlayScene::Initialize()
    {
        DinoObject* dinoObj = new DinoObject();
        AddDinoObject(dinoObj);
    }
    void PlayScene::Update()
    {
        Scene::Update();
     
    }
    void PlayScene::LateUpdate()
    {
        
        Scene::LateUpdate();
       
    }
    void PlayScene::Render(HDC hdc)
    {
        Scene::Render(hdc);
       
    }
}