#include "SimpleGameEngine.h"

int main() {
	engine::Game game;
	auto scene = std::make_shared<engine::Scene>();
	auto player = std::make_shared<engine::GameObject>();

	player->AddComponent<engine::SpriteRenderer>();
	player->AddComponent<engine::Animator>();

	auto animation = std::make_shared<engine::Animation>();
	engine::SpriteSheet walking_sheet("Assets/Character/Textures/walkcycle/BODY_male.png", { 64, 64 });

	for (int i = 1; i < 9; i++) animation->AddFrame(engine::Frame(walking_sheet.GetSprite(i), 0.1));
	auto animator = player->GetComponent<engine::Animator>();
	animator->SetAnimation(animation);

	scene->AddGameObject(player);

	game.SetCurrentScene(scene);
	game.Run();
}