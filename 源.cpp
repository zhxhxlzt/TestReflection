#include "GameObject.h"
#include "Component.h"





void TestCompOp() {
	GameObject gb;
	auto c1 = gb.AddComponent<Comp1>();
	auto c2 = gb.AddComponent<Comp2>();

	auto c3 = c1->GetComponent<Component>();
}

void TestCallMethod() {
	
	Box obj;
	auto metaInfo = obj.GetMetaObjectInfo();

	metaInfo->CallFunc(&obj, "SetProperty", Box::SetPropertyArgs{ 10, 20, 30 });
	int b = metaInfo->CallFunc<int, int>(&obj, "GetScaledVolumn", 20);
	int c = metaInfo->CallFunc<int>(&obj, "GetVolumn");
	metaInfo->CallFunc(&obj, "Clear");
}

int main()
{
	TestCallMethod();
	return 0;
}