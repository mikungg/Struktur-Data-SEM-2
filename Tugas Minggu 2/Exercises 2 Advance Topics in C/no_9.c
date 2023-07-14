#include <stdio.h>

// deklarasi struct Panjang
typedef struct{
    int meter;
    int sentimeter;
} Panjang;

// fungsi perbandingan Panjang
int comparePanjang(Panjang l1, Panjang l2){
    // konversi panjang ke sentimeter
    int centil1 = (l1.meter * 100) + l1.sentimeter;
    int centil2 = (l2.meter * 100) + l2.sentimeter;
    
    // jika panjang pertama lebih dari kedua
    if(centil1 > centil2){
        return 1;
    }
    // jika panjang pertama lebih dari kedua
    else if(centil1 < centil2){
        return -1;
    }
    // jika panjang sama
    else{
        return 0;
    }
}

// fungsi menambah panjang
int addPanjang(Panjang l1, Panjang l2){
    return((l1.meter * 100) + l1.sentimeter) + ((l2.meter * 100) + l2.sentimeter);
}

// fungsi mengurangi panjang
int subPanjang(Panjang l1, Panjang l2){
    return((l1.meter * 100) + l1.sentimeter) - ((l2.meter * 100) + l2.sentimeter);
}

int main(){
    Panjang l1, l2;

    // input
    scanf("%d %d", &l1.meter, &l1.sentimeter);
    scanf("%d %d", &l2.meter, &l2.sentimeter);

    // output
    printf("Compare lengths : %d\n", comparePanjang(l1, l2));
    printf("Addition of the lengths are : %dcm\n", addPanjang(l1, l2));
    printf("Substraction of the lengths are : %dcm", subPanjang(l1, l2));
}
