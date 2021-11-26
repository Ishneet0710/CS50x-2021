#include <cs50.h>
#include <stdio.h>

int main(void)
{
    
    // asking for the intial population size
    int x;
    do{
        x=get_int("Start size: ");
        
    }while(x<9);
    
    // asking for the end population size
    int y;
    do{
        y = get_int("End size: ");
        
    }while(y<x);
    
    // calculating number of years to reach expected end size
    int counter = 0;
    while (x < y){
        x = x + x / 3 - x / 4;
        counter++;
    }
    
    // printing the number of years required to do so
    printf("Years: %i\n", counter);

    
}