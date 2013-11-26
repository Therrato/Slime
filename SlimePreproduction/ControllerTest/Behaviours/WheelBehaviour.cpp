#include "WheelBehaviour.hpp"

#include <sfml/window.hpp>
#include <iostream>
#include "../glm.hpp"
#include "../GameObject.hpp"

WheelBehaviour::WheelBehaviour( GameObject * aParent, bool _isFrontWheel )
:	Behaviour( aParent )
{
	isFrontWheel = _isFrontWheel;
}

WheelBehaviour::~WheelBehaviour()
{
	//dtor
}

void WheelBehaviour::update( float step )
{
    if(isFrontWheel){
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right )) {

	}
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left )) {

	}

    }
	parent->rotate( step * 45, glm::vec3( 1.0f, 0.0f, 0.0f ) ); // rotates 45° per second
}


