#include <iostream>
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include <time.h>
#include <iomanip>

using namespace std;

class Main250721
{
public:
    int M1, M2, M3, M4, M5;
    char UserNameMain[20];
    char * strL,*strR;
    void DisplayM1(void);
    void CopyUsernameL();
    void CopyUsernameR();

};

#include "LogInMenu.cpp"
#include "LogIn.cpp"
#include "RegisterAndLogin.cpp"
#include "TypingMenu.cpp"
#include "Typing.cpp"
#include "Typing2.cpp"
#include "Typing3FuncTyping.cpp"
#include "Typing4FuncGenerateString.cpp"
#include "Graph.cpp"




inline void Main250721::CopyUsernameL()
{
    class Login LG2;
    strcpy(UserNameMain,LG2.UserName);
}

void Main250721::DisplayM1()
{
    cout << "M.M1: ";
    //cout << M1 << endl;
}

int main()
{
    class Main250721 M;
    class LogInMenu LM;
    class Login LG;
    class Registration RG;
    class Typing TY;
    class Graph GH;
    class TypingMenu TM;
LoginMenu:
    M.M1 = LM.FuncLogInMenu();
    //M.DisplayM1();
    M.M2 = 0;
    M.M3 = 0;
    switch (M.M1)
    {
    case 0:
    {
        //cout << "calling Login Function" << endl;
        M.M2 = LG.FuncLogin();
        // if (M.M2 != 2)
        // {
        //     cout << "Error" << endl;
        //     return 0;
        // }
        //class Main250721 M;
        //cout<<LG.UserName;
        //getch();
        strcpy(TY.UserNameMain,LG.UserName);
        //cout<<M.UserNameMain;
        //getch();
        
        if(M.M2==227)
        {
            goto LoginMenu;
        }

        
        break;
    }
    case 1:
    {
        //cout << "calling Sinup function" << endl;
        M.M3 = RG.FuncRegistration();
        if(M.M3==327)
        {
            goto LoginMenu;
        }
        // if (M.M3 != 2)
        // {
        //     cout << "Error" << endl;
        //     return 0;
        // }
        strcpy(TY.UserNameMain,RG.UserName);
        break;
    }
    case 2:
    {
        return 0;
        break;
    }
    }

    cout << "cloasing login page" << endl;

    M.M4 = 0;

    if ((M.M3 == 2) or (M.M2 == 2))
    {
    TypingMenu:
        
        M.M4 = TM.FuncTypingMenu();
    }

    if (M.M4 == 3)
    {
        //TY.FuncGenerateString();
        TY.FuncTyping(TY.UserNameMain);
        goto TypingMenu;
    }

    if (M.M4 == 4)
    {
        GH.FuncGraph(TY.UserNameMain);
        goto TypingMenu;
    }
    if (M.M4 == 5)
    {
        goto LoginMenu;
    }

    return 0;
}