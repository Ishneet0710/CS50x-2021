#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>


int caesarEncipher(string plaintext, int key);



int main(int argc, string argv[]){
    
    //program does not proceed if count is not 2
    if(argc!=2){
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //program does not proceed if key is not a valid digit
    for(int i = 0, n = strlen(argv[1]); i < n ; i++){
        if(!isdigit(argv[1][i])){
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    //get user input for plaintext
    string plaintext = get_string("plaintext:  ");
    //convert the key from string to integer
    int key = atoi(argv[1]);
    return caesarEncipher(plaintext, key);
}
//this function calculates the ciphertext
int caesarEncipher(string plaintext, int key){
    int n = strlen(plaintext);
    char ciphertext[n];
    //iterate through the entire string
    for(int i = 0 ; i < n ; i++){
        char ch = plaintext[i];
        //checks if the char at the ith position in the string is an alphabet and then proceed
        if(isalpha(ch)){
            //converts the entire string first to upper text for ease of calculation
            char x = toupper(ch);
            //formula to calculate new char 
            int pi = x -'A';
            char ci = (pi + key ) % 26 + 'A';
            //checks if the original char is upper case and then assigns ci to ith position in ciphertext
            if(isupper(ch)){
                ciphertext[i] = ci;
            }
            //checks if original char is lower case and then converts ci to lower case and then assigns to ith position in ciphertext
            else if(islower(ch)){
                ciphertext[i] = tolower(ci);
            }
        }
        else{
            ciphertext[i] = ch;
        }
    }
    //print ciphertext
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}