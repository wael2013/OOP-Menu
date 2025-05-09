#include <iostream>
#include"classes.h"
#include"Menu.h"
#include<conio.h>

using namespace std;
int main(int argc, char *argv[])
{
   // menu_Method();
   Menu menu(3,WHITE,BLACK,BLACK,WHITE);
    menu.AddMenuItem(new MenuItemNew());
    menu.AddMenuItem(new MenuItemDisplay());
    menu.AddMenuItem(new MenuItemExit());
    menu.Run(nullptr);

    cout << "Hello world!" << std::endl;
    system("pause");
}

void menu_Method()
{
    MenuItem *Menu[3] =
        {
            new MenuItemNew(),
            new MenuItemDisplay(),
            new MenuItemExit()};
    int highlight = 0;
    bool flag = true;
    do
    {
        system("cls");
        for (int i = 0; i < 3; i++)
        {
            if (i == highlight)
            {
                Menu[i]->backColor = WHITE;
                Menu[i]->foreColor = BLACK;
            }
            else
            {
                Menu[i]->backColor = BLACK;
                Menu[i]->foreColor = WHITE;
            }

            Menu[i]->Display();
        }
        char key = getch();
        switch (key)
        {
        case -32:
            key = getch();
            switch (key)
            {
            case 72:
                if (highlight > 0)
                {
                    highlight--;
                }
                break;
            case 80:
                if (highlight < 2)
                {
                    highlight++;
                }
                break;
            default:
                break;
            }

            break;

        case Enter:
            if (highlight == 2)
            {
                flag = false;
                Menu[highlight]->MenuAction(&flag);
            }
            else
            {
                void *p = nullptr;
                Menu[highlight]->MenuAction(p);
            }
            break;
        }
    } while (flag);
}
