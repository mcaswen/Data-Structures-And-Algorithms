/*
#include<stdio.h>

int main() {

	int a = 0;
	int bot = 1;
	int top = 2;
	double res = 0;
	int j;
	
	printf("正在计算数列求和，请输入您想计算的项数：");
	scanf_s("%d", &a);

	while (a > 0) {

		res += top * 1.0 / bot;
		j = bot;
		bot = top;
		top += j;
		
		a--;
	}

	printf("计算结果为：%.2f", res);
	
	return 0;
}
*/