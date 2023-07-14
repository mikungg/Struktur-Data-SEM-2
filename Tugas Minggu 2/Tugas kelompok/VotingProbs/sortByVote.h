// fungsi sorting vote terbesar ke terkecil
void sortByVote(CandidateData candidate[], int lo, int hi) {
// buat variabel sementara untuk struct CandidateData
    CandidateData insertitem;
    // algoritma sorting vote
    for(int i = lo + 1; i <= hi; i++){
        //menjadikan variabel sementara menjadi candidate[i]
        insertitem = candidate[i];
        //mendeklarasikan variabel j (kandidat yang akan dibandingkan)
        int j = i-1;

        // cek bila votes pada variabel sementara lebih besar dari votes kandidat j
        while(j >= lo && insertitem.votes > candidate[j].votes){
            // menjadikan kandidat[j+1](variabel sementara) kandidat j
            candidate[j+1] = candidate[j];
            --j;
        }

    // mengganti struct pada candidate[j+1] dengan data pada variabel sementara
    candidate[j+1] = insertitem;
    }
}