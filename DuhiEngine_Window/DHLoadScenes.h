#pragma once
#include "..\\DuhiEngine_Source\DHSceneManager.h"
#include "DHPlayScene.h"

namespace dh {
	void LoadScenes()
	{
		SceneManager::CrateScene<PlayScene>(L"PlayScene");
		//SceneManager::CrateScene<EndScene>(L"EndScene");
		//SceneManager::CrateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}