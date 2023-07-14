#include <iostream>
#include <unordered_map>
using namespace std;

void calc(int maxC, int totalC) {
    if (maxC <= totalC / 2) {
        cout << totalC % 2 << endl;
    } else {
        int rest = 2 * maxC - totalC;
        cout << rest << endl;
    }
}

int main(){

    int x, n, num;

    scanf("%d", &x);

    while(x != 0)
    {
        scanf("%d", &n);

        unordered_map<int, int> counts;

        while(n != 0){
            scanf("%d", &num);
            counts[num]++;
            n--;
        }

        int tot = 0;
        int max = 0;

        for(auto& entry : counts){

            tot += entry.second;

            if (entry.second > max){

                max = entry.second;
            }
        }
        calc(max, tot);

        x--;
    }
}