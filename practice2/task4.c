#include <stdio.h>


struct Employee {
	char name[50];
	char position[50];
	float salary;
};


void main() {
	int n;
	scanf("%d", &n);

	struct Employee employees[n];

	for (int i = 0; i < n; i++) {
		scanf("%s %s %f", &employees[i].name, &employees[i].position, &employees[i].salary);
	}

	printf("\nEmployees: \n\n");
	for (int i = 0; i < n; i++) {
		printf("Name: %s\n", employees[i].name);
		printf("Position: %s\n", employees[i].position);
		printf("Salary: %.2f\n\n", employees[i].salary);
	}
}
