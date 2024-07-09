#pragma once
#include "DHEntity.h"
#include "DHGameObject.h"
#include "DHDinoObject.h"

namespace dh {
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();


		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddDinoObject(DinoObject* dinoObj);

				
	protected:
		std::vector<GameObject*> mGameObjects;
		std::vector<DinoObject*> mDinoObjects;
	};

}
