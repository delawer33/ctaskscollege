#include <stdio.h>
#include <string.h>


int main() {
    char input[12];

    printf("Введите код: ");
    fgets(input, 12, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strcasecmp(input, "LAUNCH-2025") == 0) {
        printf("Код принят\n");
    } else {
        printf("Ошибка: неверный код\n");
    }

    return 1;
}
