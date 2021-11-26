// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table for each alphabet so we store the words based on the starting alphabet
const unsigned int N = 26;

// Hash table
node *table[N];

int words_in_dict = 0;
unsigned int hash_value;
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //store the hash value of word being checked
    int value = hash(word);
    //get the linked list at that index of that word
    node *cursor = table[value];
    //traverse the linked list until end is reached
    while(cursor != NULL){
        //checks if the word is present
        if(strcasecmp(word, cursor->word)==0){
            return true;
        }
        //otherwise move the cursor to the next word in the linked list
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
//reference : https://joseph28robinson.medium.com/cs50-pset-5-speller-f9c89d08237e
unsigned int hash(const char *word)
{
    long sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open the dicitionary file
    FILE *pointer = fopen(dictionary, "r");
    //if error in reading print error message and return false
    if(dictionary==NULL){
        printf("Error in loading the dictionary file\n");
        return false;
    }
    //temporary array to store the words before they are hashed into table
    char tmp[LENGTH + 1];
    //read each word from dict until end is reached
    while(fscanf(pointer, "%s", tmp) != EOF){
        node *n = malloc(sizeof(node));
        if(n==NULL){
            return false;
        }
        //copying the word from the temporary array into the node created for that word
        strcpy(n->word, tmp);
        hash_value = hash(tmp);
        //insert node into the hash table at that particular location based on the hash value
        n->next = table[hash_value];
        table[hash_value] = n;
        words_in_dict ++;
    }
    fclose(pointer);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return words_in_dict;
    //just returns the words in dictionary
    //we dont need to return 0 cus if dictionary wasnt loaded the words_in_dict wouldnt be incremented and the variable would remain at 0
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //iterate through the entire hash table
    for(int i=0; i<N; i++){
        //get linked list at ith position
        node *cursor = table[i];
        //traverse the linked list
        while(cursor!=NULL){
            //assign temp to current node
            node *temp = cursor;
            //move the cursor to the next node
            cursor = cursor->next;
            //free the current node
            free(temp);
        }
        //if last bucket is empty we return true as that means all the buckets have been emptied
        if (cursor == NULL && i == N - 1){
         return true;
        }
    }

    return false;
}
