// number shifting game :
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
void gotoxy(int,int);
void game();
int check(int *, int);
void instruction();
void gotoxy (int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main()
{
    
    system("color d"); //first letter is for background and second is for text color
    instruction();
    
}
void instruction()
{
    int i, j, k;
    int arr[4][4] = {
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
        11,
        12,
        13,
        14,
        15,
    };
    char strr[20];
    
   
     system("cls");
       gotoxy(20,10);
    printf("\t******  WELCOME  ******");
    for (i = 0; i <= 3; i++)
        printf("\n");

    printf("ENTER YOUR NAME : ");
    gets(strr);
    system("cls");
 gotoxy(20,3);
    printf("      RULES OF THE GAME\n");
    for (i = 0; i <= 3; i++)
        printf("\n");

    printf("1.YOU HAVE TO ARRANGE THE NUMBERS IN A FOLLOWING WAY :\n\n");

    for (i = 0; i < 4; i++)
    {
        printf("---------------------\n");
        for (j = 0; j < 4; j++)
        {

            if (arr[i][j] == 0)
                printf("|    ");
            else if (arr[i][j] <= 9)
                printf("| %d  ", arr[i][j]);

            else
                printf("| %d ", arr[i][j]);
        }

        printf("|\n");
    }
    printf("---------------------\n\n\n");

    printf("2. YOU CAN USE ONLY ARROW KEY TO PLAY THE GAME\n");
    printf("      1.arrow up   : the no. will shift upward\n");
    printf("      2.arrow down : the no. will shift downward\n");
    printf("      3.arrow right: the no. will shift rightward\n");
    printf("      4.arrow left : the no. will shift leftward\n\n\n");

    printf("3. USE SPACE TO SWFIT THE NUMBERS \n\n\n");
    printf("4. ON EACH VALID MOVES THE NUMBER OF REMANING MOVES WILL DECREASE BY 1 \n\n\n ");

    printf("PRESS ENTER TO START THE GAME : \n\n\n");
    getch();
    system("cls");
    game(&strr[0]);
}
void game(char *s)
{
    char ch;
    int i, y, x = 0, j, k = 0, t,p=30,q=20, arr1[16], arr[4][14];
    srand(time(NULL));
    for (i = 0; i < 16; i++)
    {
        t = rand() % 16;
        for (j = 0; j < i; j++)
        {
            if (t == arr1[j])
                break;
        }
        if (i == j)
            arr1[i] = t;
        else
            i--;
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)

        {
            arr[i][j] = arr1[k];
            k++;
        }
    }
    for (i = 0; i < 4; i++)
    {
        printf("---------------------\n");
        for (j = 0; j < 4; j++)
        {

            if (arr[i][j] == 0)
                printf("|    ");
            else if (arr[i][j] <= 9)
                printf("| %d  ", arr[i][j]);

            else
                printf("| %d ", arr[i][j]);
        }

        printf("|\n");
    }
    printf("---------------------\n\n\n");
    k = 1000;

    // game start :

    while (k >= 0)
    {  
        y = check(&arr[0][0], k);
    
        printf("\nplayer name : ");
        
      for (i=0;*(s+i);i++)
        printf("%c",*(s+i));
       
        printf(" \nremaining moves : %d\n",k);
        if (y == 1 || y == 2)
           break;
           
        ch = getch();
        switch (ch)
        {
        case 75:
        {
            system("cls");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    if (arr[i][j] == 0)
                    {
                    
                        if (j < 3)
                        {
                            t = arr[i][j];
                            arr[i][j] = arr[i][j + 1];
                            arr[i][j + 1] = t;
                            k--;
                            break;
                        }
                        else
                        {  
                            printf("CAN NOT MOVE \n\n");
                            break;
                        }
                    }
                }
            }

            for (i = 0; i < 4; i++)
            {
                printf("---------------------\n");
                for (j = 0; j < 4; j++)
                {

                    if (arr[i][j] == 0)
                        printf("|    ");
                    else if (arr[i][j] <= 9)
                        printf("| %d  ", arr[i][j]);

                    else
                        printf("| %d ", arr[i][j]);
                }

                printf("|\n");
            }
            printf("---------------------\n\n\n");
            break;
        }

        case 77:
        {
            system("cls");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    if (arr[i][j] == 0)
                    {
                        if (j > 0)
                        {
                            t = arr[i][j];
                            arr[i][j] = arr[i][j - 1];
                            arr[i][j - 1] = t;
                            k--;
                            break;
                        }
                        else
                        {
                            printf("CAN NOT MOVE \n\n");
                            break;
                        }
                    }
                }
            }

            for (i = 0; i < 4; i++)
            {
                printf("---------------------\n");
                for (j = 0; j < 4; j++)
                {

                    if (arr[i][j] == 0)
                        printf("|    ");
                    else if (arr[i][j] <= 9)
                        printf("| %d  ", arr[i][j]);

                    else
                        printf("| %d ", arr[i][j]);
                }

                printf("|\n");
            }
            printf("---------------------\n\n\n");
            break;
        }
       
        case 72:
        {
            system("cls");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    if (arr[i][j] == 0)
                    {

                        if (i < 3)
                        {

                            t = arr[i][j];
                            arr[i][j] = arr[i + 1][j];
                            arr[i + 1][j] = t;
                            k--;
                            
                            goto label;
                        }
                        else
                        {
                            printf("CAN NOT MOVE \n\n");
                            break;
                        }
                    }
                }
            }
             label:
            for (i = 0; i < 4; i++)
            {
                printf("---------------------\n");
                for (j = 0; j < 4; j++)
                {

                    if (arr[i][j] == 0)
                        printf("|    ");
                    else if (arr[i][j] <= 9)
                        printf("| %d  ", arr[i][j]);

                    else
                        printf("| %d ", arr[i][j]);
                }

                printf("|\n");
            }
            printf("---------------------\n\n\n");
            break;
        }
        case 80:
        {
            system("cls");
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    if (arr[i][j] == 0)
                    {
                        if (i > 0)
                        {
                            t = arr[i][j];
                            arr[i][j] = arr[i - 1][j];
                            arr[i - 1][j] = t;
                            k--;
                            break;
                        }
                        else
                        {
                            printf("CAN NOT MOVE \n\n");
                            break;
                        }
                    }
                }
            }

            for (i = 0; i < 4; i++)
            {
                printf("---------------------\n");
                for (j = 0; j < 4; j++)
                {

                    if (arr[i][j] == 0)
                        printf("|    ");
                    else if (arr[i][j] <= 9)
                        printf("| %d  ", arr[i][j]);

                    else
                        printf("| %d ", arr[i][j]);
                }

                printf("|\n");
            }
            printf("---------------------\n\n\n");
            break;
        }
        case 27:
            exit(0);
        }
    }
}
int check(int *a, int x)
{
    int r = 0, i, j, b[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    for (i = 0; i < 16; i++)
    {
        if (*(a + i) != b[i])
        {
        
            break;
        }
    }
    if (i == 15 && x > 0)
    {
        r = 1;
        printf("\n ** YOU WON **\n ");
    }
    else if (x == 0 && i != 15)
    {
        r = 2;
        printf("\n  YOU LOOSE  \n");
    }
    return r;
}