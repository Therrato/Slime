#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include <iostream>
#include <vector>
#include "Collider.h"

class CollisionDetector
{
    public:
        CollisionDetector();
        virtual ~CollisionDetector();
        bool detectCollision();
    protected:
    private:
        std::vector<Collider> collisionObjects;
};

#endif // COLLISIONDETECTOR_H
