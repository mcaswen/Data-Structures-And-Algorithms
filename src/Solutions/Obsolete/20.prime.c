#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int);

int main()
{

    int n;
    scanf("%d", &n);

    int *num = (int *)malloc(n * sizeof(int));

    int cnt = 0;
    while (cnt < n)
    {

        scanf("%d", &num[cnt]);
        cnt++;
    }
    
    int cnt1 = 0;
  
  
  while (cnt1 < cnt) {
    if ((isPrime(num[cnt1]) == 0) || num[cnt1] == 1)
    {
       
        num[cnt1] = 0;
        }
        cnt1++;   
    }

    int cnt2 = 0;

    while (cnt2 < cnt)
    {

        if (num[cnt2] != 0)
            printf("%d ", num[cnt2]);

        cnt2++;
    }

    free(num);
    return 0;
}

int isPrime(int x)
{

    int isprime = 1;
    int cntprime = 0;
    int s = sqrt(x);
    
    for (int i = 2; i <= s; i++)
    {

        if (x % i == 0)
        {
            isprime = 0;
            break;
        }

    }
    return isprime;

}
