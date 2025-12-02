#include <stdio.h>
#include <string.h>

int main(){

    char str[10000] = "";
    char strjieguo[10000][100] = {""};
    int cnt = 0;
    int cnta = 0;
    int cntb = 0;
    int wina = 0;
    int winb = 0;
    int sum = 0;

    
    while (1)
    {
        scanf("%c", &str[cnt]);

        if (str[cnt] == 'E')
            break;
        if (str[cnt] == 'W')
            cnta++;
        if (str[cnt] == 'L')
            cntb++;

        if (cnta >= 11 && cnta - cntb >= 2)
        {
            sprintf(strjieguo[sum], "%d:%d", cnta, cntb);
            cnta = 0;
            cntb = 0;
            wina++;
            sum++;
        }


        if (cntb >= 11 && cntb - cnta >= 2)
        {
            sprintf(strjieguo[sum], "%d:%d", cnta, cntb);
            cnta = 0;
            cntb = 0;
            winb++;
            sum++;
        }
        cnt++;
    }

    sprintf(strjieguo[sum], "%d:%d", cnta, cntb);
    
    for(int i = 0;i <= sum; i++) {
        printf("%s\n",strjieguo[i]);
    }
     
    printf("\n");

    char str2[100000] = "";
    char strjieguo2[100000][100] = {""};
    strcpy(str2, str);
    cnt = 0;
    cnta = 0;
    cntb = 0;
    wina = 0;
    winb = 0;
    sum = 0;

    while (1)
    {

        if (str2[cnt] == 'E')
            break;

        if (str2[cnt] == 'W')
            cnta++;
        if (str2[cnt] == 'L')
            cntb++;

        if (cnta >= 21 && cnta - cntb >= 2)
        {
            
            sprintf(strjieguo2[sum], "%d:%d", cnta, cntb);
            cnta = 0;
            cntb = 0;
            wina++;
            sum++;
        }

        if (cntb >= 21 && cntb - cnta >= 2)
        {
            
            sprintf(strjieguo2[sum], "%d:%d", cnta, cntb);
            cnta = 0;
            cntb = 0;
            winb++;
            sum++;
        }
        cnt++;
    }

     sprintf(strjieguo2[sum], "%d:%d", cnta, cntb);
     
     for(int i = 0;i <= sum; i++) {
        printf("%s\n",strjieguo2[i]);
    }

    return 0;
}