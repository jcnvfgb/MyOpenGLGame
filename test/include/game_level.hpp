#ifndef GAMELEVEL_H
#define GAMELEVEL_H
#include <vector>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "game_object.hpp"
#include "sprite_renderer.hpp"
#include "resource_manager.hpp"

class GameLevel {
public:
    std::vector<GameObject> Bricks;

    GameLevel() {}

    void Load(const char* file, unsigned int levelWidth, unsigned int levelHeight);

    void Draw(SpriteRenderer& renderer);

    bool IsCompleted();
private:
    void init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight);
};

#endif