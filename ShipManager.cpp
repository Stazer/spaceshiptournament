// Spaceship Tournament
// ShipManager.cpp

// Include other files
#include "ShipManager.hpp"
#include "Application.hpp"
#include "ResourceManager.hpp"
#include "Ship.hpp"

// Default constructor
ShipManager::ShipManager ( )
{
	this->RenderCollisionCircle = false ;
	this->Player1 = new Ship ( 0 ) ;
	this->Player2 = new Ship ( 1 ) ;
	this->Player1->SetShipManager ( this ) ;
	this->Player2->SetShipManager ( this ) ;
	this->Player1->GetSprite ( )->SetImage ( Application::GetInstancePointer ( )->GetImageManager ( )->GetObject ( "BlueShip" ) ) ;
	this->Player2->GetSprite ( )->SetImage ( Application::GetInstancePointer ( )->GetImageManager ( )->GetObject ( "RedShip" ) ) ;
	this->Player1->GetSprite ( )->SetCenter ( 87.5f , 75.0f ) ;
	this->Player2->GetSprite ( )->SetCenter ( 87.5f , 75.0f ) ;
	this->Player1->GetSprite ( )->SetPosition ( 0.0f , -250.0f ) ;
	this->Player2->GetSprite ( )->SetPosition ( 0.0f , 250.0f ) ;
	this->Player2->GetSprite ( )->Rotate ( 180.0f ) ;
}

// Default destructor
ShipManager::~ShipManager ( )
{
	this->RenderCollisionCircle = false ;
	delete this->Player1 ;
	delete this->Player2 ;
}

// Update method to update the logic of the ships
void ShipManager::Update ( )
{
	this->Player1->Update ( ) ;
	this->Player2->Update ( ) ;
}

// Render method to render the ships
void ShipManager::Render ( )
{
	this->Player1->Render ( ) ;
	this->Player2->Render ( ) ;
}

// HandleInput method to handle the input of the players
void ShipManager::HandleInput ( )
{
	this->Player1->HandleInput ( ) ;
	this->Player2->HandleInput ( ) ;
}

// Method to set whever the collision cirle will be rendered
void ShipManager::SetRenderCollisionCircle ( bool RenderCollisionCircle )
{
	this->RenderCollisionCircle = RenderCollisionCircle ;
}

// Methods to get the private members
class Ship * ShipManager::GetPlayer1 ( ) const
{
	return this->Player1 ;
}
class Ship * ShipManager::GetPlayer2 ( ) const
{
	return this->Player2 ;
}