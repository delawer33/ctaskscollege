#include <stdio.h>
#include <string.h>


int main() {
    char input[256];

    printf("Введите список космонавтов: ");
    fgets(input, 256, stdin);
    input[strcspn(input, "\n")] = '\0';

    char* prev = strtok(input, ";");

    while (prev != NULL) {
        printf("%s\n", prev);
        prev = strtok(NULL, ";");
    }

    return 1;
}
