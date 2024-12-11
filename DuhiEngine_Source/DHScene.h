#pragma once
#include "DHEntity.h"
#include "DHGameObject2p.h"
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

		void AddGameObject(GameObject2p* gameObj2p);

	private:
		std::vector<GameObject2p*> mGameObjects2p;
	};

}