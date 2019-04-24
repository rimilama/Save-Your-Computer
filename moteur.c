#include "moteur.h"


//**************************************************************************************************************//
//
//  Description : Fonction crée une fenetre ainsi que son renderer qui lui est associé
//
//  Entrées : 1 structure
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
Window crea_window(int x, int y, int longueur, int hauteur, char *nom){
    Window window;
    if(x==0 && y==0){
        window.fenetre = SDL_CreateWindow(nom, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, longueur, hauteur, SDL_WINDOW_SHOWN);
    }else{
        window.fenetre = SDL_CreateWindow(nom, x, y, longueur, hauteur, SDL_WINDOW_SHOWN);
    }
    window.renderer = SDL_CreateRenderer(window.fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    return window;
}


//**************************************************************************************************************//
//
//  Description : Procédure qui ecrit du text dans une fenetre
//
//  Entrées : /
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void ecrire_text(Window window, char *text, float size, float position){
    TTF_Font *pPolice = TTF_OpenFont("assets/police/PixelOperator.ttf", size);
    SDL_Color white = {255, 255, 255};
    SDL_Surface *pText = TTF_RenderText_Blended(pPolice, text, white);
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(window.renderer, pText);
    SDL_FreeSurface(pText);
    int texW = 0, texH = 0, longueur = 0, hauteur = 0;
    SDL_QueryTexture(pTexture, NULL, NULL, &texW, &texH);
    SDL_GetWindowSize(window.fenetre, &longueur, &hauteur);
    SDL_Rect dstrect = {(longueur/2)-(texW/2), (hauteur/position)-(texH/2), texW, texH};
    SDL_RenderCopy(window.renderer, pTexture, NULL, &dstrect);
    SDL_RenderPresent(window.renderer);
    SDL_DestroyTexture(pTexture);
    TTF_CloseFont(pPolice);
}


//**************************************************************************************************************//
//
//  Description : Procédure qui affiche une image complète dans une fenêtre
//
//  Entrées : /
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void affiche_image(Window window, char *nom, int x, int y, int longueur, int hauteur){
    SDL_Surface* surface = IMG_Load(nom);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(window.renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect rect = {x,y,longueur,hauteur};
    SDL_RenderCopy(window.renderer, texture, NULL, &rect);
    SDL_RenderPresent(window.renderer);
    SDL_DestroyTexture(texture);
}


//**************************************************************************************************************//
//
//  Description : Procédure affichant une partie d'une image dans une fenêtre
//
//  Entrées : /
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void affiche_image_dynamique(Window window, char *nom, int longueur, int hauteur, int x ,int y){
    SDL_Surface* surface = IMG_Load(nom);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(window.renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect dst = {x, y, longueur, hauteur};
    SDL_Rect dst1 = {0, 0, longueur, hauteur};
    SDL_RenderClear(window.renderer);
    SDL_RenderCopy(window.renderer, texture, &dst, &dst1);
    SDL_RenderPresent(window.renderer);
    SDL_DestroyTexture(texture);
}


//**************************************************************************************************************//
//
//  Description : Procédure qui affiche le texte et lance la musique de reussite d'une enigme
//
//  Entrées : /
//
//  Sorties : /
//
//  Notes : /
//
//***************************************************************************************************************//
void felicitation(Window window){
    Mix_Music* felicitation = Mix_LoadMUS("assets/music/felicitations.mp3");
    Mix_HaltMusic();
    Mix_PlayMusic(felicitation, 0);
    ecrire_text(window, "FELICITATIONS !", 120, 2.3);
    Sleep(4000);
    Mix_HaltMusic();
    Mix_FreeMusic(felicitation);
}
