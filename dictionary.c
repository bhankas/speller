/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"

//define node structure
typedef struct node
{
    bool is_word;
    struct node *children[27];
}node;

//initialize starting node
struct node *root;
unsigned int word_count = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    int i;
    int alpha;
    
    //point to root fr new word
    node *move = root;

    for(i=0 ; word[i] != '\0' ; i++)
    {
        if(word[i] >= 'A' && word[i] <= 'Z')
         {
             //for uppercase characters
             alpha = word[i] - 'A';
         }
         else if(word[i] >= 'a' && word[i] <= 'z')
         {
             //for lowercase characters
             alpha = word[i] - 'a';
         }
         else
         {
             //if not from characters, mark as apostrophe
             alpha = 26;
         }

        //check if child node exists, if not word doesn't exist
        if(move -> children[alpha] == NULL)
        {
            return false;
        }
        else    //move to next letter in word
        {
            move = move -> children[alpha];
        }
    }

    //if word is complete, check if dictionary says so
    if(move -> is_word == true)
    {
        return true;
    }
    else
    {
        return false;
    }    
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    //array to store word and other variables
    char word[45];
    int i,alpha;

    //open file with file pointer
    FILE *dict = fopen(dictionary, "r");

    //allocate space for root node
    root = malloc(sizeof(node));

    while (fscanf(dict, "%s", word) != EOF)
    {        
        //initialize position
        node *move = root;

        for(i=0 ; word[i] != '\0' ; i++)
        {
            alpha = (int)word[i] - 97;
            // check if alpha is anything other than alphabets
            if (!(alpha >=0 && alpha <= 25))
            {
                //put alpha to apostrophe
                alpha = 26;
            }
            
            //check if child node exists, if not malloc a new one and move to it
            if(move -> children[alpha] == NULL)
            {
                move -> children[alpha] = malloc(sizeof(node));
                move = move -> children[alpha];
            }
            else
            {
                move = move -> children[alpha];
            }
        }

        //if word is complete, mark final node so
        move -> is_word =true;
        word_count++;
    }

    // TODO : May need to check for some conditions later, if need be.
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return word_count;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
