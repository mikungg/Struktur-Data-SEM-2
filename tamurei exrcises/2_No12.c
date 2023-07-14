#include <stdio.h>
#include <string.h>

int main(){
    typedef struct{
    char nrp[20];
    int CS20A;
    int CS21A;
    int CS29A;
    int CS30A;
    int CS35A;
    int CS36A;
    } Student;
    
    Student students[100];
    int Max_student;
    FILE *fp;
    fp = fopen("registration.txt", "r");
    if(fp == NULL) {
        printf("Error opening data file");
        return 1;
    }
    for(int i = 0; i<100; i++){
        fscanf(fp, "%s", &students[i].nrp);
        if(strcmp(students[i].nrp,"0") == 0){
            Max_student = i;
            break;
        }
        fscanf(fp, "%d %d %d %d %d %d", &students[i].CS20A, &students[i].CS21A, &students[i].CS29A, &students[i].CS30A, &students[i].CS35A, &students[i].CS36A);
    }
    fclose(fp);
    for(int i = 0; i <Max_student; i++){
        if(strcmp(students[i].nrp,"0") == 0){
            break;
        }
        //printf("%s %d %d %d %d %d %d\n", nrp[i], CS20A[i], CS21A[i], CS29A[i], CS30A[i], CS35A[i], CS36A[i]);
    }
    printf("CS20A:\n");
    for(int i = 0; i<Max_student; i++){;
        if(students[i].CS20A == 1){
            printf("%s\n", students[i].nrp);
        }
        else if (students[i].CS20A == 0) continue;
    }
    printf("CS21A:\n");
    for(int i = 0; i<Max_student; i++){;
        if(students[i].CS21A == 1){
            printf("%s\n", students[i].nrp);
        }
        else if (students[i].CS21A == 0) continue;
    }
    printf("CS29A:\n");
    for(int i = 0; i<Max_student; i++){;
        if(students[i].CS29A == 1){
            printf("%s\n", students[i].nrp);
        }
        else if (students[i].CS29A == 0) continue;
    }
    printf("CS30A:\n");
    for(int i = 0; i<Max_student; i++){;
        if(students[i].CS30A == 1){
            printf("%s\n", students[i].nrp);
        }
        else if (students[i].CS30A == 0) continue;
    }
    printf("CS35A:\n");
    for(int i = 0; i<Max_student; i++){;
        if(students[i].CS35A == 1){
            printf("%s\n", students[i].nrp);
        }
        else if (students[i].CS35A == 0) continue;
    }
    printf("CS36A:\n");
    for(int i = 0; i<Max_student; i++){;
        if(students[i].CS36A == 1){
            printf("%s\n", students[i].nrp);
        }
        else if (students[i].CS36A == 0) continue;
    }
    return 0;
}