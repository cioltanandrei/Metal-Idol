#include "song.h"

struct song newSong(char name[100], char artist[100], char album[100], int year, char path[100]) {
  Mix_Music *musicObject = NULL;
  struct song song;

  strcpy(song.name, name);
  strcpy(song.artist, artist);
  strcpy(song.album, album);
  strcpy(song.path, path);
  song.year = year;
  musicObject = Mix_LoadMUS(song.path);
  song.musicObject = musicObject;

  return song;
}

int freeSong(struct song *song) {
  if(song != NULL)
    Mix_FreeMusic(song->musicObject);
  return 0;
}
