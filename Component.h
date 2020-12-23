#pragma once

#include "Object.h"

#include "GameObject.h"
class Component : public Object
{
	META_OBJECT(Component, Object){};

public:
	template<typename T>
	T* GetComponent()
	{
		return m_game_object->GetComponent<T>();
	}

private:
	friend class GameObject;
	GameObject* m_game_object;
};