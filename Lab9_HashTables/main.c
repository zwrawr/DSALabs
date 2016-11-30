//#define NDEBUG
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"


/// ====
/// Defines
/// ====
// set to < 0 to ignore
#define TEST_NUMBER_OF_STATIONS -1

/// ====
/// Prototypes
/// ====
void addStationCodes(HashTable *hashTable);


/// ====
/// Main
/// ====
int main(void)
{
    srand((unsigned int)time(NULL));
    
    HashTable *table = hashTable_Constructor(HASH_TABLE_DEFAULT_SIZE);
    
    addStationCodes(table);
    
    printf("PRESS KEY TO DISPLAY HASHTABLE \n");
    getchar();
    
    hashTable_Display(table);
    
    printf("PRESS KEY TO DECONSTRUCT HASHTABLE \n");
    getchar();
    
    hashTable_Deconstructor(table);
    printf("PRESS KEY TO EXIT \n");
    getchar();
    return 0;
}

/// ====
/// Functions
/// ====
void addStationCodes(HashTable *hashTable)
{

    FILE *file;
    char line[256];
    char stationKey[4];
    char stationName[128];
    char *token;
    char *nextToken;
    
    errno_t err = fopen_s(&file, "stationCodes.csv", "r");
    
    if (err != 0)
    {
        printf("ERROR:: could not open file\n");
        return;
    }
    
    int i = TEST_NUMBER_OF_STATIONS;
    
    while (fgets(line, sizeof(line), file) && i != 0)
    {
        line[strcspn(line, "\n")] = 0;
        token = strtok_s(line, ",", &nextToken);
        strncpy_s(stationKey, 4, token, 4);
        token = strtok_s(NULL, ",", &nextToken);
        strncpy_s(stationName, 128, token, 128);
        printf("Added\t::\t%s - %s\n", stationKey, stationName);
        hashTable_Insert(hashTable, stationKey, stationName);
        
        if (i > 0)
        {
            i--;
        }
    }
    
    fclose(file);
}