#include<cs50.h>
#include<stdio.h>

int main(void){


    //asking user for input of height between 1 and 8 inclusive
    int x;
    do{
        x = get_int("Height: ");

    }while(x<1 || x>8);

    //iterate through the ith row 
    for(int i=0;i<x;i++){
        // form a left aligned pyramid of " "
        for(int j=x-1;j>i;j--){
            printf(" ");
        }
        // form a left aligned pyramid of #
        for(int k=-1;k<i;k++){
            printf("#");
        }
        //prints the gap between the two pyramids
        printf("  ");
        //forms a righ aligned pyramid of #
        for(int k=-1;k<i;k++){
            printf("#");
        }
        //prints the each row on a new line
        printf("\n");
    }
}