#include <stdio.h>
#include <string.h> 


struct Date {
	int day;
	int month;
	int year;
};


struct Event {
	char name[50];
	struct Date date;
	char description[100];
};


void main() {
	int n, day, month, year;
	scanf("%d", &n);

	struct Event events[n];

	for (int i = 0; i < n; i++) {
		scanf("%s %d %d %d ", 
			&events[i].name, 
			&events[i].date.day, 
			&events[i].date.month, 
			&events[i].date.year
			);
		fgets(events[i].description, 100, stdin); 
	}

	printf("\nEvents: \n\n");
	for (int i = 0; i < n; i++) {
		printf("Name: %s\n", events[i].name);
		printf("Date: %d/%d/%d\n", events[i].date.day, events[i].date.month, events[i].date.year);
		printf("Description: %s\n", events[i].description);
	}
}
