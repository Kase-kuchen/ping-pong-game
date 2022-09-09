#include <iostream>
#include <windows.h>
#include <iomanip.>
#include <conio.h>
#include <cstdlib>
using namespace std;
bool  background[28][50];
bool gameover;
int score1,score2;
int p1,p2;
int bi,bj,updir,rightdir;
void startup()
{
    //This is purely for aesthetic purposes

    int i,j,k;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 8);
    int ending=100;
    for (i = 1; i <= ending; i++)
    {
        Sleep(16.6667);
        system("cls");
        for (j = 0; j < i; j += 10)
        {
            SetConsoleTextAttribute(hConsole, 8);
            cout << "[]";

        }

        k=rand()%100;
        if(i<=95)
            if(k%3==0)
                i=i+rand()%5;
        SetConsoleTextAttribute(hConsole, 14);

        cout <<" "<< i << "%";
        cout << endl;
    }
    SetConsoleTextAttribute(hConsole, 14);
    cout<<"Program has fully loaded!"<<endl;
    Sleep(1500);
    system("cls");
    SetConsoleTextAttribute(hConsole, 7);


    SetConsoleTextAttribute(hConsole, 12);
    cout<<"Welcome...";
    Sleep(1000);
    cout<<endl<<endl;
    cout<<"To the ";
    SetConsoleTextAttribute(hConsole, 4);
    cout<<"most awaited game of the year..."<<endl<<endl;
    Sleep(1750);
    cout<<"SUPER ";
    Sleep(900);
    cout<<"DELUXE ";
    Sleep(900);
    cout<<"PRO ";
    Sleep(900);
    cout<<"PING-PONG ";
    Sleep(900);
    cout<<"10 000 ! ";
    Sleep(3000);
    system("cls");





}
void init()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 8);

    int i,j,k,l;
    for(i=1; i<=28; i++)
        for(j=1; j<=50; j++)
            if(i==1||i==28||j==1||j==50)
                background[i][j]=true;
            else background[i][j]=false;

    score1=0;
    score2=0;

    p1=24;
    p2=24;
    bi=15;
    bj=15;

    l=rand()%100;
    if(l%2==0)
        updir=1;
    else updir=0;

    k=rand()%100;
    if(k%2==0)
        rightdir=1;
    else rightdir=0;

}

void players()
{

    switch (_getch())
    {
    case 'a':
    {
        if(p1>4)
        {
            background[2][p1+3]=false;
            p1--;
        }
        else break;
    }
    break;
    case 'd':
    {
        if(p1<56)
        {
            background[2][p1-3]=false;
            p1++;


        }
        else break;
    }
    break;
    case 'j':
    {
        if(p2>4)
        {
            background[27][p2+3]=false;
            p2--;
        }
        else break;
    }
    break;
    case 'l':
    {
        if(p2<56)
        {
            background[27][p2-3]=false;
            p2++;
        }
        else break;
    }
    break;
    case 'x':
        gameover = true;
        break;
    }


}
void ball()
{
    //don't even bother with the ball, this whole section is bugged to hell [the ball doesn't even appear
    background[bi][bj]=true;;
    if(updir==1)
    {
        background[bi][bj]=false;
        if(background[bi-1][bj]!=true)
            background[bi-1][bj]=true;
        else updir=0;
        bi++;
    }
    else
    {
        background[bi][bj]=false;
        if(background[bi+1][bj]!=true)
            background[bi+1][bj]=true;
        else updir=1;
        bi--;
    }
    if(rightdir==1)
    {
        background[bi][bj]=false;
        background[bi][bj+1]=true;
        bj++;
    }
    else
    {
        background[bi][bj]=false;
        background[bi-1][bj-1]=true;
        bj--;
    }

    if(background[bi+1][bj]==true)
        updir=1;
    if(background[bi-1][bj]==true)
        updir=0;

}

void draw()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 8);
    int i,j;

    for(i=1; i<=28; i++)
        for(j=1; j<=50; j++)
            if(i==1||i==28||j==1||j==50)
                background[i][j]=true;
            else background[i][j]=false;

    for(i=1; i<=28; i++)
    {
        cout<<endl;
        cout<<"                ";
        for(j=1; j<=50; j++)
        {
            background[2][p1-3]=true;
            background[2][p1-2]=true;
            background[2][p1-1]=true;
            background[2][p1]=true;
            background[2][p1+1]=true;
            background[2][p1+2]=true;
            background[2][p1+3]=true;
            background[27][p2-3]=true;
            background[27][p2-2]=true;
            background[27][p2-1]=true;
            background[27][p2]=true;
            background[27][p2+1]=true;
            background[27][p2+2]=true;
            background[27][p2+3]=true;

            if(background[i][j]==true)
            {
                if(i==1||i==28||j==1||j==50)
                    SetConsoleTextAttribute(hConsole, 8);

                if((i==2||i==27)&&(j>=2&&j<=49))
                    SetConsoleTextAttribute(hConsole, 4);

                cout<<"x";
                SetConsoleTextAttribute(hConsole, 7);
            }
            else cout<<" ";
            SetConsoleTextAttribute(hConsole, 7);

        }
    }


}

int main()
{
    gameover=false;
    startup();
    init();
    while(!gameover)
    {
        draw();
        players();
        ball();
        Sleep(16.66666667);
        // cout<<endl<<"Player 1 score: "<<score1<<endl<<"Player 2 score: "<<score2<<endl; the reason it's in comment it's because I may remove it/add it back when it's finished
        system("cls");
    }
    return 0;
}
