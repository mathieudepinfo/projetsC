#include "objets.h"

Point** copyP(Point** hitbox)
{
    Point** cp=malloc(sizeof(Point*)*NBER_OF_POINTS);
    for(int i=0;i<NBER_OF_POINTS;i++)
    {
        cp[i]=createPoint(hitbox[i]->x,hitbox[i]->y);
    }
    return cp;
}
Point* createPoint(float x,float y)
{

    Point* point=malloc(sizeof(point));
    point->x=x;
    point->y=y;

    return point;
}
Bloc* createBloc(int x, int y,int lx,int ly,int vie,Uint32 couleurs[])
{

    Bloc* bloc=malloc(sizeof(Bloc));

    float x1=(float) x;
    float y1=(float) y;
    bloc->centre=createPoint(x1,y1);

    bloc->lx=lx;
    bloc->ly=ly;

    bloc->vie=vie;
    if(vie>=MAX_VIE){ //si on est la barre
        bloc->etat=2;
        bloc->couleur=couleurs[0];
    }
    else{
    bloc->etat=1;
    bloc->couleur=couleurs[vie-1];
    }
    return bloc;
}

Balle* createBalle(int x, int y,int vx,int vy)
{
    Balle* balle=malloc(sizeof(Balle));

    float x1=(float) x;
    float y1=(float) y;
    balle->centre=createPoint(x1,y1);

    balle->rayon=RAYON_BALLE;
    balle->vx=vx;
    balle->vy=vy;
    balle->hitbox=malloc(sizeof(Point*)*NBER_OF_POINTS);
    int theta=0;
    for(int i=0;i<NBER_OF_POINTS;i++)
    {

        balle->hitbox[i]=createPoint( (balle->centre->x+balle->rayon*cos(2*theta*Pi/NBER_OF_POINTS))
                    ,(balle->centre->y+balle->rayon*sin(2*theta*Pi/NBER_OF_POINTS))
                    );
        theta++;

    }

    balle->memory=copyP(balle->hitbox);

    return balle;
}

