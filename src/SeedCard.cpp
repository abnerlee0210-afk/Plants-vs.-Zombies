//
// Created by hankl on 2026/3/13.
//
#include "SeedCard.hpp"

SeedCard::SeedCard(const std::string& imagePath,
                   PlantType plantType,
                   int cost,
                   const glm::vec2& position)
    : Util::GameObject(std::make_shared<Util::Image>(imagePath), 30.0f),
      m_PlantType(plantType),
      m_Cost(cost),
      m_Selected(false),
      m_Width(65.0f),
      m_Height(90.0f) {
    m_Transform.translation = position;
}

bool SeedCard::ContainsPoint(const glm::vec2& point) const {
    const float left = m_Transform.translation.x;
    const float right = m_Transform.translation.x + m_Width;
    const float top = m_Transform.translation.y;
    const float bottom = m_Transform.translation.y + m_Height;

    return point.x >= left && point.x <= right &&
           point.y >= top && point.y <= bottom;
}

void SeedCard::SetSelected(bool selected) {
    m_Selected = selected;

    if (m_Selected) {
        m_Transform.scale = {1.1f, 1.1f};
    } else {
        m_Transform.scale = {1.0f, 1.0f};
    }
}