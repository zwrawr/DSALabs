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
void quickSort(struct List* list, int bottom, int top);
int partition(struct List* list, int bottom, int top);
int intArrayToString( char* output, int outpur_length, int* data, int data_length);
int linearSearch( int* data, int data_length, int desired );
void swap(int* a, int* b);

/// ====
/// Structures
/// ====
struct List
{
    int capacity;
    int numEntities;
    int* entities;
    int isSorted;
};


/// ====
/// Constructors and Destructor
/// ====
struct List* list_Constructor()
{
    struct List* list;

    list = malloc(sizeof(struct List));
    list->entities = malloc(ARRAY_LIST_CAPACTITY * sizeof(int));

    list->capacity = ARRAY_LIST_CAPACTITY;
    list->numEntities = 0;
    list->isSorted=1;
    return list;
}

void list_Destructor(struct List* list)
{
    free(list->entities);
    free(list);
}


/// ====
/// Functions
/// ====
int list_Add(struct List* list, int entity)
{
    int emptySpace = list->capacity - list->numEntities;

    if ( emptySpace <= 0 ){

		//printf("filled array list adding more space\n");

		list->capacity =(int)(1.5*list->capacity);

		list->entities = realloc(list->entities, list->capacity * sizeof(int));

    }

    list->entities[list->numEntities] = entity;
    list->numEntities++;

    if (list->numEntities==1)
    {
        list->isSorted=1;
    }
    else
    {
        list->isSorted=0;
    }

    return list->numEntities;
}

void list_Display(struct List* list)
{
   char * string = malloc (10*list->numEntities*sizeof(char)); //char's per entity * num entitys * sizeof char
   intArrayToString(
                    string,
                    list->numEntities*10,
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

int list_Read(struct List* list, int index, int* entity)
{
    if((index<=0)||(index>list->capacity))
    {
        printf("\nWARNING :attempted to read from an index outside the bounds of an list\n");
        return 0;
    }
    if(index>=list->numEntities)
    {
        printf("\nWARNING :attempted to read from an index in an list that is empty\n");
        return 0;
    }

    *entity = list->entities[index];

    return 1;
}

int list_Search(struct List* list, int entity)
{
    return linearSearch( list->entities , list->numEntities, entity );
}

int list_Remove(struct List* list, int index)
{
    if((index<=0)||(index>list->capacity))
    {
        printf("\nWARNING :attempted to read from an index outside the bounds of an list\n");
        return 0;
    }
    if(index>=list->numEntities)
    {
        printf("\nWARNING :attempted to read from an index in an list that is empty\n");
        return 0;
    }

    int i;
    for ( i = index +1 ; i < list->numEntities ; i++)
    {
        list->entities[i-1] = list->entities[i];
    }
    list->numEntities--;

    return 1;
}

int list_Size(struct List* list)
{
    return list->capacity - list->numEntities;
}

// return 0 if the array list is not empty , returns 1 if the array list is empty
int list_isEmpty(struct List* list)
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

void list_BubbleSort(struct List* list)
{
    if (list->isSorted == 1)
    {
        return;
    }

    int swaps = 0, counter = 0;
    do
    {
        int i;
        for (i = 0; i < (list->numEntities - counter - 1); i++)
        {
            /*printf("\t\t Compearing [index( %d ),\tvalue( %d )] \tto \t[index( %d ),\tvalue( %d )]\n"
                     ,i,list->entities[i],i+1,list->entities[i+1]);*/
            if ( list->entities[i] > list->entities[i+1])
            {
                swap(&(list->entities[i]),&(list->entities[i+1]));
                swaps++;
            }
        }
        counter++;
    }
    while ( (swaps != 0) && (counter < list->numEntities) );

    list->isSorted=1;
}

void list_InsertionSort(struct List* list)
{
    if (list->isSorted == 1)
    {
        return;
    }

    int i;
    for(i=1;i<(list->numEntities);i++)
    {
        int x = list->entities[i];
        int j=i-1;
        while ((j>=0)&&(list->entities[j]>x))
        {
            list->entities[j+1]=list->entities[j];
            j=j-1;
        }
        list->entities[j+1]=x;
    }
    list->isSorted=1;
}

int list_AddOrdered(struct List* list, int entity)
{

    if (list->isSorted != 1)
    {
        //printf("WARNING::tried to list_AddOrdered to an unsorted list!, sorting before adding!");
        list_InsertionSort(list);
    }

    int emptySpace = list->capacity - list->numEntities;

	if (emptySpace <= 0) {

		list->capacity = (int)(1.5*list->capacity);

		list->entities = realloc(list->entities, list->capacity * sizeof(int));
	}

    int i;
    for (i = 0; i < list->numEntities;i++)
    {
        if (entity < list->entities[i]){
               break;
        }
    }
    list_Insert(list,i,entity);

    return list->numEntities;
}

void list_Insert(struct List* list,int index, int entity)
{
    int i;
    list->numEntities++;
    for (i=(list->numEntities -1); i >= index; i--)
    {
        list->entities[i] = list->entities[i-1];
    }
    list->entities[index]=entity;

    list->isSorted=0;
}

// retuns the index of entity, if entity is not found returns -1
int list_BinarySearch(struct List* list, int entity)
{
	if (list->isSorted != 1)
	{
		list_InsertionSort(list);
	}

	int bottom = 0, top = list->numEntities;
	while (bottom <= top)
	{
		int middle = (bottom + top) / 2;
		if (list->entities[middle] == entity)
		{
			return middle;
		}
		else if (list->entities[middle] < entity)
		{
			bottom = middle + 1;
		}
		else
		{
			top = middle - 1;
		}
	}
	return -1;
}

void list_QuickSort(struct List* list)
{
	if (list->isSorted) 
	{
		return;
	}
	int bottom = 0, top = list->numEntities - 1;
	quickSort(list, bottom, top);
	list->isSorted = 1;
}

/// ====
/// helpers
/// ====
void quickSort(struct List* list, int bottom, int top)
{
	int pivotPoint;
	if (top > bottom)
	{
		pivotPoint = partition(list, bottom, top);
		quickSort(list, bottom, pivotPoint - 1);
		quickSort(list, pivotPoint + 1, top);
	}
}

int partition(struct List* list, int bottom, int top)
{

	int pivotPoint = (bottom+top)/2;
	int pivotData = list->entities[pivotPoint];

	swap(&list->entities[pivotPoint], &list->entities[top]);

	for (int i = bottom ; i < top; i++)
	{

		if (list->entities[i] < pivotData)
		{
			swap(&list->entities[i], &list->entities[bottom]);
			bottom = bottom + 1;
		}
	}
	swap(&list->entities[top], &list->entities[bottom]);
	return bottom;
}

int linearSearch( int* data , int data_length, int desired )
{
    int i;
    for(i = 0; i < data_length; i++)
    {
        if(data[i] == desired)
        {
            return i;
        }
    }
    return -1;
}

// may fail for large numbers
int intArrayToString( char* output, int output_length, int* data, int data_length)
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

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
