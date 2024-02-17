#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

// Функция для проверки, можно ли сделать ход в указанную колонку
bool isValidMove(int col, char board[ROWS][COLS])
{
    if (col < 1 || col >= COLS)
        return false;
    if (board[ROWS - 1][col] != ' ')
        return false;
    return true;
}

// Функция для выпадения фишки в указанную колонку
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

// Функция для проверки наличия победителя
bool checkWin(char color, char board[ROWS][COLS])
{
    // Проверка горизонтальных линий
    for (int i = 1; i < ROWS; i++)
    {
        for (int j = 1; j < COLS - 4; j++)
        {
            if (board[i][j] == color &&
                board[i][j + 1] == color &&
                board[i][j + 2] == color &&
                board[i][j + 3] == color)
                return true;
        }
    }

    // Проверка вертикальных линий
    for (int i = 1; i < ROWS - 4; i++)
    {
        for (int j = 1; j < COLS; j++)
        {
            if (board[i][j] == color &&
                board[i + 1][j] == color &&
                board[i + 2][j] == color &&
                board[i + 3][j] == color)
                return true;
        }
    }

    // Проверка диагональных линий с положительным наклоном
    for (int i = 1; i < ROWS - 4; i++)
    {
        for (int j = 1; j < COLS - 4; j++)
        {
            if (board[i][j] == color &&
                board[i + 1][j + 1] == color &&
                board[i + 2][j + 2] == color &&
                board[i + 3][j + 3] == color)
                return true;
        }
    }

    // Проверка диагональных линий с отрицательным наклоном
    for (int i = 4; i < ROWS; i++)
    {
        for (int j = 1; j < COLS - 4; j++)
        {
            if (board[i][j] == color &&
                board[i - 1][j + 1] == color &&
                board[i - 2][j + 2] == color &&
                board[i - 3][j + 3] == color)
                return true;
        }
    }

    return false;
}

// Функция для игры
void playGame()
{
    char board[ROWS][COLS];
    for (int i = 1; i < ROWS; i++)
    {
        for (int j = 1; j < COLS; j++)
        {
            board[i][j] = ' ';
        }
    }

    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver)
    {
        displayBoard(board);

        printf("Ход игрока %c\n", currentPlayer);
        int col;
        printf("Введите номер колонки (от 1 до 9): ");
        scanf("%d", &col);

        if (isValidMove(col, board))
        {
            makeMove(col, currentPlayer, board);
            system("clear");
            if (checkWin(currentPlayer, board))
            {
                displayBoard(board);
                printf("Вы победили!\n");
                gameOver = true;
            }
            else
            {
                if (currentPlayer == 'X')
                    currentPlayer = 'O';
                else
                    currentPlayer = 'X';
            }
        }
        else
        {
            printf("Некорректный ход. Попробуйте ещё раз.\n");
        }
    }
}

// Главная функция
int main()
{
    char choice;
    do
    {
        playGame();

        printf("--------\n");
        printf("Игра окончена.\n");
        printf("Нажмите 'M', чтобы вернуться в главное меню, или 'Q', чтобы выйти: ");
        scanf(" %c", &choice);
    } while (choice == 'M' || choice == 'm');

    return 0;
}