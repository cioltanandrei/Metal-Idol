#include "game.h"
#include "song.h"

int lineCount = 0;

int main(int argc, char* argv[]) {
  SDL_Event e; // Un eveniment care s-a intamplat. Folosit pentru a detecta inchiderea programului
  char quit;
  Mix_Music *backgroundMusic;
  int option;

  if(!init()) { // Daca nu s-a petrecut nici o eroare la initializare
    quit = 0;
    hideCursor(); // Cursorul dispare
    //system("color 37"); // Seteaza culoarea de fundal
    fillBackgroundCollor(BG_CYAN + WHITE);
    if(!DEBUG) {
      putStr((getConsoleWidth() - 13) / 2, getConsoleHeight() / 2, "Se incarca...");
      Sleep(2500);
      putStr((getConsoleWidth() - 10) / 2, getConsoleHeight() / 2 + 1, "Degeaba...");
      Sleep(500);
    }
    clearScreen();
    backgroundMusic = Mix_LoadMUS(BACKGROUND_MUSIC_PATH);
    if(backgroundMusic == NULL)
      error("Nu s-a putut accesa fisierul cu melodia de fundal.");
    else
      Mix_PlayMusic(backgroundMusic, -1);
    option = buildMenu();
    if(option == 2)
      quit = 1;
    while(!quit) {
      while(SDL_PollEvent(&e) != 0) {
        if(e.type == SDL_QUIT)
          quit = 1;
      }
      if(getKey(VK_ESCAPE))
        quit = 1;
      Sleep(SLEEPCONST);
    }
    freeData();
  }
  return 0;
}

int init() { // Returneaza 0 daca totul a mers bine, 1 daca nu
  int ok = 1;
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    fprintf(stderr, "Nu s-a putut initializa SDL.\n");
    ok = 0;
  } else {
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
      fprintf(stderr, "Nu s-a putut initializa dispozitivul audio.\n");
      ok = 0;
    }
  }
  if(!ok)
    return 1;
  return 0;
}

int buildMenu() {
  lineCount += printASCIIArtFromFile(lineCount, BACKGROUND_ART_PATH, CENTER);
  lineCount += printASCIIArtFromFile(lineCount, SPLASH_ART_PATH, CENTER);
  char *options[] = {"Play", "Quit"};
  return buildOptionMenu(2, options);
}

int buildOptionMenu(int n, char* options[]) {
  int i;
  char str[100];
  int pressed;

  for(i = 0; i < n; i++) {
    sprintf(str, "%d) %s", i + 1, options[i]);
    putStrAlign(lineCount, str, LEFT);
    lineCount++;
  }
  while(getch() - '0' >= 1 && getch() - '0' <= n) {}
  return i;
}

int freeData() {
  Mix_CloseAudio();
  SDL_Quit();
  return 0;
}

void error(char const *error) {
  setTextColor(INTENS_RED);
  fprintf(stderr, error);
  exit(1);
}
