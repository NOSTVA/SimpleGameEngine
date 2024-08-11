#include "Scene.h"

void engine::Scene::AddGameObject(std::shared_ptr<GameObject> obj) {
	m_gameObjects.push_back(std::move(obj));
}

void engine::Scene::Start() {
	for (auto& obj : m_gameObjects) {
		obj->Start();
	}
}

void engine::Scene::Update(float deltaTime) {
	for (auto& obj : m_gameObjects) {
		obj->Update(deltaTime);
	}
}

void engine::Scene::Render(sf::RenderWindow& window) {
	for (auto& obj : m_gameObjects) {
		obj->Render(window);
	}
}