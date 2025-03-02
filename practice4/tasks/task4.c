#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VOWELS "aeiouyAEIOUY"


int count_vowels(const char* str) {
    int i = 0, c = 0;
    while (str[i] != '\0') {
        for (int j = 0; j < 12; j++) {
            if (str[i] == VOWELS[j]) {
                c++;
                break;
            }
        }
        i++;
    }
    return c;
}


int compare_letters(const void* str1, const void* str2) {
    const char* cstr1 = *(const char **)str1;
    const char* cstr2 = *(const char **)str2;
    return strcasecmp(cstr1, cstr2);
}


int compare_lenght(const void* str1, const void* str2) {
    const char* cstr1 = *(const char **)str1;
    const char* cstr2 = *(const char **)str2;
    return strlen(cstr1) - strlen(cstr2);
}


int compare_vowels(const void* str1, const void* str2) {
    const char* cstr1 = *(const char **)str1;
    const char* cstr2 = *(const char **)str2;
    return count_vowels(cstr1) - count_vowels(cstr2);
}


int main() {
    int (*func)(const void*, const void*);    
    int n;
    char str[100];
    printf("Введите количество строк: ");
    scanf("%d", &n);
    getchar();

    char **strings = (char **)(malloc(n * sizeof(char*)));
    for (int i = 0; i < n; i++) {
        fgets(str, 100, stdin);
        str[strcspn(str, "\n")] = '\0';
        strings[i] = strdup(str);
    }

    int f = 0;

    printf("Выберите вариант сортировки: \n");
    printf("1) По алфавиту\n");
    printf("2) По длине строки\n");
    printf("3) По количеству гласных букв в слове\n");
    
    scanf("%d", &f);
    switch (f)
    {
    case 1:
        func = compare_letters;
        break;
    case 2:
        func = compare_lenght;
        break;
    case 3:
        func = compare_vowels;
        break;
    default:
        printf("Ошибка: Некорректный ввод");
        break;
    }

    qsort(strings, n, sizeof(char*), func);
    printf("Отсортированный список строк:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
