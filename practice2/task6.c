#include <stdio.h>
#include <string.h>


enum EngineType {
    Gasoline,
    Diesel,
    Electric
};


struct Vehicle {
    char mark[50];
    char model[50];
    int year;
    enum EngineType engineType;
};


void main() {
    int n;
    scanf("%d", &n);
	struct Vehicle vehicles[n];
	
    for (int i = 0; i < n; i++) {
		char engineTypeStr[30];
        scanf("%s %s %d %s", 
			&vehicles[i].mark, 
			&vehicles[i].model, 
			&vehicles[i].year, 
			&engineTypeStr);
		if (strcmp(engineTypeStr, "Gasoline") == 0) {
			vehicles[i].engineType = Gasoline;
		} else if (strcmp(engineTypeStr, "Diesel") == 0) {
			vehicles[i].engineType = Diesel;
		} else if (strcmp(engineTypeStr, "Electric") == 0) {
			vehicles[i].engineType = Electric;
		}
    }

	printf("\nVehicles: \n\n");

    for (int i = 0; i < n; i++) {
        printf("Vehicle: %s %s\n", vehicles[i].mark, vehicles[i].model);
		printf("Year: %d\n", vehicles[i].year);
		if (vehicles[i].engineType == 0) {
			printf("Engine type: Gasoline\n\n");
		} else if (vehicles[i].engineType == 1) {
			printf("Engine type: Diesel\n\n");
		} else if (vehicles[i].engineType == 2) {
			printf("Engine type: Electric\n\n");
		}
    }
}
