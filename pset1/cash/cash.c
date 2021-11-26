#include<cs50.h>
#include<stdio.h>
#include<math.h>


int main(void){
    
    // ask the user for the changed required
    float x;
    do{
        x=get_float("Change owed: ");
        
    }while(x<=0);
    
    //greedy algo to find minimum number of coins 
    int cents = round(x*100);
    int count =0;
    while(cents>=25){
        cents -= 25;
        count++;
        
    }
     while(cents>=10){
        cents -= 10;
        count++;
    }
     while(cents>=5){
        cents -= 5;
        count++;
    }
     while(cents>=1){
        cents -= 1;
        count++;
    }
    
    // print the minimum number of coins
    printf("%i\n", count);
    
    
}