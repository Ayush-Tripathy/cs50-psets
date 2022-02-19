// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashcode = hash(word);
    node *currentNode = table[hashcode];
    while (currentNode != NULL)
    {
        char *str = malloc(45);
        for (int i = 0; i < LENGTH; i++)
        {
            str[i] = currentNode->word[i];
        }
        if (!strcasecmp(str, word))
        {
            return true;
        }
        else
        {
            currentNode = currentNode->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += (word[i] * (i +  1));
    }

    return sum % N;
    //return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dictfile = fopen(dictionary, "r");
    if (dictfile == NULL)
    {
        printf("Could not open file %s.", dictionary);
        return false;
    }
    char c;
    char *buffer = malloc(LENGTH);
    int i = 0;
    int hashcode, status = 1, r;
    while ((r = fread(&c, sizeof(char), 1, dictfile)) != 0 || status == 1)
    {
        if (r == 0)
        {
            status = 0;
        }
        if (c == '\n' || status == 0)
        {
            hashcode = hash(buffer);
            node *newNode = malloc(sizeof(node));
            for (int j = 0; j < i; j++)
            {
                newNode->word[j] = buffer[j];
            }
            newNode->next = NULL;
            if (table[hashcode] != NULL)
            {
                node *currentnode = table[hashcode];
                while (currentnode->next != NULL)
                {
                    currentnode = currentnode->next;
                }

                currentnode->next = newNode;
            }
            else
            {
                table[hashcode] = newNode;
            }
            free(buffer);
            free(newNode);
            buffer = malloc(LENGTH);
            i = 0;
        }
        else
        {
            buffer[i] = c;
            i++;
        }
    }
    free(buffer);
    fclose(dictfile);
    if (status == 0)
        return true;

    return false;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int size = 0;
    for (int i = 0; i < N; i++)
    {
        node *currentNode = table[i];
        while (currentNode != NULL)
        {
            size++;
            currentNode = currentNode->next;
        }
    }
    return size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //node *currentNode = table[0];

    return true;
}
