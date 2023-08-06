// #include <iostream>
// #include <conio.h>
// #include <windows.h>

// using namespace std;
class TypingMenu
{
private:
public:
    int Tec, Value, Remainder;
    char CharValue;

    inline void ClearScreen()
    {

        HANDLE hStdOut;
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        DWORD count;
        DWORD cellCount;
        COORD homeCoords = {0, 0};

        hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hStdOut == INVALID_HANDLE_VALUE)
            return;

        /* Get the number of cells in the current buffer */
        if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))
            return;
        cellCount = csbi.dwSize.X * csbi.dwSize.Y;

        /* Fill the entire buffer with spaces */
        if (!FillConsoleOutputCharacter(
                hStdOut,
                (TCHAR)' ',
                cellCount,
                homeCoords,
                &count))
            return;

        /* Fill the entire buffer with the current colors and attributes */
        if (!FillConsoleOutputAttribute(
                hStdOut,
                csbi.wAttributes,
                cellCount,
                homeCoords,
                &count))
            return;

        /* Move the cursor home */
        SetConsoleCursorPosition(hStdOut, homeCoords);
    }

    inline void ArrowOrNo2(int remainder, int Reference)
    {
        if (remainder == Reference)
        {
            cout << "-->";
        }
        else
        {
            cout << "   ";
        }
    }
    int FuncTypingMenu()
    {

        ClearScreen();

        for (int i1 = 0;; i1++)
        {

            if (i1 == 0)
            {
                //cout << "if statement, condition i==0            ";
                CharValue = 80;
                Value = 2;
            }
            if (CharValue == 13)
            {
                //case 13:
                //{

                //cout << "case 13< enter" << endl<< endl;
                return Remainder + 3;
                //break;
                //}
            }
            if ((i1 % 2 == 0))
            {

                cout << "Typing Practice: Login Menu" << endl;

                switch (CharValue)
                {

                case 72:
                {
                    cout << "case 72: Up" << endl
                         << endl;
                    Value += 2;

                    break;
                }
                case 80:
                {
                    cout << "case 80: Down" << endl
                         << endl;
                    Value++;

                    break;
                }

                default:
                {

                    cout << "Error1: default statement of switch case in LogIn Menu" << endl
                         << "No Use of this Button Here" << endl
                         << endl;
                    break;
                }
                }

                Remainder = (Value % 3);
                cout << "Remainder: " << Remainder << endl;

                ArrowOrNo2(Remainder, 0);
                cout << "Practice" << endl;

                ArrowOrNo2(Remainder, 1);
                cout << "Graph" << endl;

                ArrowOrNo2(Remainder, 2);
                cout << "Log Out" << endl;
            }

        Cout1Getch:
            //cout<<"1";
            CharValue = getche();
            //cout<<"2";

            if ((!(CharValue == 80)) and (!(CharValue == 72)) and (!(CharValue == 13)))
            {
                //cout << "yes";
                //cout << "i1 " << i1 << endl;
                //getche();
                if (i1 % 2 == 1)
                {
                    goto Cout1Getch;
                }
            }
            else
            {
                ClearScreen();
            }

            //system("CLS");
            //ClearScreen();
        }
    }
};

// int main()
// {
//     class LogInMenu LM;
//     LM.FuncLogInMenu();
//     return 0;
// }
