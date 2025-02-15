#include <stdio.h>
#include <string.h> 


union Data {
	int i;
	char s[100];
	float f;
};

void main() {
	int type;
	scanf("%d\n", &type);

	union Data data;

	if (type == 1) {
		scanf("%d", &data.i);
		printf("Integer: %d", data.i);
	} if (type == 2) {
		scanf("%f", &data.f);
		printf("Float: %f", data.f);
	} if (type == 3) {
		fgets(data.s, 100, stdin);
		data.s[strlen(data.s)] = '\0';
		printf("String: %s", data.s);
	}
}
