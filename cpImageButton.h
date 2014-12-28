//cpGUI - Copyright (c) 2009 Jason Cupp
//
//This software is provided 'as-is', without any express or implied warranty. 
//In no event will the authors be held liable for any damages arising from the 
//use of this software.
//
//Permission is granted to anyone to use this software for any purpose, including 
//commercial applications, and to alter it and redistribute it freely, subject to 
//the following restrictions:
//
//
//1. The origin of this software must not be misrepresented; you must not claim 
//that you wrote the original software. If you use this software in a product, an 
//acknowledgment in the product documentation would be appreciated but is not required.
//
//
//2. Altered source versions must be plainly marked as such, and must not be 
//misrepresented as being the original software.
//
//
//3. This notice may not be removed or altered from any source distribution.


#ifndef CPIMAGEBUTTON
#define CPIMAGEBUTTON

#include "cpGUI_base.h"
#include "cpObject.h"

namespace cp
{
	class cpImageButton : public cpObject
	{
	public:
		cpImageButton();
		cpImageButton(sf::RenderWindow *parent, cpGuiContainer *GUI, 
			sf::Image *image, float posx=0, float posy=0);
		void Draw();
		int CheckState(const sf::Input *input);
		bool SetSize(float width, float height);
		void SetPosition(float posx, float posy);
		void SetBackgroundColor(sf::Color color);
		void SetImage(sf::Image *image);
		void Show(bool show);

	private:
		sf::Sprite sprite;
	};
}

#endif
