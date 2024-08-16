#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

namespace engine {

	class Frame {
	public:
		Frame(std::shared_ptr<sf::Sprite> sprite, float duration = 0.1f) :m_sprite(sprite), m_duration(duration) {}

		Frame(const Frame& other) : m_sprite(other.m_sprite), m_duration(other.m_duration) {}

		Frame(Frame&& other) noexcept : m_sprite(other.m_sprite), m_duration(other.m_duration) {}

		Frame& operator=(const Frame& other) {
			if (this != &other) {
				m_sprite = other.m_sprite;
				m_duration = other.m_duration;
			}
			return *this;
		}

		Frame& operator=(Frame&& other) noexcept {
			if (this != &other) {
				m_sprite = std::move(other.m_sprite);
				m_duration = other.m_duration;
			}
			return *this;
		}

		std::shared_ptr<sf::Sprite> GetSprite() const { return m_sprite; }
		float GetDuration() const { return m_duration; }

	private:
		std::shared_ptr<sf::Sprite> m_sprite;
		float m_duration;
	};

	class Animation {
	public:
		explicit Animation(bool loop = true) : m_loop(loop) {}

		void AddFrame(std::shared_ptr<Frame> frame);
		void AddFrames(const std::vector<std::shared_ptr<Frame>>& frames);
		std::shared_ptr<Frame> GetFrame(std::size_t index) const;
		std::size_t GetFrameCount() const;
		bool IsLooping() const;

	private:
		std::vector<std::shared_ptr<Frame>> m_frames;
		bool m_loop;
	};
}