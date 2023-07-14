#include <stdio.h>
#include <string.h>
#include "header.h"
#include "initializeName.h"
#include "processVotes.h"
#include "printResults.h"
#include "sortByVote.h"
#include "sortByName.h"

int main(){
    // deklarasi variabel variabel
    CandidateData candidate[MAXCANDIDATE+1];
    TotalVotes count;
    FILE *in = fopen("votes.txt", "r");
    FILE *out = fopen("results.txt", "w");

    // jalankan fungsi initializeName
    initializeName(candidate, MAXCANDIDATE, in);
    // ubah variabel count dengan hasil proses fungsi processVotes
    count = processVotes(candidate, MAXCANDIDATE, in, out);
    // sorting votes
    sortByVote(candidate, 1, MAXCANDIDATE);

    // sorting nama dengan vote sama
    for(int i=1; i<=MAXCANDIDATE-1; i++){
        // deklarasikan counter jumlah vote yang sama untuk kandidat ke i
        int samevote = 0;

        // cek berapa kandidat yang memiliki vote yang sama dengan kandidat i
        for(int j=i+1 ; j<=MAXCANDIDATE; j++){
            if(candidate[j].votes==candidate[i].votes){
                samevote++;
            }
        }

        // jika ada yang sama jalankan fungsi sortByName
        if(samevote > 0){
            sortByName(candidate, i, i+samevote);
        }
    }

    // print ke results.txt
    printResults(candidate, MAXCANDIDATE, count, out);
    fclose(in);
    fclose(out);
}