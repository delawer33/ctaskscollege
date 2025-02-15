#include <stdio.h>


union Grade {
	int i;
	char c;
};

void main() {
	int n;
	scanf("%d\n", &n);

	union Grade grades[n];
	
	int gradeTypes[n];
	
	for (int i = 0; i < n; i++) {
		char grade[4];
        scanf("%s", &grade);

        if (sscanf(grade, "%d", &grades[i].i) > 0) {
            gradeTypes[i] = 0;
        } else {
            grades[i].c = grade[0];
			gradeTypes[i] = 1;
        }
    }

	printf("\n");

	for (int i = 0; i < n; i++) {
		if (gradeTypes[i] == 0) {
			printf("Grade: %d\n", grades[i].i);
		} else {
			printf("Grade: %c\n", grades[i].c);
		}
	}
}
