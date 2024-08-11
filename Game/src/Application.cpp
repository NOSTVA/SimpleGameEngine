#include "SimpleGameEngine.h"

int main() {
	engine::Game game;
	auto player = std::make_shared<engine::GameObject>();
	auto player2 = std::make_shared<engine::GameObject>();
	auto scene = std::make_shared<engine::Scene>();
	auto walkingAnim = std::make_shared<engine::Animation>();
	auto walkingAnim2 = std::make_shared<engine::Animation>();

	player->transform->position.x = 50.0f;

	auto animator = player->AddComponent<engine::Animator>();
	auto animator2 = player2->AddComponent<engine::Animator>();
	player->AddComponent<engine::SpriteRenderer>();
	player2->AddComponent<engine::SpriteRenderer>();

	engine::SpriteSheet walking_sheet("Assets/Character/Textures/walkcycle/BODY_male.png", { 64, 64 });

	for (int i = 1; i < 9; i++) 
		walkingAnim->AddFrame(engine::Frame(walking_sheet.GetSprite(i), 0.1));
	animator->SetAnimation(walkingAnim);

	for (int i = 10; i < 18; i++) 
		walkingAnim2->AddFrame(engine::Frame(walking_sheet.GetSprite(i), 0.1));
	animator2->SetAnimation(walkingAnim2);

	scene->AddGameObject(player);
	scene->AddGameObject(player2);

	game.SetCurrentScene(scene);
	game.Run();
}