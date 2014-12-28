// Spaceship Tournament
// SuperNova.cpp

// Include other files
#include "Include.hpp"
#include "SuperNova.hpp"
#include "Application.hpp"
#include "ResourceManager.hpp"

// Constructor
SuperNova::SuperNova ( class Ship * Ship )
{
	this->Sprite.SetImage ( Application::GetInstancePointer ( )->GetImageManager ( )->GetObject ( "Nova" ) ) ;
	this->Sprite.SetCenter ( 250 , 250 ) ;
	this->Sprite.SetScale ( 0.1f , 0.1f ) ;
	this->Ship = Ship ;
	this->RunningSuperNova = false ;
}