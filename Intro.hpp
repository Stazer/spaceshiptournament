// Spaceship Tournament
// Intro.hpp

// Includeguard
#ifndef INTRO_HPP
#define INTRO_HPP

// Include other files
#include "Include.hpp"
#include "ApplicationState.hpp"

// Intro class
class Intro : public ApplicationState
{
	private :
		// Methods to initialize and finalize the intro
		void Initialize ( ) ;
		void Finalize ( ) ;

		// Method to handle the events
		void HandleEvents ( ) ;

		// Method to handle the logic
		void HandleLogic ( ) ;

		// Method to render all
		void Render ( ) ;

		// Needed sprites
		sf::Sprite Logo ;

		// Logo identification
		unsigned int LogoIdentification ;

		// Clocks für the logos
		sf::Clock AlphaClock ;
		sf::Clock NewLogoClock ;

	protected :

	public :
		// Default constructor
		Intro ( ) ;

		// Default destructor
		~Intro ( ) ;

		// Main method
		void Main ( ) ;
} ;

// Includeguard
#endif