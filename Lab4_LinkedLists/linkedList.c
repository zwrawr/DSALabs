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
struct ListNode* listNode_Constructor(int value);
void listNode_Destructor(struct ListNode*);

struct ListNode* getNode(struct List* list, int index);
int intArrayToString( char* output, int outpur_length, int* data, int data_length);
int linearSearch( int* data, int data_length, int desired );


/// ====
/// Structures
/// ====
struct ListNode
{
    int data;
    struct ListNode* next;
    struct ListNode* prev;
};
struct List
{
    int size;
    struct ListNode* head;
    struct ListNode* tail;
};


/// ====
/// Constructors and Destructor
/// ====
struct List* list_Constructor()
{
    struct List* list;

    list = malloc(sizeof(struct List));

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

void list_Destructor(struct List* list)
{
    struct ListNode* currentRecord;
    struct ListNode* nextRecord = list->head;

    while(nextRecord!=NULL)
    {
        currentRecord = nextRecord;
        nextRecord = currentRecord->next;

        listNode_Destructor(currentRecord);
    }

    free(list);
}

struct ListNode* listNode_Constructor(int value)
{
    struct ListNode* node;

    node = malloc(sizeof(struct ListNode));
    node->data = value;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void listNode_Destructor(struct ListNode* node)
{
    free(node);
}


/// ====
/// Functions
/// ====
int list_Add(struct List* list, int entity)
{
    struct ListNode* node = listNode_Constructor(entity);

    if ( list->size == 0 ) // create new list
    {
        list->head = node;
        list->tail = node;
        node->next = NULL;
        node->prev = NULL;
    }
    else // add to tail
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
        node->next = NULL;
    }

    list->size ++;
    return list->size;
}

void list_Display(struct List* list)
{

    int* values = malloc(list->size * sizeof(int));
    values[0] = list->head->data;

    int i = 1;
    struct ListNode* node = list->head;

    do
    {
        node = node->next;

        values[i] = node->data;

        i++;
    }
    while(node->next != NULL);

    char* string = malloc(10*list->size*sizeof(char));
    intArrayToString(
                    string,
                    list->size*10,
                    values,
                    list->size
                    );


    printf(
           "List:[ size:( %d ) , entities:(%s) ]",
           list->size,
           string
           );
	free(values);
	free(string);
}

int list_Read(struct List* list, int index, int* entity)
{
    if((index<=0)||(index>list->size))
    {
        printf("\nWARNING :attempted to read from an index outside the bounds of an list\n");
        return 0;
    }
    struct ListNode* node = list->head;
    int i;
    for (i = 0 ; i < index ; i++ )
    {
        node = node->next;
    }
    *entity = node->data;

    return 1;
}

int list_Search(struct List* list, int entity)
{
    int* values = malloc(list->size * sizeof(int));
    values[0] = list->head->data;

    int i = 1;
    struct ListNode* node = list->head;

    do
    {
        node = node->next;

        values[i] = node->data;

        i++;
    }
    while(node->next != NULL);

    int index = linearSearch( values , list->size, entity );

	free(values);

	return index;
}

int list_Remove(struct List* list, int index)
{
    if((index<=0)||(index>list->size))
    {
        printf("\nWARNING :attempted to remove a node from an index outside the bounds of an list\n");
        return 0;
    }

    struct ListNode* node = getNode(list,index);
    if ( node == NULL )
    {
        printf("\nWARNING :couldn't get node \n");
        return 0;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;

    if (node->next == NULL)
    {
        list->tail = node->prev;
    }
    if (node->prev == NULL)
    {
        list->head = node->next;
    }

    listNode_Destructor(node);
    list->size--;
    return 1;
}

int list_Size(struct List* list)
{
    return list->size;
}

// return 0 if the array list is not empty , returns 1 if the array list is empty
int list_isEmpty(struct List* list)
{
    if (list->size > 0)
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

// returns one if the node is found
struct ListNode* getNode(struct List* list, int index)
{

    if((index<=0)||(index>list->size))
    {
        printf("\nWARNING :attempted to get a node from an index outside the bounds of an list\n");
        return NULL;
    }
    struct ListNode* node = list->head;
    int i;
    for (i = 0 ; i < index ; i++ )
    {
        printf("looking at node : ");
        node = node->next;
    }
    printf("\n");
    return node;
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
