#include "Animator.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include <iostream>;


namespace engine {
	Animator::Animator() : m_currentAnimation(nullptr), m_currentFrameIndex(0), m_elapsedTime(0.0f) {}

	void Animator::SetAnimation(std::shared_ptr<Animation> animation) {
		m_currentAnimation = animation;
		m_currentFrameIndex = 0;
		m_elapsedTime = 0.0f;
	}

	void Animator::Start() {
		m_renderer = gameObject->GetComponent<SpriteRenderer>();
	};

	void Animator::Update(float deltaTime) {
		if (m_currentAnimation == nullptr) return;

		m_elapsedTime += deltaTime;

		while (m_elapsedTime >= m_currentAnimation->GetFrame(m_currentFrameIndex)->GetDuration()) {
			m_elapsedTime -= m_currentAnimation->GetFrame(m_currentFrameIndex)->GetDuration();

			if (m_currentAnimation->IsLooping()) {
				m_currentFrameIndex = (m_currentFrameIndex + 1) % m_currentAnimation->GetFrameCount();
			}
			else {
				// If not looping and at the last frame, stop advancing
				if (m_currentFrameIndex < m_currentAnimation->GetFrameCount() - 1) {
					m_currentFrameIndex++;
				}
				else {
					// Stay on the last frame
					m_currentFrameIndex = m_currentAnimation->GetFrameCount() - 1;
				}
			}

			// Update the sprite renderer with the current frame's sprite
			if (m_renderer != nullptr) {
				m_renderer->SetSprite(m_currentAnimation->GetFrame(m_currentFrameIndex)->GetSprite());
			}
		}
	}
}
