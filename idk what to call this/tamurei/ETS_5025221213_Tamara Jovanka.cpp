#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <string>
using namespace std;

typedef struct ymd{
    int date;
    int month;
    int year;

} Date;

typedef struct stacknode{
    long long nrp;
    char nama[30];
    char judul[30];
    Date tglpinjam;

} Snode;

typedef struct queuenode{
    long long nrp;
    char nama[30];

} Qnode;

int main(){
    int comm, i=1;
    char yorn, dump[10];
    Snode sinsert;
    Qnode qinsert;
    stack<Snode> database;
    stack<Snode> temp;
    queue<Qnode> antremhs;

    while(1)
    {
        printf("Commands :\n1. Pinjam buku\n2. Pengembalian buku\n3. Layani pengembalian\n4. Daftar buku yang belum kembali\n9. Keluar\n\nEnter command : ");

        scanf("%d", &comm);
        printf("\n");

        if(comm == 1)
        {
            while(1)
            {
                printf("Masukkan tanggal peminjaman : ");
                scanf("%d %d %d", &sinsert.tglpinjam.date, &sinsert.tglpinjam.month, &sinsert.tglpinjam.year);
                printf("Masukkan nama : ");
                gets(dump);
                gets(sinsert.nama);
                printf("Masukkan NRP : ");
                scanf("%lld", &sinsert.nrp);
                printf("Masukkan judul buku : ");
                gets(dump);
                gets(sinsert.judul);
                printf("\nApakah data berikut sudah benar?\nNama               : %s\nNRP                : %lld\nJudul buku         : %s\nTanggal peminjaman : %d %d %d\n\ny/n?", sinsert.nama, sinsert.nrp, sinsert.judul, sinsert.tglpinjam.date, sinsert.tglpinjam.month, sinsert.tglpinjam.year);
                scanf("%c", &yorn);

                if(yorn == 'y')
                {
                    database.push(sinsert);
                    break;
                }
                else
                {}
            }
        }

        else if(comm == 2)
        {
            while(1)
            {
                printf("Masukkan nama : ");
                gets(dump);
                gets(qinsert.nama);
                printf("Masukkan NRP : ");
                scanf("%lld", &qinsert.nrp);
                printf("\nApakah data berikut sudah benar?\nNama : %s\nNRP  : %lld\n\ny/n?", qinsert.nama, qinsert.nrp);
                gets(dump);
                scanf("%c", &yorn);

                if(yorn == 'y')
                {
                    antremhs.push(qinsert);
                    break;
                }
                else
                {}
            }
        }

        else if(comm == 3)
        {
            Qnode qntemp;
            Snode sntemp;
            stack<Snode> temps;

            qntemp = antremhs.front();

            while(1)
            {
                sntemp = database.top();

                if(qntemp.nrp == sntemp.nrp)
                {
                    printf("Nama                : %s\nNRP                 : %lld\nJudul Buku          : %s\nTanggal Peminjaman  : %d %d %d\n", sntemp.nama, sntemp.nrp, sntemp.judul, sntemp.tglpinjam.date, sntemp.tglpinjam.month, sntemp.tglpinjam.year);

                    database.pop();

                    while(!temps.empty())
                    {
                        database.push(temps.top());
                        temps.pop();
                    }
                    break;
                }

                temps.push(database.top());
                database.pop();
            }
        }

        else if(comm == 4)
        {
            Snode sntemp;

            while(!database.empty())
            {        
                temp.push(database.top());        
                database.pop();
            }    

            while(!temp.empty())
            {      
                sntemp = temp.top();
                printf("%d.) Nama                : %s\n    NRP                 : %lld\n    Judul Buku          : %s\n    Tanggal Peminjaman  : %d %d %d\n\n", i, sntemp.nama, sntemp.nrp, sntemp.judul, sntemp.tglpinjam.date, sntemp.tglpinjam.month, sntemp.tglpinjam.year);
                database.push(temp.top());
                temp.pop();
                i++;
            }

            i = 1;
        }

        else if(comm == 9)
        {
            printf("Exiting...");
            break;
        }

        else
        {
            printf("Invalid command\n\n");
        }
    }
}