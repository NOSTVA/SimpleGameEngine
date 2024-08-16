#include "SpriteSheet.h"

namespace engine {
    SpriteSheet::SpriteSheet(const std::string& fileName, const sf::Vector2u& sprite_size) {
        LoadTexture(fileName);
        GenerateSprites(sprite_size);
    }

    SpriteSheet::SpriteSheet(const SpriteSheet& other) {
        if (other.m_texture) {
            m_texture = std::make_shared<sf::Texture>(*other.m_texture);
        }

        m_sprites.reserve(other.m_sprites.size());
        for (const auto& sprite : other.m_sprites) {
            auto new_sprite = std::make_shared<sf::Sprite>(*sprite);
            new_sprite->setTexture(*m_texture);
            m_sprites.push_back(new_sprite);
        }
    }

    SpriteSheet& SpriteSheet::operator=(const SpriteSheet& other) {
        if (this == &other) return *this;

        if (other.m_texture) {
            m_texture = std::make_shared<sf::Texture>(*other.m_texture);
        }

        m_sprites.clear();
        m_sprites.reserve(other.m_sprites.size());
        for (const auto& sprite : other.m_sprites) {
            auto new_sprite = std::make_shared<sf::Sprite>(*sprite);
            new_sprite->setTexture(*m_texture);
            m_sprites.push_back(new_sprite);
        }

        return *this;
    }

    void SpriteSheet::LoadTexture(const std::string& fileName) {
        m_texture = std::make_shared<sf::Texture>();
        if (!m_texture->loadFromFile(fileName)) {
            throw std::runtime_error("Failed to load texture from file: " + fileName);
        }
    }

    void SpriteSheet::GenerateSprites(const sf::Vector2u& sprite_size) {
        sf::Vector2u texture_size = m_texture->getSize();
        unsigned int cols = texture_size.x / sprite_size.x;
        unsigned int rows = texture_size.y / sprite_size.y;

        m_sprites.reserve(cols * rows);

        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < cols; ++j) {
                auto sprite = std::make_shared<sf::Sprite>();
                sprite->setTexture(*m_texture);
                sprite->setTextureRect(sf::IntRect(j * sprite_size.x, i * sprite_size.y, sprite_size.x, sprite_size.y));
                m_sprites.push_back(sprite);
            }
        }
    }

    std::shared_ptr<sf::Sprite> SpriteSheet::GetSprite(unsigned int index) const {
        if (index >= m_sprites.size()) {
            throw std::out_of_range("Sprite index out of range.");
        }
        return m_sprites[index];
    }

    const std::vector<std::shared_ptr<sf::Sprite>>& SpriteSheet::GetSprites() const {
        return m_sprites;
    }

}
