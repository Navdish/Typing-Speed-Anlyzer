inline void Typing::Display()
{
    cout << "Speed  : " << setw(6) << TypingSpeed;
    cout << " | Errors : " << setw(2) << NoOfErrors;
    cout << "    ";
    cout << " | Score  : " << Score << endl;
}

inline void Typing::Border()
{
    for (g3 = 0; g3 < 150; ++g3)
    {
        cout << "_";
        if (g3 == 149)
        {
            cout << endl;
        }
    }
}

inline void Typing::PrintStringFile()
{
    for (g2 = 0; g2 < 151; g2++)
    {
        if (g2 == 0)
        {
            StringFileRead.open("StringFile", ios::in);
            StringFileRead >> noskipws; //to turn of without space flag
        }
        if (g2 != 0)
        {

            cout << Read;
        }
        if (g2 == 150)
        {
            //cout<<":";
            StringFileRead.close();
            cout << endl;
        }
        else
        {
            StringFileRead >> Read;
        }
    }
}

inline void Typing::PrintInputFile()
{
    StringFileInputRead.open("StringFileInput", ios::in);
    StringFileInputRead << noskipws;
    for (g4 = 0; g4 < +g1; g4++)
    {
        StringFileInputRead >> ReadInputFile;
        cout << ReadInputFile;
    }
    StringFileInputRead.close();
}

int Typing::FuncTyping(char UN[20])
{
    class Main250721 MN2;
    cout << "FuncTyping() is Called" << endl
         << endl;
    for (;;)
    {

        FuncGenerateString();
        Score = 0;
        TypingSpeed = 0;
        NoOfErrors = 0;
        g5 = -1;
        for (g1 = 0; g1 < 150; ++g1)
        {

            if (g1 == 0)
            {
                cout << UN<<endl;
                StringFileInput.open("StringFileInput", ios::out);
                StringFileInput.close();
                StringFileRead2.open("StringFile2", ios::in);
                StringFileRead2 << noskipws;
            }

            Display();
            Border();
            PrintStringFile();
            Border();
            PrintInputFile();

            StringFileRead2 >> Chech;
        NearGetch:
            Start = clock();
            InputVariable = _getch();
            Stop = clock();

            if (InputVariable == 27)
            {
                ClearScreen();
                system("COLOR 07");
                StringFileRead2.close();
                return 427;
            }

            ///////////////////
            g5++;
            if (InputVariable == 8)
            {
                return 20;
            }

            if (Chech != InputVariable)
            {
                system("COLOR 0C");
                //cout<<g5<<g1;
                //cout<<"if "<<Chech;

                if (g1 == g5)
                {
                    NoOfErrors++;
                    Score = Score - 3;
                }

                goto NearGetch;
            }
            else
            {
                system("COLOR 07");
            }
            g5 = g1;

            TimeDifference = (Stop - Start);
            TypingSpeed = int(60000 / TimeDifference);
            if (g1 % 5 == 0)
            {
            cout << "XYZ";
            UserFile.open( UN, ios::app);
            UserFile << TypingSpeed;
            UserFile << ",";
            UserFile.close();
            }
            Score = Score + 10;

            if (TypingSpeed > 500)
            {
                TypingSpeed = 500;
            }

            cout << InputVariable;
            StringFileInput.open("StringFileInput", ios::app);
            StringFileInput << noskipws;
            StringFileInput << InputVariable;
            StringFileInput.close();

            cout << endl;
            ClearScreen();
        }
        StringFileInput.close();
        StringFileRead2.close();
    }

    return 1;
}