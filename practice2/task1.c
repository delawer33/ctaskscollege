#include <stdio.h>


struct Student {
	char name[50];
	int age;
	float gpa;
};


void main() {
	int n;
	scanf("%d", &n);

	struct Student students[n];

	for (int i = 0; i < n; i++) {
		scanf("%s %d %f", &students[i].name, &students[i].age, &students[i].gpa);
	}

	printf("\nStudents: \n\n");
	for (int i = 0; i < n; i++) {
		printf("Name: %s\n", students[i].name);
		printf("Age: %d\n", students[i].age);
		printf("GPA: %.2f\n\n", students[i].gpa);
	}
}
