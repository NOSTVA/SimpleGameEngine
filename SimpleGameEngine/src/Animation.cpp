#include "Animation.h"
#include <iostream>

namespace engine {
	void Animation::AddFrame(std::shared_ptr<Frame> frame) {
		m_frames.push_back(frame);
	}

	std::shared_ptr<Frame> Animation::GetFrame(std::size_t index) const {
		if (index >= m_frames.size()) {
			throw std::out_of_range("Frame index out of range.");
		}
		return m_frames.at(index);
	}

	std::size_t Animation::GetFrameCount() const {
		return m_frames.size();
	}

	bool Animation::IsLooping() const {
		return m_loop;
	}
}
