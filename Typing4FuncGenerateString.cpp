int Typing::FuncGenerateString()
{
    cout << "FuncGenerateString() is Called" << endl
         << endl;

    // UserFile >> noskipws;//to turn of without space flag
    // cout<<"opend File.txt"<<endl;
    // do
    // {
    //     UserFile>>Read;

    // }while(Read!=']');

    for (t1 = 0; t1 < 1; ++t1)
    {

        cout << "Speed  : " << setw(6) << TypingSpeed;
        cout << "Errors : " << setw(2) << NoOfErrors;
        cout << "    ";
        cout << "Score  : " << Score << endl;
        for (t2 = 0; t2 < 150; ++t2)
        {

            cout << "_";
            if (t2 == 149)
            {
                cout << endl;
            }
        }

        for (t3 = 0; t3 < 150;)
        {

            if (t3 == 0)
            {
                StringFile.open("StringFile", ios::out);
                StringFile2.open("StringFile2", ios::out);
                //cout << "entered if(t3==0)" << endl;
                t4 = 1;
                WordLength = 1;
                //cout << "(t3,t4)";
                srand(time(0));
                WordLength = (2 + rand() % 7);
                t4 = 1;
                //cout << "Random String: " << endl;
            }
            if ((t4 == WordLength) and (t3 != 0) and (t3 != 149))
            {
                //cout<<t3;
                cout << " ";
                StringFile << " ";
                StringFile2 << " ";

                WordLength = (2 + rand() % 7);
                t4 = 1;
                t3++;
            }
            else if (t3 == 149)
            {
                cout << ".";
                StringFile << ".";
                StringFile2 << ".";
                StringFile.close();
                StringFile2.close();
                cout << endl;
                t3++;
            }
            else
            {

            xyz:

                AsciiValue = (65 + rand() % 58); //65<AsciiValue<122

                if ((AsciiValue < 97) && (AsciiValue > 90))
                {
                    goto xyz;
                }

                AsciiValueCharacter = AsciiValue;
                //cout << t3 ;
                cout << AsciiValueCharacter;
                StringFile << AsciiValueCharacter;
                StringFile2 << AsciiValueCharacter;
                t4++;
                t3++;
            }
        }

        for (t5 = 0; t5 < 150; ++t5)
        {

            cout << "_";
            if (t5 == 149)
            {
                cout << endl
                     << endl;
            }
        }
    }

    ClearScreen();
    return 0;
}