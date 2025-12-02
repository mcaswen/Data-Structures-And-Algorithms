/*
#include<stdio.h>

int main() {

	int x;
	int sum = 0;
	int div = 1;

	scanf("%d", &x);
	int y = x;

	if (x > 0) {
		while (x / 10 > 0) {
			x /= 10;
			div *= 10;
		}

		while (y / 10 > 0) {

			sum += (y % 10) * div;
			div /= 10;
			y /= 10;

		}
		sum += (y % 10) * div;

		printf("%d", sum);
	}
	else {
		x = -x; y = -y;
		while (x / 10 > 0) {
			x /= 10;
			div *= 10;
		}

		while (y / 10 > 0) {

			sum += (y % 10) * div;
			div /= 10;
			y /= 10;
		}
		sum += (y % 10) * div;

		printf("%d", -sum);
	}
	
	return 0;
}
*/