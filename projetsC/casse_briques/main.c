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

    Bloc *barre=createBloc(WIDTH/2,HEIGHT-HAUTEUR_BARRE/2,30,HAUTEUR_BARRE,200000,couleurs);
    Balle *balle=createBalle(WIDTH/2,HEIGHT-HAUTEUR_BARRE/2-RAYON_BALLE-50,0,1);
    Bloc **blocs=malloc(sizeof(Bloc*)*103);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("b= %d \n",(10*i+j));
            *(blocs+10*i+j)=createBloc(300+i*30,200+j*30,15,15,1+rand()%9,couleurs);
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
    int compteur=0;
    int dx;
    int a;
    int mem;
    SDL_WM_GrabInput( SDL_GRAB_ON );

    while(continuer)
    {
        t0=SDL_GetTicks();
        while(SDL_PollEvent(&event)){

            switch(event.type)
            {
            case SDL_QUIT:
                continuer=0;
                break;

            case SDL_MOUSEMOTION:

                dx=5+VITESSE_BARRE*(event.motion.x-barre->centre->x)/WIDTH;

                break;

            case SDL_KEYDOWN:
                if(event.key.keysym.sym==SDLK_a){
                    SDL_WM_GrabInput( SDL_GRAB_OFF );
                }
                else if(event.key.keysym.sym==SDLK_q){
                    dx=-VITESSE_BARRE/10.0;
                }
                else if(event.key.keysym.sym==SDLK_d){
                    dx=VITESSE_BARRE/10.0;
                }

                break;
            case SDL_KEYUP:
                dx=0;
                break;
            }
        }
        barre->centre->x+=dx;


        for(int i=0;i<103;i++)
        {
            a=collision(balle,blocs[i]);
            if(a && ((i+1)!=mem))//on ne peut pas taper deux fois le meme bloc
            {
                mem=i+1;
                //printf("%d, %d,%d \n",a,balle->vx,balle->vy);
                rebond(a-1,balle,blocs[i],couleurs);
            }
        }
        a=collision(balle,barre);

        if(a && (mem!=0))
            {

                mem=0;
                rebond(a-1,balle,barre,couleurs);
                //printf("%d, %d,%d \n",a,balle->vx,balle->vy);
            }

        actualise(fenetre,couleurs,balle,blocs,barre);

        balle->centre->x+=0.02*VITESSE_BALLE*balle->vx/100;
        balle->centre->y+=0.02*VITESSE_BALLE*balle->vy;
        balle->memory=copyP(balle->hitbox);

        for(int i=0;i<NBER_OF_POINTS;i++)
        {

            balle->hitbox[i]->x+=0.02*VITESSE_BALLE*balle->vx/100;
            balle->hitbox[i]->y+=0.02*VITESSE_BALLE*balle->vy;
        }

        if(balle->centre->y>HEIGHT)
        {
            continuer=0;
            printf("perdu \n");
        }
        t1=SDL_GetTicks();
        while((t1-t0)<20){
            t1=SDL_GetTicks();
        }

    }

}
