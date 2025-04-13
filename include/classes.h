#include <iostream>
#include <windows.h>

#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED			4
#define MAGENTA		5
#define BROWN			6
#define LIGHTGRAY		7
#define DARKGRAY		8
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA		13
#define YELLOW			14
#define WHITE			15

#define Enter 13
#define Esc 27
#define Up 72
#define Down 80

using namespace std;
void SetColorAndBackground(int ForgC, int BackC = 0)
{
  WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

class MenuItem
{
public:
    string name;
    int backColor;
    int foreColor;
    virtual void MenuAction(void *) = 0;
    virtual void Display()
    {
        SetColorAndBackground(foreColor, backColor);
        cout << name << endl;
    }
};
class MenuItemNew: public MenuItem
{
public:
    void MenuAction(void * ptr)
    {
        system("cls");
        cout << "New" << endl;
        system("pause");
    }
    MenuItemNew()
    {
        name = "New";
    }
};
class MenuItemDisplay: public MenuItem
{
public:
    void MenuAction(void * ptr)
    {
        system("cls");
        cout << "Display" << endl;
        system("pause");
    }
    MenuItemDisplay()
    {
        name = "Display";
    }
};
class MenuItemExit: public MenuItem
{
public:
    void MenuAction(void * ptr)
    {
        system("cls");
        bool* flag=(bool*)ptr;
        *flag=false;
        system("pause");
    }
    MenuItemExit()
    {
        name = "Exit";
    }
};