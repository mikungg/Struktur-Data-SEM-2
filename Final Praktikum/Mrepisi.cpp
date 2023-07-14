#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<char> parant;
    string str;

    cin >> str;

    for(long int i=0; i < str.size(); i++)
    {
        if(!parant.empty() && parant.top() == '{' && str[i] == '}' ||!parant.empty() && parant.top() == '[' && str[i] == ']' ||!parant.empty() && parant.top() == '(' && str[i] == ')')
        {
            parant.pop();
        }
        else
        {
            parant.push(str[i]);
        }
    }

    if(!parant.empty()){
        cout << "unvaldi";
    }
    else{
        cout << "valdi";
    }

}