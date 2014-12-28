// Spaceship Tournament
// Credits.hpp

// Includeguard
#ifndef CREDITS_HPP
#define CREDITS_HPP

// Include other files
#include "Include.hpp"
#include "ApplicationState.hpp"

// Credits class
class Credits : public ApplicationState
{
	private :
		// Methods to initialize and finalize the credits
		void Initialize ( ) ;
		void Finalize ( ) ;

		// Method to handle the events
		void HandleEvents ( ) ;

		// Method to handle the logic
		void HandleLogic ( ) ;

		// Method to render all
		void Render ( ) ;

		// Background
		sf::Sprite Background ;

		// Credits
		sf::String CreditsText ;

		// Back button
		cp::cpButton * BackButton ;

	protected :

	public :
		// Default constructor
		Credits ( ) ;

		// Default destructor
		~Credits ( ) ;

		// Main method
		void Main ( ) ;
} ;

// Includeguard
#endif