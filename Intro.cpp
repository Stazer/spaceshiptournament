// Spaceship Tournament
// Intro.cpp

// Include other files
#include "Intro.hpp"
#include "Application.hpp"
#include "ApplicationState.hpp"
#include "ResourceManager.hpp"

// Methods to initialize and finalize the intro
void Intro::Initialize ( )
{
	this->LogoIdentification = 0 ;
	this->Logo.SetImage ( this->Application->GetImageManager ( )->GetObject ( "Logo1" ) ) ;
	this->Logo.SetColor ( sf::Color ( 255 , 255 , 255 , 0 ) ) ;
	this->AlphaClock.Reset ( ) ;
}
void Intro::Finalize ( )
{
}

// Method to handle events
void Intro::HandleEvents ( )
{
	while ( this->Application->GetWindow ( )->GetEvent ( * this->Application->GetEvent ( ) ) )
	{
		if ( this->Application->GetEvent ( )->Type == sf::Event::Closed )
			this->Application->SetApplicationState ( ApplicationState::Close ) ;
		this->Application->GetGUIContainer ( )->ProcessKeys ( this->Application->GetEvent ( ) ) ;
	}
	if ( this->Application->GetWindow ( )->GetInput ( ).IsMouseButtonDown ( sf::Mouse::Left ) ||
		 this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Return ) ||
		 this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Space ) ||
		 this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Escape ) )
	{
		if ( this->LogoIdentification == 0 )
		{
			this->LogoIdentification = 1 ;
			this->Logo.SetImage ( this->Application->GetImageManager ( )->GetObject ( "Logo2" ) ) ;
			this->Logo.SetColor ( sf::Color ( 255 , 255 , 255 , 0 ) ) ;
			this->AlphaClock.Reset ( ) ;
			this->NewLogoClock.Reset ( ) ;
		}
		if ( this->LogoIdentification == 1 && this->NewLogoClock.GetElapsedTime ( ) >= this->Application->GetWindow ( )->GetFrameTime ( ) * 10 )
			this->Application->SetApplicationState ( ApplicationState::MainMenu ) ;
	}
}

// Method to handle the logic
void Intro::HandleLogic ( )
{
	if ( this->Logo.GetColor ( ).a < 255 )
	{
		if ( this->AlphaClock.GetElapsedTime ( ) >= 0.01f )
		{
			this->Logo.SetColor ( sf::Color ( 255 , 255 , 255 , this->Logo.GetColor ( ).a + 1 ) ) ;
			this->AlphaClock.Reset ( ) ;
		}
	}
}

// Method to render all
void Intro::Render ( )
{
	this->Application->GetWindow ( )->Clear ( ) ;
	this->Application->GetWindow ( )->Draw ( this->Logo ) ;
	this->Application->GetWindow ( )->Display ( ) ;
}

// Default constructor
Intro::Intro ( )
{
}

// Default destructor
Intro::~Intro ( )
{
}

// Main method
void Intro::Main ( )
{
	this->Initialize ( ) ;
	while ( this->Application->GetApplicationState ( ) == ApplicationState::Intro )
	{
		this->HandleEvents ( ) ;
		this->HandleLogic ( ) ;
		this->Render ( ) ;
	}
	this->Finalize ( ) ;
}