#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct untuk menyimpan nama dan nomor telepon
typedef struct{
    char nama[100];
    int phone;
} Kontak; 

// prototipe fungsi binary search
int binarySearch(Kontak arr[], int left, int right, char target[]){
    if(left > right){
        //jika tidak ketemu return -1
        return -1;
    }

    int mid = left + (right - left)/2;

    if(strcmp(arr[mid].nama, target) == 0){
        //ketemu akan mengambil pertengahan dari array tsb
        return mid;
    } 
    else if(strcmp(arr[mid].nama, target) < 0){
        //mencari pada bagian kanan array
        return binarySearch(arr, mid + 1, right, target);
    }
    else{
        //mencari pada bagian kiri array
        return binarySearch(arr, left, mid - 1, target);
    }
}

int main(){
    int maxdata;
    printf("Berapa data yang mau dimasukkan: ");
    scanf("%d", &maxdata);
    Kontak *people = malloc(maxdata * sizeof(Kontak));

    //baca nama dan nomor telepon
    int numpeople = 0;
    while(numpeople < maxdata){
        //baca nama
        char nama[100];
        printf("Masukkan nama: ");
        scanf("%s", nama);

        //jika tidak ada nama yang ditaruh maka selesai
        if(strlen(nama) == 0){
            break;
        }

        //membaca nomor telpon
        int phone;
        printf("Masukkan nomor telepon %s: ", nama);
        scanf("%d", &phone);

        //memasukkan Kontak kedalam array
        strcpy(people[numpeople].nama, nama);
        people[numpeople].phone = phone;
        numpeople++;
    }

    //Sorting menggunakan bubble sort sebelum di binary search
    for (int i = 0; i < numpeople - 1; i++) {
        for (int j = 0; j < numpeople - i - 1; j++) {
            if (strcmp(people[j].nama, people[j + 1].nama) > 0) {
                Kontak temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }

    //Input nama ynag ingin dicari
    char nama[100];
    printf("Nama yang ingin dicari: ");
    scanf("%s", nama);

    //cari nama dengan binary search
    int index = binarySearch(people, 0, numpeople - 1, nama);

    if (index == -1) {
        printf("Name not found\n");
    } else {
        printf("%s's phone number is %d\n", people[index].nama, people[index].phone);
    }

    //melepas memory dalam array
    free(people);

    return 0;
}

//fungsi binary search
int binarySearch(Kontak arr[], int left, int right, char target[]) {
    if (left > right) {
        //jika tidak ketemu return -1
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (strcmp(arr[mid].nama, target) == 0) {
        //ketemu akan mengambil pertengahan dari array tsb
        return mid;
    } else if (strcmp(arr[mid].nama, target) < 0) {
        //mencari pada bagian kanan array
        return binarySearch(arr, mid + 1, right, target);
    } else {
        //mencari pada bagian kiri array
        return binarySearch(arr, left, mid - 1, target);
    }
}