#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <string>

namespace engine {
	class SpriteSheet {
	public:
		SpriteSheet(const std::string& fileName, const sf::Vector2u& sprite_size);

	public:
		sf::Sprite& GetSprite(unsigned int index);
		std::vector<std::shared_ptr<sf::Sprite>>& GetSprites();

	private:
		void AddSprite(std::shared_ptr<sf::Sprite> sprite);

	private:
		std::shared_ptr<sf::Texture> m_texture;
		std::vector<std::shared_ptr<sf::Sprite>> m_sprites;
	};
}

