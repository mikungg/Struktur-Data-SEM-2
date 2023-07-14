//fungsi menhitung hasil vote
TotalVotes processVotes(CandidateData candidate[], int max, FILE *in, FILE *out){
    //buat variabel sementara untuk menampung data yang dibaca
    TotalVotes temp;
    temp.valid = 0;
    temp.spoilt = 0;
    int vote;
    
    //membaca nomor vote kandidat
    fscanf(in, "%d", &vote);

    //perulangan while jika vote!=0 (0 berarti vote berakhir)
    while(vote!=0){
        //jika nomor vote diluar dari nomor kandidat yang ada spoilt vote ditambah, dan beritahu invalid vote
        if(vote < 1 || vote > max){
            fprintf(out, "Invalid vote: %d\n", vote);
            ++temp.spoilt;
        }
        //jika nomor vote sesuai elemen votes kandidat ditambah dan valid votes ditambah
        else{
            ++candidate[vote].votes;
            ++temp.valid;
        }

        //membaca nomor vote berikutnya
        fscanf(in, "%d", &vote);
    }
    
    return temp;
} 
