#include "game.h"

struct song {
  char name[100];
  char artist[100];
  char album[100];
  char path[100];
  int year;
  Mix_Music *musicObject;
};

struct song newSong(char name[100], char artist[100], char album[100], int year, char path[100]);
int freeSong(struct song *song);
