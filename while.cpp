#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<fstream>
#include<cmath>
#include<cstdlib>
using namespace std;
int X = 22, Y = 68;
int num_record=0;
int score = 0,stars=0;
bool running=true;
char pre = ' ', pre2 = ' ', pre3 = ' ', pre4 = ' ';
bool ft = 1, st = 0;
bool energizer = 0;
int gx1 = 9, gy1 = 43;
int gx2 = 3, gy2 = 3;
int gx3 = 16, gy3 = 27;
int gx4 = 6, gy4 = 55;
int movecount = 0;
int energycount = 0;
int lifes=3;
int scores[20]={-1};
char maze[24][93]={
{"#(___)################################################################[][][][][][][][][][][]"},
{"#           ##       ##*                        .....         ...*...#[]                  []"},
{"#           ##       ##...      ##########      ..O..##       ########[]                  []"},
{"#                    ##...      ##......##      .....##       ##     #[]                  []"},
{"#                    ##.O.##    ##..*...      #########       ##     #[]                  []"},
{"#  #######       ##  #######    ##......##           #######         #[]                  []"},
{"#  #             ##       ##    ##########      .......        ....  #[]                  []"},
{"# ... #########  ##       ## ...      .....  ##       #######  ....  #[]                  []"},
{"# .*. ##         ##       ## ...  ##  .....  ##O      ##       ....  #[]                  []"},
{"# ... ##                     ...  ##  .....  #######  ##  ##   ....  #[]                  []"},
{"# .O. ##   ##############    #######  .....  ##       ##  ##         #[]                  []"},
{"########    ...O...    ##    ##              ##       ##  ##         #[]                  []"},
{"#   *       .......    ##    ##        ##                 ########   #[]                  []"},
{"#  ..   #########      ##    ##        ##      ## .  ##              #[]                  []"},
{"#  ..   ##             ##  . ##        ##      ## .  ##   ############[]                  []"},
{"#  ..   ##  .          ##  .    ################# .  ##   ## .....   #[]                  []"},
{"#  ..       .  ####    ##  .             ..... ##         ## .....   #[]                  []"},
{"#    #####  .  ####        ......  ####  ..... ##              .     #[]                  []"},
{"#    ...##  .  ####        ......   O##  ..... ##############  .     #[]                  []"},
{"#### ...##  .           ###############              ##              #[]                  []"},
{"#    ...##   ######                  ##    #####     ##    ##        #[]                  []"},
{"#   ######       ##  .....   ######   ......  ##           ##        #[]                  []"},
{"#                ##                           ##     ##    ##        #[]                  []"},
{"######################################################################[][][][][][][][][][][]"}
};
void header()
{
    system("cls");
    cout << "      _____________________________________________________________________________         " << endl;
    cout << "      |                                                                            |        " << endl;
    cout << "      |          mm        mm         a          zzzzzzzzzzzzz    eeeeeeeee        |        " << endl;
    cout << "      |          mm m    m mm        aaaa        zz        zz     ee               |        " << endl;
    cout << "      |          mm  m  m  mm       aa  aa               zz       ee               |        " << endl;
    cout << "      |          mm   m    mm      aa    aa           zzz         eeeeeeeee        |        " << endl;
    cout << "      |          mm        mm     aaaaaaaaaa        zz            ee               |        " << endl;
    cout << "      |          mm        mm    aa        aa     zz        zz    ee               |        " << endl;
    cout << "      |          mm        mm   aa          aa   zzzzzzzzzzzzz    eeeeeeeee        |        " << endl;
    cout << "      |____________________________________________________________________________|        " << endl<<endl;
}
void loaddata()
{
    fstream file;
    string str;
    int x=0;
    file.open("game.txt",ios::in);
    for (int x = 0; x < 24; x++)
    {
        getline(file, str);
        for (int m = 0; m < 93; m++)
        {
            maze[x][m] = str[m];
        }
        x++;
    }
    file.close();
}
char main_menu()
{
    header();
    char option;
    cout<<endl<<"Welcome to the Game......"<<endl;
    cout<<"1) Press 1 to play the game"<<endl;
    cout<<"2) Press 2 to View Records "<<endl;
    cout<<"3) Press 3 to exit"<<endl;
    option=getche();
    return option;
}
void gotoxy(int x,int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(
    GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void storedata()
{
    fstream file;
    file.open("game.txt",ios::out);
    for(int m=0;m<24;m++)
    {
        for(int x=0 ;x<93;x++)
        {
            file<<maze[m][x];
        }
        file<<endl;
    }
    file.close();
}
void display()
{
    for (int x=0;x< 24;x++)
    {
        for(int m=0;m<93;m++)
        {
            cout<<maze[x][m];
        }
        cout<<endl;
    }
}
void score1()
{
    gotoxy(77,10);
    cout<<"Score :"<<score<<"  ";
}
void checkpoint()
{
    stars++;
    if(stars>=3)
    {
        maze[0][2]=' ';
        maze[0][3]=' ';
        maze[0][4]=' ';
        gotoxy(2,0);
        cout<<' ';
        gotoxy(3,0);
        cout<<' ';
        gotoxy(4,0);
        cout<<' ';
    }
}
void gameend()
{
    running=false;
    storedata();
    system("cls");
    display();
    score1();
    cout << "You Completed the Level!!!!!!!!!!!!!!" << endl;
    Sleep(500);
    system("pause");
    system("cls");
    exit(0);
}
void game_esc()
{
    running=false;
}
int ghostDirection1()
{
    srand(time(0));
    int result = 1 + (rand() % 4);
    return result;
}
int ghostDirection2()
{
    srand(time(0));
    int result = 1 + ((rand()) % 2);
    return result;
}
int ghostDirection3()
{
    srand(time(0));
    int result = 1 + ((rand()) % 2);
    return result;
}
int ghostDirection4()
{
    if(movecount == 5)
    {
        srand(time(0)) ;
        int value= 1+(rand()%4);
        movecount=0;
        return value;
    }
    movecount++;
    int xaxis=X-gx4;
    int yaxis=Y-gy4;
    int absx=abs(xaxis);
    int absy=abs(yaxis);
    if(absx > absy)
    {
        if(xaxis < 0)
            return 1; 
        else
            return 2;
    }
    else
    {
        if(yaxis < 0)
            return 4;
        else
            return 3;
    }
}
void gameover()
{
    if (lifes == 1)
    {
        system("cls");
        display();
        score1();
        cout << "Game Over" << endl;
        Sleep(500);
        running=false;
        system("pause");
        system("cls");
    }
    else
    {
        maze[X][Y]=' ';
        gotoxy(Y,X);
        cout<<' ';
        lifes--;
        X=22;
        Y=68;
        maze[X][Y]='P';
        gotoxy(Y,X);
        cout<<'P';
    }
}
void moveup()
{
    if (maze[X-1][Y] == '.')
    {
        score++;
    }
    if (maze[X-1][Y] == '*')
    {
        score=score+10;
        checkpoint();
    }
    if(energizer && maze[X - 1][Y] == 'G')
    {
        gotoxy(Y, X - 1);
        cout << 'P';
        maze[X - 1][Y] = 'P';
        gotoxy(Y, X);
        cout << ' ';
        maze[X][Y] = ' ';
    }
    if(!energizer && maze[X - 1][Y] == 'G')
    {gameover();}
    if (maze[X - 1][Y] == ' ' || maze[X - 1][Y] == '.' || maze[X - 1][Y] == 'O' || maze[X - 1][Y] == 'P' || maze[X - 1][Y] == '*')
    {
        if (maze[X - 1][Y] == 'O')
        {
            energizer = 1;
            energycount=0;
        }
        gotoxy(Y, X - 1);
        cout << 'P';
        maze[X - 1][Y] = 'P';
        gotoxy(Y, X);
        cout << ' ';
        maze[X][Y] = ' ';
        X--;
    }
}
void movedown()
{
    if (maze[X+1][Y] == '.')
    {
        score++;
    }
    if (maze[X+1][Y] == '*')
    {
        score=score+10;
        checkpoint();
    }
    if(energizer && maze[X+1][Y] == 'G')
    {
        gotoxy(Y,X+1);
        cout<<'P';
        maze[X+1][Y]='P';
        gotoxy(Y,X);
        cout<<' ';
        maze[X][Y]=' ';
    }
    if(!energizer && maze[X+1][Y] == 'G')
    {
        gameover();
    }
    if(maze[X+1][Y] == ' ' || maze[X+1][Y] == '.' || maze[X+1][Y] == 'O' || maze[X+1][Y] == 'P' || maze[X+1][Y] == '*')
    {
        if(maze[X+1][Y] == 'O')
            {energizer=1;
            energycount=0;}
        gotoxy(Y,X+1);
        cout<<'P';
        maze[X+1][Y]='P';
        gotoxy(Y,X);
        cout<<' ';
        maze[X][Y]=' ';
        X++;
    }
}
void moveright()
{
    if (maze[X][Y+1] == '.')
    {
        score++;
    }
    if (maze[X][Y+1] == '*')
    {
        score=score+10;
        checkpoint();
    }
    if(energizer && maze[X][Y+1]  == 'G')
    {
        gotoxy(Y+1,X);
        cout<<'P';
        maze[X][Y+1]='P';
        gotoxy(Y,X);
        cout<<' ';
        maze[X][Y]=' ';
    }
    if(!energizer && maze[X][Y+1]  == 'G')
    {
        gameover();
    }
    if(maze[X][Y+1] == ' ' || maze[X][Y+1]  == '.' || maze[X][Y+1]  == 'O' || maze[X][Y+1]  == 'P' || maze[X][Y+1]  == '*')
    {
        if(maze[X][Y+1]  == 'O')
            {energizer=1;
            energycount=0;}
        gotoxy(Y+1,X);
        cout<<'P';
        maze[X][Y+1]='P';
        gotoxy(Y,X);
        cout<<' ';
        maze[X][Y]=' ';
        Y++;
    }
}
void moveleft()
{
    if (maze[X][Y - 1] == '.')
    {
        score++;
    }
    if (maze[X][Y - 1] == '*')
    {
        score=score+10;
        checkpoint();
    }
    if(energizer && maze[X][Y - 1] == 'G')
    {
        gotoxy(Y-1,X);
        cout<<'P';
        maze[X][Y-1]='P';
        gotoxy(Y,X);
        cout<<' ';
        maze[X][Y]=' ';
    }
    if(!energizer && maze[X][Y - 1] == 'G')
    {
        gameover();
    }
    if (maze[X][Y - 1] == ' ' || maze[X][Y - 1] == '.' || maze[X][Y - 1] == 'O' || maze[X][Y - 1] == 'P' || maze[X][Y - 1] == '*')
    {
        if(maze[X][Y - 1] == 'O')
            {energizer=1;
            energycount=0;}
        gotoxy(Y-1,X);
        cout<<'P';
        maze[X][Y-1]='P';
        gotoxy(Y,X);
        cout<<' ';
        maze[X][Y]=' ';
        Y--;
    }
}
void enemy1()
{
    int value = ghostDirection1();
    if (value == 1)
    {
        if (maze[gx1 - 1][gy1] == ' ' || maze[gx1 - 1][gy1] == '.' || maze[gx1 - 1][gy1] == 'P'|| maze[gx1 - 1][gy1] == '*')
        {
            maze[gx1][gy1] = pre;
            gotoxy(gy1, gx1);
            if (maze[gx1][gy1] == '.')
            {
                cout << '.';
            }
            else
            {
                cout << ' ';
            }
            gx1--;
            if (maze[gx1][gy1] != 'P')  pre = maze[gx1][gy1];
            if (maze[gx1][gy1] == 'P')
            {
                pre=' ';
                gameover();
            }
            maze[gx1][gy1] = 'G';
            gotoxy(gy1, gx1);
            cout << 'G';
        }
    }
    if (value == 2)
    {
        if (maze[gx1 + 1][gy1] == ' ' || maze[gx1 + 1][gy1] == '.' || maze[gx1 + 1][gy1] == 'P' || maze[gx1 + 1][gy1] == '*')
        {
            maze[gx1][gy1] = pre;
            gotoxy(gy1, gx1);
            if (maze[gx1][gy1] == '.')
            {
                cout << '.';
            }
            else
            {
                cout << ' ';
            }
            gx1++;
            if (maze[gx1][gy1] != 'P')  pre = maze[gx1][gy1];
            if (maze[gx1][gy1] == 'P')
            {
                pre=' ';
                gameover();
            }
            maze[gx1][gy1] = 'G';
            gotoxy(gy1, gx1);
            cout << 'G';
        }
    }
    if (value == 3)
    {
        if (maze[gx1][gy1 + 1] == ' ' || maze[gx1][gy1 + 1] == '.' || maze[gx1][gy1 + 1] == 'P' || maze[gx1][gy1 + 1] == '*')
        {
            maze[gx1][gy1] = pre;
            gotoxy(gy1, gx1);
            if (maze[gx1][gy1] == '.')
            {
                cout << '.';
            }
            else
            {
                cout << ' ';
            }
            gy1++;
            if (maze[gx1][gy1] != 'P')
            {
                pre = maze[gx1][gy1];
            }
            if (maze[gx1][gy1] == 'P')
            {
                pre=' ';
                gameover();
            }
            maze[gx1][gy1] = 'G';
            gotoxy(gy1, gx1);
            cout << 'G';
        }
    }
    if (value == 4)
    {
        if (maze[gx1][gy1 - 1] == ' ' || maze[gx1][gy1 - 1] == '.' || maze[gx1][gy1 - 1] == 'P'|| maze[gx1][gy1 - 1] == '*')
        {
            maze[gx1][gy1] = pre;
            gotoxy(gy1, gx1);
            if (maze[gx1][gy1] == '.')
            {
                cout << '.';
            }
            else
            {
                cout << ' ';
            }
            gy1--;
            if (maze[gx1][gy1] != 'P')  pre = maze[gx1][gy1];
            if (maze[gx1][gy1] == 'P')
            {
                pre=' ';
                gameover();
            }
            maze[gx1][gy1] = 'G';
            gotoxy(gy1, gx1);
            cout << 'G';
        }
    }

}
void enemy2()
{
    int value = ghostDirection2();
    if (value == 1)
    {
        if (maze[gx2][gy2 + 1] == ' ' || maze[gx2][gy2 + 1] == '.' || maze[gx2][gy2 + 1] == 'P')
        {
            maze[gx2][gy2] = pre2;
            gotoxy(gy2, gx2);
            if (maze[gx2][gy2] == '.')
            {
                cout << '.';
            }
            else
            {
                cout << ' ';
            }
            gy2++;
            if (maze[gx2][gy2] != 'P')
            {pre2 = maze[gx2][gy2];}
            if (maze[gx2][gy2] == 'P')
            {
                pre2 =' ';
                gameover();
            }
            maze[gx2][gy2] = 'G';
            gotoxy(gy2, gx2);
            cout << 'G';
        }
    }
    if (value == 2)
    {
        if (maze[gx2][gy2 - 1] == ' ' || maze[gx2][gy2 - 1] == '.' || maze[gx2][gy2 - 1] == 'P')
        {
            maze[gx2][gy2] = pre2;
            gotoxy(gy2, gx2);
            if (maze[gx2][gy2] == '.')
            {
                cout << '.';
            }
            else
            {
                cout << ' ';
            }
            gy2--;
            if (maze[gx2][gy2] != 'P')
            {pre2 = maze[gx2][gy2];}
            if (maze[gx2][gy2] == 'P')
            {
                pre2 =' ';
                gameover();
            }
            maze[gx2][gy2] = 'G';
            gotoxy(gy2, gx2);
            cout << 'G';
        }
    }

}
void enemy3()
{
    int value = ghostDirection3();
    if (value == 1)
    {
        if (maze[gx3 - 1][gy3] == ' ' || maze[gx3 - 1][gy3] == '.' || maze[gx3 - 1][gy3] == 'P')
        {
            maze[gx3][gy3] = pre3;
            gotoxy(gy3, gx3);
            if (maze[gx3][gy3] == '.')
            {
                cout << '.';
            }
            else
            {
                cout << ' ';
            }
            gx3--;
            if (maze[gx3][gy3] != 'P')  pre3 = maze[gx3][gy3];
            if (maze[gx3][gy3] == 'P')
            {
                pre3 =' ';
                gameover();
            }
            maze[gx3][gy3] = 'G';
            gotoxy(gy3, gx3);
            cout << 'G';
        }
    }
    if (value == 2)
    {
        if (maze[gx3 + 1][gy3] == ' ' || maze[gx3 + 1][gy3] == '.' || maze[gx3 + 1][gy3] == 'P')
        {
            maze[gx3][gy3] = pre3;
            gotoxy(gy3, gx3);
            if (maze[gx3][gy3] == '.')
            {
                cout << '.';
            }
            else
            {
                cout << ' ';
            }
            gx3++;
            if(maze[gx3][gy3] != 'P')   {pre3 = maze[gx3][gy3];}
            if (maze[gx3][gy3] == 'P')
            {
                pre3 =' ';
                gameover();
            }
            maze[gx3][gy3] = 'G';
            gotoxy(gy3, gx3);
            cout << 'G';
        }
    }
}
void enemy4()
{
    int value = ghostDirection4();
    if (value == 1)
    {
        if (maze[gx4 - 1][gy4] == ' ' || maze[gx4 - 1][gy4] == '.' || maze[gx4 - 1][gy4] == 'P')
        {
            maze[gx4][gy4] = pre4;
            gotoxy(gy4, gx4);
            if (maze[gx4][gy4] == '.')
            {
                cout << '.';
            }
            else
            {
                cout << ' ';
            }
            gx4--;
            if (maze[gx4][gy4] != 'P')
            {pre4 = maze[gx4][gy4];}
            if (maze[gx4][gy4] == 'P')
            {
                pre4=' ';
                gameover();
            }
            maze[gx4][gy4] = 'G';
            gotoxy(gy4, gx4);
            cout << 'G';
        }
    }
    if (value == 2)
    {
        if (maze[gx4 + 1][gy4] == ' ' || maze[gx4 + 1][gy4] == '.' || maze[gx4 + 1][gy4] == 'P')
        {
            maze[gx4][gy4] = pre4;
            gotoxy(gy4, gx4);
            if (maze[gx4][gy4] == '.')
            {
                cout << '.';
            }
            else
            {
                cout << ' ';
            }
            gx4++;
            if (maze[gx4][gy4] != 'P')
            {pre4 = maze[gx4][gy4];}
            if (maze[gx4][gy4] == 'P')
            {
                pre4=' ';
                gameover();
            }
            maze[gx4][gy4] = 'G';
            gotoxy(gy4, gx4);
            cout << 'G';
        }
    }
    if (value == 3)
    {
        if (maze[gx4][gy4 + 1] == ' ' || maze[gx4][gy4 + 1] == '.' || maze[gx4][gy4 + 1] == 'P')
        {
            maze[gx4][gy4] = pre4;
            gotoxy(gy4, gx4);
            if (maze[gx4][gy4] == '.')
            {
                cout << '.';
            }
            else
            {
                cout << ' ';
            }
            gy4++;
            if (maze[gx4][gy4] != 'P')
            {pre4 = maze[gx4][gy4];}
            if (maze[gx4][gy4] == 'P')
            {
                pre4=' ';
                gameover();
            }
            maze[gx4][gy4] = 'G';
            gotoxy(gy4, gx4);
            cout << 'G';
        }
    }
    if (value == 4)
    {
        if (maze[gx4][gy4 - 1] == ' ' || maze[gx4][gy4 - 1] == '.' || maze[gx4][gy4 - 1] == 'P')
        {
            maze[gx4][gy4] = pre4;
            gotoxy(gy4, gx4);
            if (maze[gx4][gy4] == '.')
            {
                cout << '.';
            }
            else
            {
                cout << ' ';
            }
            gy4--;
            if (maze[gx4][gy4] != 'P')
            {pre4 = maze[gx4][gy4];}
            if (maze[gx4][gy4] == 'P')
            {
                pre4=' ';
                gameover();
            }
            maze[gx4][gy4] = 'G';
            gotoxy(gy4, gx4);
            cout << 'G';
        }
    }
}
void loadrecords()
{
    num_record=0;
    string str;
    fstream file;
    file.open("records.txt" ,ios :: in);
    for(int x=0;!file.eof();x++)
    {
        file>>scores[x];
        num_record++;
    }
    file.close();
}
void viewrecords()
{
    for(int x=0;x<num_record-1;x++)
    {
        cout<<x+1<<")  "<<scores[x]<<endl;
    }
    cout<<"Press any key to continue....";
    getch();
}
void exitgame()
{
    header();
    cout<<"Thanks For Playing the Game"<<endl;
    cout<<"..........................."<<endl;
    getch();
}


////////////////////////////    MAIN      ///////////////////////////
main()
{
    loadrecords();
    char option=' ';
    while(option!=3)
    {
        option=main_menu();
        if(option=='1')
        {
            gx1 = 9, gy1 = 43;
            gx2 = 3, gy2 = 3;
            gx3 = 16, gy3 = 27;
            gx4 = 6, gy4 = 55;
            movecount = 0;
            energycount = 0;
            lifes=3;
            X = 22, Y = 68;
            score = 0,stars=0;
            running=true;
            pre = ' ', pre2 = ' ', pre3 = ' ', pre4 = ' ';
            ft = 1, st = 0;
            energizer = 0;
            // while(running)
            // {
                system("cls");
                display();
                gotoxy(Y,X);
                cout<<'P';
                while(running)
                {
                    Sleep(50);
                    if (GetAsyncKeyState(VK_LEFT))
                    {moveleft();}
                    if (GetAsyncKeyState(VK_RIGHT))
                    {moveright();}
                    if (GetAsyncKeyState(VK_UP))
                    {moveup();}
                    if (GetAsyncKeyState(VK_DOWN))
                    {movedown();}
                    if (GetAsyncKeyState(VK_ESCAPE))
                    {game_esc();}
                    if((X==0 && Y==2) ||(X==0 && Y==3)||(X==0 && Y==4))
                    {
                        gameend();
                    }
                    if(energizer)
                    {
                        energycount++;
                        if(energycount > 150)
                        {
                            energizer=0;
                            energycount=0;
                        }
                    }
                    gotoxy(72,8);
                    if(stars <=3)
                    cout<<"Checkpoint Left:"<<3-stars;
                    else
                    {cout<<"Checkpoint Left:0";}
                    gotoxy(77, 10);
                    score1();
                    gotoxy(77,9);
                    cout<<"Lifes:"<<lifes;
                    gotoxy(75, 11);
                    if(energizer)
                    {
                        cout << "Time Left:" << 150 - energycount;
                    }
                    if (!energizer)
                    {
                        gotoxy(75, 11);
                        cout << "             ";
                        enemy1();
                        enemy2();
                        enemy3();
                        enemy4();
                    }
                // }
            }
        }
        else if(option=='2')
        {
            header();
            cout<<"View Records>"<<endl<<endl;
            viewrecords();
        }
        else if(option=='3')
        {
            exitgame();
        }
    }
}