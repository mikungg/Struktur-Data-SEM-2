#include <iostream>
#include <stack>
using namespace std;

int pwr(int t, int p)
{
    int total = t;

    if(p == 0){
        return 1;
    }
    else{
        while(p != 1)
        {
            total *= t;
            p--;
        }

        return total;
    }
}

int intConverter(stack<int> stack){
    int temp = 0, eks = 0;

    while (!stack.empty())
    {
        temp += stack.top() * pwr(10, eks);
        stack.pop();
        eks++;
    }

    return temp;
}

int main()
{
    int m, n, a, b, tot;
    stack<int> stack1;
    stack<int> stack2;

    scanf("%d %d", &m, &n);

    while (m != 0){
        scanf("%d", &a);
        stack1.push(a);
        m--;
    }
     while (n != 0){
        scanf("%d", &b);
        stack2.push(b);
        n--;
    }

    a = intConverter(stack1);
    b = intConverter(stack2);

    tot = a + b;

    printf("%d", tot);

}

