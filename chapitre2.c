#include "chapitre2.h"


//**************************************************************************************************************//
//
//  Description : Fonction qui execute la deuxième enigme
//
//  Entrées : 1 entier
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
int chapitre2(){
    Window Chapitre2;
    Chapitre2 = crea_window(0, 0, 860, 760, "Chapitre 2");

    ecrire_text(Chapitre2, "Chapitre 2", 65, 3.0);
    ecrire_text(Chapitre2, "L'alimentation", 65, 1.8);

    int x = 3;
    SDL_Event event;
    while (x>0){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_MOUSEBUTTONDOWN:
                SDL_RenderClear(Chapitre2.renderer);
                x--;
                if(x==1){
                    ecrire_text(Chapitre2, "Votre alimentation est blessée !", 65, 3.5);
                    ecrire_text(Chapitre2, "La lumière a disparu, c'est donc à vous et aidé de", 35, 2.5);
                    ecrire_text(Chapitre2, "votre fenêtre pour détruire les virus afin de", 35, 2.2);
                    ecrire_text(Chapitre2, "soigner l'alimentation.", 35, 2.0);
                    ecrire_text(Chapitre2, "GO ?!!", 65, 1.2);
                }
                break;
            case SDL_QUIT:
                return 0;
        }
    }

    SDL_DestroyRenderer(Chapitre2.renderer);
    SDL_DestroyWindow(Chapitre2.fenetre);
    Chapitre2 = crea_window(0, 0, 160, 160, "Chapitre 2");

    SDL_ShowCursor(SDL_DISABLE);

    charlie(Chapitre2, "Assets/img/vert.jpg", -10000, 100, 730,10000);
    charlie(Chapitre2, "Assets/img/rouge.jpg", 1170,1425,-10000,128);
    charlie(Chapitre2, "Assets/img/bleu.jpg",320,540,515,720);

    SDL_ShowCursor(SDL_ENABLE);

    SDL_DestroyRenderer(Chapitre2.renderer);
    SDL_DestroyWindow(Chapitre2.fenetre);
    Chapitre2 = crea_window(0, 0, 860, 760, "Chapitre 2");

    felicitation(Chapitre2);

    SDL_DestroyRenderer(Chapitre2.renderer);
    SDL_DestroyWindow(Chapitre2.fenetre);


    return 1;
}


//**************************************************************************************************************//
//
//  Description : Procédure qui fait fonctionner le déplacement de la fenêtre selon le déplacement de la souris
//
//  Entrées : /
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void charlie(Window window, char *nom, int x_Val_min, int x_Val_max, int y_Val_min, int y_Val_max){
    int x = 1;
    int x_C,y_C, x_S, y_S;
    SDL_Event event;
    SDL_GetWindowPosition(window.fenetre, &x_C, &y_C);
    affiche_image_dynamique(window, nom, 160, 160, x_C, y_C);
    uint32_t timer = SDL_GetTicks();
    while (x>0){
        SDL_PollEvent(&event);
        switch(event.type){
            case SDL_MOUSEBUTTONDOWN:
                SDL_GetWindowPosition(window.fenetre, &x_C, &y_C);
                if(x_C>x_Val_min&&x_C<x_Val_max &&y_C>y_Val_min&&y_C<y_Val_max){
                    x--;
                }
                break;
        }
        if (SDL_GetTicks() - timer > 50) {
            timer = SDL_GetTicks();
            SDL_GetGlobalMouseState(&x_S, &y_S);
            affiche_image_dynamique(window, nom, 160, 160, x_S - 80, y_S - 80);
            SDL_SetWindowPosition(window.fenetre, x_S - 80, y_S - 80);
        }
    }
    SDL_RenderClear(window.renderer);
}
