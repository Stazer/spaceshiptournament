// Spaceship Tournament
// Application.cpp

// Include other files
#include "Application.hpp"
#include "ApplicationState.hpp"
#include "ResourceManager.hpp"
#include "Intro.hpp"
#include "Game.hpp"
#include "MainMenu.hpp"
#include "Credits.hpp"

// Default constructor
Application::Application ( )
{
	this->Event = 0 ;
	this->Window = 0 ;
	this->GUIContainer = 0 ;
	this->ImageManager = 0 ;
	this->SoundManager = 0 ;
	this->SoundBufferManager = 0 ;
}

// Default destructor
Application::~Application ( )
{
	this->Event = 0 ;
	this->Window = 0 ;
	this->GUIContainer = 0 ;
	this->ImageManager = 0 ;
	this->SoundManager = 0 ;
	this->SoundBufferManager = 0 ;
}

// Get methods of the private member
sf::RenderWindow * Application::GetWindow ( ) const
{
	return this->Window ;
}
sf::Event * Application::GetEvent ( ) const
{
	return this->Event ;
}
ResourceManager <sf::Image> * Application::GetImageManager ( ) const
{
	return this->ImageManager ;
}
ResourceManager <sf::Sound> * Application::GetSoundManager ( ) const
{
	return this->SoundManager ;
}
ResourceManager <sf::SoundBuffer> * Application::GetSoundBufferManager ( ) const
{
	return this->SoundBufferManager ;
}
cp::cpGuiContainer * Application::GetGUIContainer ( ) const
{
	return this->GUIContainer ;
}

// Get and set method of the application state
void Application::SetApplicationState ( const unsigned int ApplicationState )
{
	this->ApplicationState = ApplicationState ;
}
unsigned int Application::GetApplicationState ( ) const
{
	return this->ApplicationState ;
}

// Methods which return the application instance
Application & Application::GetInstanceReference ( )
{
	static Application Instance ;
	return Instance ;
}
Application * Application::GetInstancePointer ( )
{
	static Application Instance ;
	return & Instance ;
}

// Main method
unsigned int Application::Main ( )
{
	if ( this->Initialize ( ) == 0 )
	{
		std::cin.get ( ) ;
		return -1 ;
	}
	while ( this->ApplicationState != ApplicationState::Close )
	{
		switch ( this->ApplicationState )
		{
			case ApplicationState::Intro :
			{
 				Intro Intro ;
				Intro.Main ( ) ;
				break ;
			}
			case ApplicationState::MainMenu :
			{
				MainMenu MainMenu ;
				MainMenu.Main ( ) ;
				break ;
			}
			case ApplicationState::Credits :
			{
				Credits Credits ;
				Credits.Main ( ) ;
				break ;
			}
			case ApplicationState::Game :
			{
				Game Game ;
				Game.Main ( ) ;
				break ;
			}
		}
	}
	if ( this->Finalize ( ) == 0 )
		return -1 ;
	return 0 ;
}

// Methods to initialize and finalize
// the application
unsigned int Application::Initialize ( )
{
	this->ImageManager = new ResourceManager <sf::Image> ;
	this->SoundManager = new ResourceManager <sf::Sound> ;
	this->SoundBufferManager = new ResourceManager <sf::SoundBuffer> ;
	sf::Image TempImage ;
	sf::SoundBuffer TempSound ;
	if ( ! TempImage.LoadFromFile ( "Data/Images/Explosion.png" ) )
		return 0 ;
	this->ImageManager->AddObject ( TempImage , "Explosion" ) ;
	if ( ! TempImage.LoadFromFile ( "Data/Images/Nova.png" ) )
		return 0 ;
	this->ImageManager->AddObject ( TempImage , "Nova" ) ;
	if ( ! TempImage.LoadFromFile ( "Data/Images/Logo1.png" ) )
		return 0 ;
	this->ImageManager->AddObject ( TempImage , "Logo1" ) ;
	if ( ! TempImage.LoadFromFile ( "Data/Images/Logo2.png" ) )
		return 0 ;
	this->ImageManager->AddObject ( TempImage , "Logo2" ) ;
	if ( ! TempImage.LoadFromFile ( "Data/Images/Background2.png" ) )
		return 0 ;
	this->ImageManager->AddObject ( TempImage , "Background2" ) ;
	if ( ! TempImage.LoadFromFile ( "Data/Images/Background3.png" ) )
		return 0 ;
	this->ImageManager->AddObject ( TempImage , "Background3" ) ;;
	if ( ! TempImage.LoadFromFile ( "Data/Images/Background4.png" ) )
		return 0 ;
	this->ImageManager->AddObject ( TempImage , "Background4" ) ;
	if ( ! TempImage.LoadFromFile ( "Data/Images/RedShip.png" ) )
		return 0 ;
	this->ImageManager->AddObject ( TempImage , "RedShip" ) ;
	if ( ! TempImage.LoadFromFile ( "Data/Images/BlueShip.png" ) )
		return 0 ;
	this->ImageManager->AddObject ( TempImage , "BlueShip" ) ;
	if ( ! TempImage.LoadFromFile ( "Data/Images/Star.png" ) )
		return 0 ;
	this->ImageManager->AddObject ( TempImage , "Star" ) ;
	if ( ! TempImage.LoadFromFile ( "Data/Images/Bullet.png" ) )
		return 0 ;
	this->ImageManager->AddObject ( TempImage , "Bullet" ) ;
	if ( ! TempImage.LoadFromFile ( "Data/Images/Cloud1.png" ) )
		return 0 ;
	this->ImageManager->AddObject ( TempImage , "Cloud1" ) ;
	if ( ! TempImage.LoadFromFile ( "Data/Images/Cloud2.png" ) )
		return 0 ;
	this->ImageManager->AddObject ( TempImage , "Cloud2" ) ;
	//if ( ! TempSound.LoadFromFile ( "Data/Sounds/Theme.ogg" ) )
	//	return 0 ;
	//FreeConsole ( ) ;
	//this->SoundBufferManager->AddObject ( TempSound , "Theme" ) ;
	//this->SoundManager->AddObject ( sf::Sound ( this->SoundBufferManager->GetObject ( "Theme" ) , true , 1.0f , 50.0f ) , "Theme" ) ;
	this->ApplicationState = ApplicationState::Intro ;
	this->Window = new sf::RenderWindow ( sf::VideoMode ( 800 , 600 ) , "Spaceship Tournament" , sf::Style::Close | sf::Style::Fullscreen ) ;
	this->Event = new sf::Event ;
	this->GUIContainer = new cp::cpGuiContainer ;
	this->Window->SetFramerateLimit ( 60 ) ;
	this->Window->UseVerticalSync ( true ) ;
	return 1 ;
}
unsigned int Application::Finalize ( )
{
	this->Window->Close ( ) ;
	delete this->GUIContainer ;
	delete this->SoundManager ;
	delete this->SoundBufferManager ;
	delete this->ImageManager ;
	delete this->Event ;
	delete this->Window ;
	return 1 ;
}