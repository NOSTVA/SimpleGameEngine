#pragma once
#include "Component.h"
#include "GameObject.h"

namespace engine {
	class Scene {
	public:
		Scene() = default;
		~Scene() = default;

	public:
		void AddGameObject(std::shared_ptr<GameObject> obj);
		std::vector<std::shared_ptr<GameObject>> m_gameObjects;

	public:
		void Start();
		void Update(float deltaTime);
		void Render(sf::RenderWindow& window);
	};
}
