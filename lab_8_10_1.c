#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int main() {
    char ch;

    while ((ch = getch()) != 0) { // Получаем символ без вывода на экран
        if (ch == -32) { // Если нажата функциональная клавиша
            ch = getch(); // Считываем код функциональной клавиши
            if (ch == 66) { // F8 имеет код 66
                break; // Завершаем программу
            }
        }

        if (islower(ch)) { // Если символ - строчная буква
            ch = toupper(ch); // Заменяем на заглавную букву
        }

        putchar(ch); // Выводим символ на экран
    }

    return 0;
}
