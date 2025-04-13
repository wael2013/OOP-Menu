#ifndef METHODS_H
#define METHODS_H
#include <windows.h>
using namespace std;
void SetColorAndBackground(int ForgC, int BackC = 0)
{
  WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void clearscreen()
{
  system("cls");
}
void clearscreen(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#endif