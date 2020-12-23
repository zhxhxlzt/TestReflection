#include "GameObject.h"
#include "Component.h"
void GameObject::InitComponent(Component* comp)
{
	comp->m_game_object = this;
}
