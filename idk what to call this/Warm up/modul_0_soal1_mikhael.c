#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struktur node

typedef struct snode_t
{
    int data;               //isi dari node biasanya data dan ptr link ke alamat data selanjutnya
    struct snode_t *next; 
} SlistNode;

//Struktur SinglyList

typedef struct slist_t{
    unsigned _size;         //struct single list yg isinya size buat keep track of how many elements are in the list
    SlistNode *_head;       //ptr head untuk diisi dengan alamat node yg paling atas/pertama
} SinglyList;

//Inisialisasi Single List
void slist_init(SinglyList *list){
    list->_head = NULL;             // nge assign head dari list dengan NULL 
    list->_size = 0;                // membuat size dari list start dari 0 kyk di pertaminaaaaaaa mulai dr nol >_<
}

bool slist_isEmpty(SinglyList *list){       // ini utk nge check list kosong ato ngga dengan memakai boolean 
    return (list->_head == NULL);           // return 1 jika list kosong (jika pointer head kosong)
}                                           // return 0 jika list berisi (jika pointer head menunjuk suatu alamat)



void slist_pushFront(SinglyList *list, int value){
    SlistNode *newNode = (SlistNode*) malloc(sizeof(SlistNode));    //membuat pointer yang menunjuk ke suatu alamat yang baru dialokasikan
    if (newNode){                                                   //jika alokasi memori berhasil masuk percabangan
        list->_size++;                                              //variabel _size akan ditambah satu untuk menandakan elemen di list bertambah
        newNode->data = value;                                      //assign value pada parameter pada variabel data pada pointer newnode

        if(slist_isEmpty(list)) newNode->next = NULL;               //jika list kosong maka buat link pada poinetr newnode menjadi NULL
        else newNode->next = list->_head;                           //jika list berisi maka link pada pointer newnode akan menunjuk ke _head sebelumnya
        list->_head = newNode;                                      //assign pointer newnode kepada _head supaya node yang baru terletak dipaling depan
    }
}

//Fungsi forEachElement
void forEachElement(SinglyList *list, void (*operation)(int*)){     //void (*operation)(int*) adalah parameter untuk function void
    SlistNode *current = list->_head;                               //buat pointer baru yang menunjuk _head dari list
    while(current != NULL){                                         //selama pointer current masih menunjuk ke sebuah alamat lakukan looping
        operation(&(current->data));                                //eksekusi fungsi pada parameter dengan menggunakan elemen dalam node yang ditunjuk
        current = current->next;                                    //traverse the list
    }
}

//Output
void printElement(int *elem){
    printf("%d ", *elem);                                           //print output elemen node yang ditunjuk
}

//Fungsi Reverse
void reverseEach(int *elem){
    int reverse = 0, y;                                             //deklarasi variabel baru
    int x = *elem;                                                  //misalkan x menjadi elemen pada node yang ditunjuk
    while (x != 0){                                                 //selama x belum 0 lakukan looping
        y = x % 10;                                                 
        reverse = reverse * 10 + y;                                 //algoritma reverse
        x /= 10;
    }
    *elem = reverse;
}

//Fungsi sumDigit
void sumDigit(int *elem){
    int x = *elem, sum = 0, digit;                                  //deklarasi variabel
    while( x != 0){                                                 //selama x belum 0 lakukan looping
        digit = x % 10;                                             //dapatkan digit satuan elemen pada node yang ditunjuk
        sum += digit;                                               //variabel sum ditambah denang digit dari elemen pada node yang ditunjuk
        x /= 10;                                                    //x dibagi 10 untuk mendapat digit selain satuan pada elemen pada node yang ditunjuk
    }
    *elem = sum;                                                    //selesai looping assign variabel sum pada elemen pada node yang ditunjuk
}

int main(){
    SinglyList myList;
    slist_init(&myList);

    slist_pushFront(&myList, 123);
    slist_pushFront(&myList, 234);
    slist_pushFront(&myList, 345);

    forEachElement(&myList, reverseEach);
    printf("\n Data setelah ReverseEach: ");
    forEachElement(&myList, printElement);

    forEachElement(&myList, sumDigit);
    printf("\n Data setelah Sum Digit: ");
    forEachElement(&myList, printElement);

    return 0;
}