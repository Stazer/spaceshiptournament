// Spaceship Tournament
// Credits.cpp

// Include other files
#include "Credits.hpp"
#include "Application.hpp"
#include "ApplicationState.hpp"
#include "ResourceManager.hpp"

// Methods to initialize and finalize the credits
void Credits::Initialize ( )
{
	this->Background.SetImage ( this->Application->GetImageManager ( )->GetObject ( "Background4" ) ) ;
	this->BackButton = new cp::cpButton ( this->Application->GetWindow ( ) , this->Application->GetGUIContainer ( ) , "Zurück" , 200.0f , 525.0f , 400.0f , 50.0f ) ;
	this->BackButton->SetBackgroundColor ( sf::Color ( 0 , 0 , 0 , 255 ) ) ;
	this->BackButton->SetLabelColor ( sf::Color ( 255 , 255 , 255 , 255 ) ) ;
	this->BackButton->SetMouseoverColor ( sf::Color ( 100 , 100 , 100 , 255 ) ) ;
}
void Credits::Finalize ( )
{
	this->Application->GetGUIContainer ( )->Unregister ( this->BackButton ) ;
	delete this->BackButton ;
}

// Method to handle the events
void Credits::HandleEvents ( )
{
	while ( this->Application->GetWindow ( )->GetEvent ( * this->Application->GetEvent ( ) ) )
	{
		if ( this->Application->GetEvent ( )->Type == sf::Event::Closed )
			this->Application->SetApplicationState ( ApplicationState::Close ) ;
		this->Application->GetGUIContainer ( )->ProcessKeys ( this->Application->GetEvent ( ) ) ;
	}
	if ( this->BackButton->CheckState ( & this->Application->GetWindow ( )->GetInput ( ) ) == cp::CP_ST_MOUSE_LBUTTON_DOWN )
		this->Application->SetApplicationState ( ApplicationState::MainMenu ) ;
}

// Method to handle the logic
void Credits::HandleLogic ( )
{
}

// Method to render all
void Credits::Render ( )
{
	this->Application->GetWindow ( )->Clear ( ) ;
	this->Application->GetWindow ( )->Draw ( this->Background ) ;
	this->Application->GetWindow ( )->Draw ( this->CreditsText ) ;
	this->BackButton->Draw ( ) ;
	this->Application->GetWindow ( )->Display ( ) ;
}

// Default constructor
Credits::Credits ( )
{
	this->BackButton = 0 ;
}

// Default destructor
Credits::~Credits ( )
{
	this->BackButton = 0 ;
}

// Main method
void Credits::Main ( )
{
	this->Initialize ( ) ;
	while ( this->Application->GetApplicationState ( ) == ApplicationState::Credits )
	{
		this->HandleEvents ( ) ;
		this->HandleLogic ( ) ;
		this->Render ( ) ;
	}
	this->Finalize ( ) ;
}