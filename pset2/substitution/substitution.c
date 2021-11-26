#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>


int caesarEncipher(string plaintext, string key);
bool distinctLetters(string letters);


int main(int argc, string argv[]){
    
    //program does not proceed if count is not 2
    if(argc!=2){
        printf("Usage: ./substituion key\n");
        return 1;
    }
    //length of the string must be 26
    if(strlen(argv[1]) != 26){
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for(int i = 0, n = strlen(argv[1]); i < n ; i++){
        //program does not proceed if key is not a valid digit
        if(!isalpha(argv[1][i])){
            printf("Key must contain only alphabets.\n");
            return 1;
        }
        //program does not proceed if key contains repeated alphabets
        if(!distinctLetters(argv[1])){
            printf("Key must contain only distinct alphabets.\n");
            return 1;
        }
    }
    //get user input for plaintext
    string plaintext = get_string("plaintext:  ");
    string key = (argv[1]);
    return caesarEncipher(plaintext, key);
}
//this function calculates the ciphertext
int caesarEncipher(string plaintext, string key){
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
            char ci = key[pi];
            //checks if the original char is upper case and then assigns ci to ith position in ciphertext
            if(isupper(ch)){
                ciphertext[i] = toupper(ci);
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


bool distinctLetters(string letters){
    for(int i =0; i < strlen(letters) ; i++){
        for(int k = i + 1; k < strlen(letters) ; k++){
            if(letters[i] == letters[k]){
                return false;
            }
        }
    }
    return true;
}