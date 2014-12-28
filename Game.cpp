// Spaceship Tournament
// Game.cpp

// Include other files
#include "Game.hpp"
#include "Application.hpp"
#include "ApplicationState.hpp"
#include "ShipManager.hpp"
#include "Ship.hpp"
#include "Collision.hpp"
#include "ResourceManager.hpp"

// Methods to initialize and finalize the credits
void Game::Initialize ( )
{
	this->Step = 0 ;
	this->Background.SetImage ( this->Application->GetImageManager ( )->GetObject ( "Background3" ) ) ;
	this->ShipManager = new class ShipManager ( ) ;
	this->NextButton = new cp::cpButton ( this->Application->GetWindow ( ) , this->Application->GetGUIContainer ( ) , "", 0.0f , 0.0f , 0.0f , 0.0f ) ;
	this->BackButton = new cp::cpButton ( this->Application->GetWindow ( ) , this->Application->GetGUIContainer ( ) , "", 0.0f , 0.0f , 0.0f , 0.0f ) ;
	this->NextButton->SetSize ( 400.0f , 50.0f ) ;
	this->NextButton->SetBackgroundColor ( sf::Color::Black ) ;
	this->BackButton->SetBackgroundColor ( sf::Color::Black ) ;
	this->NextButton->SetLabelColor ( sf::Color::White ) ;
	this->BackButton->SetLabelColor ( sf::Color::White ) ;
	this->NextButton->SetMouseoverColor ( sf::Color ( 100 , 100 , 100 , 255 ) ) ;
	this->BackButton->SetMouseoverColor ( sf::Color ( 100 , 100 , 100 , 255 ) ) ;
	this->NextButton->SetPosition ( 200.0f , 222.5f ) ;
	this->NextButton->SetLabelText ( "Weiterspielen" ) ;
	this->BackButton->SetSize ( 400.0f , 50.0f ) ;
	this->BackButton->SetPosition ( 200.0f , 307.5f ) ;
	this->BackButton->SetLabelText ( "Zurück zum Hauptmenü" ) ;
	this->Camera.SetCenter ( 0 , 0 ) ;
	this->Camera.SetHalfSize ( 400 , 300 ) ;
	this->Clock.Reset ( ) ;
	this->Win = false ;
	this->Camera.Zoom ( 0.5f ) ;
	this->Map = sf::Rect <float> ( -5000 , 3750 , 5000 , -3750 ) ;
	for ( unsigned int CurrentElement = 0 ; CurrentElement < 1000 ; CurrentElement++ )
	{
		this->Stars [ CurrentElement ].SetImage ( this->Application->GetImageManager ( )->GetObject ( "Star" ) ) ;
		int X = sf::Randomizer::Random ( -5000 , 5000 ) ;
		int Y = sf::Randomizer::Random ( -3750 , 3750 ) ;
		float Scale = sf::Randomizer::Random ( 0.1f , 5.0f ) ;
		this->Stars [ CurrentElement ].SetPosition ( static_cast <float> ( X ) , static_cast <float> ( Y ) ) ;
		this->Stars [ CurrentElement ].SetScale ( Scale , Scale ) ;
	}
	this->Clouds [ 0 ].SetImage ( this->Application->GetImageManager ( )->GetObject ( "Cloud1" ) ) ;
	this->Clouds [ 0 ].SetPosition ( -3750 , -1000 ) ;
	this->Clouds [ 0 ].SetScale ( 10.0f , 10.0f ) ;
	this->Clouds [ 1 ].SetImage ( this->Application->GetImageManager ( )->GetObject ( "Cloud2" ) ) ;
	this->Clouds [ 1 ].SetPosition ( 4000.0f , 2000.0f ) ;
	this->Clouds [ 1 ].SetCenter ( 200.0f , 200.0f ) ;
	this->Clouds [ 1 ].SetScale ( 5.0f , 5.0f ) ;
}
void Game::Finalize ( )
{
	this->Application->GetGUIContainer ( )->Unregister ( this->NextButton ) ;
	this->Application->GetGUIContainer ( )->Unregister ( this->BackButton ) ;
	delete this->ShipManager ;
	delete this->NextButton ;
	delete this->BackButton ;
}

// Method to handle the events
void Game::HandleEvents ( )
{
	while ( this->Application->GetWindow ( )->GetEvent ( * this->Application->GetEvent ( ) ) )
	{
		if ( this->Application->GetEvent ( )->Type == sf::Event::Closed )
			this->Application->SetApplicationState ( ApplicationState::Close ) ;
		this->Application->GetGUIContainer ( )->ProcessKeys ( this->Application->GetEvent ( ) ) ;
	}
	if ( this->Step == 0 )
	{
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Escape ) )
		{
			this->Application->GetWindow ( )->SetView ( this->Application->GetWindow ( )->GetDefaultView ( ) ) ;
			this->Step = 1 ;
		}
		this->ShipManager->HandleInput ( ) ;
	}
	else if ( this->Step == 1 )
	{
		if ( this->Win && this->NextButton->CheckState ( & this->Application->GetWindow ( )->GetInput ( ) ) == cp::CP_ST_MOUSE_LBUTTON_DOWN )
			this->Step = 0 ;
		if ( this->BackButton->CheckState ( & this->Application->GetWindow ( )->GetInput ( ) ) == cp::CP_ST_MOUSE_LBUTTON_DOWN )
			this->Application->SetApplicationState ( ApplicationState::MainMenu ) ;
	}
}

// Method to handle the logic
void Game::HandleLogic ( )
{
	if ( this->Step == 0 )
	{
		if ( this->Map.Left > this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).x )
			this->ShipManager->GetPlayer1 ( )->GetSprite ( )->SetPosition ( 5000 , this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).y ) ;
		if ( this->Map.Right < this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).x )
			this->ShipManager->GetPlayer1 ( )->GetSprite ( )->SetPosition ( -5000 , this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).y ) ;
		if ( this->Map.Bottom > this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).y )
			this->ShipManager->GetPlayer1 ( )->GetSprite ( )->SetPosition ( this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).x , 3750 ) ;
		if ( this->Map.Top < this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).y )
			this->ShipManager->GetPlayer1 ( )->GetSprite ( )->SetPosition ( this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).x  , -3750 ) ;
		if ( this->Map.Left > this->ShipManager->GetPlayer2 ( )->GetSprite ( )->GetPosition ( ).x )
			this->ShipManager->GetPlayer2 ( )->GetSprite ( )->SetPosition ( 5000 , this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).y ) ;
		if ( this->Map.Right < this->ShipManager->GetPlayer2 ( )->GetSprite ( )->GetPosition ( ).x )
			this->ShipManager->GetPlayer2 ( )->GetSprite ( )->SetPosition ( -5000 , this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).y ) ;
		if ( this->Map.Bottom > this->ShipManager->GetPlayer2 ( )->GetSprite ( )->GetPosition ( ).y )
			this->ShipManager->GetPlayer2 ( )->GetSprite ( )->SetPosition ( this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).x , 3750 ) ;
		if ( this->Map.Top < this->ShipManager->GetPlayer2 ( )->GetSprite ( )->GetPosition ( ).y )
			this->ShipManager->GetPlayer2 ( )->GetSprite ( )->SetPosition ( this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).x  , -3750 ) ;

		if ( ! this->Camera.GetRect ( ).Contains ( this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).x , this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).y ) || 
			 ! this->Camera.GetRect ( ).Contains ( this->ShipManager->GetPlayer2 ( )->GetSprite ( )->GetPosition ( ).x , this->ShipManager->GetPlayer2 ( )->GetSprite ( )->GetPosition ( ).y ) )
		{
			while ( ( ! this->Camera.GetRect ( ).Contains ( this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).x , this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).y ) || 
					  ! this->Camera.GetRect ( ).Contains ( this->ShipManager->GetPlayer2 ( )->GetSprite ( )->GetPosition ( ).x , this->ShipManager->GetPlayer2 ( )->GetSprite ( )->GetPosition ( ).y ) ) &&
					  ! this->Map.Contains ( this->Camera.GetRect ( ).GetWidth ( ) , this->Camera.GetRect ( ).GetHeight ( ) ) )
			{
				this->Camera.Zoom ( 0.999f ) ;
			}
		}
		else
		{
			if ( this->Clock.GetElapsedTime ( ) >= 5.0f )
			{
				if ( this->Camera.GetRect ( ).Contains ( this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).x * 2 , this->ShipManager->GetPlayer1 ( )->GetSprite ( )->GetPosition ( ).y * 2 ) &&
					 this->Camera.GetRect ( ).Contains ( this->ShipManager->GetPlayer2 ( )->GetSprite ( )->GetPosition ( ).x * 2 , this->ShipManager->GetPlayer2 ( )->GetSprite ( )->GetPosition ( ).y * 2 ) )
				{
					this->Camera.Zoom ( 1.007f ) ;
				}
				else
				{
					this->Clock.Reset ( ) ;
				}
			}
		}
		if ( this->Map.Left > this->Clouds [ 0 ].GetPosition ( ).x )
			this->Clouds [ 0 ].SetPosition ( 5000 , this->Clouds [ 0 ].GetPosition ( ).y ) ;
		if ( this->Map.Right < this->Clouds [ 0 ].GetPosition ( ).x )
			this->Clouds [ 0 ].SetPosition ( -5000 , this->Clouds [ 0 ].GetPosition ( ).y ) ;
		if ( this->Map.Bottom > this->Clouds [ 0 ].GetPosition ( ).y )
			this->Clouds [ 0 ].SetPosition ( this->Clouds [ 0 ].GetPosition ( ).x , 3750 ) ;
		if ( this->Map.Top < this->Clouds [ 0 ].GetPosition ( ).y )
			this->Clouds [ 0 ].SetPosition ( this->Clouds [ 0 ].GetPosition ( ).x  , -3750 ) ;
		Clouds [ 0 ].Move ( - 10.0f * this->Application->GetWindow ( )->GetFrameTime ( ) , - 10.0f * this->Application->GetWindow ( )->GetFrameTime ( ) ) ;
		Clouds [ 1 ].Rotate ( 120.0f * this->Application->GetWindow ( )->GetFrameTime ( ) ) ;
		if ( Collision::CircleTest ( this->Clouds [ 1 ] , * this->ShipManager->GetPlayer1 ( )->GetSprite ( ) , -250.0f , -250.0f ) )
			this->ShipManager->GetPlayer1 ( )->SetHealth ( 0.0f ) ;
		if ( Collision::CircleTest ( this->Clouds [ 1 ] , * this->ShipManager->GetPlayer2 ( )->GetSprite ( ) , -250.0f , -250.0f ) )
			this->ShipManager->GetPlayer2 ( )->SetHealth ( 0.0f ) ;
		this->ShipManager->Update ( ) ;
		this->ShipManager->HandleInput ( ) ;
		if ( this->ShipManager->GetPlayer1 ( )->GetHealth ( ) <= 0.0f )
		{
			this->NextButton->SetLabelText ( "Spieler 2 hat gewonnen!" ) ;
			this->Win = true ;
			this->Step = 1 ;
		}
		else if ( this->ShipManager->GetPlayer2 ( )->GetHealth ( ) <= 0.0f )
		{
			this->NextButton->SetLabelText ( "Spieler 1 hat gewonnen!" ) ;
			this->Win = true ;
			this->Step = 1 ;
		}
	}
}

// Method to render all
void Game::Render ( )
{
	this->Application->GetWindow ( )->Clear ( ) ;
	if ( this->Step == 0 )
	{
		for ( unsigned int CurrentElement = 0 ; CurrentElement < 1000 ; CurrentElement++ )
		{
			this->Application->GetWindow ( )->Draw ( this->Stars [ CurrentElement ] ) ;
		}
		this->Application->GetWindow ( )->SetView ( this->Camera ) ;
		this->ShipManager->Render ( ) ;
		for ( unsigned int CurrentElement = 0 ; CurrentElement < 2 ; CurrentElement++ )
		{
			this->Application->GetWindow ( )->Draw ( this->Clouds [ CurrentElement ] ) ;
		}
	}
	else if ( this->Step == 1 )
	{
		this->Application->GetWindow ( )->Draw ( this->Background ) ;
		this->Application->GetWindow ( )->SetView ( this->Application->GetWindow ( )->GetDefaultView ( ) ) ;
		this->BackButton->Draw ( ) ;
		this->NextButton->Draw ( ) ;
	}
	this->Application->GetWindow ( )->Display ( ) ;
	Sleep ( 0 ) ;
}

// Default constructor
Game::Game ( )
{
	this->BackButton = 0 ;
	this->NextButton = 0 ;
	this->ShipManager = 0 ;
}

// Default destructor
Game::~Game ( )
{
	this->BackButton = 0 ;
	this->NextButton = 0 ;
	this->ShipManager = 0 ;
}

// Main method
void Game::Main ( )
{
	this->Initialize ( ) ;
	while ( this->Application->GetApplicationState ( ) == ApplicationState::Game )
	{
		this->HandleEvents ( ) ;
		this->HandleLogic ( ) ;
		this->Render ( ) ;
	}
	this->Finalize ( ) ;
}