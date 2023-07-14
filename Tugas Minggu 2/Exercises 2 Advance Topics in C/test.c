#include <stdio.h>
 
 struct tgl{
    int d;
    int m;
    int y;   
 };

 int cmp(int , int);
 int cmpm(int, int, int);

 int main(){
    struct tgl st;
    struct tgl nd;

    scanf("%d %d %d", &.tgl, &m.tgl,);
    printf("%d", cmpm(cmp(st.y, nd.y), cmp(st.m, nd.m), cmp(st.d, nd.d)));

 }

int cmp(int a, int b){
    if( b > a){
        return -1;
    }
    else if(b < a){
        return 1;
    }
    else{
        return 0;
    }

}

int cmpm(int y, int m, int d){
    if(y != 0){
        return y;
    }
    else{
        if(m != 0){
            return m;
        }
        else{
            if(d != 0){
                return d;
            }
            else{
                return 0;
            }
        }
    }
}