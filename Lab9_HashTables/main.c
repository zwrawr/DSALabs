//#define NDEBUG
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"


/// ====
/// Defines
/// ====
#define TEST_SIZE 32

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
    
    HashTable *table = hashTable_Constructor(4);
    
    addStationCodes(table);
    
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
    
    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line, "\n")] = 0;
        token = strtok_s(line, ",", &nextToken);
        strncpy_s(stationKey, 4, token, 4);
        token = strtok_s(NULL, ",", &nextToken);
        strncpy_s(stationName, 128, token, 128);
        printf("Added\t::\t%s - %s\n", stationKey, stationName);
        hashTable_Insert(hashTable, stationKey, stationName);
    }
    
    fclose(file);
}