#include <stdio.h>

//buat struct Date untuk tanggal
typedef struct{
    int year;
    int month;
    int day;
} Date;

int compareDate(Date d1, Date d2){
    // cek tahun
    if(d1.year<d2.year){
        return -1;
    }
    else if(d1.year > d2.year){
        return 1;
    } 
    else{                                       // d1.year == d2.year
        // cek bulan
        if(d1.month < d2.month){
            return -1;
        }
        else if(d1.month > d2.month){
            return 1;
        }
        else {                                  // d1.month == d2.month
            // cek hari
            if(d1.day < d2.day){
                return -1;
            }
            else if(d1.day > d2.day){
                return 1;
            }
            else{                               // d1.day == d2.day
                return 0;
            }
        }
    }
}

int main(){
    Date d1 = {2023, 2, 20};
    Date d2 = {2023, 2, 21};
    Date d3 = {2023, 2, 21};
    Date d4 = {2024, 1, 1};
    Date d5 = {2022, 12, 31};
  
    printf("%d\n", compareDate(d1, d2)); // expect -1
    printf("%d\n", compareDate(d2, d3)); // expect 0
    printf("%d\n", compareDate(d3, d4)); // expect -1
    printf("%d\n", compareDate(d1, d5)); // expect 1
  
    return 0;
}