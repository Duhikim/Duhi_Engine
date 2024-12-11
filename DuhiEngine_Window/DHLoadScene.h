#pragma once
#include "..\\DuhiEngine_Source\\DHSceneManager.h"
#include "DHPlayScene.h"
#include "DHEndScene.h"
#include "DHTitleScene.h"



namespace dh {
	void LoadScenes()
	{
		SceneManager::CreatScene<PlayScene>(L"Play Scene");
		SceneManager::CreatScene<EndScene>(L"End Scene");
		SceneManager::CreatScene<TitleScene>(L"Title Scene");

		SceneManager::LoadScene(L"Play Scene");
	}
}