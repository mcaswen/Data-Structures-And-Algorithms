#include<stdio.h>
/*
int main() {

	int a, b, i;
	int cnt = 0;
	int res = 0;
	int div = 2;
	int True = 0;
	printf("请输入您要计算的区间：（格式：a b）");
	scanf_s("%d %d", &a, &b);
	i = a;
	if (i == 1) i = 2;
	
	while (i <= b) {
		True = 0;
		while (div < i-1) {
			
			if (i % div == 0) {

				True = 1;
				break;
			}
			div++;
		}

		if (True == 0) {
			cnt++;
			res += i;
			//printf("%d", i);
		
		}
		i++;
		div = 2;
	}		
	
	printf("区间内有%d个素数，它们的和为%d\n", cnt, res);
	
	return 0;
}
*/