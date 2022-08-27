//NAME:- NILESH PANCHOTIYA
//GAME:- NUMBER SHIFTING GAME


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


#define WHITE "\e[0;97m"
#define BOLD "\e[1;91m"
#define BOLDBLUE "\e[1;34m"
#define UNDERLINE "\e[4;32m"
#define RED "\e[0;31m"
#define YELLOW "\e[0;33m"
#define GREEN "\e[0;32m"
#define PUR "\e[0;35m"
#define UCYAN "\e[4;36m"
#define WING "\e[1;92m"


void downarrow(int a[][4], int *);
void uparrow(int a[][4], int *);
void rightarrow(int a[][4], int *);
void leftarrow(int a[][4], int *);
void display(int arr[][4], int);
void createMatrix(int arr[][4]);
int win(int a[][4]);
void winning();
void rules();
int findkey();


int win(int a[][4])
{
    int i, n = 1;
    int mat[4][4];
    for (i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mat[i][j] = n;
            n++;
            if (mat[i][j] == mat[3][3])
                mat[i][j] = ' ';
        }
    }
    for (i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] == mat[i][j])
                printf("");
            else
                return 1;
        }
    }
    system("cls");
    printf(WING "\n\n\n\a!!!!!!!!!!!!!Congratulations You Are Win The Game !!!!!!!!!!!!!\n\a" WHITE);
    return 0;
}

void leftarrow(int a[][4], int *step)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] == ' ' && j < 3)
            {
                int temp = a[i][j];
                a[i][j] = a[i][j + 1];
                a[i][j + 1] = temp;
                *step -= 1;
                return;
            }
        }
    }
}
void rightarrow(int a[][4], int *step)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] == ' ' && j > 0)
            {
                int temp = a[i][j];
                a[i][j] = a[i][j - 1];
                a[i][j - 1] = temp;
                *step -= 1;
                return;
            }
        }
    }
}

void downarrow(int a[][4], int *step)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] == ' ' && i > 0)
            {
                int temp = a[i][j];
                a[i][j] = a[i - 1][j];
                a[i - 1][j] = temp;
                *step -= 1;
                return;
            }
        }
    }
}
void uparrow(int a[][4], int *step)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] == ' ' && i < 3)
            {
                int temp = a[i][j];
                a[i][j] = a[i + 1][j];
                a[i + 1][j] = temp;
                *step -= 1;
                return;
            }
        }
    }
}
int findkey()
{
    int t;
    t = _getch();
    if (t == 32)
        t = _getch();
    return t;
}
void winning()
{
    int i, n = 1;
    int mat[4][4];
    for (i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mat[i][j] = n;
            n++;
            if (mat[i][j] == mat[3][3])
                mat[i][j] = ' ';
        }
    }
    n = 1;
    printf(RED "---------------------\n" WHITE);
    for (i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (mat[i][j] == mat[3][3])
            {
                printf(RED "|" WHITE " %c  ", mat[i][j]);
                n++;
                break;
            }
            if (n < 10)
            {
                printf(RED "|" WHITE " %d  ", mat[i][j]);
                n++;
            }
            else
            {
                printf(RED "|" WHITE " %d ", mat[i][j]);
                n++;
            }
        }
        printf(RED "|\n");
        printf(RED "---------------------\n" WHITE);
    }
}

void display(int arr[][4], int step)
{
    int i = 0;
    printf("\n\n");
    printf(PUR "Reaming Steps =" YELLOW " %d" WHITE, step);
    printf(GREEN "\n\n---------------------\n" WHITE);
    for (i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == ' ')
                printf(GREEN "|" WHITE " %c  ", arr[i][j]);
            else if (arr[i][j] < 10)
                printf(GREEN "|" WHITE " %d  ", arr[i][j]);
            else
                printf(GREEN "|" WHITE " %d ", arr[i][j]);
        }
        printf(GREEN "|\n");
        printf(GREEN "---------------------\n" WHITE);
    }
    printf("\n\n");
}

void createMatrix(int arr[][4])
{
    int n = 15;
    int num[n], i, j;
    for (i = 0; i < 15; i++)
        num[i] = i + 1;

    srand(time(NULL));

    int lastIndex = n - 1, index;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {
            if (lastIndex >= 0)
            {
                index = rand() % (lastIndex + 1);
                arr[i][j] = num[index];
                num[index] = num[lastIndex--];
            }
        }
    arr[i - 1][j - 1] = ' ';
}

int main()
{
    while (1)
    {
        char name[30];
        int a[4][4], step = 500;
        printf("\n\n\n\nEnter Player Name :- ");
        fflush(stdin);
        scanf("%s", name);
        fflush(stdin);
        system("cls");
        printf(PUR "\n\nHii, %s\n\t\t" BOLDBLUE "You will Enter in Number Shifting Game\n\n", name);
        rules();
        createMatrix(a);
        while (win(a) && step)
        {
            system("cls");
            fflush(stdin);
            display(a, step);
            int k = findkey();
            switch (k)
            {
            case 72:
                uparrow(a, &step);
                break;
            case 80:
                downarrow(a, &step);
                break;
            case 77:
                rightarrow(a, &step);
                break;
            case 75:
                leftarrow(a, &step);
                break;
            case 'e':
            case 'E':
                printf("--------------Thanks For Playing--------------\n\n");
                printf("Press Any Key to Exit... ");
                getch();
                return 0;
            }
        }
        if (step < 1)
        {
            system("cls");
            printf(RED "You Are LOSE The Game");
            printf(PUR "\n\nYour step will be end\n");
        }
        printf(GREEN "\n'y' to Play again'? = ");
        int y = getch();
        if (y == 'y' || y == 'Y')
            printf("");
        else
        {
            printf("\n\n-------------------Thanks For Playing-------------------\n\n\n");
            getch();
            return 0;
        }
    }
    return 0;
}

void rules()
{
    printf(BOLD "\t\t\tRULES OF GAME\n\n");
    printf(YELLOW "1.You can move only 1 step at a time by arrow key\n");
    printf("MOVE UP   :  With UP ARROW KEY\n");
    printf("MOVE DOWN :  With DOWN ARROW KEY\n");
    printf("MOVE LEFT :  With LEFT ARROW KEY\n");
    printf("MOVE RIGHT:  With RIGHT ARROW KEY\n\n");
    printf(GREEN "2.You can move number at empty postion only\n\n");
    printf(YELLOW "3.For each valid move : your total number of move will decreased by 1\n\n");
    printf(GREEN "4.Wining situation: Number in a 4*4 matrix should be in order from 1 to 15\n\n");
    printf(UCYAN "Winning situation : \n\n" WHITE);
    winning();
    printf(YELLOW "\n5.You can exit the game at any time by pressing 'E' or 'e' \n\n");
    printf(PUR "\nSo Try to win in minimum no of move");
    printf(GREEN "\n\n________Good Luck________\n\n");
    printf(WHITE "Enter the Any key to start ......... \n");
    getch();
}
