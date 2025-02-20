#include "ship.h"

void check_fuel(int fuel) {
    if (fuel < 10) {
        printf("ВНИМАНИЕ: Уровень топлива ниже 10%%\n");
    }
}
