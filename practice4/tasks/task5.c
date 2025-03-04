#include <stdio.h>
#include <string.h>


int main() {
    char input[200];

    printf("Введите отчет: ");
    fgets(input, 200, stdin);
    input[strcspn(input, "\n")] = '\0';

    char* copy = strndup(input, strlen(input));

    printf("Оригинал: %s\n", input);
    printf("Копия: %s\n", copy);
    return 1;
}
