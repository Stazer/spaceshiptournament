// Spaceship Tournament
// ShipManager.hpp

// Includeguard
#ifndef SHIPMANAGER_HPP
#define SHIPMANAGER_HPP

// Include other files
#include "Include.hpp"
#include "Ship.hpp"

// ShipManager class
class ShipManager
{
	private :
		// Player 1
		class Ship * Player1 ;

		// Player 2
		class Ship * Player2 ;

		// CollisionCircle
		bool RenderCollisionCircle ;

	protected :

	public :
		// Default constructor
		ShipManager ( ) ;

		// Default destructor
		~ShipManager ( ) ;

		// Method to create the shipmanager
		void Create ( ) ;

		// Update method to update the logic of the ships
		void Update ( ) ;

		// Method to set the render cillision circle variable
		void SetRenderCollisionCircle ( bool RenderCollisionCircle ) ;

		// Render method to render the ships
		void Render ( ) ;

		// HandleInput method to handle the input of the player
		void HandleInput ( ) ;

		// Methods to get the private members
		class Ship * GetPlayer1 ( ) const ;
		class Ship * GetPlayer2 ( ) const ;
} ;

// Includeguard
#endif