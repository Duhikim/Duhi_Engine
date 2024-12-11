#include "DHSceneManager.h"

namespace dh {

	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;
	//Scene* SceneManager::mDontDestroyOnLoad = nullptr;
	

	SceneManager::SceneManager()	
	{}
	SceneManager::~SceneManager()
	{}
	
	bool SceneManager::SetActiveScene(const std::wstring& name)
	{
		auto iter = mScene.find(name);
		if (iter == mScene.end()) return false;

		mActiveScene = iter->second;

		return true;
	}

	//Scene* SceneManager::LoadScene(const std::wstring& name)
	//{
	//	//Not built yet
	//}



	void SceneManager::Initialize()
	{
	
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
	
}