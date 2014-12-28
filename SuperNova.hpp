// Spaceship Tournament
// SuperNova.hpp

// Includeguard
#ifndef SUPERNOVA_HPP
#define SUPERNOVA_HPP

// Include other files
#include "Include.hpp"

// Ship Prototype
class Ship ;

// SuperNova class
class SuperNova
{
	private :
		// Variable which defines whether the supernova is activated
		bool RunningSuperNova ;

		// Sprite
		sf::Sprite Sprite ;

		// Pointer to the ship
		class Ship * Ship ;

	public :
		// Constructor
		SuperNova ( class Ship * Ship ) ;
} ;

// Includeguard
#endif