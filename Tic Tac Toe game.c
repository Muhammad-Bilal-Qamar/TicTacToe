#include<stdio.h>
#include<time.h>
#include<stdlib.h>

char Board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

// Function prototypes
void resetboard();
void printBoard();
int checkFreeSpaces();
void PlayerMove();
void computerMove();
char Checkwinner();
void PrintWinner(char);

int main()
{
    int n;
    do
    {
        char winner = ' ';

        resetboard(); // clearing Board

        while( winner == ' ' && checkFreeSpaces() != 0 )
        {
            printBoard(); // printing board
            PlayerMove();
            winner= Checkwinner();
            if( winner != ' ' || checkFreeSpaces() == 0 )
            {
                break;
            }

            computerMove();
            winner= Checkwinner();
            if( winner != ' ' || checkFreeSpaces() == 0 )
            {
                break;
            }
        }

        printBoard();
        PrintWinner( winner );
        printf("\nYES = 1");
        printf("\nNO = 2");
        printf("\nWant to play again:");
        scanf("%d",&n);
    }while( n = 1 && n != 2 );
    return 0;
}

void resetboard()
{
    for( int i=0 ; i<3 ;i++ )
    {
        for( int j=0 ; j<3 ; j++ )
        {
            Board[i][j] = ' ';
        }
    }
}
void printBoard()
{
    printf("\t\t|\t\t|\t\t");
    printf("\n\t\t|\t\t|\t\t\n");
    printf("\t%c\t|\t%c\t|\t%c",Board[0][0],Board[0][1],Board[0][2]);
    printf("\n----------------|---------------|----------------\n");
    printf("\t\t|\t\t|\t\t\n");
    printf("\t\t|\t\t|\t\t\n");
    printf("\t%c\t|\t%c\t|\t%c\t",Board[1][0],Board[1][1],Board[1][2]);
    printf("\n----------------|---------------|----------------\n");
    printf("\t%c\t|\t%c\t|\t%c\t",Board[2][0],Board[2][1],Board[2][2]);
    printf("\n\t\t|\t\t|\t\t\n");
    printf("\t\t|\t\t|\t\t");
    printf("\n");
}
int checkFreeSpaces()
{
    int FreeSpaces = 9;
    for( int i=0 ; i<3 ; i++ )
    {
        for( int j=0 ; j<3 ; j++ )
        {
            if( Board[i][j] != ' ' )
            {
                FreeSpaces-- ;
            }
        }
    }
    return FreeSpaces;
}
void PlayerMove()
{
    int x , y;

    do
    {
        printf("Enter Row No.(1-3): ");
        scanf("%d",&x);
        x--;
        printf("Enter Column No.(1-3): ");
        scanf("%d",&y);
        y--;

        if( Board[x][y] != ' ' )
        {
            printf("Invalid Move!\n");
        }
        else
        {
            Board[x][y] = PLAYER;
            break;
        }
    }while( Board[x][y] != ' ' );
}
void computerMove()
{
    //creates a seed based on current time
    srand(time(0));
    int x , y;

    if( checkFreeSpaces() > 0 )
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        }while( Board[x][y] != ' ' );

        Board[x][y] = COMPUTER;
    }
    else
    {
        PrintWinner(' ');
    }
}
char Checkwinner()
{
    //check rows
    for( int i=0; i<3 ; i++ )
    {
        if( Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2] )
        {
            return Board[i][0];
        }
    }
    // check columns
    for( int i=0; i<3 ; i++ )
    {
        if( Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i] )
        {
            return Board[0][i];
        }
    }
    // check Diagonals
    if( Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2] )
    {
        return Board[0][0];
    }
    if( Board[0][2] == Board[1][1] && Board[0][2] == Board[2][0] )
    {
        return Board[0][2];
    }

    return ' ';
}
void PrintWinner(char winner)
{
    // Checking Winner
    if( winner == PLAYER )
    {
        printf("YOU WIN!");
    }
    else if( winner == COMPUTER )
    {
        printf("YOU LOSE!");
    }
    else
    {
        printf("IT'S A TIE!");
    }
}
