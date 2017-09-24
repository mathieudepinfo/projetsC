#ifndef OBJETS_H_INCLUDED
#define OBJETS_H_INCLUDED

#include <stdlib.h>
#include "SDL.h"
#include <math.h>
#include "defines.h"

typedef struct Point Point;

struct Point

{
    float x;
    float y;
};
typedef struct Bloc Bloc;

struct Bloc

{
    Point* centre;
    int lx;
    int ly;
    int vie;
    int etat;
    Uint32 couleur;
};

typedef struct Balle Balle;

struct Balle

{
    Point* centre;
    int vx;//vitesse en x
    int vy;//vitesse en y
    int rayon;
    Point** hitbox;
    Point** memory;
};
Point** copyP(Point** hitbox);
Point* createPoint(float x,float y);
Bloc *createBloc(int x, int y,int lx,int ly,int vie,Uint32 couleurs[]);
Balle *createBalle(int x, int y,int vx,int vy);

#endif // OBJETS_H_INCLUDED
