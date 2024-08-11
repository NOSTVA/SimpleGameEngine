#include "SpriteSheet.h"

engine::SpriteSheet::SpriteSheet(const std::string& fileName, const sf::Vector2u& sprite_size) {
	m_texture = std::make_shared<sf::Texture>();
	if (m_texture->loadFromFile(fileName)) {
		sf::Vector2u texture_size = m_texture->getSize();
		unsigned int cols = texture_size.x / sprite_size.x;
		unsigned int rows = texture_size.y / sprite_size.y;

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				auto sprite = std::make_shared<sf::Sprite>();
				sprite->setTexture(*m_texture);
				sprite->setTextureRect(sf::IntRect(j * sprite_size.x, i * sprite_size.y, sprite_size.x, sprite_size.y));
				AddSprite(std::move(sprite));
			}
		}
	}
}

sf::Sprite& engine::SpriteSheet::GetSprite(unsigned int index) {
	return *m_sprites[index];
}

std::vector<std::shared_ptr<sf::Sprite>>& engine::SpriteSheet::GetSprites() {
	return m_sprites;
}

void engine::SpriteSheet::AddSprite(std::shared_ptr<sf::Sprite> sprite) {
	m_sprites.push_back(std::move(sprite));
}