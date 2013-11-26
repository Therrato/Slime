#ifndef FOLLOWBEHAVIOR_H
#define FOLLOWBEHAVIOR_H

#include "../Behaviour.hpp"
#include "../GameObject.hpp"
#include "../glm.hpp"

class FollowBehavior : public Behaviour
{
    public:
        FollowBehavior(GameObject * par,GameObject * tar);
        virtual ~FollowBehavior();
        virtual void update( float step );

    protected:
    private:
        GameObject * target;
};

#endif // FOLLOWBEHAVIOR_H
