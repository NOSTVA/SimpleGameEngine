#pragma once
#include <SFML/Graphics.hpp>

namespace engine {
	class Frame {
	public:
		Frame(sf::Sprite& sprite, float duration = 0.1f) : m_sprite(sprite), m_duration(duration) { }
		sf::Sprite& m_sprite;
		float m_duration;
	};

	class Animation {
	public:
		Animation(bool loop = true) : m_loop(loop) {}
		void AddFrame(const Frame& frame);
		const Frame& GetFrame(std::size_t index) const;
		std::size_t GetFrameCount() const;
		bool IsLooping() const {
			return m_loop;
		}

	private:
		std::vector<Frame> m_frames;
		bool m_loop;
	};
}
