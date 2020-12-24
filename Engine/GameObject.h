#pragma once

#include "Object.h"



class Component;
class GameObject : public Object
{
	META_OBJECT(GameObject, Object);

public:
	template<typename T>
	T* AddComponent()
	{
		auto comp = std::make_unique<T>();
		InitComponent(comp.get());
		m_comps.emplace_back(std::move(comp));
		return static_cast<T*>(m_comps.back().get());
		
	}

	void InitComponent(Component* comp);
	
	template<typename T>
	T* GetComponent()
	{
		static const T t_comp;
		for (auto& comp : m_comps)
		{
			if (comp->GetRealClassName() == t_comp.GetRealClassName() ||
				IsBaseClassOf(*comp, t_comp))
			{
				return static_cast<T*>(comp.get());
			}
		}
		return nullptr;
	}

private:

	std::vector<std::unique_ptr<Component>> m_comps;
	
};