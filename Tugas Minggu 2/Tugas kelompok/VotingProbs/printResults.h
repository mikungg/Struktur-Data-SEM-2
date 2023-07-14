// fungsi mendapatkan kandidat keberapa dengan vote terbanyak
int getLargest(CandidateData candidate[], int lo, int hi){
    //buat variabel sementara
    int big = lo;

    for(int i = lo + 1; i <= hi; i++){
        //cek vote kandidat terbesar, kemudian disetor dalam variabel sementara 
        if (candidate[i].votes > candidate[big].votes){
            big = i;
        }
    }

    return big;
}

// fungsi print ke results.txt 
void printResults(CandidateData candidate[], int max, TotalVotes c, FILE *out){
    //print jumlah voter
    fprintf(out, "\nNumber of voters: %d\n", c.valid + c.spoilt);
    //print jumlah vote valid
    fprintf(out, "Number of valid votes: %d\n", c.valid);
    //print jumlah vote invalid
    fprintf(out, "Number of spoilt votes: %d\n", c.spoilt);
    fprintf(out, "\nCandidate Score\n\n");

    //print seluruh kandidat
    for(int i = 1; i <= max; i++){
        fprintf(out, "%-15s %3d\n", candidate[i].name, candidate[i].votes);
    }
    
    fprintf(out, "\nThe winner(s)\n");

    //buat variabel untuk menampung hasil function getLargest
    int win = getLargest(candidate, 1, max);

    //print pemenang yang memiliki jumlah vote sama dengan vote candidate[win].votes
    int winningvote = candidate[win].votes;
    for(int i = 1; i <= max; i++){
        if (candidate[i].votes == winningvote){
            fprintf(out, "%s\n", candidate[i].name);
        }
    }
}