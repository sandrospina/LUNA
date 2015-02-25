#include "entity.h"

Entity::Entity(int p_id, float p_posX, float p_posY, float p_angle)
{
    id = p_id;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(p_posX, p_posY);
    bodyDef.angle = p_angle;
}