#include <stdio.h>

typedef struct{
    int year;
    int month;
    int day;
} Date;

int daysAhead(Date d2, Date d1){
    // ngecek tanggal ke 2 jika lebih besar dari tanggal pertama
    if(d2.year > d1.year || d2.year == d1.year && d2.month > d1.month || d2.year == d1.year && d2.month == d1.month && d2.day > d1.day){
        // jika hanya tahun yang berbeda
        if(d2.year > d1.year && d2.month == d1.month && d2.day == d1.day){
            return (d2.year - d1.year) * 365;
        }
        // jika tahun dan bulan yang berbeda
        else if(d2.year > d1.year && d2.month > d1.month && d2.day == d1.day){
            return ((d2.year - d1.year) * 365) + ((d2.month - d1.month) * 30);
        }
        // jika tahun, bulan, dan hari berbeda
        else{
            return ((d2.year - d1.year) * 365) + ((d2.month - d1.month) * 30) + (d2.day - d1.day);
        }
    }
    // ngecek tanggal ke 1 jika lebih besar dari tanggal kedua
    else if(d1.year > d2.year || d2.year == d1.year && d1.month > d2.month || d2.year == d1.year && d2.month == d1.month && d1.day > d2.day){
        // jika hanya tahun yang berbeda
        if(d2.year > d1.year && d2.month == d1.month && d2.day == d1.day){
            return (d2.year - d1.year) * 365;
        }
        // jika tahun dan bulan yang berbeda
        else if(d2.year > d1.year && d2.month > d1.month && d2.day == d1.day){
            return ((d2.year - d1.year) * 365) + ((d2.month - d1.month) * 30);
        }
        // jika tahun, bulan, dan hari yang berbeda
        else{
            return ((d2.year - d1.year) * 365) + ((d2.month - d1.month) * 30) + (d2.day - d1.day);
        }
    }
    else{
        return 0;
    }
}

int main(){
    Date d1 = {2023, 2, 20};
    Date d2 = {2023, 2, 21};
    Date d3 = {2023, 2, 21};
    Date d4 = {2024, 1, 1};
    Date d5 = {2022, 12, 31};

    printf("%d", daysAhead(d1, d2));
    printf("\n%d", daysAhead(d2, d3));
    printf("\n%d", daysAhead(d3, d4));
    printf("\n%d", daysAhead(d4, d5));
}