#include "SimpleGameEngine.h"
#include <iostream>


std::shared_ptr<engine::Animation> LoadAnimation(int start, int end, engine::SpriteSheet& sheet) {
	auto animation = std::make_shared<engine::Animation>();

	for (int i = start; i < end; i++) {
		if (i == start) {
			animation->AddFrame(std::make_shared<engine::Frame>(engine::Frame(sheet.GetSprite(i), 0)));
		}
		animation->AddFrame(std::make_shared<engine::Frame>(engine::Frame(sheet.GetSprite(i))));
	}

	return animation;
}

// custom component
class PlayerController : public engine::Component<PlayerController> {
	enum class Direction { Top, Bottom, Left, Right };

	Direction lastDirection = Direction::Bottom;

	float speed = 3.0f;

	engine::SpriteSheet walking_sheet = engine::SpriteSheet("Assets/Character/Textures/walkcycle/BODY_male.png", { 64, 64 });

	std::shared_ptr<engine::Animator> animator;

	std::shared_ptr<engine::Animation> walking_top_anim;
	std::shared_ptr<engine::Animation> walking_left_anim;
	std::shared_ptr<engine::Animation> walking_bottom_anim;
	std::shared_ptr<engine::Animation> walking_right_anim;

	std::shared_ptr<engine::Animation> idle_top_anim;
	std::shared_ptr<engine::Animation> idle_left_anim;
	std::shared_ptr<engine::Animation> idle_bottom_anim;
	std::shared_ptr<engine::Animation> idle_right_anim;

	std::shared_ptr<engine::Animation> current_anim = idle_bottom_anim;



	void Start() {
		gameObject->transform->scale = sf::Vector2f(2, 2);

		animator = gameObject->GetComponent<engine::Animator>();

		idle_top_anim = LoadAnimation(0, 1, walking_sheet);
		idle_left_anim = LoadAnimation(9, 10, walking_sheet);
		idle_bottom_anim = LoadAnimation(18, 19, walking_sheet);
		idle_right_anim = LoadAnimation(27, 28, walking_sheet);

		walking_top_anim = LoadAnimation(1, 9, walking_sheet);
		walking_left_anim = LoadAnimation(10, 18, walking_sheet);
		walking_bottom_anim = LoadAnimation(19, 27, walking_sheet);
		walking_right_anim = LoadAnimation(28, 36, walking_sheet);

		if (animator != nullptr) animator->SetAnimation(current_anim);
	}

	void Update(float deltaTime) {
		bool isMoving = false;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			gameObject->transform->position.y -= speed;
			if (animator != nullptr && current_anim != walking_top_anim) {
				animator->SetAnimation(walking_top_anim);
				current_anim = walking_top_anim;
				lastDirection = Direction::Top;
			}
			isMoving = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			gameObject->transform->position.y += speed;
			if (animator != nullptr && current_anim != walking_bottom_anim) {
				animator->SetAnimation(walking_bottom_anim);
				current_anim = walking_bottom_anim;
				lastDirection = Direction::Bottom;
			}
			isMoving = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			gameObject->transform->position.x -= speed;
			if (animator != nullptr && current_anim != walking_left_anim) {
				animator->SetAnimation(walking_left_anim);
				current_anim = walking_left_anim;
				lastDirection = Direction::Left;
			}
			isMoving = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			gameObject->transform->position.x += speed;
			if (animator != nullptr && current_anim != walking_right_anim) {
				animator->SetAnimation(walking_right_anim);
				current_anim = walking_right_anim;
				lastDirection = Direction::Right;
			}
			isMoving = true;
		}

		// If no movement key is pressed, transition to the idle animation based on the last direction
		if (!isMoving) {
			switch (lastDirection) {
			case Direction::Top:
				if (current_anim != idle_top_anim) {
					animator->SetAnimation(idle_top_anim);
					current_anim = idle_top_anim;
				}
				break;
			case Direction::Bottom:
				if (current_anim != idle_bottom_anim) {
					animator->SetAnimation(idle_bottom_anim);
					current_anim = idle_bottom_anim;
				}
				break;
			case Direction::Left:
				if (current_anim != idle_left_anim) {
					animator->SetAnimation(idle_left_anim);
					current_anim = idle_left_anim;
				}
				break;
			case Direction::Right:
				if (current_anim != idle_right_anim) {
					animator->SetAnimation(idle_right_anim);
					current_anim = idle_right_anim;
				}
				break;
			}
		}
	}
};

int main() {
	engine::Game game;

	auto player1 = std::make_shared<engine::GameObject>();
	player1->AddComponent<engine::SpriteRenderer>();
	player1->AddComponent<engine::Animator>();
	player1->AddComponent<PlayerController>();

	auto scene = std::make_shared<engine::Scene>();
	scene->AddGameObject(player1);

	game.SetCurrentScene(scene);
	game.Run();
}