#include <stdio.h>
#include <string.h>


int main() {
    char signal[256];
    char result[256];
    char trash_symbols[] = "#*"; //по условию задачи вроде # и *
    printf("Введите зашифрованное сообщение: ");
    fgets(signal, 256, stdin);

    size_t start = strspn(signal, trash_symbols);
    size_t end = strcspn(signal + start, trash_symbols);
    
    strncpy(result, signal + start, end);

    printf("%s", result);
    return 1;
}
