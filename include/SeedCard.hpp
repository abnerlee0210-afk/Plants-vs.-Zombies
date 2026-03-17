//
// Created by hankl on 2026/3/13.
//

#ifndef SEEDCARD_HPP
#define SEEDCARD_HPP

#include "pch.hpp"

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

// 植物種類
enum class PlantType {
    PEASHOOTER,
    SUNFLOWER
};

class SeedCard : public Util::GameObject {
public:
    SeedCard(const std::string& imagePath,
             PlantType plantType,
             int cost,
             const glm::vec2& position);

    PlantType GetPlantType() const { return m_PlantType; }
    int GetCost() const { return m_Cost; }

    bool ContainsPoint(const glm::vec2& point) const;

    void SetSelected(bool selected);
    bool IsSelected() const { return m_Selected; }

private:
    PlantType m_PlantType;
    int m_Cost;
    bool m_Selected;

    float m_Width;
    float m_Height;
};

#endif //SEEDCARD_HPP
