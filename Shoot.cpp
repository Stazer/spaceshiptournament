// Spaceship Tournament
// Shoot.cpp

// Include other files
#include "Ship.hpp"
#include "Application.hpp"
#include "ResourceManager.hpp"
#include "ShipManager.hpp"
#include "Collision.hpp"
#include "WeaponManager.hpp"
#include "Shoot.hpp"

// Default constructor
Shoot::Shoot ( float Rotation , float Speed )
{
	float Radian = Rotation * static_cast <float> ( PI ) / 180.0f ;
	this->Position.x = ( Speed * Application::GetInstancePointer ( )->GetWindow ( )->GetFrameTime ( ) + 75.0f ) * sin ( Radian )  ;
	this->Position.y = ( Speed * Application::GetInstancePointer ( )->GetWindow ( )->GetFrameTime ( ) + 75.0f ) * cos ( Radian ) ;
}

// Method to update the logic
void Shoot::Update ( )
{
	this->Sprite.Move ( this->Position ) ;
}

// Methods to get the private members
sf::Sprite * Shoot::GetSprite ( )
{
	return & this->Sprite ;
}
sf::Clock * Shoot::GetTimer ( )
{
	return & this->Timer ;
}