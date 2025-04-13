#ifndef MENUITEM_H
#define MENUITEM_H
#include <iostream>
#include "methods.h"
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
#endif