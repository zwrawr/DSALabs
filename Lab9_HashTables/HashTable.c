#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "HashTable.h"
#include "ConsoleColor.h"


/// ====
/// Defines
/// ====
#define MAX_KEY_LENGTH 4
#define MAX_VALUE_LENGTH 128
#define MaX_ELEMENTS_IN_BUCKET_TO_BE_PRINTED 4


/// ====
/// TypeDefs
/// ====
typedef struct HashElement HashElement;

/// ====
/// Prototypes
/// ====
HashElement *hashElement_Constructor(char *key, char *value);
void hashElement_Deconstructor(HashElement *hashElement);
int hash(char *key, int numBuckets);


/// ====
/// Structures
/// ====
struct HashTable
{
    int numBuckets;
    int numElements;
    HashElement **buckets;
};


struct HashElement
{
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    HashElement *next;
};


/// ====
/// Constructors and Destructor
/// ====
HashElement *hashElement_Constructor(char *key, char *value)
{
    HashElement *hashElement;
    hashElement = malloc(sizeof(HashElement));
    
    
    strcpy_s(hashElement->key, MAX_KEY_LENGTH, key);
    strcpy_s(hashElement->value, MAX_VALUE_LENGTH, value);
    hashElement->next = NULL;
    
    return hashElement;
}

void hashElement_Deconstructor(HashElement *hashElement)
{
    if (hashElement->next != NULL)
    {
        hashElement_Deconstructor(hashElement->next);
    }
    
    free(hashElement);
    return;
}

HashTable *hashTable_Constructor(int numBuckets)
{
    HashTable *hashTable;
    hashTable = malloc(sizeof(HashTable));
    
    hashTable->numBuckets = numBuckets;
    
    hashTable->buckets = malloc(numBuckets * sizeof(HashElement));
    
    for (int i = 0; i < numBuckets; i++)
    {
        hashTable->buckets[i] = NULL;
    }
    
    hashTable->numElements = 0;
    
    return hashTable;
}

void hashTable_Deconstructor(HashTable *hashTable)
{

    for (int i = 0; i < hashTable->numBuckets; i++)
    {
        if (hashTable->buckets[i] != NULL)
        {
            hashElement_Deconstructor(hashTable->buckets[i]);
        }
    }
    
    free(hashTable->buckets);
    
    free(hashTable);
}


/// ====
/// Public Functions
/// ====
void hashTable_Insert(struct HashTable *hashTable, char *key, char *value)
{
    int hashValue = hash(key, hashTable->numBuckets);
    
    if (hashTable->buckets[hashValue] == NULL)
    {
        hashTable->buckets[hashValue] = hashElement_Constructor(key, value);
    }
    else
    {
        HashElement *curr = hashTable->buckets[hashValue];
        
        int i = 0;
        
        while (curr->next != NULL)
        {
            curr = curr->next;
            i++;
        }
        
        curr->next = hashElement_Constructor(key, value);;
    }
    
    hashTable->numElements++;
}

void hashTable_Display(struct HashTable *hashTable)
{
    printf("HashTable\n");
    
    for (int i = 0; i < hashTable->numBuckets; i++)
    {
        if (hashTable->buckets[i] != NULL)
        {
            consoleColors_SetColor(FG_BLUE);
            printf("\tBucket[ %d ]", i);
            consoleColors_RestoreDefault();
            printf("\titems[ ");
            
            HashElement *curr = hashTable->buckets[i];
            
            int elementsPrinted = 0;
            
            while (curr->next != NULL)
            {
                if (elementsPrinted < MaX_ELEMENTS_IN_BUCKET_TO_BE_PRINTED)
                {
                    printf("( %s, %s ), ", curr->key, curr->value);
                }
                else if (elementsPrinted == MaX_ELEMENTS_IN_BUCKET_TO_BE_PRINTED)
                {
                    consoleColors_SetColor(FG_RED | FG_INTENSE);
                    printf(" +");
                }
                else
                {
                    printf("+");
                }
                
                elementsPrinted++;
                curr = curr->next;
            }
            
            if (elementsPrinted < MaX_ELEMENTS_IN_BUCKET_TO_BE_PRINTED)
            {
                printf("( %s, %s ) ]\n", curr->key, curr->value);
            }
            else
            {
                consoleColors_SetColor(FG_RED | FG_INTENSE);
                printf("+");
                consoleColors_RestoreDefault();
                printf(" ]\n");
            }
        }
    }
    
    printf("\n\n");
}


/// ====
/// Helper Functions
/// ====

// max hash is 630 if key is upper case alphibetic, if it uses lower case then max is 854
int hash(char *key, int numBuckets)
{
    return  key[0] + 2 * key[1] + 4 * key[2] % numBuckets;
}

