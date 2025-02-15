#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void task1() {
	int weight;
	printf("Enter weight: ");
	scanf("%d", &weight);
	if (weight < 60 || weight > 90) {
		printf("You can't qualify.");
	} else {
		printf("You can qualify.");
	}
}


void task2() {
	int distance;
	printf("Enter distance to the nearest station (in km): ");
	scanf("%d", &distance);
	if (distance > 500) {
		printf("The moon rover can't reach the station");
	} else {
		printf("The moon rover can reach the station");
	}
}

void task3() {
	char detail;
	printf("Enter the detail marking: ");
	scanf("%c", &detail);
	if (detail < 'A' || detail > 'Z') {
		printf("Marking is invalid");
	} else {
		printf("Marking is valid");
	}
}


void task4() {
	int date;
	printf("Enter mission start date: ");
	scanf("%d", &date);

	time_t t = time(NULL);
	struct tm *now = localtime(&t);

	int cur_date = (now->tm_year + 1900) * 10000 + now->tm_mon * 100 + now->tm_mday * 10;
	
	if (cur_date < date) {
		printf("Mission date is in future");
	} else if (cur_date > date) {
		printf("Mission date is in past");
	} else {
		printf("Misson starts today");
	}
}


void task5() {
	double actual;
	double estimated;
	printf("Enter estimated speed: ");
	scanf("%lf", &estimated);
	printf("Enter actual speed: ");
	scanf("%lf", &actual);

	double diff = fabs(estimated - actual);
	
	if (diff > 0.1) {
		printf("Orbit is unstable. Actual and estimated speeds differ by %lf\n m/s", diff);
	} else {
		printf("Orbit is stable");
	}
}


void task6() {
	int amount;
	printf("Enter amount of astronauts: ");
	scanf("%d", &amount);

	if (amount <= 1) {
		printf("Too few people to form group");
		return;
	}

	int m2, all = 0;

	for (int m4 = 0; m4 <= amount / 4; m4++) {
		for (int m3 = 0; m3 <= amount - 4 * m4; m3++){
			m2 = amount - m4 * 4 - m3 * 3;
			if (m2 >= 0 && m2 % 2 == 0) {
				all += 1;
				m2 = m2 / 2;
				printf("Variant %d: %d four-man modules, %d three-man modules and %d two-man modules\n", all, m4, m3, m2);
			}
		}
	}
	printf("Total: %d modules", all);
}


void task7() {
	float x;
	printf("Enter signal frequency (HHz): ");
	scanf("%f", &x);
	
	if (x < 3.5 && x > 2.5) {
		printf("Connection is stable");
	} else {
		printf("Connection is unstable");
	}
}


void task8() {
	int n;
	printf("Enter cargo weight (kg): ");
	scanf("%d", &n);
	
	if (n == 0) {
		printf("Cargo can't be 0 kg");
		return;
	}

	if (n % 4 != 0) {
		printf("Impossible to distribute cargo evenly");
	} else {
		printf("Cargo can be distributed in four parts of %d kg", n / 4);
	}
}


void task9() {
	double t;
	printf("Enter time in seconds: ");
	scanf("%lf", &t);
	
	printf("%d minute %.1f seconds", (int)(t / 60), t - 60 * (int)(t / 60));
}


void task10() {
	int t;
	printf("Enter temperature: ");
	scanf("%d", &t);
	if (t <= 120 && t >= -150) {
		printf("Temperature is acceptable");
	} else {
		printf("Temperature is not acceptable");
	}
}


void task11() {
	float oxygen;
	printf("Enter oxygen level (\%): ");
	scanf("%f", &oxygen);
	if (oxygen < 15) {
		printf("Oxygen level is low! Turn on the emergency system!");
	} else {
		printf("Oxygen level is normal");
	}
}


void task12() {
	int angle;
	printf("Enter angle: ");
	scanf("%d", &angle);
	if (angle <= 180 && angle >= -180) {
		printf("Angle is normal");
	} else {
		printf("The angle is out of the acceptable range");
	}
}


void task13() {
	int n;
	printf("Enter number of astronauts: ");
	scanf("%d", &n);
	if (n % 2 == 0) {
		printf("Astronauts can be delivered without a remainder");
	} else {
		printf("Astronauts can't be delivered without a remainder");
	}
}


void task14() {
	int weight;
	printf("Enter your weight (kg): ");
	scanf("%d", &weight);
	float weightOnMoon = weight / 6;
	printf("Your weight on moon: %.2f kg", weightOnMoon);
}


void task15() {
	float data, speed;
	printf("Enter amount of data (MB): ");
	scanf("%f", &data);
	printf("Enter transmission spped (Kb/s): ");
	scanf("%f", &speed);
	data = data * 8000;
	int time_min = data / speed;
	float time_sec = data - speed * (int)(data / speed);
	printf("It will take %d minutes and %.2f seconds to transfer data", time_min, time_sec);
}


void main() {
	// task1();
	// task2();
	// task3();
	// task4();
	// task5();
	task6();
	// task7();
	// task8();
	// task9();
	// task10();
	// task11();
	// task12();
	// task13();
	// task14();
	// task15();
}

