// Spaceship Tournament
// ApplicationState.cpp

// Include other files
#include "ApplicationState.hpp"
#include "Application.hpp"

// Default constructor
ApplicationState::ApplicationState ( )
{
	this->Application = Application::GetInstancePointer ( ) ;
}

// Default destructor
ApplicationState::~ApplicationState ( )
{
	this->Application = 0 ;
}