// Spaceship Tournament
// Application.hpp

// Includeguard
#ifndef APPLICATION_HPP
#define APPLICATION_HPP

// Include other files
#include "Include.hpp"

// Prototypes
template <class Type>
class ResourceManager ;

// Application class
class Application
{
	private :
		// Default constructor
		Application ( ) ;

		// Required instances
		sf::RenderWindow * Window ;
		sf::Event * Event ;
		ResourceManager <sf::Image> * ImageManager ;
		ResourceManager <sf::SoundBuffer> * SoundBufferManager ;
		ResourceManager <sf::Sound> * SoundManager ;
		cp::cpGuiContainer * GUIContainer ;

		// Current application state
		unsigned int ApplicationState ;

	protected :

	public :
		// Default destructor
		~Application ( ) ;

		// Get methods of the private member
		sf::RenderWindow * GetWindow ( ) const ;
		sf::Event * GetEvent ( ) const ;
		ResourceManager <sf::Image> * GetImageManager ( ) const ;
		ResourceManager <sf::Sound> * GetSoundManager ( ) const ;
		ResourceManager <sf::SoundBuffer> * GetSoundBufferManager ( ) const ;
		cp::cpGuiContainer * GetGUIContainer ( ) const ;

		// Get and set method of the application state
		void SetApplicationState ( const unsigned int ApplicationState ) ;
		unsigned int GetApplicationState ( ) const ;

		// Methods which return the application instance
		static Application & GetInstanceReference ( ) ;
		static Application * GetInstancePointer ( ) ;

		// Main method
		unsigned int Main ( ) ;

		// Methods to initialize and finalize
		// the application
		unsigned int Initialize ( ) ;
		unsigned int Finalize ( ) ;
} ;

// Includeguard
#endif