#include "DHPlayScene.h"

namespace dh {
	PlayScene::PlayScene()
	{
	};

	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		for (int i = 0; i < 3; i++) {
			GameObject2p* obj2p = new GameObject2p;
			obj2p->SetPosition(rand() % 1600, rand() % 900);
			AddGameObject(obj2p);
		}
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
	;

}