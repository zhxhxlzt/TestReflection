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


void TestCompOp() {
	GameObject gb;
	auto c1 = gb.AddComponent<Comp1>();
	auto c2 = gb.AddComponent<Comp2>();

	auto c3 = c1->GetComponent<Component>();
}

void TestCallMethod() {
	class Box : public Object
	{
		META_OBJECT(Box, Object) {
			REGISTER_FUNC(SetProperty);
			REGISTER_FUNC(GetScaledVolumn);
			REGISTER_FUNC(GetVolumn);
			REGISTER_FUNC(Clear);
		}
	public:
		META_VOID_FUNC_P(SetProperty, { int length; int width; int height; }) {
			length = args.length;
			width = args.width;
			height = args.height;
		}

		META_FUNC(GetScaledVolumn, int, int, scale) {
			return length * width * height * scale;
		}

		META_FUNC_VOID(GetVolumn, int) {
			return length * width * height;
		}

		META_VOID_FUNC_VOID(Clear) {
			length = width = height = 0;
		}

	private:
		int length;
		int width;
		int height;

	};
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