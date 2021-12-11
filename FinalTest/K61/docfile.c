#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct name
{
    int id;
    char name[30];
} data;

int main(){
    int n,x1,x2,x3,x4;
    data A[1];
    FILE *ptr;
    int k = 0;
    ptr = fopen("bongda.txt","r");
    if(ptr == NULL){
        printf("Cannot open the file\n");
        return 1;    
    }
    fscanf(ptr,"%d%*c",&n);
    printf("%d\n",n);
    for(i = 0;i < n;i++){
        fscanf(ptr,"%d%*c%[^\n]%*c",&A[0].id,A[0].name);
        printf("%-20d\t%-20s\n",A[0].id,A[0].name);
    }
    

    /*while( fscanf(ptr,"%d%*c%[^\n]%*c",&A[0].id,A[0].name) == 2){
        printf("%-20d\t%-20s\n",A[0].id,A[0].name);
    }*/
    fclose(ptr);
    return 0;
}