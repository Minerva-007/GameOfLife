#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#include"windows.h"
#include"time.h"

void PrintIt(bool arr[42][62])
{
     for(int i=0;i<40;i++){
             for(int j=0;j<60;j++)
                     if(arr[i+1][j+1]==true)putch('x');else putch(' ');
             putch('\n');}
}

int isAlive(bool cell)
{
    return (cell==true?1:0);
}

void CopyArray(bool arr[42][62], bool abc[42][62])
{
     for(int i=0;i<40;i++)
             for(int j=0;j<60;j++)
                     arr[i+1][j+1]=abc[i+1][j+1];
}

int main()
{
    srand(time(0));
    bool arr[42][62];
    for(int i=0;i<40;i++)
            for(int j=0;j<60;j++)
                    arr[i+1][j+1]=rand()%2;
    PrintIt(arr);
    while(1)
    {
            Sleep(200);
            system("cls");
            bool abc[42][62];
            for(int i=0;i<40;i++)
                    for(int j=0;j<60;j++)
                            {
                                         int Alive=isAlive(arr[i][j])+isAlive(arr[i][j+1])+isAlive(arr[i][j+2])+isAlive(arr[i+1][j])+isAlive(arr[i+1][j+2])+isAlive(arr[i+2][j])+isAlive(arr[i+2][j+1])+isAlive(arr[i+2][j+2]);
                                         switch(Alive)
                                         {
                                                      case 2:
                                                           abc[i+1][j+1]=arr[i+1][j+1];
                                                           break;
                                                      case 3:
                                                           abc[i+1][j+1]=true;
                                                           break;
                                                      default:
                                                           abc[i+1][j+1]=false;
                                         }
                            }
            CopyArray(arr,abc);
            PrintIt(arr);
    }      
    getch();
}
