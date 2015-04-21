#include <windows.h>
#include <conio.h>

#define DEFAULT_CONSOLE_COLOR (BG_BLACK + BG_WHITE)

/* Face sa dispara cursorul de pe ecran, frumos pentru jocuri */
void hideCursor();

/* Sterge ecranul (folosind setarea actuala de culoare) */
void clearScreen();

/* Afiseaza caracterul 'ch' la coordonatele 'x' si 'y' */
void putChar( int x, int y, char ch );

/* Afiseaza sirul de caractere 's' la coordonatele 'x' si 'y' */
void putStr( int x, int y, char *s );

enum ALIGN {
    LEFT = -1,
  CENTER =  0,
   RIGHT =  1
};
/* Afiseaza sirul de caractere 's' la ordonata,
   aliniate la stanga, in centru sau la dreapta
*/
void putStrAlign( int y, char *s, enum ALIGN align );
/* Considerand s continutul unui fisier in care se afla un
   desen ASCII, functia afiseaza s la ordonata y.
   "Align" specifica in ce directie sa fie aliniat textul.
*/
int printASCIIArt( int y, char *s, enum ALIGN align );

/* La fel ca si functia printASCIIArt, doar ca textul este citit dintr-un fisier
*/
int printASCIIArtFromFile( int y, char *path, enum ALIGN align );

/*
#define FOREGROUND_BLUE	1
#define FOREGROUND_GREEN	2
#define FOREGROUND_RED	4
#define FOREGROUND_INTENSITY	8
#define BACKGROUND_BLUE	16
#define BACKGROUND_GREEN	32
#define BACKGROUND_RED	64
#define BACKGROUND_INTENSITY	128
#define ENABLE_ECHO_INPUT 4
*/
enum COLOR {
         BLACK      = 0,
         GREY       = FOREGROUND_BLUE+FOREGROUND_GREEN+FOREGROUND_RED,
         WHITE      = FOREGROUND_INTENSITY+GREY,
  INTENS_BLUE       = FOREGROUND_INTENSITY+FOREGROUND_BLUE,
  INTENS_GREEN      = FOREGROUND_INTENSITY+FOREGROUND_GREEN,
  INTENS_RED        = FOREGROUND_INTENSITY+FOREGROUND_RED,
         CYAN       = FOREGROUND_BLUE+FOREGROUND_GREEN,
  INTENS_CYAN       = FOREGROUND_INTENSITY+CYAN,
         MAGENTA    = FOREGROUND_RED+FOREGROUND_BLUE,
  INTENS_MAGENTA    = FOREGROUND_INTENSITY+MAGENTA,
         YELLOW     = FOREGROUND_RED+FOREGROUND_GREEN,
  INTENS_YELLOW     = FOREGROUND_INTENSITY+YELLOW,
         BG_BLACK   = 0,
         BG_GREY    = BACKGROUND_BLUE+BACKGROUND_GREEN+BACKGROUND_RED,
         BG_WHITE   = BACKGROUND_INTENSITY+BG_GREY,
  BG_INTENS_BLUE    = BACKGROUND_INTENSITY+BACKGROUND_BLUE,
  BG_INTENS_GREEN   = BACKGROUND_INTENSITY+BACKGROUND_GREEN,
  BG_INTENS_RED     = BACKGROUND_INTENSITY+BACKGROUND_RED,
         BG_CYAN    = BACKGROUND_BLUE+BACKGROUND_GREEN,
  BG_INTENS_CYAN    = BACKGROUND_INTENSITY+BG_CYAN,
         BG_MAGENTA = BACKGROUND_RED+BACKGROUND_BLUE,
  BG_INTENS_MAGENTA = BACKGROUND_INTENSITY+BG_MAGENTA,
         BG_YELLOW  = BACKGROUND_RED+BACKGROUND_GREEN,
  BG_INTENS_YELLOW  = BACKGROUND_INTENSITY+BG_YELLOW
};
/*
  Schimba culoarea textului ce va fi afisat de acum inainte. Exemplu:
  - setTextColor( BG_INTENS_YELLOW + INTENS_BLUE );
  va tipari text de culoare albastru intens pe un fundal galben intens.
*/
void setTextColor( int color );

void fillBackgroundCollor( int color );

/*
  Returneaza 1 daca tasta 'key' este apasata, 0 in caz contrar. key poate fi:
  - litera mare sau cifra pentru tasta respectiva
  - valori speciale, constante:
  VK_ESCAPE  - tasta Esc
  VK_SHIFT   - tasta Shift
  VK_CONTROL - tasta Ctrl
  VK_MENU    - tasta Alt
  VK_F1      - tasta F1 (similar celelalte taste Fx)
  VK_UP      - tasta sageata sus
  VK_DOWN    - tasta sageata jos
  VK_LEFT    - tasta sageata stinga
  VK_RIGHT   - tasta sageata dreapta
 */
int getKey( int key );

/* Returneaza nr. de coloane ale consolei. */
int getConsoleWidth();

/* Returneaza nr. de linii ale consolei */
int getConsoleHeight();

/*
  Asteapta (nu face nimic) vreme de 'msec' milisecunde
  Functie definita in windows.h, nu o redefinim aici :)
*/
// void Sleep( int msec );

