#include "DHScene.h"

namespace dh {
	
	Scene::Scene()
		:mGameObjects{}
		, mDinoObjects{}
	{}

	Scene::~Scene() {}

	void Scene::Initialize() 
	{
		
	}
	void Scene::Update() 
	{
		/*for (int i = 0; i < mGameObjects.size(); i++) {
		 mGameObjects[i]->Update();
	 }*/

	 //범위 기반 for문
		for (DinoObject* dinoObj : mDinoObjects) {
			dinoObj->Update();
		}
	}
	void Scene::LateUpdate() 
	{
		for (DinoObject* dinoObj : mDinoObjects) {
			dinoObj->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc) 
	{
		for (DinoObject* dinoObj : mDinoObjects) {
			dinoObj->Render(hdc);
		}
	}

	void Scene::AddDinoObject(DinoObject* dinoObj) 
	{
		mDinoObjects.push_back(dinoObj);
	}

}
	
