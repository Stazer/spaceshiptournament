// Spaceship Tournament
// Ship.hpp

// Includeguard
#ifndef SHIP_HPP
#define SHIP_HPP

// Include other files
#include "Include.hpp"
#include "Animation.hpp"

// Prototypes
class ShipManager ;
class Application ;
class WeaponManager ;

// Ship class
class Ship
{
	private :

	protected :		
		// Health and power
		float Health ;
		float Power ;

		// Healthbar
		sf::Shape HealthBar ;

		// Power bar
		sf::Shape PowerBar ;

		// Pointer to the shipmanager
		class ShipManager * ShipManager ;

		// WeaponManager for each ship
		class WeaponManager * WeaponManager ;

		// Speed
		float Speed ;

		// Explosion handling
		TimeAniSprite * ExplosionSprite ;
		bool Exploded ;

		// Pointer to the application
		Application * Application ;

		// Clocks for the skills
		sf::Clock SpeedBoostTimer ;
		sf::Clock ShootTimer ;

		// Skills
		void SpeedBoost ( ) ;
		void Repair ( ) ;
		void SuperNova ( ) ;
		void Shoot ( ) ;

		// Identification number
		unsigned int Identification ;

		// Sprite
		sf::Sprite Sprite ;

	public :
		// Default constructor
		Ship ( unsigned int Identification ) ;

		// Default destructor
		~Ship ( ) ;

		// Method to render
		void Render ( ) ;

		// Method to set and get the ship manager pointer
		void SetShipManager ( class ShipManager * ShipManager ) ;
		class ShipManager * GetShipManager ( ) ;

		// Method to update the position and rotation
		void Update ( ) ;

		// Methods to get the sprite
		sf::Sprite * GetSprite ( ) ;

		// Methode which gives the identificaiton back
		unsigned int GetIdentification ( ) const ;

		// Method to get and handle the speed
		float GetSpeed ( ) const ;

		// Method to handle the input of a player
		void HandleInput ( ) ;

		// Methods to set and get the health and power
		void SetHealth ( const float Health ) ;
		void SetPower ( const float Power ) ;
		float GetHealth ( ) const ;
		float GetPower ( ) const ;

		// Behavior of a ship
		static float GetTopSpeed ( ) ;
		static float GetMinimalSpeed ( ) ;
		static float GetAcceleration ( ) ;
		static float GetSpeedBrake ( ) ;
		static float GetSpeedBoost ( ) ;
		static float GetFriction ( ) ;
		static float GetRotation ( ) ;
		static float GetRotationSpeedProportion ( ) ;
} ;

// Includeguard
#endif