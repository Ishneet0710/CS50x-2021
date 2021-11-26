#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

bool checkValid(int x[], int n);

int main(void){
    int arr[100];
    char buffer[100];
    
    long number = get_long("Numbers: ");
    sprintf(buffer, "%li", number);
    int n = strlen(buffer);
    for(int i = 0 ; i < n ; i++){
        //convert each char digit in buffer to integer in arr
        arr[i]= buffer[i] - '0';
    }
    if(n == 16 && checkValid(arr, n) && arr[0] == 5 && (arr[1] == 1 || arr[1] == 2 || arr[1] == 3 || arr[1] == 4 || arr[1] == 5 )){
        printf("MASTERCARD\n");
    }
    else if(n == 15 && checkValid(arr, n) && arr[0] == 3 && (arr[1] == 4 || arr[1] == 7)){
        printf("AMEX\n");
    }
    else if((n == 16 || n == 13) && arr[0] == 4 && checkValid(arr, n)){
        printf("VISA\n");
    }
    else{
        printf("INVALID\n");
    }
}



//works:)
bool checkValid(int x[], int n){
    int odd = 0;
    int even = 0;
    int finalsum = 0;
    int digit ;
    int digit_1;
    int digit_2;
    int array[100];
    if(n % 2 == 0){
        for(int i = 0 ; i < n ; i++){
        if(i % 2 == 0){
            if((2 * x[i]) > 9){
                digit = 2 * x[i];
                digit_1 = digit % 10;
                digit /= 10;
                digit_2 = digit % 10;
                digit = digit_1 + digit_2;
                even += digit;
            }
            else{
                even += 2 * x[i];
            }
        }
        else{
            odd += x[i];
        }
    }
    }
    else{
        for(int i = 0 ; i < n ; i++){
        if(i % 2 != 0){
            if((2 * x[i]) > 9){
                digit = 2 * x[i];
                digit_1 = digit % 10;
                digit /= 10;
                digit_2 = digit % 10;
                digit = digit_1 + digit_2;
                odd += digit;
            }
            else{
                odd += 2 * x[i];
            }
        }
        else{
            even += x[i];
        }
    }
    }
    
    finalsum = odd + even;
    if(finalsum % 10 == 0){
        return true;
    }
    else{
        return false;
    }
}