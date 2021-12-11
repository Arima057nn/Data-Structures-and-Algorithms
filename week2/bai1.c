#include <stdio.h>
#include <stdlib.h>


int main(int argc,char *argv[]){

    double width,height;
    if(argc != 3){
        printf("Wrong number of the arguments!");
        printf("correnct syntax: rect <Width> <height>");
        return 1;
    }
    width = atof(argv[1]);
    height = atof(argv[2]);

    printf("%f",width * height);
    printf("%f",2 * (width + height));


    return 0;
}