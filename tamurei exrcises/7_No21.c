#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int random(int m, int n) {
    int offset = rand() / (RAND_MAX + 1.0) * (n - m + 1);

    return m + offset;
}

int main()
{
    int m = 1;
    int n = 40;
    int num;
    int array[41] = {0};

    srand(time(NULL));

    for (int i = 0; i < 5; i++){

        for (int j = 0; j < 7; j++){
            num = random(m, n);

            while(array[num] != 0)
            {
                if(num == 40)
                {
                    num = 1;
                }
                else
                {
                    num++;
                }
            }

            array[num] = 1;

            printf("%d ", num);
        }

        printf("\n");
    }

}
