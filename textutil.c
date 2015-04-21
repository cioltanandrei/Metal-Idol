#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "textutil.h"

void GotoXY(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int getConsoleWidth() {
  CONSOLE_SCREEN_BUFFER_INFO info;
  int width;

  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
  width = info.srWindow.Right - info.srWindow.Left + 1;

  return width;
}

int getConsoleHeight() {
  CONSOLE_SCREEN_BUFFER_INFO info;
  int height;

  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
  height = info.srWindow.Bottom - info.srWindow.Top + 1;

  return height;
}

void hideCursor() {
  HANDLE hOut;
  CONSOLE_CURSOR_INFO ConCurInf;

  hOut = GetStdHandle(STD_OUTPUT_HANDLE);

  ConCurInf.dwSize = 10;
  ConCurInf.bVisible = FALSE;

  SetConsoleCursorInfo(hOut, &ConCurInf);
}

void putChar( int x, int y, char ch ) {
  GotoXY(x, y);
  _putch(ch);
}

void putStr( int x, int y, char *s ) {
  GotoXY(x, y);
  _cprintf(s);
}

void putStrAlign( int y, char *s, enum ALIGN align ) {
  switch(align) {
  case LEFT:
    putStr(0, y, s);
    break;
  case CENTER:
    putStr((getConsoleWidth() - strlen(s)) / 2, y, s);
    break;
  case RIGHT:
    putStr((getConsoleWidth() - strlen(s)), y, s);
    break;
  }
}

int printASCIIArt( int y, char *s, enum ALIGN align ) {
  char *line;
  int i;

  line = strtok(s, "\n"); // Afiseaza linie cu linie
  i = 0;
  while(line != NULL) {
    putStrAlign(y + i, line, align);
    line = strtok(NULL, "\n");
    i++;
  }

  return i;
}

int printASCIIArtFromFile( int y, char *path, enum ALIGN align ) {
  FILE *file = fopen(path, "r");
  char *file_contents;
  long file_size;
  // Pune tot continutul fisierului intr-un string, apoi il paseaza functiei
  // printASCIIArt
  fseek(file, 0, SEEK_END);
  file_size = ftell(file);
  fseek(file, 0, SEEK_SET);
  file_contents = malloc(file_size + (sizeof(char)));
  fread(file_contents, file_size, sizeof(char), file);
  fclose(file);
  return printASCIIArt(y, file_contents, align);
}

int getKey( int key ) {
  return (GetAsyncKeyState(key) & 0x8000) > 0;
}

void setTextColor( int color ) {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void fillBackgroundCollor( int color ) {
  int i, j;
  system("color");
  for(i = 0; i < getConsoleHeight(); i++)
    for(j = 0; j < getConsoleWidth(); j++) {
      setTextColor(color);
      putChar(j, i, ' ');
    }
  GotoXY(0, 0);
}

void clearScreen() {
  system("cls");
}
