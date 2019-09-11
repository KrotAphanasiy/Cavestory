#include "input.h"//SDL.h included in input.h

//keeps track of a keyboard state  



/*gets called at the begining of each new frame
to reset the keys that are no longer relevant
*/
void Input::beginNewFrame() {
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

//key goes up
void Input::keyUpEvent(const SDL_Event &event) {
	this->_releasedKeys[event.key.keysym.scancode] = true;
}


//key goes up
void Input::keyDownEvent(const SDL_Event &event) {
	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;
}

//was certain key pressed
bool Input::wasKeyPressed(SDL_Scancode key) {
	return this->_pressedKeys[key];
}

//was certain key released
bool Input::wasKeyReleaased(SDL_Scancode key) {
	return this->_releasedKeys[key];
}

//is certain key being held
bool Input::isKeyHeld(SDL_Scancode key) {
	return this->_heldKeys[key];
}
