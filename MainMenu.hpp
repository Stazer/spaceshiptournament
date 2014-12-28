// Spaceship Tournament
// MainMenu.hpp

// Includeguard
#ifndef MAINMENU_HPP
#define MAINMENU_HPP

// Include other files
#include "Include.hpp"
#include "ApplicationState.hpp"

// MainMenu class
class MainMenu : public ApplicationState
{
	private :
		// Methods to initialize and finalize the mainmenu
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

		// Buttons
		cp::cpButton * GameButton ;
		cp::cpButton * CreditsButton ;
		cp::cpButton * CloseButton ;

	protected :

	public :
		// Default constructor
		MainMenu ( ) ;

		// Default destructor
		~MainMenu ( ) ;

		// Main method
		void Main ( ) ;
} ;

// Includeguard
#endif