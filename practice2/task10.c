#include <stdio.h>


struct Course {
	char name[50];
	int credits;
	char professor[50];
};


void main() {
	int n;
	scanf("%d", &n);

	struct Course course[n];

	for (int i = 0; i < n; i++) {
		scanf("%s %d ", &course[i].name, &course[i].credits);
		fgets(course[i].professor, 100, stdin);
	}

	printf("\nStudents: \n\n");
	for (int i = 0; i < n; i++) {
		printf("Course: %s\n", course[i].name);
		printf("Credits: %d\n", course[i].credits);
		printf("Professor: %s\n\n", course[i].professor);
	}
}
