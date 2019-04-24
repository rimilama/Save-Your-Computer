#include "chapitre3.h"


//**************************************************************************************************************//
//
//  Description : Fonction qui execute la troisième enigme
//
//  Entrées : 1 entier
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
int chapitre3(){
    Window Chapitre3;
    Chapitre3 = crea_window(0, 0, 860, 760, "Chapitre 3");

    ecrire_text(Chapitre3, "Chapitre 3", 65, 3.0);
    ecrire_text(Chapitre3, "La RAM", 65, 1.8);

    int x = 3;
    SDL_Event event;
    while (x>0){
        SDL_PollEvent(&event);
        switch(event.type){
            case SDL_MOUSEBUTTONDOWN:
                SDL_RenderClear(Chapitre3.renderer);
                x--;
                if(x==1){
                    ecrire_text(Chapitre3, "Le virus vous a enfermé", 65, 4.5);
                    ecrire_text(Chapitre3, "dans votre RAM !", 65, 3.5);
                    ecrire_text(Chapitre3, "Vous devais vous en échapper avant que le", 35, 2.5);
                    ecrire_text(Chapitre3, "virus n'éteigne votre ordinateur vous faisant ainsi", 35, 2.2);
                    ecrire_text(Chapitre3, "disparaître pour toujours.", 35, 2.0);
                    ecrire_text(Chapitre3, "GO ?!!", 65, 1.2);
                }
                break;
            case SDL_QUIT:
                return 0;
        }
    }

    SDL_DestroyRenderer(Chapitre3.renderer);
    SDL_DestroyWindow(Chapitre3.fenetre);

    Window ampoule;
    ampoule = crea_window(100, 100, 200, 200, "");
    affiche_image(ampoule, "Assets/img/ampoule_off.bmp", 0, 0, 200, 200);

    Window fire;
    fire = crea_window(500, 500, 200, 200, "");
    affiche_image(fire, "Assets/img/zippo.bmp", 0, 0, 200, 200);

    Window corde;
    corde = crea_window(1600, 0, 150, 1080, "");
    affiche_image_dynamique(corde, "Assets/img/corde.jpg", 150, 1080, 0, 920);

    Window end;
    end = crea_window(1200, 1200, 200, 200, "");
    int ID = SDL_GetWindowID(end.fenetre);



    int lumiere = 0;
    x = 1;
    int x_zippo=0, y_zippo=0, x_ampoule=0, y_ampoule=0;
    int y_souris_av, y_souris_ap;
    int onclick=0, cliquer=0;
    while(x>0){
        while(SDL_PollEvent(&event)){
            SDL_GetWindowPosition(ampoule.fenetre, &x_ampoule, &y_ampoule);
            SDL_GetWindowPosition(fire.fenetre, &x_zippo, &y_zippo);
            SDL_RenderClear(ampoule.renderer);
            SDL_RenderClear(end.renderer);
            if(x_zippo<x_ampoule+200&&y_zippo<y_ampoule+200&&y_zippo>y_ampoule-200&&x_zippo>x_ampoule-200){
                affiche_image(ampoule, "Assets/img/ampoule_on.bmp", 0, 0, 200, 200);
                affiche_image(end, "Assets/img/exit.bmp", 0, 0, 200, 200);
                lumiere = 1;
            }else{
                affiche_image(ampoule, "Assets/img/ampoule_off.bmp", 0, 0, 200, 200);
                affiche_image(end, "Assets/img/black.jpg", 0, 0, 200, 200);
                lumiere = 0;
            }
            if(event.type == SDL_MOUSEBUTTONDOWN){
                onclick=1;
                cliquer++;
                if(cliquer==1){
                        y_souris_av = event.button.y;
                }
            }else if(event.type==SDL_MOUSEBUTTONUP){
                onclick=0;
                cliquer=0;
            }
            if(event.type == SDL_MOUSEMOTION){
                if(onclick==1){
                    y_souris_ap = event.motion.y;
                    affiche_image_dynamique(corde, "Assets/img/corde.jpg", 150, 1080, 0, 950-(y_souris_ap - y_souris_av));
                    SDL_SetWindowPosition(end.fenetre,1200, 1200-(y_souris_ap - y_souris_av));
                }
            }
            if(lumiere==1&&event.type==SDL_MOUSEBUTTONUP&&event.button.windowID==ID){
                x--;
            }
        }
    }

    SDL_DestroyRenderer(ampoule.renderer);
    SDL_DestroyWindow(ampoule.fenetre);
    SDL_DestroyRenderer(fire.renderer);
    SDL_DestroyWindow(fire.fenetre);
    SDL_DestroyRenderer(end.renderer);
    SDL_DestroyWindow(end.fenetre);
    SDL_DestroyRenderer(corde.renderer);
    SDL_DestroyWindow(corde.fenetre);

    Chapitre3 = crea_window(0, 0, 860, 760, "Chapitre 3");

    felicitation(Chapitre3);

    SDL_DestroyRenderer(Chapitre3.renderer);
    SDL_DestroyWindow(Chapitre3.fenetre);

    return 1;
}
