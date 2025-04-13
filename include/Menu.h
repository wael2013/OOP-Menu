#ifndef MENU_H
#define MENU_H
#include "define.h"
#include <conio.h>
#include <iostream>
#include"methods.h"
#include"MenuItem.h"
using namespace std;
struct MenuColor
{
    int foreColor;
    int backColor;
    MenuColor(int c, int bc)
    {
        foreColor = c;
        backColor = bc;
    }
};

class Menu
{
private:
    int choice;
    MenuItem **ptr;
    int itemsCount;
    int size;
    MenuColor normal;
    MenuColor selected;

public:
    Menu():normal(WHITE,BLACK),selected(BLACK,WHITE)
    {
        ptr = NULL;
        itemsCount = 0;
        choice = 0;

    }
    Menu(int s,int normalColor,int normalback,int selectedColor,int selectedback):
    normal(normalColor, normalback),selected(selectedColor, selectedback)
    {
        size = s;
        itemsCount = 0;
        ptr = new MenuItem *[s];
        choice = 0;
    }
    void AddMenuItem(MenuItem *item)
    {
        if (itemsCount < size)
        {
            ptr[itemsCount] = item;
            itemsCount++;
        }
    }
    void Display()
    {
        SetColorAndBackground(WHITE,BLACK);
        system("cls");
        for (int i = 0; i < itemsCount; i++)
        {
            if (i == choice)
            {
                ptr[i]->backColor = selected.backColor;
                ptr[i]->foreColor = selected.foreColor;
            }
            else
            {
                ptr[i]->backColor = normal.backColor;
                ptr[i]->foreColor = normal.foreColor;
            }

            ptr[i]->Display();
        }
    }
    void Run(void *data)
    {
        bool flag = true;
        do
        {

            Display();

            // TODO add logic here
            char key = getch();
            switch (key)
            {
            case -32:
            {
                key = getch();
                case Down:
                choice++;
                if (choice == itemsCount)
                {
                    choice = 0;
                }
                break;
            case Up:
                choice--;
                if (choice == -1)
                {
                    choice = itemsCount - 1;
                }
                break;
            }
            break;
            case Enter:
                SetColorAndBackground(WHITE,BLACK);
                system("cls");
                if (choice == itemsCount - 1)
                {
                    flag = false;
                    break;
                }
                ptr[choice]->MenuAction(data);
                break;
            default:
                break;
            }
        } while (flag);
    }
};
#endif