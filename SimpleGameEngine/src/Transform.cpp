#include "Transform.h"


engine::Transform::Transform() : position(sf::Vector2f(0, 0)), scale(sf::Vector2f(1, 1)), rotation(0.0f) {}

engine::Transform::Transform(sf::Vector2f position, sf::Vector2f scale, float rotation) : position(position), scale(scale), rotation(rotation) {}

void engine::Transform::Start() {};

void engine::Transform::Update(float deltaTime) {}