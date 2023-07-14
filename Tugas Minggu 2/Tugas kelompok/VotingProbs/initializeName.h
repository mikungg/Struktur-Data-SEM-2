//fungsi membuat nama depan dan belakang menjadi 1 string dan set votes menjadi 0
void initializeName(CandidateData candidate[], int max, FILE *in){

    //membuat variabel nama belakang
    char lastname[MAXNAMEBUFFAA];

    //algoritma menyatukan nama dan set votes mejadi 0
    for (int i=1; i<=max; i++) {
        //membaca string dari file input
        fscanf(in, "%s %s", candidate[i].name, lastname);

        //menyambungkan nama depan dan nama belakang 
        strcat(candidate[i].name, " ");
        strcat(candidate[i].name, lastname);

        //set votes menjadi 0
        candidate[i].votes = 0;
    }
}
