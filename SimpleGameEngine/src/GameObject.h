#pragma once
#include <vector>
#include "Component.h"
#include "Transform.h"
#include "SpriteRenderer.h"

namespace engine {
	class GameObject {
	public:
		GameObject();
		void Start();
		void Update(float deltaTime);
		void Render(sf::RenderWindow& window);

	public:
		std::shared_ptr<Transform> transform = nullptr;

		template <class ComponentType, typename... Args>
		std::shared_ptr<ComponentType> AddComponent(Args&&... params);

		template <class ComponentType>
		std::shared_ptr<ComponentType> GetComponent();

		template<class ComponentType>
		bool RemoveComponent();

		template<class ComponentType>
		std::vector<std::shared_ptr<ComponentType>> GetComponents();

		template<class ComponentType>
		int RemoveComponents();

	private:
		std::vector<std::shared_ptr<ComponentBase>> m_components;
	};

	template<class ComponentType, typename... Args>
	std::shared_ptr<ComponentType> GameObject::AddComponent(Args&&... params) {
		if (ComponentType::type == SpriteRenderer::type) {
			auto existingComponent = GetComponent<ComponentType>();
			if (existingComponent) {
				throw std::runtime_error("Component of this type already exists.");
			}
		}

		auto component = std::make_shared<ComponentType>(std::forward<Args>(params)...);
		component->SetGameObject(this);
		m_components.emplace_back(component);
		return component;
	}

	template <class ComponentType>
	std::shared_ptr<ComponentType> GameObject::GetComponent() {
		for (auto&& component : m_components) {
			if (component->getType() == ComponentType::type)
				return std::static_pointer_cast<ComponentType>(component);
		}
		return nullptr;
	}

	template<class ComponentType>
	bool GameObject::RemoveComponent() {
		if (m_components.empty())
			return false;

		auto& index = std::find_if(m_components.begin(), m_components.end(),
			[](auto& component) {
				return component->getType() == ComponentType::type;
			});

		bool success = index != m_components.end();

		if (success)
			m_components.erase(index);

		return success;
	}

	template<class ComponentType>
	std::vector<std::shared_ptr<ComponentType>> GameObject::GetComponents() {
		std::vector<ComponentType*> componentsOfType;

		for (auto&& component : m_components) {
			if (component->getType() == ComponentType::type)
				componentsOfType.emplace_back(std::static_pointer_cast<ComponentType>(component));
		}

		return componentsOfType;
	}

	template<class ComponentType>
	int GameObject::RemoveComponents() {
		if (m_components.empty()) {
			return 0;
		}

		int numRemoved = 0;
		bool success = false;

		do {
			auto& index = std::find_if(m_components.begin(), m_components.end(),
				[](auto& component) {
					return component->getType() == ComponentType::type;
				});

			success = index != m_components.end();

			if (success) {
				m_components.erase(index);
				++numRemoved;
			}

		} while (success);

		return numRemoved;
	}
}