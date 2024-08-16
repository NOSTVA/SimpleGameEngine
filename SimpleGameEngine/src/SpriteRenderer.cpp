#include "SpriteRenderer.h"

namespace engine {
	SpriteRenderer::SpriteRenderer(std::shared_ptr<sf::Sprite> sprite) {
		SetSprite(sprite);
	}

	void SpriteRenderer::Start() {

	};

	void SpriteRenderer::Update(float deltaTime) {

	}

	const std::shared_ptr<sf::Sprite> SpriteRenderer::GetSprite() {
		return m_sprite;
	}

	void SpriteRenderer::SetSprite(std::shared_ptr<sf::Sprite> sprite) {
		m_sprite = std::move(sprite);
	}
}