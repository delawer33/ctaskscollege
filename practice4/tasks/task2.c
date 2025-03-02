#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VOWELS "aeiouyAEIOUY"

struct Command {
    char *name;
    char* (*func)(char*);
};

char* delete_spaces(char* str) {
    int k = 0, i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            k++;
            i++;
            continue;
        }
        str[i - k] = str[i];
        i++;
    }
    str[i - k] = '\0';
    return str;
}


char* replace_vowels(char* str) {
    int i = 0, v = 0;
    while (str[i] != '\0') {
        while (VOWELS[v] != '\0'){
            if (str[i] == VOWELS[v]) {
                str[i] = '*';
                break;
            }
            v++;
        }
        v = 0;
        i++;
    }
    return str;
}


char* invert_register(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] <= 'Z' && str[i] >= 'A') {
            str[i] += 32;
        } else if (str[i] <= 'z' && str[i] >= 'a') {
            str[i] -= 32;
        }
        i++;
    }
    return str;
}


int main() {    
    char *res;
    char commands_from_user[100][50];
    char str[128];
    char input_func[265];

    struct Command commands[] = {
        {"delete_spaces", delete_spaces},
        {"replace_vowels", replace_vowels},
        {"invert_register", invert_register}
    };
    
    printf("Введите строку: ");
    fgets(str, 128, stdin);
    printf("Введите название операции (или введите несколько через пробел): ");
    fgets(input_func, 256, stdin);
    input_func[strcspn(input_func, "\n")] = '\0';
    
    int i = 0, k = 0, j = 0;
    while (input_func[i] != '\0') {
        if (input_func[i] == ' ') {
            k++;
            j = 0;
            i++;
            continue;
        }
        commands_from_user[k][j] = input_func[i];
        j++;
        i++;
    }

    res = str;
    int f = 0;
    for (int i = 0; i < k + 1; i++) {
        for (int j = 0; j < sizeof(commands) / sizeof(commands[0]); j++) {
            if (strcmp(commands[j].name, commands_from_user[i]) == 0) {
                res = commands[j].func(res);
                f = 1;
            }
        }
        if (!f) {
            printf("Команда с названием `%s` не найдена!\n", commands_from_user[i]);
        }
        f = 0;
    }
    
    printf("Результат: %s", res);
    return 0;
}
