#include "end.h"


//**************************************************************************************************************//
//
//  Description : Fonction qui execute la conclusion
//
//  Entrées : 1 entier
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
int fin(){
    Window End;
    End = crea_window(0, 0, 860, 680, "introduction");

    ecrire_text(End, "BRAVO !", 65, 3.5);
    ecrire_text(End, "En aidant vos composants, vous", 35, 2.5);
    ecrire_text(End, "avez sauvé votre ordinateur et il", 35, 2.2);
    ecrire_text(End, "vous en remercie.", 35, 2.0);
    ecrire_text(End, "END ?!!", 35, 1.2);

    SDL_Event event;
    int x = 2;
    while (x>0){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_MOUSEBUTTONDOWN:
                SDL_RenderClear(End.renderer);
                x--;
                break;
            case SDL_QUIT:
                return 0;
        }
    }

    felicitation(End);

    SDL_DestroyRenderer(End.renderer);
    SDL_DestroyWindow(End.fenetre);
    return 1;
}
