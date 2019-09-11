//HOLDS EVERYTHING ABOUT GRAPHICS
#ifndef GRAPHICS_H
#define GRAPHICS_H


#include <SDL.h>
#include <map>
#include <string>

class Graphics {
public:
	Graphics();
	~Graphics();

	//loads image to _spriteSheets map if doesn`t already exist
	//as a result every image will be loaded once
	//returns the image from the map regardless of whether or not it was just loaded
	SDL_Surface* loadImage(const std::string &filePath);

	//draws texture to a certain part of the screen
	void blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);


	//renders everything to the screen
	void flip();

	//clears the screen
	void clear(); 


	//returns our renderer
	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	
	std::map<std::string, SDL_Surface*> _spriteSheets;


};

#endif
