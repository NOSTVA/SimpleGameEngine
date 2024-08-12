#pragma once
#include "Component.h"
#include "SpriteRenderer.h"
#include "Animation.h"

namespace engine {
	class Animator : public Component<Animator> {
	public:
		Animator();
		virtual void Start();
		virtual void Update(float deltaTime);

	public:
		void SetAnimation(std::shared_ptr<Animation> animation);

	private:
		std::shared_ptr<SpriteRenderer> m_renderer;
		std::shared_ptr<Animation> m_currentAnimation;
		std::size_t m_currentFrameIndex;
		float m_elapsedTime;
	};
}

