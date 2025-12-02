#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{

    char str[10000] = "";
    int cnt = 0;
    int number = 0;
    while (1)
    {
        scanf("%c", &str[cnt]);

        if (str[cnt] == '\n')
            break;
        cnt++;
    }


    int cnt2;
    int k = 0;
    int t = 0;
    scanf("%d", &k);


    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < cnt; i++)
        {

            if (str[i] >= str[i+1])
            {
                str[i+1] = '!';
                k--;
            
            }
            if (str[i] == '!') i++;
            
            
            if (k <= 0)
                break;
        }
        if (k <= 0)
            break;
    }

    while (str[t] == '0' || str[t] == '!') t++;

    if (t >= cnt) printf("0");
    
    
    for (;t < cnt; t++) {
    
        if (isdigit(str[t]))
            printf("%c",str[t]);
    
    }
    
    
    return 0;
}