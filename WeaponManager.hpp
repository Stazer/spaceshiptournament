// Spaceship Tournament
// WeaponManager.hpp

// Includeguard
#ifndef WEAPONMANAGER_HPP
#define WEAPONMANAGER_HPP

// Include other files
#include "Include.hpp"
#include <list>
#include "Shoot.hpp"

// Prototypes
class Ship ;
class Application ;
class Shoot ;

// Weaponmanager
class WeaponManager
{
	private :
		// Ship
		class Ship * Ship ;

		// SuperNova Sprite
		sf::Sprite SuperNova ;

		// Running SuperNova
		bool RunningSuperNova ;

		// Default constructor
		WeaponManager ( ) ;

		// Shoots 
		std::list <Shoot> Shoots ;

	protected :

	public :
		// Constructor
		WeaponManager ( class Ship * Ship ) ;

		// Default destructor
		~WeaponManager ( ) ;

		// Method to update the logic of the weapons
		void Update ( ) ;

		// Method to render the weapon effects
		void Render ( ) ;

		// Skills
		void StartSuperNova ( ) ;
		void AddShoot ( ) ;
} ;

// Includeguard
#endif