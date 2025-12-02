#include<stdio.h>
#include<string.h>

void zhengshu(char*, char*);
void xiaoshu(char*, char*);
void fenshu(char*, char*);
void baifenshu(char*, char*);

int main() {

	int n;
	char str[30] = "";
	char outstr[30] = "";
	
	scanf("%s", str);

	zhengshu(str, outstr);
	xiaoshu(str, outstr);
	fenshu(str, outstr);
	baifenshu(str, outstr);

	printf("%s", outstr);

	scanf("%d",&n);
	return 0;
}

void zhengshu(char* str, char* outstr) {

	if ((!strchr(str, '.')) && (!strchr(str, '%')) && (!strchr(str, '/'))) {

		int cnt1 = 0;
		int cnt2 = 0;


		while (str[cnt1] != '\0') {
			cnt1++;
		} 
		cnt1--;

		int cnt3 = 0;

		int is0 = 1;

		while (str[cnt3] != '\0') {

			if (str[cnt3++] != '0') {

				is0 = 0;
				break;
			}
		}

		if (is0 == 0) {

			while (str[cnt1] == '0') cnt1--;

			for (cnt1; cnt1 >= 0; cnt1--) {

				outstr[cnt2] = str[cnt1];

				cnt2++;

			}

			outstr[cnt2] = '\0';

		}
		else strcpy(outstr, "0");
	}
}

void xiaoshu(char* str, char* outstr) {

	if (strchr(str, '.') != NULL) {
		
		char str1[30] = "";
		char str2[30] = "";
		char outstr1[30] = "";
		char outstr2[30] = "";
		
		char cnt1 = 0;
		char cnt2 = 0;
		char cnt = 0;
		
		while (str[cnt1] != '.') {
			
			str1[cnt1] = str[cnt1];
	        cnt1++;
		}
		zhengshu(str1, outstr1);
	
		cnt1++;
		int cnt3 = cnt1;
		
		int is0 = 1;
		
		
		while (str[cnt3] != '\0') {
			
			if (str[cnt3++] != '0') {

				is0 = 0;
				break;
			}
		}

		if (is0 == 0) {

			while (str[cnt1] == '0') cnt1++;

			while (str[cnt1] != '\0') {
				
				str2[cnt2] = str[cnt1];
                 cnt1++;cnt2++;

			}
			zhengshu(str2, outstr2);
		}
		else strcpy(outstr2, "0");
				
		strcat(outstr1, ".");
		strcat(outstr1, outstr2);
	    
		while (outstr1[cnt] != '\0') {
			
			outstr[cnt] = outstr1[cnt];
		    cnt++;
		}
		outstr[cnt] = '\0';	
	}
}

void fenshu(char* str, char* outstr) {

	if (strchr(str, '/') != NULL) {

		char str1[30] = "";
		char str2[30] = "";
		char outstr1[30] = "";
		char outstr2[30] = "";

		char cnt1 = 0;
		char cnt2 = 0;
		char cnt = 0;

		while (str[cnt1] != '/') {
			
			str1[cnt1] = str[cnt1];
		    cnt1++;
		
		}    
		zhengshu(str1, outstr1);

		cnt1++;

		while (str[cnt1] != '\0') {
			
			str2[cnt2] = str[cnt1];
            cnt1++;cnt2++;
		}
		
		zhengshu(str2, outstr2);

		strcat(outstr1, "/");
		strcat(outstr1, outstr2);

		while (outstr1[cnt] != '\0') {
			
			outstr[cnt] = outstr1[cnt];
            cnt++;
		}
		outstr[cnt] = '\0';

	}

}

void baifenshu(char* str, char* outstr) {

	if (strchr(str, '%') != NULL) {

		char str1[30] = "";
		char outstr1[30] = "";

		char cnt1 = 0;
		char cnt = 0;

		while (str[cnt1] != '%') {
			
			str1[cnt1] = str[cnt1];
	        cnt1++;
		}   		
		zhengshu(str1, outstr1);
	
		strcat(outstr1, "%");
	
		while (outstr1[cnt] != '\0') {
			
			outstr[cnt] = outstr1[cnt];
            cnt++;		
		}
		outstr[cnt] = '\0';
	}

}