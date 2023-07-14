#include <stdio.h>

int main()
{
    int n;
    int i = 0;
    int sum1 = 0;
    int sum0 = 0;

    scanf("%d", &n);
    int abs[n];

    while (1)
    {
        scanf("%d", &abs[i]);
        n--;
        
        if (abs[i] == 1)
        {
            sum1 = sum1 + 1;
        }
        else if (abs[i] == 0)
        {
            sum0 = sum0 + 1;
        }

        ++i;

        if (n == 0)
        {
            break;
        }
    }

    printf("%d %d", sum1, sum0);
}
