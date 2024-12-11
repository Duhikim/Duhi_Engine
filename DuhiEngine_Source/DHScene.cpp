#include "DHScene.h"


namespace dh {
	Scene::Scene()
		
	{
	}

	Scene::~Scene()
	{
		for (GameObject2p* gameObj2p : mGameObjects2p) {
			delete gameObj2p;
		}
		mGameObjects2p.clear();
	}

	void Scene::Initialize()
	{
	/*	for (int i = 0; i < 5; i++) {
			GameObject2p* gameObj2p = new GameObject2p;
			gameObj2p->SetPosition(rand()%1600, rand()%500);
			mGameObjects2p.push_back(gameObj2p);
		}*/
	}

	void Scene::Update()
	{
		////일반적인 for 문
		//for (int i = 0; i < mGameObjects2p.size(); i++) {
		//	mGameObjects2p[i]->Update();
		//}

		//범위기반 for 문
		for (GameObject2p* gameObj : mGameObjects2p) 
		{
			gameObj->Update();
		}
	}
	void Scene::LateUpdate()
	{
		/*for (GameObject2p* gameObj : mGameObjects2p)
		{
			gameObj->LateUpdate();
		}*/
	}
	void Scene::Render(HDC hdc)
	{
		for (GameObject2p* gameObj : mGameObjects2p)
		{
			gameObj->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject2p* gameObj2p)
	{
		mGameObjects2p.push_back(gameObj2p);
	}
}