#include <stdlib.h>
#include <stdio.h>
#include "SDL.h"

SDL_Surface* affichage;

void initSDL(void);
void attendreTouche(void);
void setPixel(int x, int y, Uint32 coul);
void actualiser(void);
void dessinerEtoiles(void);

int main(int argc, char** argv)
{
  initSDL();
  dessinerEtoiles();
  actualiser();
  attendreTouche();
  return EXIT_SUCCESS;
}

void initSDL(void)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "Erreur à l'initialisation de la SDL : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  atexit(SDL_Quit);
  affichage = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);

  if (affichage == NULL) {
    fprintf(stderr, "Impossible d'activer le mode graphique : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  SDL_WM_SetCaption("Ciel étoilé", NULL);
}

void attendreTouche(void)
{
  SDL_Event event;

  do
    SDL_WaitEvent(&event);
  while (event.type != SDL_QUIT && event.type != SDL_KEYDOWN);
}

void setPixel(int x, int y, Uint32 coul)
{
  *((Uint32*)(affichage->pixels) + x + y * affichage->w) = coul;
}

void actualiser(void)
{
  SDL_UpdateRect(affichage, 0, 0, 0, 0);
}

void dessinerEtoiles(void)
{
  int i;

  for (i = 0; i < 100; i++)
    setPixel(rand() % 800, rand() % 600,
             SDL_MapRGB(affichage->format,
             rand() % 128 + 128, rand() % 128 + 128, rand() % 128 + 128));
}
