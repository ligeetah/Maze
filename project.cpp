#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<fstream>
#include<cmath>
#include<cstdlib>
using namespace std;
int X=22,Y=68;
int score=0;
char pre=' ',pre2=' ',pre3=' ',pre4=' ';
bool ft=1,st=0;
bool energizer=0;
int gx1=9 ,gy1=43 ;
int gx2=3,gy2=3;
int gx3 = 16 , gy3 = 27;
int gx4 = 6 , gy4 =55 ;
int movecount=0;
char maze[24][93]={
{"#(  )#################################################################[][][][][][][][][][][]"},
{"#           ##       ##                         .....         ......O#[]                  []"},
{"#           ##       ##...      ##########      ..O..##       ########[]                  []"},
{"#                    ##...      ##......##      .....##       ##     #[]                  []"},
{"#                    ##.O.##    ##..O...      #########       ##     #[]                  []"},
{"#  #######       ##  #######    ##......##           #######         #[]                  []"},
{"#  #             ##       ##    ##########      .......        ....  #[]                  []"},
{"# ... #########  ##       ## ...      .....  ##       #######  ....  #[]                  []"},
{"# ... ##         ##       ## ...  ##  .....  ##O      ##       ....  #[]                  []"},
{"# ... ##                     ...  ##  .....  #######  ##  ##   ....  #[]                  []"},
{"# .O. ##   ##############    #######  .....  ##       ##  ##         #[]                  []"},
{"########    ...O...    ##    ##              ##       ##  ##         #[]                  []"},
{"#           .......    ##    ##        ##                 ########   #[]                  []"},
{"#  ..   #########      ##    ##        ##      ## .  ##              #[]                  []"},
{"#  ..   ##             ##  . ##        ##      ## .  ##   ############[]                  []"},
{"#  ..   ##  .          ##  .    ################# .  ##   ## .....   #[]                  []"},
{"#  ..       .  ####    ##  .             ..... ##         ## .....   #[]                  []"},
{"#    #####  .  ####        ......  ####  ..... ##              .     #[]                  []"},
{"#    ...##  .  ####        ......   O##  ..... ##############  .     #[]                  []"},
{"#### ...##  .           ###############              ##              #[]                  []"},
{"#......O##   ######                  ##    #####     ##    ##        #[]                  []"},
{"#   ######       ##  .....   ######   ......  ##           ##        #[]                  []"},
{"#                ##                           ##     ##    ##        #[]                  []"}, 
{"######################################################################[][][][][][][][][][][]"}
};
void gotoxy(int x,int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(
    GetStdHandle(STD_OUTPUT_HANDLE), c);
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
int checklocation()
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
    system("cls");
    display();
    score1();
    cout<<"Game Over"<<endl;
    Sleep(500);
    system("pause");
    system("cls");
    exit(0);
}
bool moveup()
{
    bool ans=0;
    if (maze[X-1][Y] == '.')
    {
        score++;
    }
    if (maze[X - 1][Y] == 'G' )
    {
        gameover();
    }
    if (maze[X - 1][Y] == ' ' || maze[X - 1][Y] == '.' || maze[X - 1][Y] == 'O')
    {
        if(maze[X - 1][Y] == 'O')
            {ans=1;}
        gotoxy(Y,X-1);
        cout<<'P';
        maze[X-1][Y]='P';
        gotoxy(Y,X);
        cout<<' ';
        maze[X][Y]=' ';
        X--;
    }
    return ans;
}
bool movedown()
{
    bool ans=0;
    if (maze[X+1][Y] == '.')
    {
        score++;
    }
    if(maze[X+1][Y] == 'G')
    {
        gameover();
    }
    if(maze[X+1][Y] == ' ' || maze[X+1][Y] == '.' || maze[X+1][Y] == 'O')
    {
        if(maze[X+1][Y] == 'O')
            {ans=1;}
        gotoxy(Y,X+1);
        cout<<'P';
        maze[X+1][Y]='P';
        gotoxy(Y,X);
        cout<<' ';
        maze[X][Y]=' ';
        X++;
    }
    return ans;
}
bool moveright()
{
    bool ans=0;
    if (maze[X][Y+1] == '.')
    {
        score++;
    }
    if(maze[X][Y+1]  == 'G')
    {
        gameover();
    }
    if(maze[X][Y+1] == ' ' || maze[X][Y+1]  == '.' || maze[X][Y+1]  == 'O')
    {
        if(maze[X][Y+1]  == 'O')
            {ans=1;}
        gotoxy(Y+1,X);
        cout<<'P';
        maze[X][Y+1]='P';
        gotoxy(Y,X);
        cout<<' ';
        maze[X][Y]=' ';
        Y++;
    }
    return ans;
}
bool moveleft()
{
    bool ans=0;
    if (maze[X][Y - 1] == '.')
    {
        score++;
    }
    if(maze[X][Y - 1] == 'G')
    {
        gameover();
    }
    if (maze[X][Y - 1] == ' ' || maze[X][Y - 1] == '.' || maze[X][Y - 1] == 'O')
    {
        if(maze[X][Y - 1] == 'O')
            {ans=1;}
        gotoxy(Y-1,X);
        cout<<'P';
        maze[X][Y-1]='P';
        gotoxy(Y,X);
        cout<<' ';
        maze[X][Y]=' ';
        Y--;
    }
    return ans;
}
bool ghost1()
{
    int value = ghostDirection1();
    if (value == 1)
    {
        if(maze[gx1-1][gy1]==' ' || maze[gx1-1][gy1]=='.' || maze[gx1-1][gy1]=='P')
        {
            maze[gx1][gy1] = pre;
            gotoxy(gy1, gx1);
            if (maze[gx1][gy1] == '.')
                {cout << '.';}
            else
                {cout << ' ';}
            gx1--;
            pre = maze[gx1][gy1];
            if (maze[gx1][gy1] == 'P')
            {
                return 1;
            }
            maze[gx1][gy1] = 'G';
            gotoxy(gy1, gx1);
            cout << 'G';
        }
    }
    if (value == 2)
    {
        if(maze[gx1+1][gy1]==' ' || maze[gx1+1][gy1]=='.' || maze[gx1+1][gy1]=='P')
        {
            maze[gx1][gy1] = pre;
            gotoxy(gy1, gx1);
            if (maze[gx1][gy1] == '.')
                {cout << '.';}
            else
                {cout << ' ';}
            gx1++;
            pre = maze[gx1][gy1];
            if (maze[gx1][gy1] == 'P')
            {
                return 1;
            }
            maze[gx1][gy1] = 'G';
            gotoxy(gy1, gx1);
            cout << 'G';
        }
    }
    if (value == 3)
    {
        if(maze[gx1][gy1+1]==' ' || maze[gx1][gy1+1]=='.' || maze[gx1][gy1+1]=='P')
        {
            maze[gx1][gy1] = pre;
            gotoxy(gy1, gx1);
            if (maze[gx1][gy1] == '.')
                {cout << '.';}
            else
                {cout << ' ';}
            gy1++;
            pre = maze[gx1][gy1];
            if (maze[gx1][gy1] == 'P')
            {
                return 1;
            }
            maze[gx1][gy1] = 'G';
            gotoxy(gy1, gx1);
            cout << 'G';
        }
        
    }
    if (value == 4)
    {
        if(maze[gx1][gy1-1]==' ' || maze[gx1][gy1-1]=='.' || maze[gx1][gy1-1]=='P')
        {
            maze[gx1][gy1] = pre;
            gotoxy(gy1, gx1);
            if (maze[gx1][gy1] == '.')
                {cout << '.';}
            else
                {cout << ' ';}
            gy1--;
            pre = maze[gx1][gy1];
            if (maze[gx1][gy1] == 'P')
            {
                return 1;
            }
            maze[gx1][gy1] = 'G';
            gotoxy(gy1, gx1);
            cout << 'G';
        }
    }
}
bool ghost2()
{
    int value = ghostDirection2();
    if (value == 1)
    {
        if(maze[gx2][gy2+1]==' ' || maze[gx2][gy2+1]=='.' || maze[gx2][gy2+1]=='P')
        {
            maze[gx2][gy2] = pre2;
            gotoxy(gy2, gx2);
            if (maze[gx2][gy2] == '.')
                {cout << '.';}
            else
                {cout << ' ';}
            gy2++;
            pre2 = maze[gx2][gy2];
            if (maze[gx2][gy2] == 'P')
            {
                return 1;
            }
            maze[gx2][gy2] = 'G';
            gotoxy(gy2, gx2);
            cout << 'G';
        }
        
    }
    if (value == 2)
    {
        if(maze[gx2][gy2-1]==' ' || maze[gx2][gy2-1]=='.' || maze[gx2][gy2-1]=='P')
        {
            maze[gx2][gy2] = pre2;
            gotoxy(gy2, gx2);
            if (maze[gx2][gy2] == '.')
                {cout << '.';}
            else
                {cout << ' ';}
            gy2--;
            pre2 = maze[gx2][gy2];
            if (maze[gx2][gy2] == 'P')
            {
                return 1;
            }
            maze[gx2][gy2] = 'G';
            gotoxy(gy2, gx2);
            cout << 'G';
        }
    }
}
bool ghost3()
{
    int value = ghostDirection3();
    if (value == 1)
    {
        if(maze[gx3-1][gy3]==' ' || maze[gx3-1][gy3]=='.' || maze[gx3-1][gy3]=='P')
        {
            maze[gx3][gy3] = pre3;
            gotoxy(gy3, gx3);
            if (maze[gx3][gy3] == '.')
                {cout << '.';}
            else
                {cout << ' ';}
            gx3--;
            pre3 = maze[gx3][gy3];
            if (maze[gx3][gy3] == 'P')
            {
                return 1;
            }
            maze[gx3][gy3] = 'G';
            gotoxy(gy3, gx3);
            cout << 'G';
        }
    }
    if (value == 2)
    {
        if(maze[gx3+1][gy3]==' ' || maze[gx3+1][gy3]=='.' || maze[gx3+1][gy3]=='P')
        {
            maze[gx3][gy3] = pre3;
            gotoxy(gy3, gx3);
            if (maze[gx3][gy3] == '.')
                {cout << '.';}
            else
                {cout << ' ';}
            gx3++;
            pre3 = maze[gx3][gy3];
            if (maze[gx3][gy3] == 'P')
            {
                return 1;
            }
            maze[gx3][gy3] = 'G';
            gotoxy(gy3, gx3);
            cout << 'G';
        }
    }
}
bool ghost4()
{
    int value = checklocation();
    if (value == 1)
    {
        if(maze[gx4-1][gy4]==' ' || maze[gx4-1][gy4]=='.' || maze[gx4-1][gy4]=='P')
        {
            maze[gx4][gy4] = pre4;
            gotoxy(gy4, gx4);
            if (maze[gx4][gy4] == '.')
                {cout << '.';}
            else
                {cout << ' ';}
            gx4--;
            pre4 = maze[gx4][gy4];
            if (maze[gx4][gy4] == 'P')
            {
                return 1;
            }
            maze[gx4][gy4] = 'G';
            gotoxy(gy4, gx4);
            cout << 'G';
        }
    }
    if (value == 2)
    {
        if(maze[gx4+1][gy4]==' ' || maze[gx4+1][gy4]=='.' || maze[gx4+1][gy4]=='P')
        {
            maze[gx4][gy4] = pre4;
            gotoxy(gy4, gx4);
            if (maze[gx4][gy4] == '.')
                {cout << '.';}
            else
                {cout << ' ';}
            gx4++;
            pre4 = maze[gx4][gy4];
            if (maze[gx4][gy4] == 'P')
            {
                return 1;
            }
            maze[gx4][gy4] = 'G';
            gotoxy(gy4, gx4);
            cout << 'G';
        }
    }
    if (value == 3)
    {
        if(maze[gx4][gy4+1]==' ' || maze[gx4][gy4+1]=='.' || maze[gx4][gy4+1]=='P')
        {
            maze[gx4][gy4] = pre4;
            gotoxy(gy4, gx4);
            if (maze[gx4][gy4] == '.')
                {cout << '.';}
            else
                {cout << ' ';}
            gy4++;
            pre4 = maze[gx4][gy4];
            if (maze[gx4][gy4] == 'P')
            {
                return 1;
            }
            maze[gx4][gy4] = 'G';
            gotoxy(gy4, gx4);
            cout << 'G';
        }
        
    }
    if (value == 4)
    {
        if(maze[gx4][gy4-1]==' ' || maze[gx4][gy4-1]=='.' || maze[gx4][gy4-1]=='P')
        {
            maze[gx4][gy4] = pre4;
            gotoxy(gy4, gx4);
            if (maze[gx4][gy4] == '.')
                {cout << '.';}
            else
                {cout << ' ';}
            gy4--;
            pre4 = maze[gx4][gy4];
            if (maze[gx4][gy4] == 'P')
            {
                return 1;
            }
            maze[gx4][gy4] = 'G';
            gotoxy(gy4, gx4);
            cout << 'G';
        }
    }
}
void eatup()
{
    if (maze[X-1][Y] == '.')
    {
        score++;
    }
    if (maze[X - 1][Y] == ' ' || maze[X - 1][Y] == '.' || maze[X - 1][Y] == 'O' || maze[X - 1][Y] == 'G')
    {
        gotoxy(Y,X-1);
        cout<<'P';
        maze[X-1][Y]='P';
        gotoxy(Y,X);
        cout<<' ';
        maze[X][Y]=' ';
        X--;
    }
}
void eatdown()
{
    if (maze[X+1][Y] == '.')
    {
        score++;
    }
    if(maze[X+1][Y] == ' ' || maze[X+1][Y] == '.' || maze[X+1][Y] == 'O' || maze[X+1][Y] == 'G')
    {
        gotoxy(Y,X+1);
        cout<<'P';
        maze[X+1][Y]='P';
        gotoxy(Y,X);
        cout<<' ';
        maze[X][Y]=' ';
        X++;
    }
}
void eatright()
{
    if (maze[X][Y+1] == '.')
    {
        score++;
    }
    if(maze[X][Y+1] == ' ' || maze[X][Y+1]  == '.' || maze[X][Y+1]  == 'O' || maze[X][Y+1]  == 'G')
    {
        gotoxy(Y+1,X);
        cout<<'P';
        maze[X][Y+1]='P';
        gotoxy(Y,X);
        cout<<' ';
        maze[X][Y]=' ';
        Y++;
    }
}
void eatleft()
{
    if (maze[X][Y - 1] == '.')
    {
        score++;
    }
    if (maze[X][Y - 1] == ' ' || maze[X][Y - 1] == '.' || maze[X][Y - 1] == 'O' || maze[X][Y - 1] == 'G')
    {
        gotoxy(Y-1,X);
        cout<<'P';
        maze[X][Y-1]='P';
        gotoxy(Y,X);
        cout<<' ';
        maze[X][Y]=' ';
        Y--;
    }
}

////////////////////////////    MAIN      ///////////////////////////
main()
{
    bool ans=0;
    int x=0;
    system("cls");
    display();
    gotoxy(Y,X);
    cout<<'P';
    while(1)
    {
        Sleep(50);
        if (GetAsyncKeyState(VK_LEFT))
        {
            energizer=moveleft();
            if(energizer == 1) ans=1;
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            energizer=moveright();
            if(energizer == 1) ans=1;
        }
        if (GetAsyncKeyState(VK_UP))
        {
            energizer=moveup();
            if(energizer == 1) ans=1;
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            energizer=movedown();
            if(energizer == 1) ans=1;
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }
        if((X==0 && Y==2) ||(X==0 && Y==3))
        {
            gameover();
        }
        if (ans)
        {
            while(x<300)
            {
                x++;
                Sleep(50);
                if (GetAsyncKeyState(VK_LEFT))
                {eatleft();}
                if (GetAsyncKeyState(VK_RIGHT))
                {eatright();}
                if (GetAsyncKeyState(VK_UP))
                {eatup();}
                if (GetAsyncKeyState(VK_DOWN))
                {eatdown();}
                if (GetAsyncKeyState(VK_ESCAPE))
                {break;}
                if((X==0 && Y==2) ||(X==0 && Y==3))
                {
                    gameover();
                }
                gotoxy(77, 10);
                score1();
                gotoxy(77, 11);
                cout<<"Power: "<<300-x;
            }
            ans=0;
            x=0;
        }
        gotoxy(77, 10);
        score1();
        bool yt=0;
        yt = ghost1();
        if(yt == 1) break;
        yt = ghost2();
        if(yt == 1) break;
        yt = ghost3();
        if(yt == 1) break;
        yt=ghost4();
        if(yt == 1) break;
    }
    system("cls");
    cout<<"Game Over"<<endl;
    display();
    score1();
}