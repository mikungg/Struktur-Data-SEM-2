#include <stdio.h>

typedef struct{
    int jam;
    int menit;
} waktu;

int compareTime(waktu t1, waktu t2){
    //konversi waktu menjadi menit
    int totmenitt1 = (t1.jam * 60) + t1.menit;
    int totmenitt2 = (t2.jam * 60) + t2.menit;

    //menghitung selisih waktu
    return (totmenitt2 - totmenitt1);  
}

int main(){
    //input
    waktu t1 = {16, 45};
    waktu t2 = {23, 25};

    //menunjukkan hasil
    printf("%d", compareTime(t1, t2));
}