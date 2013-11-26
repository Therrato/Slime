#ifndef COLLIDER_H
#define COLLIDER_H

#include "glm.hpp"


class Collider
{
    public:
        Collider();
        Collider(int radius, glm::mat4 wPos);
        virtual ~Collider();

        Collider getCollider();
        glm::mat4 worldPosition;


    protected:

    private:
        int radius;
        int getRadius();
};

#endif // COLLIDER_H
