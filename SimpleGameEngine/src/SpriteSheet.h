#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>

namespace engine {
    class SpriteSheet {
    public:
        SpriteSheet() = default;
        SpriteSheet(const std::string& fileName, const sf::Vector2u& sprite_size);
        SpriteSheet(const SpriteSheet& other);
        SpriteSheet& operator=(const SpriteSheet& other);

        std::shared_ptr<sf::Sprite> GetSprite(unsigned int index) const;
        const std::vector<std::shared_ptr<sf::Sprite>>& GetSprites() const;

    private:
        void LoadTexture(const std::string& fileName);
        void GenerateSprites(const sf::Vector2u& sprite_size);

    private:
        std::shared_ptr<sf::Texture> m_texture;
        std::vector<std::shared_ptr<sf::Sprite>> m_sprites;
    };
}
