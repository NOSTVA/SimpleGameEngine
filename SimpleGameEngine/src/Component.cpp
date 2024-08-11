#include "Component.h"
#include "GameObject.h"

void engine::ComponentBase::SetGameObject(engine::GameObject* gameObject) {
	this->gameObject = gameObject;
};