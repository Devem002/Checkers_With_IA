#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include "objects/Drawable.h"
#include "utils/SDLfunctions.h"
#include "objects/Game.h"

#include <iostream>

using namespace std;

SDL_Surface* fg = NULL, *bg = NULL, *screen = NULL;

const Uint32 fps = 40;
const Uint32 minframetime = 1000 / fps;

int main(int argc, char* argv[]) {
    // Intento de iniciar el SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        return 1;
    }

    // Creacion de la ventana
    screen = SDL_SetVideoMode(480,480,32,SDL_SWSURFACE);

    Drawable::screen = screen;

    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int initted=IMG_Init(flags);
    if( initted & flags != flags) {
        cout<<"could not init SDL_Image" << endl;
        cout<<"Reason: " << IMG_GetError() << endl;
    }

    if (screen == NULL) {
        return 1; // En caso de que se caiga la ventana
    } .

    // Setea el caption
    SDL_WM_SetCaption("CheckersAI", NULL);


    // Setea imagenes y ventana a 32 bits
    applySurface(0, 0, bg, screen);
    applySurface(180, 140, fg, screen);

    // Recarga la pantalla
    if (SDL_Flip(screen) == -1) {
        return 1;
    }

    Game game;
    bool running = true;
    SDL_Event event;
    Uint32 frametime;

    while (running)
    {

      frametime = SDL_GetTicks ();

      while (SDL_PollEvent (&event) != 0)
      {
			switch (event.type)
			{
			  case SDL_QUIT:    running = false;
								break;
			  case SDL_MOUSEBUTTONDOWN:
								game.click(event.button.x, event.button.y);
								break;
			  case SDL_MOUSEMOTION:
				  	  	  	  	game.mouseMove(event.motion.x, event.motion.y);
				  	  	  	  	break;
			}
      }

      if (SDL_GetTicks () - frametime < minframetime)
        SDL_Delay (minframetime - (SDL_GetTicks () - frametime));
      game.play();
      game.draw(screen);
      SDL_Flip( screen );

    }

    return 0;
}
