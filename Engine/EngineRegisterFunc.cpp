#include "Component.h" 
void Component::RegisterAllMethod() {
}
void Comp1::RegisterAllMethod() {
}
void Comp2::RegisterAllMethod() {
}
#include "GameObject.h" 
void GameObject::RegisterAllMethod() {
}
#include "Object.h" 
void Object::RegisterAllMethod() {
}
void Box::RegisterAllMethod() {
	REGISTER_FUNC(SetProperty);
	REGISTER_FUNC(GetScaledVolumn);
	REGISTER_FUNC(GetVolumn);
	REGISTER_FUNC(Clear);
}

