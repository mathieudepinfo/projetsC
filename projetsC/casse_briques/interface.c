#include "interface.h"

int Isinfen(SDL_Surface* fenetre,int x,int y)
{
    if(0<x && x<fenetre->w && 0<y && y<fenetre->h)
    {
        return 1;
    }
    else{
        return 0;
    }
}
Uint32* initCouleurs(SDL_Surface* fenetre)
{
    Uint32* couleurs=malloc(sizeof(Uint32)*11);

    couleurs[0] = SDL_MapRGB(fenetre->format, 0x00, 0x00, 0x00);
    couleurs[1] = SDL_MapRGB(fenetre->format, 0x00, 0x00, 0x80);
    couleurs[2] = SDL_MapRGB(fenetre->format, 0x00, 0x80, 0x00);
    couleurs[3] = SDL_MapRGB(fenetre->format, 0x00, 0x80, 0x80);
    couleurs[4] = SDL_MapRGB(fenetre->format, 0x80, 0x00, 0x00);
    couleurs[5] = SDL_MapRGB(fenetre->format, 0x80, 0x00, 0x80);
    couleurs[6] = SDL_MapRGB(fenetre->format, 0x80, 0x80, 0x00);
    couleurs[7] = SDL_MapRGB(fenetre->format, 0xC0, 0xC0, 0xC0);
    couleurs[8] = SDL_MapRGB(fenetre->format, 0x80, 0x80, 0x80);
    couleurs[9] = SDL_MapRGB(fenetre->format, 0x00, 0x00, 0xFF);
    couleurs[10]= SDL_MapRGB(fenetre->format, 0xFF, 0xFF, 0xFF);

    return couleurs;
}

SDL_Surface* initSDL()
{
    SDL_Surface* fenetre=NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {

        fprintf(stderr, "Erreur à l'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    atexit(SDL_Quit);
    fenetre = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_SWSURFACE);

    if (fenetre == NULL) {
        fprintf(stderr, "Impossible d'activer le mode graphique : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_WM_SetCaption("Casse briques mammene", NULL);

    return fenetre;
}

void setPixel(SDL_Surface* fenetre,double x, double y, Uint32 coul)
{

  *((Uint32*)(fenetre->pixels) + (int)x + (int)y * fenetre->w) = coul;
}

void actualise(SDL_Surface* fenetre,Uint32 couleurs[],Balle* balle,Bloc** blocs,Bloc* barre)
{

    //remise a zero de toute la fenetre ( a optimiser)
    for(int i=0;i<fenetre->w;i++){
        for(int j=0;j<fenetre->h;j++){
            setPixel(fenetre,i,j,couleurs[0]);
        }
    }

    //actualisation des blocs (a optimiser)
    for(int i=0;i<103;i++)
    {
        for(int j=-blocs[i]->lx;j<blocs[i]->lx;j++)
        {
            for(int k=-blocs[i]->ly;k<blocs[i]->ly;k++)
            {
                if(Isinfen(fenetre,blocs[i]->centre->x+j,blocs[i]->centre->y+k)){
                if(blocs[i]->vie<=0)
                {
                    setPixel(fenetre,blocs[i]->centre->x+j,blocs[i]->centre->y+k,couleurs[0]);
                }
                else
                {
                    setPixel(fenetre,blocs[i]->centre->x+j,blocs[i]->centre->y+k,couleurs[blocs[i]->vie]);
                }
                }

            }

        }
    }

    //actualisation de la barre

    for(int j=-barre->lx;j<=barre->lx;j++)
    {
        for(int k=-HAUTEUR_BARRE/2;k<HAUTEUR_BARRE/2;k++)
        {
            if(Isinfen(fenetre,barre->centre->x+j,barre->centre->y+k))
            {
                setPixel(fenetre,barre->centre->x+j,barre->centre->y+k,couleurs[10]);
            }
        }

    }

    //actualiation de la balle
    for(int i=-RAYON_BALLE;i<=RAYON_BALLE;i++)
    {
        for(int j=-RAYON_BALLE;j<=RAYON_BALLE;j++)
        {

            if(((i*i+j*j)<=(balle->rayon*balle->rayon)) && Isinfen(fenetre,balle->centre->x+i,balle->centre->y+j))
            {
                setPixel(fenetre,balle->centre->x+i,balle->centre->y+j,couleurs[10]);

            }
        }
    }


    SDL_UpdateRect(fenetre, 0, 0, 0, 0);
}




