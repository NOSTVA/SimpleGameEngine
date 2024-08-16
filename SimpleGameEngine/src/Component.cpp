#include "Component.h"
#include "GameObject.h"

namespace engine {
	void ComponentBase::SetGameObject(GameObject* gameObject) {
		this->gameObject = gameObject;
	};
}