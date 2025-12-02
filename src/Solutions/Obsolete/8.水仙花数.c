
/*
#include<stdio.h>

	int main() {

		int a = 0;
		int t = 1;
		int i = 0;
		int j = 0;
		int k = 0;
		int res = 0;
		int t2 = 0;
		int middle = 1;
		int b = 0;
		int c = 0;

		printf("你想知道几位数的水仙花数？");
		scanf_s("%d", &a);

		b = a;
		c = a;
		
		while (a > 1) {

			a--;
			t *= 10;
		}
		t2 = t;

		for (i = t2; i < t2 * 10; i++) {

			j = i;
			k = i;

			while (t > 0) {

				k = (j / t) % 10;
				middle = 1;
				b = c;

				while (b > 0) {

					middle *= k;
					b--;
			
				}

				res += middle;

				t /= 10;

			}

			t = t2;

			if (res == i) {

				printf("%d ", res);
		
			}
			res = 0;
		}

}
*/