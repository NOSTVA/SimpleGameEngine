#include "SpriteRenderer.h"


engine::SpriteRenderer::SpriteRenderer(const sf::Sprite& sprite) {
	SetSprite(sprite);
}

void engine::SpriteRenderer::Start() {

};

void engine::SpriteRenderer::Update(float deltaTime) {

}

const std::shared_ptr<sf::Sprite> engine::SpriteRenderer::GetSprite() {
	return m_sprite;
}

void engine::SpriteRenderer::SetSprite(const sf::Sprite& sprite) {
	m_sprite = std::make_shared<sf::Sprite>(sprite);
}