#include "Scene.h"
namespace engine {
	void Scene::Start() {
		for (auto& obj : m_gameObjects) {
			obj->Start();
		}
	}

	void Scene::Update(float deltaTime) {
		for (auto& obj : m_gameObjects) {
			obj->Update(deltaTime);
		}
	}

	void Scene::Render(sf::RenderWindow& window) {
		for (auto& obj : m_gameObjects) {
			obj->Render(window);
		}
	}

	void Scene::AddGameObject(std::shared_ptr<GameObject> obj) {
		m_gameObjects.push_back(std::move(obj));
	}
}