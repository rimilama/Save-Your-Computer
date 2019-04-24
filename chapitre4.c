#include "chapitre4.h"
#include <windows.h> //Bibliothèque permettant d'utiliser la fonction "Sleep()"


//**************************************************************************************************************//
//
//  Description : Fonction qui execute la quatrième enigme
//
//  Entrées : 1 entier
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
int chapitre4(){
    Window Chapitre4;
    Chapitre4 = crea_window(0, 0, 860, 760, "Chapitre 4");

    ecrire_text(Chapitre4, "Chapitre 4", 65, 3.0);
    ecrire_text(Chapitre4, "Le processeur", 65, 1.8);

    int x = 3;
    SDL_Event event;
    while (x>0){
        SDL_PollEvent(&event);
        switch(event.type){
            case SDL_MOUSEBUTTONDOWN:
                SDL_RenderClear(Chapitre4.renderer);
                x--;
                if(x==1){
                    ecrire_text(Chapitre4, "Votre processeur vient", 65, 4.8);
                    ecrire_text(Chapitre4, "de court-circuiter !", 65, 3.5);
                    ecrire_text(Chapitre4, "Vous allez devoir résoudre l'équation", 35, 2.5);
                    ecrire_text(Chapitre4, "à la place du processeur afin qu'il puisse", 35, 2.2);
                    ecrire_text(Chapitre4, "l'exécuter.", 35, 2.0);
                    ecrire_text(Chapitre4, "GO ?!!", 65, 1.2);
                }
                break;
            case SDL_QUIT:
                return 0;
        }
    }

    affiche_image(Chapitre4, "Assets/img/page_calcul.jpg", 0, 0, 860, 760);
    int longueur = 0, hauteur = 0;
    SDL_GetWindowSize(Chapitre4.fenetre, &longueur, &hauteur);
    affiche_image(Chapitre4, "Assets/img/but.jpg", (longueur/2)-50, hauteur-80, 100, 50);
    ecrire_text(Chapitre4, "OK ?", 55, 1.08);
    Window chiffre1, chiffre2, chiffre3, chiffre4, chiffre5;
    affiche_chiffre(&chiffre1, &chiffre2, &chiffre3, &chiffre4, &chiffre5);
    int x_1, x_2, x_3, x_4, x_5, x_C, y_1, y_2, y_3, y_4, y_5, y_C;
    int ID = SDL_GetWindowID(Chapitre4.fenetre);
    int detr = 0;
    x=1;
    while (x>0){
        detr = 0;
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.windowID==ID){
                    SDL_GetWindowPosition(chiffre1.fenetre, &x_1, &y_1);
                    SDL_GetWindowPosition(chiffre2.fenetre, &x_2, &y_2);
                    SDL_GetWindowPosition(chiffre3.fenetre, &x_3, &y_3);
                    SDL_GetWindowPosition(chiffre4.fenetre, &x_4, &y_4);
                    SDL_GetWindowPosition(chiffre5.fenetre, &x_5, &y_5);
                    SDL_GetWindowPosition(Chapitre4.fenetre, &x_C, &y_C);
                    if((x_C+10<x_2&&x_C+246>x_2+200&&y_C+75<y_2&&y_C+318>y_2+200)||(x_C+10<x_5&&x_C+246>x_5+200&&y_C+75<y_5&&y_C+318>y_5+200)){
                        if((x_C+282<x_2&&x_C+518>x_2+200&&y_C+75<y_2&&y_C+318>y_2+200)||(x_C+282<x_5&&x_C+518>x_5+200&&y_C+75<y_5&&y_C+318>y_5+200)){
                            if(x_C+9<x_1&&x_C+244>x_1+200&&y_C+403<y_1&&y_C+647>y_1+200){
                                if((x_C+285<x_4&&x_C+648>x_4+200&&y_C+403<y_4&&y_C+648>y_4+200)||(x_C+285<x_3&&x_C+648>x_3+200&&y_C+403<y_3&&y_C+648>y_3+200)){
                                    if((x_C+616<x_4&&x_C+852>x_4+200&&y_C+226<y_4&&y_C+469>y_4+200)||(x_C+616<x_3&&x_C+852>x_3+200&&y_C+226<y_3&&y_C+469>y_3+200)){
                                        destroy_chiffre(chiffre1, chiffre2, chiffre3, chiffre4, chiffre5);
                                        SDL_RenderClear(Chapitre4.renderer);
                                        x--;
                                    }else{
                                        detr = 1;
                                    }
                                }else{
                                    detr = 1;
                                }
                            }else{
                                detr = 1;
                            }
                        }else{
                            detr = 1;
                        }
                    }else{
                        detr = 1;
                    }

                    if(detr==1){
                        destroy_chiffre(chiffre1, chiffre2, chiffre3, chiffre4, chiffre5);
                        affiche_chiffre(&chiffre1, &chiffre2, &chiffre3, &chiffre4, &chiffre5);
                    }
                }
                break;
            case SDL_QUIT:
                return 0;
        }
    }

    felicitation(Chapitre4);

    SDL_DestroyRenderer(Chapitre4.renderer);
    SDL_DestroyWindow(Chapitre4.fenetre);

    return 1;
}


//**************************************************************************************************************//
//
//  Description : Procédure affichant et placant les differentes fenêtres
//
//  Entrées : /
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void affiche_chiffre(Window *chiffre1, Window *chiffre2, Window *chiffre3, Window *chiffre4, Window *chiffre5){
    *chiffre1 = crea_window(558, 269, 200, 200, " ");
    affiche_image(*chiffre1, "Assets/img/chi10.jpg", 0, 0, 200, 200);

    *chiffre2 = crea_window(837, 269, 200, 200, " ");
    affiche_image(*chiffre2, "Assets/img/chi8.jpg", 0, 0, 200, 200);

    *chiffre3 = crea_window(558, 599, 200, 200, " ");
    affiche_image(*chiffre3, "Assets/img/chi4.jpg", 0, 0, 200, 200);

    *chiffre4 = crea_window(837, 599, 200, 200, " ");
    affiche_image(*chiffre4, "Assets/img/chi4.jpg", 0, 0, 200, 200);

    *chiffre5 = crea_window(1172, 423, 200, 200, " ");
    affiche_image(*chiffre5, "Assets/img/chi3.jpg", 0, 0, 200, 200);
}


//**************************************************************************************************************//
//
//  Description : Procédure detruisant les fenêtres avec les chiffres
//
//  Entrées : /
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void destroy_chiffre(Window chiffre1, Window chiffre2, Window chiffre3, Window chiffre4, Window chiffre5){
    SDL_DestroyRenderer(chiffre1.renderer);
    SDL_DestroyWindow(chiffre1.fenetre);

    SDL_DestroyRenderer(chiffre2.renderer);
    SDL_DestroyWindow(chiffre2.fenetre);

    SDL_DestroyRenderer(chiffre3.renderer);
    SDL_DestroyWindow(chiffre3.fenetre);

    SDL_DestroyRenderer(chiffre4.renderer);
    SDL_DestroyWindow(chiffre4.fenetre);

    SDL_DestroyRenderer(chiffre5.renderer);
    SDL_DestroyWindow(chiffre5.fenetre);
}
