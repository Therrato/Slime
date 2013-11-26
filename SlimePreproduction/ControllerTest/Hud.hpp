#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "time.h"

class Hud
{
	private:
		sf::RenderWindow * window;
		sf::Font font;
		sf::Texture marvinTex;
		sf::Texture cd3Tex;
		sf::Texture cd2Tex;
		sf::Texture cd1Tex;
		sf::Sprite marvin;
		sf::Sprite cd3;
		sf::Sprite cd2;
		sf::Sprite cd1;
		float counter;
		bool cdDone;
	public:
		Hud( sf::RenderWindow * aWindow );
		virtual ~Hud();
		void countDown();

		void draw( );
};

#endif // HUD_H
