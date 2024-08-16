#include "Transform.h"

namespace engine {
	Transform::Transform() : position(sf::Vector2f(0, 0)), scale(sf::Vector2f(1, 1)), rotation(0.0f) {}

	Transform::Transform(sf::Vector2f position, sf::Vector2f scale, float rotation) : position(position), scale(scale), rotation(rotation) {}

	void Transform::Start() {};

	void Transform::Update(float deltaTime) {}
}