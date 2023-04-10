#include <iostream>
#include <Windows.h>
#include <windows.h>
#include <cwchar>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include<dos.h>

using namespace std;

int s=0,m=0,h=0,k;

void timereset();
void timepause();
void timecount();
void timeshow();

void timeshow()
{
    system("CLS");

    cout << "                                                                            -------" << endl;
    cout << "                                                                             " << "-----" << endl;
    cout << "                                                                              " << "---" << endl;
    cout << "                                                                               " << "-" << endl;
    cout << "                                                                             "  << h << ":" << m << ":" << s << endl;
    cout << "                                                                               " << "-" << endl;
    cout << "                                                                              " << "---" << endl;
    cout << "                                                                             " << "-----" << endl;
    cout << "                                                                            -------" << endl << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|Type 'P' to pause. | Type 'R' to reset.|" << endl;
    cout << "-----------------------------------------" << endl << endl;
}

void timepause()
{
    system("CLS");
    cout << h << ":" << m << ":" << s << endl << endl;
    cout << "--------------------------------------------" << endl;
    cout << "|Type 'C' to continue. | Type 'R' to reset.|" << endl;
    cout << "--------------------------------------------" << endl << endl;
    while(1)
    {
        if(GetKeyState('C') & 0x8000)
        {
            timecount();
        }
        else
            if(GetKeyState('R') & 0x8000)
            {
                timereset();
            }
    }
}

void timecount()
{
    while(1)
    {
        timeshow();
        sleep(1);
        s++;
        if(s==60)
        {
            s=0;
            m++;
            if(m==60)
            {
                m=0;
                h++;
            }
        }
        if(GetKeyState('P') & 0x8000)
        {
            timepause();
        }
        else
        {
            if(GetKeyState('R') & 0x8000)
                timereset();
        }
    }
}

void timereset()
{
    s=0;
    m=0;
    h=0;
    timecount();
}

int main()
{
    char z;
    system("Color 0C");

    cout << "                                ----------------------------------------" << endl;
    cout << "                                |ORGANIZE YOURSELF BY USING THIS TIMER!|" << endl;
    cout << "                                ----------------------------------------" << endl << endl;

    cout << "-------------------------------------------------------------------------------------------------" << endl;
    cout << "|IMPORTANT: Type 'S' to start. | Type 'P' to pause. | Type 'C' to continue. | Type 'R' to reset.|" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl << endl;

    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "IMPORTANT: For letters 'P', 'C' and 'R', press them longer when you want to use, else the letter you type won't be detected!" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl;

    cout << "-------------------------------------" << endl;
    cout << "|Now you only can type 'S' to start.|" << endl;
    cout << "-------------------------------------" << endl << endl;

    do
    {
        cin >> z;
        cout << "--------------------" << endl;
        cout << "|Type 'S' to start.|" << endl;
        cout << "--------------------" << endl << endl;
    }while(z!='S' && z!='s');

    timecount();

    return 0;
}
