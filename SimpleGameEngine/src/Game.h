#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"

namespace engine {
	class Game {
	public:
		Game();
		void Run();
		sf::RenderWindow& GetWindow();

	private:
		void InitializeGame();
		void ProcessEvents();
		void Update(float deltaTime);
		void Render();
		sf::ContextSettings m_settings;
		sf::RenderWindow m_window;

	public:
		void SetCurrentScene(std::shared_ptr<Scene> scene);
		std::shared_ptr<Scene> m_scene;
	};
}

