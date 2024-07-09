#pragma once
#pragma once
#include "CommonInclude.h"


namespace dh {
	class Entity
	{
	public:
		Entity();
		~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; }

	private:
		std::wstring mName;
	};

}