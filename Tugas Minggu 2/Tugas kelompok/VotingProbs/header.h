#define MAXCANDIDATE 5
#define MAXNAMELENGTH 30
#define MAXNAMEBUFFAA MAXNAMELENGTH+1

//struct data kandidat
typedef struct{
    char name[MAXNAMEBUFFAA];
    int votes;
} CandidateData;
CandidateData candidate[MAXCANDIDATE+1];

//struct untuk total voting terbuang dan valid
typedef struct{
    int valid;
    int spoilt;
} TotalVotes;
TotalVotes count;

//prototype function
void initializeName(CandidateData[], int, FILE *);
TotalVotes processVotes(CandidateData[], int, FILE *, FILE *);
void printResults(CandidateData[], int, TotalVotes, FILE *);