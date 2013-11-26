#ifndef WHEELBEHAVIOUR_H
#define WHEELBEHAVIOUR_H

#include "../Behaviour.hpp"

class WheelBehaviour : public Behaviour
{
	public:
		WheelBehaviour( GameObject * aParent, bool _isFrontWheel );
		virtual ~WheelBehaviour();

		virtual void update( float step );
		void setRotateDistance(const float distan);

    private:
        float wheelRotateDistance;
        bool isFrontWheel;

};

#endif // WHEELBEHAVIOUR_H

