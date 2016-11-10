#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/// ====
/// Defines
/// ====
#define ARRAY_LIST_CAPACTITY 50

/// ====
/// Prototypes
/// ====
int intArrayToString( char *output, int outpur_length, int *data, int data_length);
int linearSearch( int *data, int data_length, int desired );


/// ====
/// Structures
/// ====
struct List
{
    int capacity;
    int numEntities;
    int *entities;
};


/// ====
/// Constructors and Destructor
/// ====
struct List *list_Constructor()
{
    struct List *list;
    
    list = malloc(sizeof(struct List));
    list->entities = malloc(ARRAY_LIST_CAPACTITY *sizeof(int));
    
    list->capacity = ARRAY_LIST_CAPACTITY;
    list->numEntities = 0;
    
    return list;
}

void list_Destructor(struct List *list)
{
    free(list->entities);
    free(list);
}


/// ====
/// Functions
/// ====
int list_Add(struct List *list, int entity)
{
    int emptySpace = list->capacity - list->numEntities;
    
    if ( emptySpace <= 0 )
    {
        return 0;
    }
    
    list->entities[list->numEntities] = entity;
    list->numEntities++;
    
    return list->numEntities;
}

void list_Display(struct List *list)
{
    char *string = malloc(10 * list->numEntities * sizeof(string));
    intArrayToString(
        string,
        list->numEntities * 10,
        list->entities,
        list->numEntities
    );
    
    
    printf(
        "List:[ capacity:( %d ) , numEntities:( %d ) , entities:(%s) ]",
        list->capacity,
        list->numEntities,
        string
    );
}

int list_Read(struct List *list, int index, int *entity)
{
    if ((index <= 0) || (index > list->capacity))
    {
        printf("\nWARNING :attempted to read from an index outside the bounds of an list\n");
        return 0;
    }
    
    if (index >= list->numEntities)
    {
        printf("\nWARNING :attempted to read from an index in an list that is empty\n");
        return 0;
    }
    
    *entity = list->entities[index];
    
    return 1;
}

int list_Search(struct List *list, int entity)
{
    return linearSearch( list->entities , list->numEntities, entity );
}

int list_Remove(struct List *list, int index)
{
    if ((index <= 0) || (index > list->capacity))
    {
        printf("\nWARNING :attempted to read from an index outside the bounds of an list\n");
        return 0;
    }
    
    if (index >= list->numEntities)
    {
        printf("\nWARNING :attempted to read from an index in an list that is empty\n");
        return 0;
    }
    
    int i;
    
    for ( i = index + 1 ; i < list->numEntities ; i++)
    {
        list->entities[i - 1] = list->entities[i];
    }
    
    list->numEntities--;
    
    return 1;
}

int list_Size(struct List *list)
{
    return list->capacity - list->numEntities;
}

// return 0 if the array list is not empty , returns 1 if the array list is empty
int list_isEmpty(struct List *list)
{
    if (list->numEntities > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


/// ====
/// helpers
/// ====
int linearSearch( int *data , int data_length, int desired )
{
    int i;
    
    for (i = 0; i < data_length; i++)
    {
        if (data[i] == desired)
        {
            return i;
        }
    }
    
    return -1;
}


// may fail for large numbers
int intArrayToString( char *output, int output_length, int *data, int data_length)
{
    int writtenLenght;
    
    for (writtenLenght = 0; data_length; data_length--)
    {
        int length = snprintf(output, output_length, "%d,", *data++);
        
        if (length >= output_length)
        {
            // not enough space
            return -1;
        }
        
        writtenLenght += length;
        output += length;
        output_length -= length;
    }
    
    return writtenLenght;
}
