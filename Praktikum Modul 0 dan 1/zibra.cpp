#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int main()
{
	int t;
    long long n;
	deque<int> dq;
	queue<long long> save; //pake queue buat save hasil
	
	scanf("%d", &t);
	
	for(int j = 0; j < t; j++)
	{
		scanf("%lld", &n);
		dq.clear();
		
		//algoritma mengubah angka ke binary
		while(n > 0){
			int sisa = n % 2;
			n /= 2;
			
			if(dq.empty() || dq.front() != sisa){
				dq.push_front(sisa);
			} else {
				dq.pop_front();
			}
		}
	
		//algoritma mengubah kembali binary ke angka
		long long decimal = 0;
	    long long base = 1;
	    while (!dq.empty()) { 
	        decimal += dq.back() * base;
	        base *= 2;
	        dq.pop_back();
	    }
	    save.push(decimal);
	}
	
	while(!save.empty())
	{
    	printf("%lld\n", save.front());
		save.pop();
	}		
}
