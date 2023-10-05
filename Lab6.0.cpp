// Lab6.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

//Finds the difference between the color to change and reference. Returns true if they are similar. 
bool closeColors(Color reference, Color toChange) 
{
	int r_dif = abs(reference.r - toChange.r);
	int g_dif = abs(reference.g - toChange.g);
	int b_dif = abs(reference.b - toChange.b);

	float color_dif = r_dif * g_dif * b_dif / 3;

	if (color_dif < 3)
	{ 
		return true; 
	}

	else 
	{
		return false;
	}
	

}


int main() {
	//Defines the images.
	string background = "images1/backgrounds/winter.png";
	string foreground = "images1/characters/yoda.png";
	Texture backgroundTex;

	//Handle issues where the images couldn't load. 
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}

	//Copies textures to the image. 
	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	Vector2u sz = backgroundImage.getSize();

	Color green = foregroundImage.getPixel(0, 0);

	//For loop that will replace each pixel 
	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {
			
			Color compareColor = foregroundImage.getPixel(x, y);
			if (closeColors(compareColor,green)) 
			{
				Color replacement = backgroundImage.getPixel(x, y);
				foregroundImage.setPixel(x, y, replacement);
			}
			
			
		}
	}
	// By default, just show the foreground image
	RenderWindow window(VideoMode(1024, 768), "Here's the output");
	Sprite sprite1;
	Texture tex1;
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);

}
