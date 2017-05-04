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
node root;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    
    
    // TODO
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    char word[25];
    int i,alpha;

    FILE *dict = fopen(dictionary, "r");

    while (fscanf(dict, "%s", word) != EOF)
    {
        //initialize position
        node *move = &root;

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

        move -> is_word =true;
    }

    // TODO : May need to check for some conditions later, if need be.
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
