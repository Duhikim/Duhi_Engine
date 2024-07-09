#include "DHSceneManager.h"

namespace dh {


	void SceneManager::Initialize()
	{
		PlayScene playscene1;
		playscene1.Initialize();
	}
	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

	std::map<std::wstring, Scene*> SceneManager::mScene;
	Scene* SceneManager::mActiveScene = nullptr;
}