#ifndef GAME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include <string.h>
#include "textutil.h"
#include "constants.h"

#define DEBUG 1
#define SLEEPCONST 10

int init(); // Initializeaza toate sistemele
int buildMenu(); // Construieste meniul de la inceput

void error(char const *error); // Tranteste o eroare si opreste programul
int freeData(); // Elibereaza datele

int buildOptionMenu(int n, char* options[]);
#define GAME_H_INCLUDED
#endif
