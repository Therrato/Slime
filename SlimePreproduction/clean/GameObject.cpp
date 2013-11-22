#include <cassert>
#include <iostream>

#include "Renderer.hpp"
#include "GameObject.hpp"
#include "Behaviour.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"

GameObject::GameObject( std::string aName, glm::vec3 aPosition )
:	name( aName ), transform( glm::translate( aPosition ) ), behaviour( NULL ), mesh( NULL ), colorMap( NULL ) // initialisation list
{
}

GameObject::~GameObject()
{
	//dtor
}

void GameObject::translate( glm::vec3 translation )
{
	transform = glm::translate( transform, translation );
}
void GameObject::rotate( float angle, glm::vec3 axis )
{
	transform = glm::rotate( transform, angle, axis);
}

const std::string GameObject::getName()
{
	return name;
}

glm::vec3 GameObject::getLocation()
{
	return glm::vec3( transform[3][0], transform[3][1], transform[3][2] );
}

void GameObject::setBehaviour( Behaviour * aBehaviour )
{
	assert( aBehaviour != NULL );
	behaviour = aBehaviour;
}

void GameObject::setMesh( Mesh * aMesh )
{
	assert( aMesh != NULL );
	mesh = aMesh;
}

void GameObject::setColorMap( Texture * aColorMap )
{
	assert( aColorMap != NULL );
	assert( aColorMap->getId() > 0 );
	colorMap = aColorMap;
}

void GameObject::update( float step )
{
	if ( behaviour ) { // note no assert on behaviour, it is ok when there is no behaviour
		behaviour->update( step );
	}
	for ( std::vector< GameObject * >::iterator i = children.begin(); i != children.end(); ++i ) {
		((GameObject * )*i)->update( step );
	}

}

void GameObject::onCollision(  GameObject * otherGameObject )
{
	if ( behaviour ) {
		behaviour->onCollision( otherGameObject );
	}
}

void GameObject::draw( Renderer * aRenderer, glm::mat4 parentTransform )
{
	assert( aRenderer != NULL );

	//std::cout << name << "  ";
	if ( mesh ) { // if there is something to draw
		aRenderer->setModel( parentTransform * transform ); // combine parents transfor with own
		if ( colorMap ) { //is has a colormap
			aRenderer->setColorMap( colorMap );
		}
		mesh->draw( aRenderer );
	}
	// draw children
	for ( std::vector< GameObject * >::iterator i = children.begin(); i != children.end(); ++i ) {
		((GameObject * )*i)->draw( aRenderer, parentTransform * transform );
	}
}

void GameObject::add( GameObject * child )
{
	assert( child != NULL );
	children.push_back( child );
}

// private functions

