#include <stdio.h>

typedef struct{
    int jam;
    int menit;
} Waktu;

int compInfo (Waktu t1, Waktu t2){
    //konversi kedua waktu menjadi menit
    int cmenitt1 = (t1.jam * 60) + t1.menit;
    int cmenitt2;
    //jika t2 lebih kecil daripada t1, maka itu merupakan hari selanjutnya
    if (t2.jam < t1.jam){
        cmenitt2 = ((t2.jam + 24) * 60) + t2.menit;
    } 
    else{ //kalau t2 masih sama dengan t1, harinya tidak diubah dan selisih waktunya pada hari itu    
        cmenitt2 = (t2.jam * 60) + t2.menit;
    }

    //menghitung selisih
    return (cmenitt2 - cmenitt1);
}

int main(){
    Waktu t1, t2;

    //scan input
    scanf("%d %d", &t1.jam, &t1.menit);
    scanf("%d %d", &t2.jam, &t2.menit);

    //print hasil
    printf("%d", compInfo(t1, t2));
}