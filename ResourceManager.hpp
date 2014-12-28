// Spaceship Tournament
// ResourceManager.hpp

// Includeguard
#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

// Include other files
#include "Include.hpp"

template <class Type>
class ResourceManager
{
	private :
		// Dynamic array which contains
		// all objects and a dynamic array
		// which contains the names
		Type * Objects ;
		std::string * Names ;


		// Size af the dynamic array
		unsigned int Size ;

		// Intern method to add a object
		void InternAddObject ( const Type Object , std::string Name = "" )
		{
			Type * NewObjects = new Type [ this->Size + 1 ] ;
			std::string * NewNames = new std::string [ this->Size + 1 ] ;
			for ( unsigned int CurrentObject = 0 ; CurrentObject < this->Size ; CurrentObject++ )
			{
				NewObjects [ CurrentObject ] = this->Objects [ CurrentObject ] ;
				NewNames [ CurrentObject ] = this->Names [ CurrentObject ] ;
			}
			NewObjects [ this->Size ] = Object ;
			NewNames [ this->Size ] = Name ;
			delete [ ] this->Objects ;
			this->Objects = NewObjects ;
			delete [ ] this->Names ;
			this->Names = NewNames ;
			this->Size++ ;
		}

	protected :

	public :
		// Default constructor
		ResourceManager ( )
		{
			this->Objects = 0 ;
			this->Names = 0 ;
			this->Size = 0 ;
		}

		// Default destructor
		~ResourceManager ( )
		{
			this->Size = 0 ;
			delete [ ] this->Objects ;
			this->Objects = 0 ;
			delete [ ] this->Names ;
			this->Names = 0 ;
		}

		// Method which returns the size of
		// the string
		unsigned int GetSize ( ) const
		{
			return this->Size ;
		}

		// Method and overloaded operator
		// to add a object
		void AddObject ( const Type Object , const std::string Name = "" )
		{
			this->InternAddObject ( Object , Name ) ;
		}
		void operator += ( const Type Object )
		{
			this->InternAddObject ( Object ) ;
		}

		// Method and overloaded operator
		// to get a object
		Type & GetObject ( const unsigned int Element ) const
		{
			return this->Objects [ Element ] ;
		}
		Type & GetObject ( const std::string & Name ) const
		{
			for ( unsigned int CurrentName = 0 ; CurrentName < this->Size ; CurrentName++ )
			{
				if ( this->Names [ CurrentName ] == Name )
					return this->Objects [ CurrentName ] ;
			}
			return this->Objects [ 0 ] ;
		}
		Type operator [ ] ( const unsigned int Element ) const
		{
			return this->Objects [ Element ].GetObjectInstance ( ) ;
		}
} ;

// Includeguard
#endif