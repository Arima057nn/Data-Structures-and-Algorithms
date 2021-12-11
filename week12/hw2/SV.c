#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max 10
typedef struct Student{
  char ten[10];
  char dem[10];
  char ho[10];
} student;

student inputName(){
    student new;
    printf("Ten: ");
    gets(new.ten);
    printf("Dem: ");
    gets(new.dem);
    printf("Ho: ");
    gets(new.ho);
    return new;
}   
int main(){ 
    int i;
    student A[1];
    FILE *ptr = fopen("studentList.txt","w+");
    if(ptr == NULL){
        printf("Cannot open the file\n");
        return 1;
    }
    for(i = 0;i < Max;i++){
        A[0] = inputName();
        fprintf(ptr,"%-10s %-10s %-10s\n",A[0].ho,A[0].dem,A[0].ten);
    }
    fclose(ptr);

    return 0;
}