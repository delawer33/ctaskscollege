#include "ship.h"

float calculate_distance(float speed, float time) {
    if (speed < 0 || time < 0) {    
        printf("ОШИБКА: Некорректный ввод\n");
        exit(1);
    }
    return speed * time;
}
