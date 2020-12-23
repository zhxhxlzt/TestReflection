#include "GameObject.h"
#include "Component.h"


class Comp1 : public Component
{
	META_OBJECT(Comp1, Component){};
	
};

class Comp2 : public Component
{
	META_OBJECT(Comp2, Component){};
};


class M
{
public:
	M()
	{
		printf("M inited\n");
	}

	void Say()
	{
		printf("Hello");
	}
	void Register_Say()
	{
		
	}
};

class N : public M
{
public:
	N()
	{
		printf("N inited");
	}
};





int main()
{
	M m;
	N n;
	GameObject gb;
	auto c1 = gb.AddComponent<Comp1>();
	auto c2 = gb.AddComponent<Comp2>();

	auto c3 = c1->GetComponent<Component>();

	Object obj;
	Object::GetMetaObjectInfo()->no_args_func_map["Nice"](&obj);

	return 0;
}