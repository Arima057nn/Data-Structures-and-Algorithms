#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct HAHA{
    char mssv[10];
    int score;
    char name[10];
} AA;
int main(){
    AA BB;
    FILE *ptr =fopen("b.txt","r");
    if(ptr == NULL){
        printf("Cannot open the file");
        return 1;
    }

    while(fscanf(ptr,"%s %d %[^\n]",BB.mssv,&BB.score,BB.name) == 3){
        printf("%s %d %s\n",BB.mssv,BB.score,BB.name);
    }
    fclose(ptr);
    return 0;
}