#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Решил сделать с динамическим массивом



// Это решение если делать с массивом строк
int main() {
    char** strings;
    int n;
    printf("Введите количесвто кораблей: ");
    scanf("%d", &n);
    getchar();

    strings = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        strings[i] = (char*)malloc(50 * sizeof(char));
        fgets(strings[i], 50, stdin);
        strings[i][strcspn(strings[i], "\n")] = '\0';
    }


    for (int i = 0; i < n; i++) {
        if (strncmp(strings[i], "SS", 2) == 0) {
            printf("Первый корабль с названием, начинающимся на SS: %s\n", strings[i]);
            return 1;
        }
    }
    printf("Кораблей с названием, начинающимся на SS не найдено.\n");
    return 1;
}


// Это решение без массива строк

// int main() {
//     char input[50];
//     int n;
//     printf("Введите количесвто кораблей: ");
//     scanf("%d", &n);
//     getchar();

//     for (int i = 0; i < n; i++) {
//         fgets(input, 50, stdin);
//         if (strncmp(input, "SS", 2) == 0) {
//             printf("Первый корабль с названием, начинающимся на SS: %s\n", input);
//             return 1;
//         }
//     }

//     printf("Кораблей с названием, начинающимся на SS не найдено.\n");
//     return 1;
// }

