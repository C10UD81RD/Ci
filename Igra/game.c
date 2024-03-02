#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


#define ROWS 10
#define COLS 10

void displayBoard(char board[ROWS][COLS])
{
    printf("1 2 3 4 5 6 7 8 9\n");
    printf("_________________\n");
    for (int i = ROWS - 1; i >= 1; i--)
    {
        for (int j = 1; j < COLS; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("—————————————————\n");
    printf("1 2 3 4 5 6 7 8 9\n");
}

bool isValidMove(int col, char board[ROWS][COLS])
{
    return (col >= 1 && col < COLS && board[ROWS - 1][col] == ' ');
}

void makeMove(int col, char color, char board[ROWS][COLS])
{
    for (int i = 1; i < ROWS; i++)
    {
        if (board[i][col] == ' ')
        {
            board[i][col] = color;
            break;
        }
    }
}

bool checkWin(char color, char board[ROWS][COLS])
{
    // Проверка горизонтальных и вертикальных линий
    for (int i = 1; i < ROWS; i++)
    {
        for (int j = 1; j < COLS - 3; j++)
        {
            if ((board[i][j] == color && board[i][j + 1] == color && board[i][j + 2] == color && board[i][j + 3] == color) ||
                (board[j][i] == color && board[j + 1][i] == color && board[j + 2][i] == color && board[j + 3][i] == color))
            {
                return true;
            }
        }
    }

    // Проверка нисходящих диагоналей
    for (int i = 1; i < ROWS - 3; i++)
    {
        for (int j = 1; j < COLS - 3; j++)
        {
            if (board[i][j] == color && board[i + 1][j + 1] == color && board[i + 2][j + 2] == color && board[i + 3][j + 3] == color)
            {
                return true;
            }
        }
    }

    // Проверка восходящих диагоналей
    for (int i = 4; i < ROWS; i++)
    {
        for (int j = 1; j < COLS - 3; j++)
        {
            if (board[i][j] == color && board[i - 1][j + 1] == color && board[i - 2][j + 2] == color && board[i - 3][j + 3] == color)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    char board[ROWS][COLS];

    // Инициализация доски
    for (int i = 1; i < ROWS; i++)
    {
        for (int j = 1; j < COLS; j++)
        {
            board[i][j] = ' ';
        }
    }

    srand(time(NULL));

    bool isPlayerTurn = true;
    char playerColor = 'X';
    char aiColor = 'O';

    while (true)
    {
        displayBoard(board);

        if (isPlayerTurn)
        {
            // Ход игрока
            int col;
            printf("Введите номер колонки: ");
            scanf("%d", &col);
            
            if (isValidMove(col, board))
            {
                system("clear");
                makeMove(col, playerColor, board);
                if (checkWin(playerColor, board))
                {
                    printf("Вы победили!\n");
                    break;
                }
                isPlayerTurn = false;
            }
            else
            {
                printf("Некорректный ход! Попробуйте снова.\n");
            }
            
        }
        else
        {   
            // Ход ИИ
            int aiCol = rand() % (COLS - 1) + 1;
            
            if (isValidMove(aiCol, board))
            {
                system("clear");
                makeMove(aiCol, aiColor, board);
                if (checkWin(aiColor, board))
                {
                    printf("ИИ победил!\n");
                    break;
                }
                isPlayerTurn = true;
            }
        }
    }

    displayBoard(board);

    return 0;
}