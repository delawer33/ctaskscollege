// -----------------------------------------------------

// Если вдруг программа не компилится и выходит ошибка
// о функции `pow`, то использовать команду gcc task3.c -lm

// -----------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


float calculate(float n1, float n2, char oper) {
    switch (oper)
    {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
        
        default:
            printf("Ошибка: не указана операция\n");
            exit(0);
    }
}

int main() {    
    char allowed_symbols[] = "0123456789+-/* ";
    int allowed_symbols_len = sizeof(allowed_symbols) / sizeof(allowed_symbols[0]) - 1;
    char input[64];
    int i = 0, j = 0, f = 0, int_mul = 0, f_mul = 1, int_or_fract = 0, number = 0;
    char oper = 'n';
    float numbers[] = {0., 0.};

    printf("Введите выражение: ");
    fgets(input, 64, stdin);
    

    while (input[i] != '\n'){
        if (input[i] == ' ') {
            i++;
            continue;
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            oper = input[i];
            if (number > 0) {
                printf("Может быть только один знак операции\n");
                exit(0);
            }
            number += 1;
            int_mul = 0;
            f_mul = 1;
            int_or_fract = 0;
        } else if (input[i] == '.') {
            if (int_or_fract > 0) {
                printf("В числе может быть только одна точка\n");
                exit(0);
            }
            int_or_fract += 1;
        } else if (input[i] >= '0' && input[i] <= '9') {
            if (int_or_fract == 0) {
                numbers[number] = numbers[number] * 10 + (input[i] - 48);
            } else {
                numbers[number] += (numbers[number] - numbers[number] / 1) + (input[i] - 48) * pow(0.1, f_mul);
                f_mul += 1;
            }
        } else {
            printf("Недопустимый символ `%c`", input[i]);
            exit(0);
        }
        i++;
    }

    printf("Результат: %f\n", calculate(numbers[0], numbers[1], oper));
    return 0;
}
