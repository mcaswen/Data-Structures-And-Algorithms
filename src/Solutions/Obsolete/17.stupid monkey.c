#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char str[200] = "";

    scanf("%s", str);

    char strcun[200] = "";

    int cnt = 1;
    int chongfu = 0;
    int cntcun = 1;

    strcun[0] = str[0];

    while (str[cnt] != '\0')
    {

        chongfu = 0;
        for (int i = 0; i < cnt; i++)
        {

            if (str[cnt] == str[i])
                chongfu = 1;
        }

        if (chongfu == 0)
        {

            strcun[cntcun] = str[cnt];
            cntcun++;
        }

        cnt++;
    }

    int number = cntcun + 1;

    int num[number];

    for (int cntnum = 0; cntnum < number; cntnum++)
    {

        num[cntnum] = 0;
    }

    cnt = 0;

    while (strcun[cnt] != '\0')
    {

        while (strchr(str, strcun[cnt]) != NULL)
        {

            *(strchr(str, strcun[cnt])) = '0';
            num[cnt]++;
        }

        cnt++;
    }

    int min = 10000;
    int max = 0;
    int cntnew = 0;

    while (num[cntnew] != 0)
    {

        if (num[cntnew] < min)
            min = num[cntnew];
        if (num[cntnew] > max)
            max = num[cntnew];
        cntnew++;
    }

    int x = max - min;
    int isPrime = 1;

    if (x == 0 || x == 1)
        isPrime = 0;

    for (int j = 2; j < x; j++)
    {

        if (x % j == 0)
        {

            isPrime = 0;
            break;
        }
    }

    if (isPrime == 1)
    {

        printf("Lucky Word\n");
        printf("%d", x);
    }
    else
    {

        printf("No Answer\n");
        printf("0");
    }

    return 0;
}