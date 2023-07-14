#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nama[101];
    float jarak;
} InfoAtlet;

int main(){
    //membuka file input.txt
    FILE* in = fopen("input.txt", "r");
    if(in == NULL){
        printf("Error! Can't open file\n");
        return 1;   
    }

    int jumlah;
    fscanf(in, "%d", &jumlah);

    //mengalokasi memori struct ke dalam atlet
    InfoAtlet* atlet = (InfoAtlet*) malloc(jumlah * sizeof(InfoAtlet));
    if(atlet == NULL){
        printf("Error tidak bisa alokasi memory\n");
        return 1;
    }
    
    for(int i=0; i<jumlah; i++){
        fscanf(in, "%s %f", atlet[i].nama, &atlet[i].jarak);
    }

    //mengrutukan pelompat terbaik dengan bubble sort
    for (int i = 0; i < jumlah; i++){
        for (int j = 0; j < jumlah - 1 - i; j++){
            if (atlet[j].jarak < atlet[j + 1].jarak){
                InfoAtlet temp;
                temp = atlet[j];
                atlet[j] = atlet[j + 1];
                atlet[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < jumlah; i++){
        printf("%s %.2f\n", atlet[i].nama, atlet[i].jarak);
    }

    free(atlet);
    fclose(in);    
    return 0;
}