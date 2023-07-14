#include <stdio.h>

int main()
{
    int n, a, ab1 = 0, ab0 = 0;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &a);

        switch(a)
        {
        case 1:
            ab1++;
            break;

        case 0:
            ab0++;
            break;
        }
    }

    printf("%d %d", ab1, ab0);
}