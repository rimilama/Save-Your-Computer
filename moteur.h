#ifndef MOTEUR_H_INCLUDED
#define MOTEUR_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <windows.h>

typedef struct Window{
    SDL_Window* fenetre;
    SDL_Renderer* renderer;
}Window;

Window crea_window(int,int,int,int,char*);
void ecrire_text(Window,char*,float,float);
void affiche_image(Window,char*,int,int,int,int);
void affiche_image_dynamique(Window,char*,int,int,int,int);
void felicitation();

#endif // MOTEUR_H_INCLUDED
