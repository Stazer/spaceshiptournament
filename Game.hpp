// Spaceship Tournament
// Game.hpp

// Includeguard
#ifndef GAME_HPP
#define GAME_HPP

// Include other files
#include "Include.hpp"
#include "ApplicationState.hpp"

// Prototypes
class ShipManager ;

// Game class
class Game : public ApplicationState
{
	private :
		// Methods to initialize and finalize the game instance
		void Initialize ( ) ;
		void Finalize ( ) ;

		// Win Var :D
		bool Win ;

		// Method to handle the events
		void HandleEvents ( ) ;

		// Map
		sf::Rect <float> Map ;

		// Method to handle the logic
		void HandleLogic ( ) ;

		// Method to render all
		void Render ( ) ;

		// Steps
		unsigned int Step ;

		// Back and next button
		cp::cpButton * BackButton ;
		cp::cpButton * NextButton ;

		// Camera
		sf::View Camera ;
		sf::Clock Clock ;

		// Stars
		sf::Sprite Stars [ 1000 ] ;

		// Clouds
		sf::Sprite Clouds [ 2 ] ;

		// Background
		sf::Sprite Background ;

		// Ship manager for the player the enemys and the allys
		ShipManager * ShipManager ;

	protected :

	public :
		// Default constructor
		Game ( ) ;

		// Default destructor
		~Game ( ) ;

		// Main method
		void Main ( ) ;
} ;

// Includeguard
#endif