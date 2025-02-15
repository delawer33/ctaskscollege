#include <stdio.h>
#include <string.h>


enum Condition {Sunny, Cloudy, Rainy};

struct Weather {
    float temperature;
    float humidity;
    enum Condition condition;
};

int main() {
    struct Weather weather;
	char conditionStr[10];

	scanf("%f %f %s", &weather.temperature, &weather.humidity, &conditionStr);
	
	if (strcmp(conditionStr, "Sunny") == 0) {
		weather.condition = Sunny;
	} else if (strcmp(conditionStr, "Cloudy") == 0) {
		weather.condition = Cloudy;
	} else if (strcmp(conditionStr, "Rainy") == 0) {
		weather.condition = Rainy;
	}

	printf("Temperature: %.2f deg\n", weather.temperature);
    printf("Humidity: %.2f%%\n", weather.humidity);

	if (weather.condition == Sunny) {
		printf("Condition: Sunny\n");
	} else if (weather.condition == Cloudy) {
		printf("Condition: Cloudy\n");
	} else if (weather.condition == Rainy) {
		printf("Condition: Rainy\n");
	}

}