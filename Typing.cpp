// #include <iostream>
// #include <conio.h>
// #include <windows.h>
// #include <fstream>
// #include <time.h>
// #include <iomanip>

// using namespace std;

class Typing
{
public:
    fstream UserFile, StringFile, StringFile2, StringFileRead, StringFileRead2, StringFileInputRead, StringFileInput;
    int t1, t2, t3, t4, t5;
    int g1, g2, g3, g4, g5;
    int Score = 0, TypingSpeed = 0, NoOfErrors = 0;
    int AsciiValue, WordLength;
    clock_t Start, Stop, TimeDifference;
    char AsciiValueCharacter,UserNameMain[20], Read, ReadInputFile, Fill, InputVariable, Chech;
    int FuncGenerateString();
    int FuncTyping(char UN[20]);
    inline void ClearScreen();
    inline void Border();
    inline void Display();
    inline void PrintStringFile();
    inline void PrintInputFile();
};

// #include "Typing2.cpp"

// #include"Typing3FuncTyping.cpp"

// #include"Typing4FuncGenerateString.cpp"

// int main()
// {
//     int M2, M3;
//     class Typing TP;
//     M2 = TP.FuncGenerateString();
//     cout << "M2" << M2;

//     M3 = TP.FuncTyping();
//     cout << " M3: " << M3;

//     return 0;
// }