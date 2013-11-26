#include <cassert>

#include "Time.hpp"
#include "FPS.hpp"

#include "Hud.hpp"
#include "Renderer.hpp"
#include "ShaderProgram.hpp"
#include "Game.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"
#include "Behaviours/KeysBehaviour.hpp"
#include "Behaviours/WASDBehaviour.hpp"
#include "Behaviours/RotatingBehaviour.hpp"
#include "Behaviours/FollowBehavior.hpp"

Game::Game()
:	window(NULL), hud(NULL), renderer(NULL), world(NULL), camera(NULL), light(NULL)
{
	window = new sf::RenderWindow( sf::VideoMode( 800, 600 ), "Saxion Game" ); // get a window
	std::cout << "Init Glew" << glewInit() << std::endl;
	std::cout << "gl version = " << glGetString(GL_VERSION) << std::endl;

	hud = new Hud( window );
	//window->setVerticalSyncEnabled( true ); // sync with monitor ->60 hz approx
	renderer = new Renderer( window );
}

Game::~Game()
{
	//dtor
}

void Game::build()
{
	renderer->use(  new ShaderProgram( "shaders/default.vs", "shaders/default.fs" ) );
	//camera = new Camera( "Camera", glm::vec3( 0, 1, 10 ) );
	//	camera->setBehaviour( new WASDBehaviour( camera, window ) );
	light = new Light( "Light", glm::vec3( 2.0f, 10.0f, 15.0f ) ); // not used now, just ambient light
	Mesh * carMesh = Mesh::load( "models/RollsRoy.obj");
	Mesh * wheel = Mesh::load("models/RollWheel.obj");
	world = new World( "World" );
		world->add( light );

    GameObject * player = new GameObject("Player", glm::vec3( -10.0, 0.5, 0.0 ));
			player->setBehaviour( new WASDBehaviour( player,window ) );
			player->setMesh( carMesh );
			player->setColorMap( Texture::load("models/bricks.jpg") );
			world->add( player);

		GameObject * wheelObject = new GameObject("wheelObject", glm::vec3( -1.5,0.5,3 ) );
			wheelObject->setBehaviour( new RotatingBehaviour( wheelObject ) );
			wheelObject->setMesh( wheel );
			wheelObject->setColorMap( Texture::load("models/tire.jpg") );
			player->add(wheelObject);

        GameObject * wheelObject2 = new GameObject("wheelObject2", glm::vec3( 1.5,0.5,3 ) );
			wheelObject2->setBehaviour( new RotatingBehaviour( wheelObject2 ) );
			wheelObject2->setMesh( wheel );
			wheelObject2->setColorMap( Texture::load("models/tire.jpg") );
			player->add(wheelObject2);

        GameObject * wheelObject3 = new GameObject("wheelObject3", glm::vec3( -1.5,0.5,-3 ) );
			wheelObject3->setBehaviour( new RotatingBehaviour( wheelObject3) );
			wheelObject3->setMesh( wheel );
			wheelObject3->setColorMap( Texture::load("models/tire.jpg") );
			player->add(wheelObject3);

         GameObject * wheelObject4 = new GameObject("wheelObject4", glm::vec3( 1.5,0.5,-3 ) );
			wheelObject4->setBehaviour( new RotatingBehaviour( wheelObject4 ) );
			wheelObject4->setMesh( wheel );
			wheelObject4->setColorMap( Texture::load("models/tire.jpg") );
			player->add(wheelObject4);

		GameObject * floor = new GameObject("Floor", glm::vec3( 10,0,-10 ) );
			floor->setMesh( Mesh::load( "models/floor.obj" ) );
			floor->setColorMap( Texture::load( "models/land.jpg" ) );
			world->add( floor );


        GameObject * floor2 = new GameObject("Floor2", glm::vec3( -10,0,-10 ) );
			floor2->setMesh( Mesh::load( "models/floor.obj" ) );
			floor2->setColorMap( Texture::load( "models/land.jpg" ) );
			floor2->rotate(90,glm::vec3( 0.0f, 1.0f, 0.0f ));
			world->add( floor2 );
        GameObject * floor3 = new GameObject("Floor3", glm::vec3( 10,0,10 ) );
			floor3->setMesh( Mesh::load( "models/floor.obj" ) );
			floor3->setColorMap( Texture::load( "models/land.jpg" ) );
			floor3->rotate(270,glm::vec3( 0.0f, 1.0f, 0.0f ));
			world->add( floor3 );
       GameObject * floor4 = new GameObject("Floor4", glm::vec3( -10,0,10 ) );
			floor4->setMesh( Mesh::load( "models/floor.obj" ) );
			floor4->setColorMap( Texture::load( "models/land.jpg" ) );
			floor4->rotate(180,glm::vec3( 0.0f, 1.0f, 0.0f ));
			world->add( floor4 );

    camera = new Camera( "Camera", glm::vec3( 0, 30, 10 ) );
		camera->setBehaviour( new FollowBehavior(camera, player));
		camera->rotate(180,glm::vec3( 0.0f, 1.0f, 0.0f ));
		//camera->setBehaviour( new KeysBehaviour(camera));
			world->add( camera );
}

void Game::run()
{
	running = true;
	while ( running ) {
		Time::update();
		FPS::update();
		control();
		if ( running ) { // control may have changed running;
			update( Time::step() );
			draw();
		}
	}
}

void Game::stop()
{
}

// private functions

void Game::control()
{
	sf::Event event;
	while( window->pollEvent( event ) ) { // we must empty the event queue
		if ( event.type == sf::Event::Closed ) {
			window->close(); // oeps, still drawing after this one !!!!!!
			running = false; // running = false;
		}
	}
}

void Game::update( float step )
{
	assert( world != NULL );
	world->update( step );
}

void Game::draw()
{
	assert( window != NULL );
	assert( renderer != NULL );
	assert( world != NULL );

	renderer->draw( world );
	hud->draw();
	window->display(); // swap colorbuffer to screen
}


