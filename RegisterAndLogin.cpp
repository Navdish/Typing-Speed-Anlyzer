class Registration
{
public:
    fstream RegFile;
    int i1, i2, Tech;
    char UserName[20];
    char Pass[20],RRR;
    int FuncRegistration();
    inline void ClearScreen();
};

inline void Registration::ClearScreen()
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

int Registration::FuncRegistration()
{
CoutUsername:
    cout << "Enter your Desired Username: ";
    for (i1 = 0;; i1++)
    {
    label2:
        //cout<<"1";
        UserName[i1] = tolower(_getch());
        //cout<<"2";

        if (UserName[i1] == 27)
        {
            return 327;
        }

        if ((i1 == 19) and (UserName[i1] != 13) and (UserName[i1] != 8))
        {
            UserName[i1] = '\0';
            goto label2;
        }

        if (!(((UserName[i1] > 32) and (UserName[i1] < 127)) or (UserName[i1] == 8) or (UserName[i1] == 13)))
        {
            UserName[i1] = '\0';
            goto label2;
        }

        // if(UserName[i1]==32)//space
        // {
        //     UserName[i1] = '\0';
        //     goto label2;
        // }

        if ((UserName[i1] == 13) and (i1 < 6))
        {
            UserName[i1] = '\0';
            goto label2;
        }

        if (UserName[i1] == 13)
        {
            cout << endl;
            UserName[i1] = '\0';
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
            goto label2;
        }
        cout << UserName[i1];
    }

    RegFile.open(UserName, ios::in);
    if (RegFile)
    {
        ClearScreen();
        cout << "This UserName Is Occupied , Try Another one " << endl;
        Above0RRR:
        RRR=_getch();
        if(RRR!=27)
        {
            goto Above0RRR;
        }
        else
        {
            ClearScreen();
        RegFile.close();
        }

        goto CoutUsername;
    }

    RegFile.open(UserName, ios::out);

    cout << "File Created" << endl
         << endl;

    cout << "Enter Password: ";
    RegFile << "[";
    for (i2 = 0;; i2++)
    {
    label4:
        Pass[i2] = _getch();

        if (Pass[i2] == 27)
        {
            RegFile.close();
            remove(UserName);
            ClearScreen();
            goto CoutUsername;
        }

        if ((i2 == 19) and (Pass[i2] != 13) and (Pass[i2] != 8))
        {
            Pass[i2] = '\0';
            goto label4;
        }

        if (!(((Pass[i2] > 31) and (Pass[i2] < 127) and (Pass[i2] != 91) and (Pass[i2] != 93)) or (Pass[i2] == 13) or (Pass[i2] == 8)))
        {
            Pass[i2] = '\0';
            goto label4;
        }
        if ((Pass[i2] == 13) and (i2 < 6))
        {
            Pass[i2] = '\0';
            goto label4;
        }
        if (Pass[i2] == 13)
        {
            Pass[i2] = '\0';
            cout << endl;
            break;
        }

        if ((Pass[i2] == 8) and (i2 > 0))
        {
            cout << "\b \b";
            Pass[--i2] = '\0';
            i2--;
            continue;
        }
        if ((Pass[i2] == 8) and (i2 == 0))
        {
            //cout<<" ";
            Pass[i2] = '\0';
            goto label4;
        }
        cout << Pass[i2];
    }
    for (int r = 0; r < i2; r++)
    {
        RegFile << Pass[r];
    }
    RegFile << "]";

    RegFile.close();
    cout << endl;
    cout << "Registration Complete" << endl
         << endl;

    return 2;
}