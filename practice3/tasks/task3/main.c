#include "ship.h"


int main() {
    float speed, time;
    int fuel;

    printf("Введите скорость (км/ч): ");
    scanf("%f", &speed);

    printf("Введите время (часы): ");
    scanf("%f", &time);

    printf("Введите уровень топлива (%%): ");
    scanf("%d", &fuel);

    check_fuel(fuel);

    float dist = calculate_distance(speed, time);
    printf("Дистанция: %f км\n", dist);

    return 0;
    
}
