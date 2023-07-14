#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, p, i;
    int st, nd;
    deque<int> mipy;
    deque<int> temp;

    cin >> t;

    while (t != 0){
        
        cin >> n;

        while (n != 0){
            cin >> p;
            mipy.push_back(p);
            n--;
        }

        temp = mipy;

        i = 1;
        int odd;
        while (1){
            odd = i%2;

            if(odd == 1){
                int j;
                int size = temp.size();
                for(j = 1; j < size; j++){
                    if(temp[j] != temp.front()){
                        temp.erase(temp.begin()+j);
                        temp.pop_front();
                        break;
                    }
                }

                if(j == size){
                    st = size;
                    break;
                }
                else if(temp.empty()){
                    st = 0;
                    break;
                }
            }
            else if(odd == 0){
                int j;
                int size = temp.size();
                for(j = size-2; j > -1; j--){
                    if(temp[j] != temp.back()){
                        temp.erase(temp.end()-(size - 1 - j));
                        temp.pop_back();
                        break;
                    }
                }

                if(j == -1){
                    st = size;
                    break;
                }
                else if(temp.empty()){
                    st = 0;
                    break;
                }
            }

            i++;
        }

        i = 1;

        while (1){
            odd = i%2;

            if(odd == 0){
                int j;
                int size = mipy.size();
                for(j = 1; j < size; j++){
                    if(mipy[j] != mipy.front()){
                        mipy.erase(mipy.begin()+j);
                        mipy.pop_front();
                        break;
                    }
                }

                if(j == size){
                    nd = size;
                    break;
                }
                else if(mipy.empty()){
                    nd = 0;
                    break;
                }
            }
            else if(odd == 1){
                int j;
                int size = mipy.size();
                for(j = size-2; j > -1; j--){
                    if(mipy[j] != mipy.back()){
                        mipy.erase(mipy.end()-(size - 1 - j));
                        mipy.pop_back();
                        break;
                    }
                }

                if(j == -1){
                    nd = size;
                    break;
                }
                else if(temp.empty()){
                    nd = 0;
                    break;
                }
            }

            i++;
        }

        if(st < nd){
            printf("%d\n", st);
        }
        else{
            printf("%d\n", nd);
        }
        

        
        mipy.clear();
        temp.clear();
        t--;
    }    
}