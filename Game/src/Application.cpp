#include "SimpleGameEngine.h"
#include <iostream>

// custom component
class PlayerController : public engine::Component<PlayerController> {
	float speed = 1.0f;
	engine::SpriteSheet walking_sheet = engine::SpriteSheet("Assets/Character/Textures/walkcycle/BODY_male.png", { 64, 64 });
	std::shared_ptr<engine::Animator> animator;

	std::shared_ptr<engine::Animation> walking_top_anim = std::make_shared<engine::Animation>();
	std::shared_ptr<engine::Animation> walking_left_anim = std::make_shared<engine::Animation>();
	std::shared_ptr<engine::Animation> walking_bottom_anim = std::make_shared<engine::Animation>();
	std::shared_ptr<engine::Animation> walking_right_anim = std::make_shared<engine::Animation>();

	std::shared_ptr<engine::Animation> idle_top_anim = std::make_shared<engine::Animation>();
	std::shared_ptr<engine::Animation> idle_left_anim = std::make_shared<engine::Animation>();
	std::shared_ptr<engine::Animation> idle_bottom_anim = std::make_shared<engine::Animation>();
	std::shared_ptr<engine::Animation> idle_right_anim = std::make_shared<engine::Animation>();

	std::shared_ptr<engine::Animation> current_anim = idle_bottom_anim;

	enum class Direction { Top, Bottom, Left, Right };

	Direction lastDirection = Direction::Bottom;

	void Start() {
		animator = gameObject->GetComponent<engine::Animator>();

		idle_top_anim->AddFrame(std::make_shared<engine::Frame>(engine::Frame(walking_sheet.GetSprite(0))));
		idle_left_anim->AddFrame(std::make_shared<engine::Frame>(engine::Frame(walking_sheet.GetSprite(9))));
		idle_bottom_anim->AddFrame(std::make_shared<engine::Frame>(engine::Frame(walking_sheet.GetSprite(18))));
		idle_right_anim->AddFrame(std::make_shared<engine::Frame>(engine::Frame(walking_sheet.GetSprite(27))));

		for (int i = 1; i < 9; i++) walking_top_anim->AddFrame(std::make_shared<engine::Frame>(engine::Frame(walking_sheet.GetSprite(i))));
		for (int i = 10; i < 17; i++) walking_left_anim->AddFrame(std::make_shared<engine::Frame>(engine::Frame(walking_sheet.GetSprite(i))));
		for (int i = 19; i < 26; i++) walking_bottom_anim->AddFrame(std::make_shared<engine::Frame>(engine::Frame(walking_sheet.GetSprite(i))));
		for (int i = 28; i < 35; i++) walking_right_anim->AddFrame(std::make_shared<engine::Frame>(engine::Frame(walking_sheet.GetSprite(i))));

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