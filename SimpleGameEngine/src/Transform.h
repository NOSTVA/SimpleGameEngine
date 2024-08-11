#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>

namespace engine {
	class Transform : public Component<Transform> {
	public:
		Transform();
		Transform(sf::Vector2f position, sf::Vector2f scale, float rotation);
		virtual void Start();
		virtual void Update(float deltaTime);

	public:
		sf::Vector2f position;
		sf::Vector2f scale;
		float rotation;
	};
}
