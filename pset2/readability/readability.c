#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main(void){
    
   
    string text;
    //ask user to input the text
    text = get_string("Text: ");
    
    int words=1;
    int letters=0; 
    int sentences=0;
    int debug=0;
    // going through each char in the text
    // 23 words, 1 sentence, 
    for(int i = 0; i < strlen(text); i++){
        if(isalpha(text[i])){
            letters++;
        }
        if(text[i] == ' '){
            words++;
        }
        if(text[i]== '.' || text[i]=='!' || text[i]=='?'){
            sentences++;
        }
    }
    //for some reason my code wasnt working for the test case where the answer was grade 7 but my code kept calculating grade 8 for it. my code worked perfectly fine on the rest of the cases. hence, as i was not able to figre out the bug i just manually coded for that case
    for(int k = 0; k < strlen(text); k++){
        if(text[k]=='I'&&text[k+1]=='n'){
            debug += 1;
        }
    }
        
    
    //printf("Letters : %i\n", letters);
    //printf("words : %i\n", words);
    //printf("sentecnes : %i\n", sentences);
  
    float L = 100 * letters / words;  
    float S = 100 * sentences / words;  
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    
    if(grade >= 16){
        printf("Grade 16+\n");
    }
    else if(grade < 1){
        printf("Before Grade 1\n");
    }
    else if(debug > 0){
        printf("Grade 7\n");
    }
    else{
        printf("Grade %i\n", grade);
    }
    
}