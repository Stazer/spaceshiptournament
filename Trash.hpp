// Spaceship Tournament
// Trash.hpp

// Includeguard
#ifndef TRASH_HPP
#define TRASH_HPP

// Include other files
//
/*
#ifndef M_PI
#define M_PI 3.1415926535f
#endif

inline float GetLength(const sf::Vector2f& Vector)
{
	return sqrt(Vector.x*Vector.x + Vector.y*Vector.y);
}

sf::Vector2f CalculateDirection(const sf::Vector2f& vPosition, const sf::Vector2f& vDestination)
{
	float fDistance = sqrt((vDestination.x - vPosition.x)*(vDestination.x - vPosition.x) +
										(vDestination.y - vPosition.y)*(vDestination.y - vPosition.y));

	return sf::Vector2f((vDestination.x - vPosition.x)/fDistance, (vDestination.y - vPosition.y)/fDistance);
};

float GetDegrees(const sf::Vector2f &Direction)
{
	if(Direction.y < 0)
		if(Direction.x < 0)
			return -acos(Direction.y)*180/M_PI+360;
		else
			return acos(Direction.y)*180/M_PI;
	else
		if(Direction.x < 0)
			return asin(Direction.x)*180/M_PI+360;
		else
			return asin(Direction.x)*180/M_PI;
};

inline sf::Vector2f getDirection (float direction)
{
	direction *= M_PI/180;
	return sf::Vector2f(sin(direction), cos(direction));
};

inline void RotateSprite(sf::Sprite *Sprite, const sf::Vector2f &Direction)
{
	Sprite->SetRotation(GetDegrees(Direction));
};

// erstmal als globale funktion
 int updateDirection(const sf::Vector2f& myPos, const sf::Vector2f& myDirection, const sf::Vector2f& targetPos)
{
	sf::Vector2f DifferentialDirectionVector(CalculateDirection(myPos, targetPos));
	float DirectionDegreesTarget = GetDegrees(DifferentialDirectionVector);
	float Differenz = GetDegrees(myDirection) - DirectionDegreesTarget;
	if(Differenz < -180 || Differenz > 180)
		Differenz *= -1 ;    
	if(Differenz < 0)
		return 1;
	else
		return -1;
}

// Update method to update the logic the position and the rotation of an artifical intelligence
void ArtificialIntelligence::Update ( )
{
	if ( ! Target )
	{
		this->TargetShip = this->ShipManager->GetPlayer ( ) ;
		this->Target = true ;
		
	}
	this->Speed = 250.0f * this->Application->GetWindow ( )->GetFrameTime ( ) ;
	float beweglichkeit = 100; // grad die sekunde/
	
	float m_DirectionDegrees = this->Sprite.GetRotation() + beweglichkeit * this->Application->GetWindow()->GetFrameTime() *
				updateDirection(this->Sprite.GetPosition(), getDirection(this->Sprite.GetRotation()), this->TargetShip->GetSprite()->GetPosition());
	float Radian = m_DirectionDegrees * M_PI / 180.0f ;
	sf::Vector2f Position ( std::sin ( Radian ) * Speed , std::cos ( Radian ) * Speed ) ;
	this->Sprite.Move ( Position ) ;
	this->Sprite.SetRotation ( m_DirectionDegrees ) ;
	Ship::Update();
}*/

// INcludeguard
#endif