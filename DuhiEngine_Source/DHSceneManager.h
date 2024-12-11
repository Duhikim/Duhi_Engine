#pragma once
#include "DHScene.h"


namespace dh {
	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();

		template <typename T>
		static Scene* CreatScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));
			
			return scene;
		}

		static Scene* LoadScene(const std::wstring& name)
		{
			std::map<std::wstring, Scene*>::iterator iter 
				= mScene.find(name);

			if (iter == mScene.end()) 
				return nullptr;

			mActiveScene = iter->second;

			return iter->second;
		}
		static bool SetActiveScene(const std::wstring& name);
		//static Scene* LoadScene(const std::wstring& name);

		//static Scene* GetActiveScene() { return mActiveScene; }
		//static Scene* GetDontDestroyOnLoad() { return mDontDestroyOnLoad; }
		//static std::vector<GameObject2p*> GetGameObjects(eLayerType layer);

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:		
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
		//static Scene* mDontDestroyOnLoad;
	};

}