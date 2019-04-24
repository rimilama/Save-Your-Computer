#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>

#include "intro.h"
#include "chapitre1.h"
#include "chapitre2.h"
#include "chapitre3.h"
#include "chapitre4.h"
#include "end.h"


int main(int argc, char** argv)
{
    //Initialisation SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        return 0;
    }

    //Initialisation TTF
    if(TTF_Init() == -1)
    {
        fprintf(stdout, "Échec de l'initialisation de TTF (%s)\n", TTF_GetError());
        return 0;
    }

    //Initialisation Mixer
    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096)==-1){
        fprintf(stdout, "Échec de l'initialisation du mixer (%s)\n", Mix_GetError());
    }

    Mix_Music* music_intro = Mix_LoadMUS("assets/music/musique_intro.mp3");
    Mix_PlayMusic(music_intro, -1);
    int val_chapitre = intro();
    Mix_HaltMusic();
    Mix_FreeMusic(music_intro);

    if(val_chapitre==1){
        Mix_Music* musique_chapitre1 = Mix_LoadMUS("assets/music/musique_chapitre1.mp3");
        Mix_PlayMusic(musique_chapitre1, -1);
        val_chapitre = chapitre1();
        Mix_HaltMusic();
        Mix_FreeMusic(musique_chapitre1);
    }else{
        Mix_CloseAudio();
        TTF_Quit();
        SDL_Quit();
        return 0;
    }

    if(val_chapitre==1){
        Mix_Music* musique_chapitre2 = Mix_LoadMUS("assets/music/musique_chapitre2.mp3");
        Mix_PlayMusic(musique_chapitre2, -1);
        val_chapitre = chapitre2();
        Mix_HaltMusic();
        Mix_FreeMusic(musique_chapitre2);
    }else{
        Mix_CloseAudio();
        TTF_Quit();
        SDL_Quit();
        return 0;
    }

    if(val_chapitre==1){
        Mix_Music* musique_chapitre3 = Mix_LoadMUS("assets/music/musique_chapitre3.mp3");
        Mix_PlayMusic(musique_chapitre3, -1);
        val_chapitre = chapitre3();
        Mix_HaltMusic();
        Mix_FreeMusic(musique_chapitre3);
    }else{
        Mix_CloseAudio();
        TTF_Quit();
        SDL_Quit();
        return 0;
    }

    if(val_chapitre==1){
        Mix_Music* musique_chapitre4 = Mix_LoadMUS("assets/music/musique_chapitre4.mp3");
        Mix_PlayMusic(musique_chapitre4, -1);
        chapitre4();
        Mix_HaltMusic();
        Mix_FreeMusic(musique_chapitre4);
    }else{
        Mix_CloseAudio();
        TTF_Quit();
        SDL_Quit();
        return 0;
    }

    if(val_chapitre==1){
        Mix_Music* music_intro = Mix_LoadMUS("assets/music/musique_intro.mp3");
        Mix_PlayMusic(music_intro, -1);
        fin();
        Mix_HaltMusic();
        Mix_FreeMusic(music_intro);
    }else{
        Mix_CloseAudio();
        TTF_Quit();
        SDL_Quit();
        return 0;
    }

    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();
    return 1;
}

