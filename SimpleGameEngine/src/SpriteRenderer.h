#pragma once
#include "Component.h"
#include "SFML/Graphics.hpp"

namespace engine {
	class SpriteRenderer : public Component<SpriteRenderer> {
	public:
		SpriteRenderer() = default;
		SpriteRenderer(const sf::Sprite& sprite);
		virtual void Start();
		virtual void Update(float deltaTime);

	public:
		const std::shared_ptr<sf::Sprite> GetSprite();
		void SetSprite(const sf::Sprite& sprite);

	private:
		std::shared_ptr<sf::Sprite> m_sprite = nullptr;
	};
}
