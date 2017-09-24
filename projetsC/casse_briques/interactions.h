#ifndef INTERACTIONS_H_INCLUDED
#define INTERACTIONS_H_INCLUDED

#include <stdlib.h>
#include "defines.h"
#include <math.h>
#include "objets.h"

float dist(Point* p1,Point* p2);
float maxi(float a,float b);
float abso(float a);
int IsinRectangle(Point* point,Bloc* bloc);
int collision(Balle *balle,Bloc *bloc);
void rebond(int i,Balle *balle,Bloc *bloc,Uint32 couleurs[]);



#endif // INTERACTIONS_H_INCLUDED
