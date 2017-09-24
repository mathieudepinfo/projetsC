#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include "objets.h"
#include "defines.h"
#include <stdlib.h>
#include <stdio.h>
#include "SDL.h"
#include <unistd.h>

int Isinfen(SDL_Surface* fenetre,int x,int y);
Uint32* initCouleurs(SDL_Surface* fenetre);
SDL_Surface* initSDL();
void setPixel(SDL_Surface* fenetre,double x,double y, Uint32 coul);
void actualise(SDL_Surface* fenetre,Uint32 couleurs[],Balle* balle,Bloc** blocs,Bloc* barre);
#endif // INTERFACE_H_INCLUDED
