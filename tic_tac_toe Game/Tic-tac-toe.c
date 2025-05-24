#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void starting_text(void);
void rules_text(void);
void clear_position(int A[][4]);
void cell_printing(int A[][4]);
int start_playing(int A[][4]);
bool draw_checker(int A[][4]);
bool invalid_checker(int A[][4],int r,int c);
int winner_checker(int A[][4]);
void winning_combination(int A[][4]);

int main(void)
{
    starting_text();
    rules_text();

    int matrix[4][4];

    clear_position(matrix);

    printf("Game is starting...\n\n");
    cell_printing(matrix);

    int win = start_playing(matrix);

    if(win>0)
    {
        printf("\n\n\nCongratulations..\nPlayer %d Wins...\n\n\n",win);
        winning_combination(matrix);
    }
    else
    {
        printf("\n\n\nMatch Drawn.. Well Played...\n\n\n");
        cell_printing(matrix);
    }


    printf("\n\n\n                THE END\n");
    printf("                =======\n\n\n");

    return 0;
}

void starting_text(void)
{
    printf("Simple Project by Hazrat Ali \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("            Tic-Tac-Toe\n");
    printf("            ~~~~~~~~~~~\n\n");
}

void rules_text(void)
{
    printf("Rules:\n");
    printf("~~~~~~\n");
    printf("1. Player 1 moves first and puts X.\n");
    printf("2. Player 2 moves next and puts O.\n");
    printf("3. Enter row and column to take the position.\n");
    printf("   Enter 2 3 to take 2nd row and 3rd column position.\n");
    printf("4. Each can move once a time.\n");
    printf("5. If one position is taken, Can't be taken that position again.\n");
    printf("6. Take full row or column or diagonal to win.\n\n\n");
}

void clear_position(int A[][4])
{
    for(int i=1; i<4; i++)
        for(int j=1; j<4; j++)
            A[i][j]=0;
}

void cell_printing(int A[][4])
{
    for(int i=1; i<4; i++)
    {
        printf("\n    ");
        for(int j=1; j<4; j++)
        {
            if(A[i][j]==0) printf("       ");
            else if(A[i][j]==1) printf("   X   ");
            else printf("   O   ");
            if(j<3) printf("|");
        }
        if(i<3) printf("\n    -----------------------");
    }
    printf("\n\n");
}
int start_playing(int A[][4])
{
    bool player_1=true, player_2=false;
    int r,c,W=0;

    while(!draw_checker(A))
    {
        if(player_1)
        {
            printf("Player 1's move (X) : ");
            scanf("%d %d",&r,&c);
            if(invalid_checker(A,r,c))
            {
                printf("\nInvalid position..\n");
                printf("Find empty location and Try again..\n\n");
                continue;
            }
            A[r][c]=1;
            cell_printing(A);
            player_1=false;
            player_2=true;
        }
        else if(player_2)
        {
            printf("Player 2's move (O) : ");
            scanf("%d %d",&r,&c);
            if(invalid_checker(A,r,c))
            {
                printf("\nInvalid position..\n");
                printf("Find empty location and Try again..\n\n");
                continue;
            }
            A[r][c]=2;
            cell_printing(A);
            player_1=true;
            player_2=false;
        }

        W = winner_checker(A);
        if(W==1)    return 1;
        if(W==2)    return 2;
    }
    return 0;
}

bool draw_checker(int A[][4])
{
    int filled=0;
    for(int i=1; i<4; i++)
    {
        for(int j=1; j<4; j++)
        {
            if(A[i][j]!=0)
                filled++;
        }
    }
    if(filled<9)    return false;
    return true;
}
bool invalid_checker(int A[][4],int r,int c)
{
    if(r>3 || c>3 || r<1 || c<1)    return true;
    if(A[r][c]==0)  return false;
    return true;
}

int winner_checker(int A[][4])
{
    for(int i=1; i<4; i++)
    {
        if(A[i][1]!=0 && A[i][1]==A[i][2] && A[i][1]==A[i][3])
        {
            if(A[i][1]==1)  return 1;
            else            return 2;
        }
    }
    for(int i=1; i<4; i++)
    {
        if(A[1][i]!=0 && A[1][i]==A[2][i] && A[2][i]==A[3][i])
        {
            if(A[1][i]==1)  return 1;
            else            return 2;
        }
    }
    if(A[1][1]!=0 && A[1][1]==A[2][2] && A[2][2]==A[3][3])
    {
        if(A[1][1]==1)  return 1;
        else            return 2;
    }
    if(A[2][2]!=0 && A[1][3]==A[2][2] && A[2][2]==A[3][1])
    {
        if(A[1][3]==1)  return 1;
        else            return 2;
    }
    return 0;
}
// Tic Tac Toe
void winning_combination(int A[][4])
{
    bool print=false;
    for(int ii=1; ii<4; ii++)
    {
        if(A[ii][1]!=0 && A[ii][1]==A[ii][2] && A[ii][1]==A[ii][3])
        {
            for(int i=1; i<4; i++)
            {
                print=true;
                printf("\n    ");
                for(int j=1; j<4; j++)
                {
                    if(i==ii)
                    {
                         if(A[i][3]==1)     printf("   X   ");
                         else  printf("   O   ");
                    }
                    else printf("       ");
                    if(j<3) printf("|");
                }
                if(i<3) printf("\n    -----------------------");
            }
        }

        if(print)
        {   printf("\n\n\n");            return;  }


        if(A[1][ii]!=0 && A[1][ii]==A[2][ii] && A[2][ii]==A[3][ii])
        {
            for(int i=1; i<4; i++)
            {
                print=true;
                printf("\n    ");
                for(int j=1; j<4; j++)
                {
                    if(j==ii)
                    {
                         if(A[1][j]==1)     printf("   X   ");
                         else  printf("   O   ");
                    }
                    else printf("       ");
                    if(j<3) printf("|");
                }
                if(i<3) printf("\n    -----------------------");
            }
        }
    }

    if(print)
        {   printf("\n\n\n");            return;  }


    if(A[1][1]!=0 && A[1][1]==A[2][2] && A[2][2]==A[3][3])
    {
        print=true;
        for(int i=1; i<4; i++)
            {
                printf("\n    ");
                for(int j=1; j<4; j++)
                {
                    if(i==j)
                    {
                         if(A[2][2]==1)     printf("   X   ");
                         else  printf("   O   ");
                    }
                    else printf("       ");
                    if(j<3) printf("|");
                }
                if(i<3) printf("\n    -----------------------");
            }
    }
    else if(A[1][3]!=0 && A[1][3]==A[2][2] && A[2][2]==A[3][1])
    {
        print=true;
        for(int i=1; i<4; i++)
            {
                printf("\n    ");
                for(int j=1; j<4; j++)
                {
                    if(i+j==4)
                    {
                         if(A[2][2]==1)     printf("   X   ");
                         else  printf("   O   ");
                    }
                    else printf("       ");
                    if(j<3) printf("|");
                }
                if(i<3) printf("\n    -----------------------");
            }
    }
    if(print)
        {   printf("\n\n\n");            return;  }
}
