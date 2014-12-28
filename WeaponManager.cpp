// Spaceship Tournament
// WeaponManager.cpp

// Include other files
#include "Include.hpp"
#include "WeaponManager.hpp"
#include "Ship.hpp"
#include "ResourceManager.hpp"
#include "Application.hpp"
#include "ShipManager.hpp"
#include "Collision.hpp"

// Constructor
WeaponManager::WeaponManager ( class Ship * Ship )
{
	this->SuperNova.SetImage ( Application::GetInstancePointer ( )->GetImageManager ( )->GetObject ( "Nova" ) ) ;
	this->SuperNova.SetCenter ( 250 , 250 ) ;
	this->SuperNova.SetScale ( 0.1f , 0.1f ) ;
	this->Ship = Ship ;
	this->RunningSuperNova = false ;
}

// Default destructor
WeaponManager::~WeaponManager ( )
{
	this->Ship = 0 ;
}

// Method to update the logic of the weapons
void WeaponManager::Update ( )
{
	if ( RunningSuperNova )
	{
		this->SuperNova.SetPosition ( this->Ship->GetSprite ( )->GetPosition ( ) ) ;
		this->SuperNova.SetScale ( this->SuperNova.GetScale ( ).x + 5 * Application::GetInstancePointer ( )->GetWindow ( )->GetFrameTime ( ) , this->SuperNova.GetScale ( ).y + 5 * Application::GetInstancePointer ( )->GetWindow ( )->GetFrameTime ( ) ) ;
		if ( this->SuperNova.GetScale ( ).x >= 2.5f && this->SuperNova.GetScale ( ).y )
		{
			if ( this->Ship->GetIdentification ( ) == 0 )
			{
				if ( Collision::CircleTest ( * this->Ship->GetSprite ( ) , * this->Ship->GetShipManager ( )->GetPlayer2 ( )->GetSprite ( ) , 250.0f , 0.0f ) )
					this->Ship->GetShipManager ( )->GetPlayer2 ( )->SetHealth ( this->Ship->GetShipManager ( )->GetPlayer2 ( )->GetHealth ( ) - 45.0f ) ;
			}
			else
			{
				if ( Collision::CircleTest ( * this->Ship->GetSprite ( ) , * this->Ship->GetShipManager ( )->GetPlayer1 ( )->GetSprite ( ) , 250.0f , 0.0f ) )
					this->Ship->GetShipManager ( )->GetPlayer1 ( )->SetHealth ( this->Ship->GetShipManager ( )->GetPlayer1 ( )->GetHealth ( ) - 45.0f ) ;
			}
			this->RunningSuperNova = false ;
			this->SuperNova.SetScale ( 0.1f , 0.1f ) ;
		}
	}
	for ( std::list <Shoot>::iterator CurrentElement = this->Shoots.begin ( ) ; CurrentElement != this->Shoots.end ( ) ; ++CurrentElement )
	{
		if ( this->Ship->GetIdentification ( ) == 0 )
		{
			if ( Collision::CircleTest ( * this->Ship->GetShipManager ( )->GetPlayer2 ( )->GetSprite ( ) , * CurrentElement->GetSprite ( ) , 0.0f , 0.0f ) )
			{
				this->Ship->GetShipManager ( )->GetPlayer2 ( )->SetHealth ( this->Ship->GetShipManager ( )->GetPlayer2 ( )->GetHealth ( ) - 2.5f ) ;
				CurrentElement = this->Shoots.erase ( CurrentElement ) ;
				continue ;
			}
		}
		else
		{
			if ( Collision::CircleTest ( * this->Ship->GetShipManager ( )->GetPlayer1 ( )->GetSprite ( ) , * CurrentElement->GetSprite ( ) , 0.0f , 0.0f ) )
			{
				this->Ship->GetShipManager ( )->GetPlayer1 ( )->SetHealth ( this->Ship->GetShipManager ( )->GetPlayer1 ( )->GetHealth ( ) - 2.5f ) ;
				CurrentElement = this->Shoots.erase ( CurrentElement ) ;
				continue ;
			}
		}
		if ( CurrentElement->GetTimer ( )->GetElapsedTime ( ) >= 2.5f )
		{
			CurrentElement = this->Shoots.erase ( CurrentElement ) ;
		}
		else
		{
			CurrentElement->Update ( ) ;
		}
	}
}

// Method to render the weapon effects
void WeaponManager::Render ( )
{
	if ( RunningSuperNova )
	{
		Application::GetInstancePointer ( )->GetWindow ( )->Draw ( this->SuperNova ) ;
	}
	for ( std::list <Shoot>::iterator CurrentElement = this->Shoots.begin ( ) ; CurrentElement != this->Shoots.end ( ) ; ++CurrentElement )
	{
		Application::GetInstancePointer ( )->GetWindow ( )->Draw ( *CurrentElement->GetSprite ( ) ) ;
	}
}

// Skills
void WeaponManager::StartSuperNova ( )
{
	this->RunningSuperNova = true ;
}
void WeaponManager::AddShoot ( )
{
	class Shoot Shoot ( this->Ship->GetSprite ( )->GetRotation ( ) , this->Ship->GetSpeed ( ) ) ;
	Shoot.GetSprite ( )->SetImage ( Application::GetInstancePointer ( )->GetImageManager ( )->GetObject ( "Bullet" ) ) ;
	Shoot.GetSprite ( )->SetPosition ( this->Ship->GetSprite ( )->GetPosition ( ) ) ;
	this->Shoots.push_back ( Shoot ) ;
}