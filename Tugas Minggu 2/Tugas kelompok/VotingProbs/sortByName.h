// fungsi sorting nama
void sortByName(CandidateData candidate[], int lo, int hi) {
    //membuat variabel struct sementara
    CandidateData insertitem;
    // algoritma sorting nama
    for(int i = lo+1; i <= hi; i++){
         //menjadikan variabel sementara menjadi candidate[i]
        insertitem = candidate[i];
        //mendeklarasikan variabel j (kandidat yang akan dibandingkan)
        int j = i-1;

        // cek bila nama pada variabel sementara lebih besar dari votes kandidat j
        while(j >= lo && strcmp(insertitem.name, candidate[j].name) < 0) {
            candidate[j+1] = candidate[j];
            --j;
        }

    // mengganti struct pada candidate[j+1] dengan data pada variabel sementara
    candidate[j+1] = insertitem;
    }
}