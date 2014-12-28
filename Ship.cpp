// Spaceship Tournament
// Ship.cpp

// Include other files
#include "Ship.hpp"
#include "Application.hpp"
#include "ResourceManager.hpp"
#include "ShipManager.hpp"
#include "Collision.hpp"
#include "WeaponManager.hpp"

// Default constructor
Ship::Ship ( unsigned int Identification )
{
	this->ShipManager = 0 ;
	this->Application = Application::GetInstancePointer ( ) ;
	this->Health = 100 ;
	this->Power = 100 ;
	this->Speed = 0.0f ;
	this->Exploded = false ;
	this->ExplosionSprite = new TimeAniSprite ( 24.0f ) ;
	this->ExplosionSprite->SetImage ( this->Application->GetImageManager ( )->GetObject ( "Explosion" ) ) ;
	this->ExplosionSprite->setSubRectSize ( sf::Vector2 <unsigned int> ( 320 , 240 ) ) ;
	this->ExplosionSprite->setNumFrames ( sf::Vector2 <unsigned int> ( 4 , 5 ) ) ;
	this->ExplosionSprite->SetCenter ( 320 / 2 , 240 / 2 ) ;
	this->PowerBar = sf::Shape::Rectangle ( sf::Vector2f ( 0 , 0 ) , sf::Vector2f ( 100 , 10 ) , sf::Color ( 0 , 0 , 255 , 255 ) ) ;
	this->PowerBar.SetCenter ( 50.0f , 5.0f ) ;
	this->HealthBar = sf::Shape::Rectangle ( sf::Vector2f ( 0 , 0 ) , sf::Vector2f ( 100 , 10 ) , sf::Color ( 255 , 0 , 0 , 255 ) ) ;
	this->HealthBar.SetCenter ( 50.0f , 5.0f ) ;
	this->SpeedBoostTimer.Reset ( ) ;
	this->ExplosionSprite->SetScale ( 5.0f , 5.0f ) ;
	this->WeaponManager = new class WeaponManager ( this ) ;
	this->Identification = Identification ;
	this->ShootTimer.Reset ( ) ;
}

// Default destructor
Ship::~Ship ( )
{
	delete this->WeaponManager ;
	delete this->ExplosionSprite ;
}

// Method to render
void Ship::Render ( )
{
	if ( this->Health > 0.0f )
	{
		this->Application->GetWindow ( )->Draw ( this->Sprite ) ;
		this->Application->GetWindow ( )->Draw ( this->HealthBar ) ;
		this->Application->GetWindow ( )->Draw ( this->PowerBar ) ;
		this->WeaponManager->Render ( ) ;
	}
	else
	{
		if ( ! this->Exploded )
			this->Application->GetWindow ( )->Draw ( * this->ExplosionSprite ) ;
	}
}

// Method whcih give the identification back
unsigned int Ship::GetIdentification ( ) const
{
	return this->Identification ;
}

// Method to handle the input of a player
void Ship::HandleInput ( )
{
	if ( this->Identification == 0 )
	{
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::W ) )
		{
			this->Speed += this->GetAcceleration ( ) * this->Application->GetWindow ( )->GetFrameTime ( ) ;
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::S ) )
		{
			this->Speed -= this->GetAcceleration ( ) * this->Application->GetWindow ( )->GetFrameTime ( ) ;
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::A ) )
		{
			this->GetSprite ( )->Rotate ( this->GetRotation ( ) * this->Application->GetWindow ( )->GetFrameTime ( ) ) ;
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::D ) )
		{
			this->GetSprite ( )->Rotate ( this->GetRotation ( ) * this->Application->GetWindow ( )->GetFrameTime ( ) * -1 ) ;
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Space ) )
		{
			this->Shoot ( ) ;
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Num1 ) )
		{
			this->SpeedBoost ( ) ;
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Num2 ) )
		{
			this->Repair ( ) ;
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Num3 ) )
		{
			this->SuperNova ( ) ;
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Num4 ) )
		{
			
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Num5 ) )
		{
			this->Health = 0.0f ;
		}
	}
	else
	{
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Up ) )
		{
			this->Speed += this->GetAcceleration ( ) * this->Application->GetWindow ( )->GetFrameTime ( ) ;
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Down ) )
		{
			this->Speed -= this->GetAcceleration ( ) * this->Application->GetWindow ( )->GetFrameTime ( ) ;
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Left ) )
		{
			this->GetSprite ( )->Rotate ( this->GetRotation ( ) * this->Application->GetWindow ( )->GetFrameTime ( ) ) ;
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Right ) )
		{
			this->GetSprite ( )->Rotate ( this->GetRotation ( ) * this->Application->GetWindow ( )->GetFrameTime ( ) * -1 ) ;
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Numpad0 ) )
		{
			this->Shoot ( ) ;
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Numpad1 ) )
		{
			this->SpeedBoost ( ) ;
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Numpad2 ) )
		{
			this->Repair ( ) ;
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Numpad3 ) )
		{
			this->SuperNova ( ) ;
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Numpad4 ) )
		{
			
		}
		if ( this->Application->GetWindow ( )->GetInput ( ).IsKeyDown ( sf::Key::Numpad5 ) )
		{
			this->Health = 0.0f ;
		}
	}
}

// Skills
void Ship::SpeedBoost ( )
{
	if ( this->SpeedBoostTimer.GetElapsedTime ( ) >= 5.0f && Power >= 25.0f)
	{
		this->Speed += Ship::GetSpeedBoost ( ) * this->Application->GetWindow ( )->GetFrameTime ( ) ;
		this->Power -= 25.0f ;
		this->SpeedBoostTimer.Reset ( ) ;
		if(this->Speed > Ship::GetTopSpeed())
			Speed = GetTopSpeed();
	}
}
void Ship::Repair ( )
{
	if ( this->Power == 100.0f )
	{
		this->Health += 25.0f ;
		this->Power = 0 ;
	}
}
void Ship::SuperNova ( )
{
	if ( this->Power >= 75.0f )
	{
		this->Power -= 75.0f ;
		this->WeaponManager->StartSuperNova ( ) ;
	}
}
void Ship::Shoot ( )
{
	if ( this->ShootTimer.GetElapsedTime ( ) >= 0.1f )
	{
		this->ShootTimer.Reset ( ) ;
		this->WeaponManager->AddShoot ( ) ;
	}
}

// Methods to get the sprite
sf::Sprite * Ship::GetSprite ( )
{
	return & this->Sprite ;
}

// Method to update the position and rotation
void Ship::Update ( )
{
	if ( this->Health > 0.0f )
	{
		if ( this->Identification == 0 )
		{
			if ( this->ShipManager->GetPlayer2 ( )->GetHealth ( ) > 0.0f && Collision::CircleTest ( this->Sprite , * this->ShipManager->GetPlayer2 ( )->GetSprite ( ) , 0.0f , 0.0f ) )
			{
				this->Health -= 10 * this->Application->GetWindow ( )->GetFrameTime ( ) ;
			}
		}
		else
		{
			if ( this->ShipManager->GetPlayer1 ( )->GetHealth ( ) > 0.0f  && Collision::CircleTest ( this->Sprite , * this->ShipManager->GetPlayer1 ( )->GetSprite ( ) , 0.0f , 0.0f ) )
			{
				this->Health -= 10 * this->Application->GetWindow ( )->GetFrameTime ( ) ;
			}
		}
		if ( this->Power < 100 )
			this->Power += 5 * this->Application->GetWindow ( )->GetFrameTime ( ) ;
		if ( this->Power > 100 )
			this->Power = 100.0f ;
		sf::Vector2f Position ;
		float Radian = this->Sprite.GetRotation ( ) * static_cast <float> ( PI ) / 180.0f ;
		Position.x = this->Speed * sin ( Radian ) ;
		Position.y = this->Speed * cos ( Radian ) ;
		this->Sprite.Move ( Position ) ;
		this->PowerBar.SetPosition ( this->Sprite.GetPosition ( ).x , this->Sprite.GetPosition ( ).y - this->Sprite.GetImage ( )->GetHeight ( ) / 2 - 50.0f ) ;
		this->PowerBar.SetScale ( this->Power / 100.0f , 1.0f ) ;
		this->HealthBar.SetPosition ( this->Sprite.GetPosition ( ).x , this->Sprite.GetPosition ( ).y - this->Sprite.GetImage ( )->GetHeight ( ) / 2 - 75.0f ) ;
		this->HealthBar.SetScale ( this->Health / 100.0f , 1.0f ) ;
		this->Speed -= Ship::GetFriction ( ) * this->Application->GetWindow ( )->GetFrameTime ( ) ;
		if ( this->Speed < Ship::GetMinimalSpeed ( ) )
			this->Speed = Ship::GetMinimalSpeed ( ) ;
		if ( this->Speed > ( Ship::GetTopSpeed ( ) ) )
			this->Speed = Ship::GetTopSpeed ( );
		this->ExplosionSprite->SetPosition ( this->Sprite.GetPosition ( ) ) ;
		this->WeaponManager->Update ( ) ;
	}
	else
	{
		if ( this->Exploded == false )
		{
			this->ExplosionSprite->update ( this->Application->GetWindow ( )->GetFrameTime ( ) ) ;
			if ( this->ExplosionSprite->getAniPhase ( ) == 19 )
				this->Exploded = true ;
		}
	}
	if ( this->Health > 100.0f )
		this->Health = 100.0f ;
	if ( this->Health < 0.0f )
		this->Health = 0.0f ;
}

// Method to get and handle the speed
float Ship::GetSpeed ( ) const
{
	return this->Speed ;
}

// Method to set the ship manager pointer
void Ship::SetShipManager ( class ShipManager * ShipManager )
{
	this->ShipManager = ShipManager ;
}
class ShipManager * Ship::GetShipManager ( )
{
	return this->ShipManager ;
}

// Methods to set and get the health and power
void Ship::SetHealth ( const float Health )
{
	this->Health = Health ;
}
void Ship::SetPower ( const float Power )
{
	this->Power = Power ;
}
float Ship::GetHealth ( ) const
{
	return this->Health ;
}
float Ship::GetPower ( ) const
{
	return this->Power ;
}

// Behavior of a ship
float Ship::GetTopSpeed ( )
{
	return 65.0f ;
}
float Ship::GetMinimalSpeed ( )
{
	return 0.0f ;
}
float Ship::GetAcceleration ( )
{
	return 2.5f ;
}
float Ship::GetSpeedBrake ( )
{
	return 5.0f ;
}
float Ship::GetSpeedBoost ( )
{
	return 30.0f ;
}
float Ship::GetFriction ( )
{
	return 0.25f ;
}
float Ship::GetRotation ( )
{
	return 120.0f ;
}
float Ship::GetRotationSpeedProportion ( )
{
	return 0.0f ;
}