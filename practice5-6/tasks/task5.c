#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct MemoryBlock {
    char* memory;
    size_t size;
};


struct Command {
    char *name;
    void (*func)(struct MemoryBlock *memory, char* n);
};


void alloc_cmd(struct MemoryBlock *memory, char* n) {
    if (memory->memory != NULL) {
        printf("Ошибка: Память уже выделена. Используйте `free`, чтобы освободить память\n");
        return;
    }

    int mul = 1;
    if (n[0] == '-') {
        mul = -1;
        n++;
    }

    int size = atoi(n) * mul;
    
    if (size <= 0) {
        printf("Ошибка: Размер памяти должен быть положительным числом\n");
        return;
    }

    memory->memory = (char* )malloc(size);

    memory->size = size;
    printf("Выделено %d байт памяти\n", size);
}


void free_cmd(struct MemoryBlock *memory, char* arg) {
    if (memory->memory == NULL) {
        printf("Ошибка: Память уже пуста\n");
        return;
    }

    memory->memory = NULL;
    memory->size = 0;
    printf("Память очищена\n");
}


void write_cmd(struct MemoryBlock *memory, char* text) {
    if (memory->memory == NULL) {
        printf("Ошибка: Память не выделена\n");
        return;
    }

    int i = 0;
    while (text[i] != '\0' && i < memory->size) {
        memory->memory[i] = text[i];
        i++;
    }
    memory->memory[i] = '\0';
    while (text[i] != '\0') {
        i++;
    }

    printf("Текст записан");
    if (i > memory->size) {
        printf(" (Только первые %zu символов)", memory->size);
    }
    printf("\n");
}


void print_cmd(struct MemoryBlock *memory, char* text) {
    if (memory->memory == NULL) {
        printf("Ошибка: Память не выделена\n");
        return;
    }

    printf("%s\n", memory->memory);
}


int main() {
    struct MemoryBlock memory = {NULL, 0};

    struct Command commands[] = {
        {"alloc", alloc_cmd},
        {"free", free_cmd},
        {"write", write_cmd},
        {"print", print_cmd},
        {"exit", NULL}
    };
    size_t commands_len = sizeof(commands) / sizeof(commands[0]);

    char input[256];
    int i, k, f, cmd_i, arg_i;
    char cmd[256];
    char arg[256];
    
    while (1) {
        printf("$> ");
        fgets(input, sizeof(input), stdin);
        if (input[0] == '\n') {
            continue;
        }
        
        i = 0;
        f = 0;
        cmd_i = 0;
        arg_i = 0;
        while (input[i] != '\n') {
            
            if (input[i] == ' ') {
                f = 1;
            } else if (f == 0) {
                cmd[cmd_i] = input[i];
                cmd_i++;
            } else {
                arg[arg_i] = input[i];
                arg_i++;
            }
            i++;
        }
        cmd[cmd_i] = '\0';
        arg[arg_i] = '\0';

        f = 0;

        for (int k = 0; k < commands_len; k++) {
            if (strcmp(cmd, commands[k].name) == 0) {
                if (!commands[k].func) {
                    return 1;
                }
                commands[k].func(&memory, arg);
                f = 1;
            }
        }
        if (!f) {
            printf("Команда не найдена: %s\n", cmd);
        }

    }

    return 0;
}
