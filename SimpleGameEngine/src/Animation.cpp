#include "Animation.h"

void engine::Animation::AddFrame(const Frame& frame){
	m_frames.push_back(frame);
}

const engine::Frame& engine::Animation::GetFrame(std::size_t index) const {
	return m_frames.at(index);
}

std::size_t engine::Animation::GetFrameCount() const {
	return m_frames.size();
}