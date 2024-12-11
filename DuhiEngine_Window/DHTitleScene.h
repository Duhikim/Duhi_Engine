#pragma once
#include "..\DuhiEngine_Source\DHScene.h"
#include "..\DuhiEngine_Source\DHGameObject2p.h"

namespace dh {
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}