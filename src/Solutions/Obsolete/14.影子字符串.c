/*
#include<stdio.h>
#include<string.h>

int main() {

	char str[50000] = "";
	char instr[50000] = "";

	while (1) {
		
		scanf("%s", instr);
		
		if (strcmp(instr, "0") == 0) break;
		
		if (!strstr(str, instr)) strcat(str, instr);

	}
	
	printf("%s", str);
	
	return 0;
}
*/