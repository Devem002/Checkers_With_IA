#ifndef SDLFUNCTIONS_H_
#define SDLFUNCTIONS_H_

#include <SDL/SDL.h>
#include <string>

SDL_Surface* loadIMG(std::string); // Carga la imagen
void applySurface(int, int, SDL_Surface*, SDL_Surface*); // Aplica la imagen
void FreeIMG(SDL_Surface*, ...);


#endif
