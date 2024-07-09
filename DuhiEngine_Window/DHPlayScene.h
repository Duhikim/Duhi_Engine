#pragma once
#include "..\\DuhiEngine_Source\DHScene.h"

namespace dh {
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();


		void Initialize() override;
		void Update() override;
		void LateUpdate()override;
		void Render(HDC hdc)override;

	private:
		/*std::vector<GameObject*> mGameObjects;
		std::vector<DinoObject*> mDinoObjects;*/
	};

}