#include "SDLfunctions.h"

SDL_Surface* loadIMG(std::string filename) {
    SDL_Surface* temp = SDL_LoadBMP(filename.c_str()); // Carga la imagen
    SDL_Surface* surface = NULL;

    if (temp) { // Carga la imagen de forma correcta
        surface = SDL_DisplayFormat(temp); // Cambia la imagen a 32 bits
        SDL_FreeSurface(temp); // Libera la memoria.
    }

    return surface;
}

void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination) {
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source, NULL, destination, &offset);
}

void FreeIMG(SDL_Surface* surf, ...) {
    if (surf != NULL) {
        SDL_FreeSurface(surf);
    }
}
