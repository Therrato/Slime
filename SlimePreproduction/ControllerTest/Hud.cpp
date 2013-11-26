#include <cassert>
#include <iostream>
#include <cstdio>
#include <GL/glew.h>
#include "FPS.hpp"
#include "Hud.hpp"
#include "Time.hpp"

Hud::Hud( sf::RenderWindow * aWindow )
:	window( aWindow )
{
	assert ( window != NULL );

    if ( marvinTex.loadFromFile("models/marvin.png") ) { // when succesfull loaded
		marvin.setTexture( marvinTex); // provide sprite with texture
		marvin.setPosition(150,150); // put it somewhere anoying
    } else {
		std::cout << "Could not load sprite" << std::endl;
	}
    if ( cd3Tex.loadFromFile("models/3.png") ) { // when succesfull loaded
		cd3.setTexture( cd3Tex); // provide sprite with texture
		cd3.setPosition(350,350); // put it somewhere anoying
    } else {
		std::cout << "Could not load countdown 3" << std::endl;
	}
    if ( cd2Tex.loadFromFile("models/2.png") ) { // when succesfull loaded
		cd2.setTexture( cd2Tex); // provide sprite with texture
		cd2.setPosition(350,350); // put it somewhere anoying
    } else {
		std::cout << "Could not load countdown 2" << std::endl;
	}
    if ( cd1Tex.loadFromFile("models/1.png") ) { // when succesfull loaded
		cd1.setTexture( cd1Tex); // provide sprite with texture
		cd1.setPosition(350,350); // put it somewhere anoying
    } else {
		std::cout << "Could not load countdown 1" << std::endl;
	}
	counter = 3.0f;
	cdDone = false;
}

Hud::~Hud()
{
	//dtor
}

void Hud::draw()
{
	glDisable( GL_CULL_FACE ); // needed for text, dont know why
	char fps[] = "Test";
	sprintf( fps, "%4d", FPS::getFPS() ); // put fps in char array ( primitive string )
	sf::Text text( fps );
	//text.setFont(font); // when loaded other font
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::Yellow);
	text.setPosition( 10,10);

	// Draw it
	//std::cout << "Drawing text" << std::endl;
	assert ( window != NULL );
	window->pushGLStates();

		window->draw( text );
	window->popGLStates();
	countDown();
}

void Hud::countDown(){
    counter = counter - Time::step();

assert ( window != NULL );
    if(!cdDone){
	window->pushGLStates();
        if (counter>2)window->draw(cd3);
        else if (counter>1)window->draw(cd2);
        else if (counter>0)window ->draw(cd1);
        else {
                std::cout <<"countdown finished" << std::endl;
                cdDone = true;
                }

	window->popGLStates();
    }
}


