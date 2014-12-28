// Spaceship Tournament
// ApplicationState.hpp

// Includeguard
#ifndef APPLICATIONSTATE_HPP
#define APPLICATIONSTATE_HPP

// Include other files
#include "Include.hpp"

// Prototypes
class Application ;

// Base application state class
class ApplicationState
{
	private :

	protected :
		// Pointer of application instance
		Application * Application ;

		// Virtual methods
		virtual void HandleEvents ( ) = 0 ;
		virtual void Render ( ) = 0 ;
		virtual void Initialize ( ) = 0 ;
		virtual void Finalize ( ) = 0 ;
		virtual void HandleLogic ( ) = 0 ;

	public :
		// Default constructor
		ApplicationState ( ) ;

		// Default destructor
		~ApplicationState ( ) ;

		// Virtual method
		virtual void Main ( ) = 0 ;

		// Application states
		enum ApplicationStates
		{
			Intro		= 0 ,
			MainMenu	= 1 ,
			Credits		= 3 ,
			Game		= 4 ,
			Close		= 5
		} ;
} ;

// Includeguard
#endif