#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Command {
    char *name;
    char* (*func)(char*);
};

char* upper(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if ('a' <= str[i] && str[i] <= 'z') {
            str[i] -= 32;
        }
        i++;
    }
    return str;
}


char* lower(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] += 32;
        }
        i++;
    }
    return str;
}


char* reverse(char *str) {
    int i = 0, j = 0, t;
    while (str[i] != '\0') {
        i++;
    }
    i--;
    
    while (j < i) {
        t = str[j];
        str[j] = str[i];
        str[i] = t;
        j++;
        i--;
    }
    return str;
}


int main() {
    char *res;
    char str[128];
    char input_func[32];

    struct Command commands[] = {
        {"upper", upper},
        {"lower", lower},
        {"reverse", reverse},
        {"exit", NULL}
    };

    while (1) {
        printf("Введите строку: ");
        fgets(str, 128, stdin);
        printf("Введите название операции: ");
        fgets(input_func, 32, stdin);
        input_func[strcspn(input_func, "\n")] = '\0';

        int f = 0;
        for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
            if (strcmp(commands[i].name, input_func) == 0) {
                if (!commands[i].func) {
                    exit(1);
                }
                res = commands[i].func(str);
                printf("Результат: %s", res);
                f = 1;
            }
        }
        if (!f) {
            printf("Команда с названием `%s` не найдена!\n", input_func);
        }
        printf("\n");
    }
    return 0;
}
