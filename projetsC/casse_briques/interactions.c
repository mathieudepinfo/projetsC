#include "interactions.h"

float dist(Point* p1,Point* p2){

    return sqrt(pow((p1->x-p2->x),2)+pow((p1->y-p2->y),2));
}

float maxi(float a,float b){

    if(a<b){
        return b;
    }
    else{
        return a;
    }
}

float abso(float a){

    if(a<0.0){
        return -a;
    }
    else{
        return a;
    }
}

int IsinRectangle(Point* point,Bloc* bloc){

    if(     point->x>=(bloc->centre->x-bloc->lx)
        &&  point->x<=(bloc->centre->x+bloc->lx)
        &&  point->y>=(bloc->centre->y-bloc->ly)
        &&  point->y<=(bloc->centre->y+bloc->ly)
       ){

        return 1;
    }
    else{
        return 0;
    }
}

int collision(Balle *balle,Bloc *bloc)
{
    if(!(bloc->etat)) //si le bloc est mort
    {
        return 0;
    }
    else if (dist(balle->centre,bloc->centre)<(balle->rayon+maxi(bloc->lx,bloc->ly))){ //si on est relativement proche

        for(int i=0;i<NBER_OF_POINTS;i++){// on teste tout les points de la hitbox,

            if(IsinRectangle(balle->hitbox[i],bloc)){

                return i+1;// on retourne le point d'impact
            }
        }
        return 0;
    }

    else{
        return 0;
    }
}

void rebond(int i,Balle *balle,Bloc *bloc,Uint32 couleurs[])
{
    printf("%d, \n",i);
    if(bloc->etat==2){ //si c'est la barre

        if((balle->memory[i]->y)<=(bloc->centre->y-bloc->ly)) //la barre part de y=0 jusque y=HAUTEUR_BARRE
        {

            float d=balle->hitbox[i]->x-bloc->centre->x;
            //printf("ici %f \n",d);
            balle->vx=100*d/(bloc->lx);
            balle->vy*=-1;
        }
        else if((balle->memory[i]->x)<=(bloc->centre->x-bloc->lx)
             || (balle->memory[i]->x)>=(bloc->centre->x+bloc->lx))
        {
            balle->vx*=-1;
        }
    }
    else if(bloc->etat==1){ //si c'est un bloc vivant


        if((balle->memory[i]->x<=(bloc->centre->x-bloc->lx))
         ||(balle->memory[i]->x>=(bloc->centre->x+bloc->lx)))
        {
            balle->vx*=-1;
        }
        else if((balle->memory[i]->y<=(bloc->centre->y-bloc->ly))||(balle->memory[i]->y>=(bloc->centre->y+bloc->ly)))
        {
            balle->vy*=-1;
        }

        if (bloc->vie<1000){//si c'est pas un bord
            bloc->vie-=1;
        }

        if(bloc->vie<=0){
            bloc->etat=0;
        }

        else{
            bloc->couleur=couleurs[(bloc->vie-1)%10];
        }

    }

}


