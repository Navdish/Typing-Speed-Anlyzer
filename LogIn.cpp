// #include <iostream>
// #include <fstream>
// #include <conio.h>

// using namespace std;

class Login
{
public:
    fstream MyFile;
    char UserName[20];
    char EnteredPasword[20], TempCh[20], ch = 0;
    int i1, i7 = 0, i8 = 0, Match = 0, Now = 0;

    int FuncLogin();
    inline void ClearScreen();
};

inline void Login::ClearScreen()
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

int Login::FuncLogin()
{
    //static class Main250721 ML;
    //strcpy(M.UserNameMain,LG.UserName);
EnterUsername:
    cout << "Enter Your Username: ";
    for (i1 = 0; i1 < 20; i1++)
    {
    label6:
        //cout<<"1";
        UserName[i1] = tolower(_getch());
        //cout<<"2";

        if (UserName[i1] == 27)
        {
            return 227;
        }

        if ((i1 == 19) and (UserName[i1] != 13) and (UserName[i1] != 8))
        {
            UserName[i1] = '\0';
            goto label6;
        }

        if (!(((UserName[i1] > 32) and (UserName[i1] < 127)) or (UserName[i1] == 8) or (UserName[i1] == 13)))
        {
            UserName[i1] = '\0';
            goto label6;
        }
        // if(UserName[i1]==32)//space
        // {
        //     UserName[i1] = '\0';
        //     goto label6;
        // }

        if ((UserName[i1] == 13) and (i1 < 6))
        {
            UserName[i1] = '\0';
            goto label6;
        }

        if (UserName[i1] == 13)
        {
            cout << endl;
            UserName[i1] = '\0';
            //class Main250721 M;
            //strcpy(ML.UserNameMain, UserName);
            break;
        }
        if ((UserName[i1] == 8) and (i1 > 0))
        {
            cout << "\b \b";
            UserName[--i1] = '\0';
            i1--;
            continue;
        }
        if ((UserName[i1] == 8) and (i1 == 0))
        {
            UserName[i1] = '\0';
            goto label6;
        }
        cout << UserName[i1];
    }
start:
    MyFile.open(UserName, ios::in);
    cout << "Opening MyFile, " << UserName << ", with ios::in" << endl
         << endl;

    if (!MyFile)
    {
        cout << "No such file Exists" << endl;
    }
    else
    {
        cout << "File Exist" << endl
             << endl;
        MyFile >> noskipws; //this statement is to Turn Off Skip Whitespace Flag

        cout << "enter pasword: ";
        for (i7 = 0;; i7++)
        {
        label4:

            EnteredPasword[i7] = _getch();

            if (EnteredPasword[i7] == 27)
            {
                MyFile.close();
                ClearScreen();
                goto EnterUsername;
                //return 227;
            }

            if ((i7 == 19) and (EnteredPasword[i7] != 13) and (EnteredPasword[i7] != 8))
            {
                EnteredPasword[i7] = '\0';
                goto label4;
            }

            if (!(((EnteredPasword[i7] > 31) and (EnteredPasword[i7] < 127) and (EnteredPasword[i7] != 91) and (EnteredPasword[i7] != 93)) or (EnteredPasword[i7] == 13) or (EnteredPasword[i7] == 8)))
            {
                EnteredPasword[i7] = '\0';
                goto label4;
            }
            if ((EnteredPasword[i7] == 13) and (i7 < 6))
            {
                EnteredPasword[i7] = '\0';
                goto label4;
            }
            if (EnteredPasword[i7] == 13)
            {
                EnteredPasword[i7] = '\0';
                MyFile.close();
                cout << endl;
                break;
            }

            if ((EnteredPasword[i7] == 8) and (i7 > 0))
            {
                cout << "\b \b";
                EnteredPasword[--i7] = '\0';
                i7--;
                continue;
            }
            if ((EnteredPasword[i7] == 8) and (i7 == 0))
            {
                //cout<<" ";
                EnteredPasword[i7] = '\0';
                goto label4;
            }
            cout << EnteredPasword[i7];
        }
        cout << endl
             << endl;

        cout << "Entered Pasword: ";
        cout << EnteredPasword << endl
             << endl;

        //cout << "Character 1 from File: ";
        MyFile >> ch;
        //cout << ch << endl
        //     << endl;

        if (ch == '[')
        {
            MyFile >> ch;
            //cout << "Character 2 from File: ";
            //cout << ch << endl;
            Now = 0;
            for (i1 = 1; ch != ']'; i1++)
            {
                if (i1 == 1)
                {
                    Match = 0;
                }
                //cout << "Character " << i1 << " Entered: " << EnteredPasword[i1 - 1] << endl;
                if (EnteredPasword[i1 - 1] != ch)
                {
                    Match++;
                    Now = 1;
                    break;
                }
                MyFile >> ch;
                //cout << "Character " << i1 + 2 << " from File: ";
                //cout << "" << ch << endl;
            }
            cout << endl;
            MyFile.close();
            //cout << "MyFile Closed" << endl;
        }

        if (((Match < 3) and (Match > 0)) and (Now == 1))
        {
            cout << "Pasword is Wrong" << endl;

            cout << "Entered Password(before): ";
            for (i8 = 0; i8 <= i7; i8++)
            {
                cout << EnteredPasword[i8];
            }
            cout << endl;

            cout << "Entered Pasword(now): ";
            EnteredPasword[0] = '\0';
            cout << EnteredPasword << "." << endl;

            //cout << "ch: " << ch << endl;
            //cout << "Match" << Match << endl;
            //cout << "Now" << Now << endl;
            goto start;
        }
        if (Match == 3)
        {
            cout << "Try again" << endl;
            cout << "Entered Pasword: ";
            for (i8 = 0; i8 <= i7; i8++)
            {
                cout << EnteredPasword[i8];
            }
            cout << endl;
            cout << "ch: " << ch << endl;
            cout << "Match" << Match << endl;
            cout << "Now" << Now << endl;
            return 1;
        }
        if (Now == 0)
        {
            cout << "Pasword is Correct" << endl;
            cout << "Entered Pasword: ";
            for (i8 = 0; i8 <= i7; i8++)
            {
                cout << EnteredPasword[i8];
            }
            cout << endl;
            //cout << "ch: " << ch << endl;
            //cout << "Match" << Match << endl;
            //cout << "Now" << Now << endl;
            //cout<<UserName;
            getch();
            return 2;
        }
    }

    cout << "Error:NO IF STATEMENT IS USED" << endl;
    cout << "Entered Pasword: ";
    for (i8 = 0; i8 <= i7; i8++)
    {
        cout << EnteredPasword[i8];
    }
    cout << endl;
    cout << "ch: " << ch << endl;
    cout << "Match" << Match << endl;
    cout << "Now" << Now << endl;
    return 3;
}

// int main()
// {
//     class Login L;
//     L.Tech=L.FuncLogin();
//     return 0;
// }