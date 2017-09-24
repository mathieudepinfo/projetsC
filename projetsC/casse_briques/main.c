#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include "objets.h"
#include "interactions.h"
#include "interface.h"
#include <unistd.h>



void initpartie(SDL_Surface* fenetre,Uint32 couleurs[]);
void partie(SDL_Surface* fenetre,Bloc* barre,Bloc** blocs,Balle* balle,Uint32 couleurs[]);


int main()
{
    initSDL();//création de notre fenetre
    SDL_Surface* fenetre=SDL_GetVideoSurface();

    Uint32* couleurs=initCouleurs(fenetre); //creation d'un panel de couleurs
    initpartie(fenetre,couleurs);
    printf("LA PARTIE EST FINIE");
    return EXIT_SUCCESS;
}


void initpartie(SDL_Surface* fenetre,Uint32 couleurs[])
{

    Bloc *barre=createBloc(WIDTH/2-10,HEIGHT-HAUTEUR_BARRE/2,200,HAUTEUR_BARRE,200000,couleurs);
    Balle *balle=createBalle(WIDTH/2,HEIGHT-HAUTEUR_BARRE/2-RAYON_BALLE-50,0,VITESSE_BALLE);
    Bloc **blocs=malloc(sizeof(Bloc*)*103);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("b= %d \n",(10*i+j));
            *(blocs+10*i+j)=createBloc(300+i*30,200+j*30,15,15,rand()%10,couleurs);
        }

    }
    blocs[100]=createBloc(0,HEIGHT/2,1,HEIGHT/2+2,1500,couleurs);
    blocs[101]=createBloc(WIDTH,HEIGHT/2,1,HEIGHT/2+2,1500,couleurs);
    blocs[102]=createBloc(WIDTH/2,0,WIDTH/2+2,1,1500,couleurs);
    partie(fenetre,barre,blocs,balle,couleurs);
}
void partie(SDL_Surface* fenetre,Bloc* barre,Bloc** blocs,Balle* balle,Uint32 couleurs[])
{
    SDL_Event event;
    int continuer=1;
    int t0 = 0, t1 = 0;

    while(continuer)
    {
        t0=SDL_GetTicks();
        SDL_PollEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;
        }

        int a;
        for(int i=0;i<103;i++)
        {
            a=collision(balle,blocs[i]);
            if(a)
            {

                printf("%d, %d,%d \n",a,balle->vx,balle->vy);
                rebond(a-1,balle,blocs[i],couleurs);
            }
        }
        a=collision(balle,barre);

        if(a)
            {

                printf("%d, %d,%d \n",a,balle->vx,balle->vy);
                rebond(a-1,balle,barre,couleurs);
            }

        actualise(fenetre,couleurs,balle,blocs,barre);

        balle->centre->x+=(1.0/VITESSE_BALLE)*balle->vx;
        balle->centre->y+=(1.0/VITESSE_BALLE)*balle->vy;
        balle->memory=copyP(balle->hitbox);
        for(int i=0;i<NBER_OF_POINTS;i++)
        {

            balle->hitbox[i]->x+=(1.0/VITESSE_BALLE)*balle->vx;
            balle->hitbox[i]->y+=(1.0/VITESSE_BALLE)*balle->vy;
        }

        if(balle->centre->y>HEIGHT)
        {
            continuer=0;
            printf("perdu \n");
        }
        t1=SDL_GetTicks();
        while((t1-t0)<((1.0/VITESSE_BALLE)*1000)){

            t1=SDL_GetTicks();
        }

    }

}
