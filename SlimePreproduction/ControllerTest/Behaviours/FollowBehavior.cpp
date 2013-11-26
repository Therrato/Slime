#include "FollowBehavior.hpp"
#include "../glm.hpp"

FollowBehavior::FollowBehavior(GameObject *par,GameObject *tar):Behaviour( par ), target (tar)
{
    //ctor
}

FollowBehavior::~FollowBehavior()
{
    //dtor
}

void FollowBehavior::update( float step )
{
    glm::mat4 newpos  = target->getTo();
    parent->moveTo(target->getTo());
    parent->translate(glm::vec3(0,10,-10));
    parent->transform = glm::inverse(glm::lookAt(parent->getLocation(),target->getLocation(),glm::vec3(0,1,0)));

    /*
    glm::mat4 campos= glm::lookAt(newpos,target->getLocation(),glm::vec3(1,1,1));

    parent->moveTo(campos);
*/
}
