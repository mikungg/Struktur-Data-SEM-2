#include<iostream>
#include<string.h>
#include<deque>
using namespace std;

int main(){
    int n = 0;
    deque<char> parant;
    char str[1000000]; 
    
    scanf("%s", str);

    while(n < strlen(str))
    {
        parant.push_back(str[n]);
        n++;
    }

    if(strlen(str) % 2 == 1)
    {
        printf("unvaldi");
    }
    else
    {
        while(!parant.empty())
        {
            char temp = parant.front();
            parant.pop_front();
            
            if(temp == '{' && parant.front() == '}')
            {
                parant.pop_front();
            }
            else if(temp == '[' && parant.front() == ']')
            {
                parant.pop_front();
            }
            else if(temp == '(' && parant.front() == ')')
            {
                parant.pop_front();
            }
            else
            {
                if(temp == '{' && parant.back() == '}')
                {
                    parant.pop_back();
                }
                else if(temp == '[' && parant.back() == ']')
                {
                    parant.pop_back();
                }
                else if(temp == '(' && parant.back() == ')')
                {
                    parant.pop_back();
                }
                else
                {
                    printf("unvaldi");
                }
            }
        }

        if(parant.empty())
        {
            printf("valdi");
        }
    }

}
