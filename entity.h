#include <Box2D/Box2D.h>

class Entity
{
    public:
        int id;
        b2BodyDef bodyDef;
        b2Body *body;
        b2PolygonShape bodyShape;
        b2FixtureDef fixtureDef;

        Entity(int p_id, float p_posX, float p_posY, float p_angle);
};