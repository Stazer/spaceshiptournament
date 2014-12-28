// Spaceship Tournament
// Shoot.hpp

// Includeguard
#ifndef SHOOT_HPP
#define SHOOT_HPP

// Include other files
#include "Include.hpp"

// Class for a Shoot
class Shoot
{
	private :
		// Shoot :D
		sf::Sprite Sprite ;
		sf::Clock Timer ;
		sf::Vector2f Position ;

	protected :

	public :
		// Default constructor
		Shoot ( float Rotation , float Speed ) ;

		// Methods to get the private members
		sf::Sprite * GetSprite ( ) ;
		sf::Clock * GetTimer ( ) ;

		// Method to update the logic
		void Update ( ) ;
} ;

// Includeguard
#endif