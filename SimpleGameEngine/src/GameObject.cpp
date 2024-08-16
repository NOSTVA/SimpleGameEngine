#include "GameObject.h"
#include "Component.h"

namespace engine {
	GameObject::GameObject() {
		this->transform = AddComponent<Transform>();
	}

	void GameObject::Start() {
		for (const auto& component : m_components) {
			component->Start();
		}
	}

	void GameObject::Update(float deltaTime) {
		for (const auto& component : m_components) {
			component->Update(deltaTime);
		}
	}

	void GameObject::Render(sf::RenderWindow& window) {
		auto renderer = GetComponent<SpriteRenderer>();
		auto transform = GetComponent<Transform>();

		if (renderer != nullptr && transform != nullptr) {
			const auto& sprite = renderer->GetSprite();

			if (sprite != nullptr) {
				sprite->setPosition(transform->position);
				sprite->setRotation(transform->rotation);
				sprite->setScale(transform->scale);
				window.draw(*sprite);
			}
		}
	}
}