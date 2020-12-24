#pragma once

#include "Object.h"

#include "GameObject.h"
class Component : public Object
{
	META_OBJECT(Component, Object);

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

class Comp1 : public Component
{
	META_OBJECT(Comp1, Component);

};

class Comp2 : public Component
{
	META_OBJECT(Comp2, Component);
};