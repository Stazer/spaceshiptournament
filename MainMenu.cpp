// Spaceship Tournament
// MainMenu.cpp

// Include other files
#include "MainMenu.hpp"
#include "ApplicationState.hpp"
#include "Application.hpp"
#include "ResourceManager.hpp"

// Methods to initialize and finalize the main menu
void MainMenu::Initialize ( )
{
	//sf::Sound & ThemeSong = this->Application->GetSoundManager ( )->GetObject ( "Theme" ) ;
	//if ( ThemeSong.GetStatus ( ) == sf::Sound::Stopped )
		//ThemeSong.Play ( ) ;
	this->Background.SetImage ( this->Application->GetImageManager ( )->GetObject ( "Background2" ) ) ;
	this->GameButton = new cp::cpButton ( this->Application->GetWindow ( ) , this->Application->GetGUIContainer ( ) , "Spielen" , 200.0f , 222.5f , 400.0f , 50.0f ) ;
	this->GameButton->SetBackgroundColor ( sf::Color ( 0 , 0 , 0 , 255 ) ) ;
	this->GameButton->SetLabelColor ( sf::Color ( 255 , 255 , 255 , 255 ) ) ;
	this->GameButton->SetMouseoverColor ( sf::Color ( 100 , 100 , 100 , 255 ) ) ;
	this->CreditsButton = new cp::cpButton ( this->Application->GetWindow ( ) , this->Application->GetGUIContainer ( ) , "Credits" , 200.0f , 275.0f , 400.0f , 50.0f ) ;
	this->CreditsButton->SetBackgroundColor ( sf::Color ( 0 , 0 , 0 , 255 ) ) ;
	this->CreditsButton->SetLabelColor ( sf::Color ( 255 , 255 , 255 , 255 ) ) ;
	this->CreditsButton->SetMouseoverColor ( sf::Color ( 100 , 100 , 100 , 255 ) ) ;
	this->CloseButton = new cp::cpButton ( this->Application->GetWindow ( ) , this->Application->GetGUIContainer ( ) , "Beenden" , 200.0f , 307.5f , 400.0f , 50.0f ) ;
	this->CloseButton->SetBackgroundColor ( sf::Color ( 0 , 0 , 0 , 255 ) ) ;
	this->CloseButton->SetLabelColor ( sf::Color ( 255 , 255 , 255 , 255 ) ) ;
	this->CloseButton->SetMouseoverColor ( sf::Color ( 100 , 100 , 100 , 255 ) ) ;
}
void MainMenu::Finalize ( )
{
	this->Application->GetGUIContainer ( )->Unregister ( this->CloseButton ) ;
	delete this->CloseButton ;
	this->Application->GetGUIContainer ( )->Unregister ( this->CreditsButton ) ;
	delete this->CreditsButton ;
	this->Application->GetGUIContainer ( )->Unregister ( this->GameButton ) ;
	delete this->GameButton ;
}

// Method to handle the events
void MainMenu::HandleEvents ( )
{
	while ( this->Application->GetWindow ( )->GetEvent ( * this->Application->GetEvent ( ) ) )
	{
		if ( this->Application->GetEvent ( )->Type == sf::Event::Closed )
			this->Application->SetApplicationState ( ApplicationState::Close ) ;
		this->Application->GetGUIContainer ( )->ProcessKeys ( this->Application->GetEvent ( ) ) ;
	}
	if ( this->GameButton->CheckState ( & this->Application->GetWindow ( )->GetInput ( ) ) == cp::CP_ST_MOUSE_LBUTTON_DOWN )
		this->Application->SetApplicationState ( ApplicationState::Game ) ;
	/*if ( this->CreditsButton->CheckState ( & this->Application->GetWindow ( )->GetInput ( ) ) == cp::CP_ST_MOUSE_LBUTTON_DOWN )
		this->Application->SetApplicationState ( ApplicationState::Credits ) ;*/
	if ( this->CloseButton->CheckState ( & this->Application->GetWindow ( )->GetInput ( ) ) == cp::CP_ST_MOUSE_LBUTTON_DOWN )
		this->Application->SetApplicationState ( ApplicationState::Close ) ;
}

// Method to handle the logic
void MainMenu::HandleLogic ( )
{
}

// Method to render all
void MainMenu::Render ( )
{
	this->Application->GetWindow ( )->Clear ( ) ;
	this->Application->GetWindow ( )->Draw ( this->Background ) ;
	this->GameButton->Draw ( ) ;
	//this->CreditsButton->Draw ( ) ;
	this->CloseButton->Draw ( ) ;
	this->Application->GetWindow ( )->Display ( ) ;
}

// Default constructor
MainMenu::MainMenu ( )
{
	this->CloseButton = 0 ;
	this->CreditsButton = 0 ;
	this->GameButton = 0 ;
}

// Default destructor
MainMenu::~MainMenu ( )
{
	this->CloseButton = 0 ;
	this->CreditsButton = 0 ;
	this->GameButton = 0 ;
}

// Main method
void MainMenu::Main ( )
{
	this->Initialize ( ) ;
	while ( this->Application->GetApplicationState ( ) == ApplicationState::MainMenu )
	{
		this->HandleEvents ( ) ;
		this->HandleLogic ( ) ;
		this->Render ( ) ;
	}
	this->Finalize ( ) ;
}