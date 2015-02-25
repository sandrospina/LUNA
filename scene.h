#include <Box2D/Box2D.h>
#include <SDL.h>
#include <vector>
#include <BGLayer>

class Scene
{
public:

    bool usesBackgroundTexture;
    std::vector<BGLayer> *bLayers;

    Scene();
    void AddBackgroundLayer(BGLayer * p_bLayer);
};