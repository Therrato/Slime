#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>

#include "WASDBehaviour.hpp"
#include "../glm.hpp"
#include "../GameObject.hpp"


WASDBehaviour::WASDBehaviour( GameObject * aParent, sf::Window * aWindow )
:	Behaviour( aParent ), window( aWindow )
{

    xc = new XController(0);
    xc->update();
    if( xc->isConnected()){
        xcon = true;
        std::cout << "controller conected"<< std::endl;
    }
    else {
        xcon = false;
        std::cout << "No Controller Selected"<< std::endl;
    }
}

WASDBehaviour::~WASDBehaviour()
{
}
void WASDBehaviour::update( float step )
{
    xc->update();
    xcon = xc->isConnected();
    if (xcon){
    float speed = 5.0f;
    //std::cout<<parent->getLocation()<<std::endl;
    float rotatingSpeed = -135.0f*(xc->getRightStickState().dirX*xc->getRightStickState().magnitude)*step;

    speed += speed * xc->getLeftTriggerState();
	parent->translate(glm::vec3(-speed*(xc->getLeftStickState().dirX*xc->getLeftStickState().magnitude)*step,0.0f,speed*(xc->getLeftStickState().dirY*xc->getLeftStickState().magnitude)*step));
	parent->rotate(rotatingSpeed,glm::vec3(0.0f,1.0f,0.0f));

    }
    else{
        xc = new XController(0);
    }



}
