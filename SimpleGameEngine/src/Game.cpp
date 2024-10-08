#include "Game.h"

namespace engine {
	Game::Game() : m_settings(), m_window(sf::VideoMode(1280, 600), "Untitled", sf::Style::Default, m_settings), m_scene(nullptr) {
		m_settings.antialiasingLevel = 8;
		m_window.setFramerateLimit(60);
	}

	sf::RenderWindow& Game::GetWindow() {
		return m_window;
	}

	void Game::SetCurrentScene(std::shared_ptr<Scene> scene) {
		m_scene = std::move(scene);
	}

	void Game::Run() {
		sf::Clock clock;
		InitializeGame();
		while (m_window.isOpen()) {
			sf::Time deltaTime = clock.restart();
			ProcessEvents();
			Update(deltaTime.asSeconds());
			Render();
		}
	}

	void Game::InitializeGame() {
		if (m_scene != nullptr)
			m_scene->Start();
	}

	void Game::ProcessEvents() {
		sf::Event event;
		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				m_window.close();
			}

			if (event.type == sf::Event::Resized) {
				sf::FloatRect view(0.0f, 0.0f, static_cast<float>(event.size.width), static_cast<float>(event.size.height));
				m_window.setView(sf::View(view));
			}
		}
	}

	void Game::Update(float deltaTime) {
		if (m_scene != nullptr)
			m_scene->Update(deltaTime);
	}

	void Game::Render() {
		m_window.clear();

		if (m_scene != nullptr)
			m_scene->Render(m_window);

		m_window.display();
	}
}