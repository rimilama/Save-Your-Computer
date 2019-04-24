#include "intro.h"


//**************************************************************************************************************//
//
//  Description : Fonction qui execute l'introduction du jeu
//
//  Entrées : 1 entier
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
int intro(){
    Window Intro;
    Intro = crea_window(0, 0, 860, 680, "introduction");

    ecrire_text(Intro, "Save your computeur", 65, 3);
    ecrire_text(Intro, "Cliquez pour lancer l'histoire", 35, 1.5);

    SDL_Event event;
    int x = 2;
    while (x>0){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_MOUSEBUTTONDOWN:
                SDL_RenderClear(Intro.renderer);
                x--;
                if(x==1){
                    ecrire_text(Intro, "Votre ordinateur a été", 65, 3.5);
                    ecrire_text(Intro, "infecté par un virus.", 65, 2.6);
                    ecrire_text(Intro, "Vous allez devoir rentrer dans chaque composant", 35, 1.8);
                    ecrire_text(Intro, "de votre machine afin de les nettoyer.", 35, 1.6);
                    ecrire_text(Intro, "Cliquez pour sauver votre ordinateur", 35, 1.2);
                }
                break;
            case SDL_QUIT:
                return 0;
        }
    }
    SDL_DestroyRenderer(Intro.renderer);
    SDL_DestroyWindow(Intro.fenetre);
    return 1;
}
