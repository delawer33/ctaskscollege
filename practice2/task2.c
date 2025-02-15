#include <stdio.h>


struct Item {
	char name[50];
	int amount;
	float price;
};


void main() {
	int n;
	scanf("%d", &n);

	struct Item items[n];

	for (int i = 0; i < n; i++) {
		scanf("%s %d %f", &items[i].name, &items[i].amount, &items[i].price);
	}

	printf("\nItems: \n\n");
	for (int i = 0; i < n; i++) {
		printf("Name: %s\n", items[i].name);
		printf("Amount: %d\n", items[i].amount);
		printf("Price: %.2f\n\n", items[i].price);
	}
}
