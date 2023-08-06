// #include <iostream>
// #include <fstream>
// #include <conio.h>
// #include <windows.h>

// using namespace std;

class Graph
{
public:
    fstream GraphFile;
    int GraphFileInteger = 0, g1, g2, g3, NoOfLetters, Digits[10], YParameter, XParameter, NoOfDigits = 0, Fix = 0, Power, YaxisTypingSpeed = 0, XaxisTime = 0;
    char GraphFileCharacter, exit;
    long int GraphTypingSpeed = 0;
    void FuncGraph(char UNG[20]);
    inline void ClearScreen();
};

inline void Graph::ClearScreen()
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

void Graph::FuncGraph(char UNG[20])
{
    GraphFile.open(UNG, ios::in);
    if (GraphFile.eof())
    {
        cout << "File does not exist" << endl;
    }
    else
    {
        cout << "File Exists" << endl;
    }
    cout << "Opened file GraphFile,using GraphFile,in ios::in mode" << endl;
    GraphFile >> GraphFileCharacter;
    //cout << "GraphFileCharacter 1: " << GraphFileCharacter << endl;
    //getch();

    g2 = 2;
    do
    {

        GraphFile >> GraphFileCharacter;
        //cout << "GraphFileCharacter " << g2 << ": ";
        //cout << GraphFileCharacter << endl;
        g2++;
        //getch();

    } while (GraphFileCharacter != ']');

    cout << "Typing Speed(horizontal axis) v/s"
         << " No of Letters Typed(vertical axis)" << endl
         << endl;
    cout << "Typing Speed : "
         << "1) One Unit = 10 Letters/min"
         << endl
         << "               "
         << "2) Increasing From Left to right" << endl
         << endl;
    cout << "No of Letters: "
         << "1) One Unit = 10 Letters"
         << endl
         << "               2) Decreasing Downward" << endl
         << endl;

    cout << "+";
    // while (YaxisTypingSpeed < 50)
    for (YaxisTypingSpeed = 0; YaxisTypingSpeed < 50; YaxisTypingSpeed++)
    {
        cout << "+";
    }
    //cout<<YaxisTypingSpeed;
    cout << endl;

    for (NoOfLetters = 0;;)
    {
        if (GraphFile.eof())
        {
            GraphFile.close();
            //cout << "\b\b";
        //ClearScreen();
        AboveExit:
            exit = _getch();
            if (exit != 27)
            {
                goto AboveExit;
            }
            else
            {
                break;
            }
        }
        NoOfDigits++;
        GraphFile >> GraphFileCharacter;
        //cout<<GraphFileCharacter<<endl;
        //getch();
        //cout<<"go";
        if (GraphFileCharacter == ',')
        {
            NoOfLetters += 10;
            Fix = NoOfDigits - 1;
            while (NoOfDigits != 1)
            {
                NoOfDigits--;
                Power = 1;
                for (g3 = 1; g3 < NoOfDigits; g3++)
                {
                    Power = (Power * 10);
                }
                GraphTypingSpeed = (GraphTypingSpeed + (Digits[Fix - NoOfDigits] * Power));
                //cout<<"NoOfDigits: "<<NoOfDigits<<" GraphTypingSpeed: "<<GraphTypingSpeed<<" int(Digits[NoOfDigits-1]): "<<(Digits[NoOfDigits-1])<<" ";
                //getch();
            }
            if (GraphTypingSpeed == 0)
            {
                goto AfterIfElse;
            }
            YParameter = int((GraphTypingSpeed) / 10);

            if (YParameter < 51)
            {
                for (g1 = 0; g1 <= YParameter; g1++)
                {
                    cout << "|";
                }
                //cout << "(" << NoOfLetters << "," << GraphTypingSpeed << ")";
                cout << endl;
            }
            else
            {
                for (g1 = 0; g1 < 51; g1++)
                {
                    cout << "|";
                }
                cout << "(" << NoOfLetters << "," << GraphTypingSpeed << ")";
                cout << endl;
            }
        AfterIfElse:
            Digits[0] = '\0';
            NoOfDigits = 0;
            Fix = 0;
            GraphTypingSpeed = 0;

            continue;
        }

        Digits[(NoOfDigits - 1)] = (int(GraphFileCharacter) - 48);
        //because ascii value of o is 48
        //cout<<"Digit "<<NoOfDigits<<": "<<Digits[(NoOfDigits - 1)]<<" ";
        //getch();
    }
}

// int main()
// {
//     class Graph GH;
//     char user[20] = "amrinder6677";
//     GH.FuncGraph(user);

//     return 0;
// }