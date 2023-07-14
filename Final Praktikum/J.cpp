#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1000000009;

long long modex(long long base, long long exponent) {
    long long result = 1;
    base %= MOD;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }

    return result;
}

int main()
{
    int m;
    long long pattern, n;
    vector<long long> hasil;

    scanf("%d", &m);

    while(m != 0){
        scanf("%lld", &n);

        pattern = modex(2, n * (n-1)/2);
        hasil.push_back(pattern);

        m--;
    }

    int i = 0;

    while(i < hasil.size()){
        cout << "Zodiak found: " << hasil[i] << " signs" << endl;

        i++;
    }
}
