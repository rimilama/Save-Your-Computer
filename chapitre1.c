#include "chapitre1.h"
#include <windows.h> //Bibliothèque permettant d'utiliser la fonction "Sleep()"


//**************************************************************************************************************//
//
//  Description : Fonction qui execute la première enigme
//
//  Entrées : 1 entier
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
int chapitre1(){
    Window Chapitre1;
    Chapitre1 = crea_window(0, 0, 860, 760, "Chapitre 1");

    ecrire_text(Chapitre1, "Chapitre 1", 65, 3.0);
    ecrire_text(Chapitre1, "Le disque dur", 65, 1.8);

    int x = 2;
    SDL_Event event;
    while (x>0){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_MOUSEBUTTONDOWN:
                SDL_RenderClear(Chapitre1.renderer);
                x--;
                if(x==1){
                    ecrire_text(Chapitre1, "Votre disque dur est malade !", 65, 3.5);
                    ecrire_text(Chapitre1, "A vous d'aider votre disque dur car il", 35, 2.5);
                    ecrire_text(Chapitre1, "n'arrive plus à écrire des informations", 35, 2.2);
                    ecrire_text(Chapitre1, "en mémoire.", 35, 2.0);
                    ecrire_text(Chapitre1, "(Attention vous n'aurez que 3 secondes pour observer)", 25, 1.7);
                    ecrire_text(Chapitre1, "GO ?!!", 65, 1.2);
                }
                break;
            case SDL_QUIT:
                return 0;
        }
    }


    int longueur = 0, hauteur = 0;
    SDL_GetWindowSize(Chapitre1.fenetre, &longueur, &hauteur);
    depart(&Chapitre1, longueur, hauteur);

    Window monstre1, monstre2, monstre3, monstre4, monstre5;
    affiche_monstre(&monstre1, &monstre2, &monstre3, &monstre4, &monstre5);
    int x_1, x_2, x_3, x_4, x_5, x_C, y_1, y_2, y_3, y_4, y_5, y_C;
    int ID = SDL_GetWindowID(Chapitre1.fenetre);
    int detr = 0;

    x=1;
    while (x>0){
        detr = 0;
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.windowID==ID){
                    SDL_GetWindowPosition(monstre1.fenetre, &x_1, &y_1);
                    SDL_GetWindowPosition(monstre2.fenetre, &x_2, &y_2);
                    SDL_GetWindowPosition(monstre3.fenetre, &x_3, &y_3);
                    SDL_GetWindowPosition(monstre4.fenetre, &x_4, &y_4);
                    SDL_GetWindowPosition(monstre5.fenetre, &x_5, &y_5);
                    SDL_GetWindowPosition(Chapitre1.fenetre, &x_C, &y_C);
                    if(x_C+62<x_1&&x_C+302>x_1+200&&y_C+40<y_1&&y_C+300>y_1+200){
                        if(x_C+600<x_2&&x_C+840>x_2+200&&y_C+15<y_2&&y_C+270>y_2+200){
                            if(x_C+610<x_3&&x_C+850>x_3+200&&y_C+500<y_3&&y_C+750>y_3+200){
                                if(x_C+345<x_4&&x_C+590>x_4+200&&y_C+300<y_4&&y_C+550>y_4+200){
                                    if(x_C+50<x_5&&x_C+290>x_5+200&&y_C+480<y_5&&y_C+730>y_5+200){
                                        destroy_monstre(monstre1, monstre2, monstre3, monstre4, monstre5);
                                        SDL_RenderClear(Chapitre1.renderer);
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
                        destroy_monstre(monstre1, monstre2, monstre3, monstre4, monstre5);
                        int longueur = 0, hauteur = 0;
                        SDL_GetWindowSize(Chapitre1.fenetre, &longueur, &hauteur);
                        depart(&Chapitre1, longueur, hauteur);
                        affiche_monstre(&monstre1, &monstre2, &monstre3, &monstre4, &monstre5);
                    }
                }
                break;
            case SDL_QUIT:
                return 0;
        }
    }

    felicitation(Chapitre1);

    SDL_DestroyRenderer(Chapitre1.renderer);
    SDL_DestroyWindow(Chapitre1.fenetre);

    return 1;
}


//**************************************************************************************************************//
//
//  Description : Procédure qui affiche les images dans le bon ordre
//
//  Entrées : /
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void depart(Window *window, int longueur, int hauteur){
    affiche_image(*window, "Assets/img/enigme1_faceA.jpg", 0, 0, 860, 760);
    Sleep(3000);
    affiche_image(*window, "Assets/img/enigme1_faceB.jpg", 0, 0, 860, 760);
    affiche_image(*window, "Assets/img/but.jpg", (longueur/2)-50, hauteur-100, 100, 50);
    ecrire_text(*window, "OK ?", 55, 1.11);
}


//**************************************************************************************************************//
//
//  Description : Fonction qui affiche séparement et place les differentes fenêtres
//
//  Entrées : /
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void affiche_monstre(Window *monstre1, Window *monstre2, Window *monstre3, Window *monstre4, Window *monstre5){
    *monstre1 = crea_window(50, 50, 200, 200, " ");
    affiche_image(*monstre1, "Assets/img/inv1.jpg", 0, 0, 200, 200);

    *monstre2 = crea_window(1600, 50, 200, 200, " ");
    affiche_image(*monstre2, "Assets/img/inv2.jpg", 0, 0, 200, 200);

    *monstre3 = crea_window(1700, 500, 200, 200, " ");
    affiche_image(*monstre3, "Assets/img/inv3.jpg", 0, 0, 200, 200);

    *monstre4 = crea_window(1500, 800, 200, 200, " ");
    affiche_image(*monstre4, "Assets/img/inv4.jpg", 0, 0, 200, 200);

    *monstre5 = crea_window(100, 600, 200, 200, " ");
    affiche_image(*monstre5, "Assets/img/inv5.jpg", 0, 0, 200, 200);
}


//**************************************************************************************************************//
//
//  Description : Procédure qui détruit les fenêtre à déplacer
//
//  Entrées : /
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void destroy_monstre(Window monstre1, Window monstre2, Window monstre3, Window monstre4, Window monstre5){
    SDL_DestroyRenderer(monstre1.renderer);
    SDL_DestroyWindow(monstre1.fenetre);

    SDL_DestroyRenderer(monstre2.renderer);
    SDL_DestroyWindow(monstre2.fenetre);

    SDL_DestroyRenderer(monstre3.renderer);
    SDL_DestroyWindow(monstre3.fenetre);

    SDL_DestroyRenderer(monstre4.renderer);
    SDL_DestroyWindow(monstre4.fenetre);

    SDL_DestroyRenderer(monstre5.renderer);
    SDL_DestroyWindow(monstre5.fenetre);
}
