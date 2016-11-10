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
void swap(int* a, int* b);
struct ListNode* getNode(struct List* list, int index);
int intArrayToString( char* output, int outpur_length, int* data, int data_length);
int linearSearch( int* data, int data_length, int desired );
void quickSort(struct ListNode* l, struct ListNode* h);
struct ListNode* partition(struct ListNode* l, struct ListNode* h);



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
    int isSorted;
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

    list->isSorted = 1;
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

    if (list->size==1)
    {
        list->isSorted=1;
    }
    else
    {
        list->isSorted=0;
    }

    return list->size;
}

void list_Display(struct List* list)
{

    int * values = malloc(list->size * sizeof(int));
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

    char * string = malloc(10 * list->size * sizeof(char)); // char's per item * number of items * size of char
    intArrayToString(
        string,
        list->size*10,
        values,
        list->size
    );


    printf(
        "\t\tList:[ size:( %d ) , entities:(%s) ]\n",
        list->size,
        string
    );
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
    int * values = malloc(list->size * sizeof(int));
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

    return linearSearch( values , list->size, entity );
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

void list_BubbleSort(struct List* list)
{
    if (list->isSorted == 1)
    {
        return;
    }

    int swaps = 0, counter = 0;
    do
    {
        struct ListNode* node = list->head;

        int i;
        for ( i = 0; i < (list->size - counter - 1); i++ )
        {
            if (node->data > node->next->data)
            {
                int tmp = node->next->data;
                node->next->data = node->data;
                node->data=tmp;
                swaps++;
            }
            node = node->next;
        }
        counter++;
    }
    while( (swaps != 0) && (counter < list->size) );
}

void list_InsertionSort(struct List* list)
{
    if (list->isSorted == 1)
    {
        return;
    }

    struct ListNode* pivot = list->head;
    //printf("\t Pivot : %d\n",pivot->data);

    while (pivot != NULL)
    {
        //printf("\t Pivot : %d\n", pivot->data);
        //list_Display(list);
        //printf("\n");

        struct ListNode* nextPivot = pivot->next;

        struct ListNode* curr = list->head;

        while (curr != pivot)
        {
            if (curr->data > pivot->data)
            {
                if (pivot->next != NULL)
                {
                    pivot->next->prev = pivot->prev;
                }
                else
                {
                    list->tail = pivot->prev;
                }

                if (pivot->prev != NULL)
                {
                    pivot->prev->next = pivot->next;
                }

                pivot->prev = curr->prev;
                pivot->next = curr;

                if (curr->prev != NULL)
                {
                    curr->prev->next = pivot;
                }
                curr->prev = pivot;

                if (list->head == curr)
                {
                    list->head = pivot;
                }

                break;
            }

            curr = curr->next;
        }
        pivot = nextPivot;
    }
    list->isSorted = 1;
}

int list_AddOrdered(struct List* list, int entity)
{
    if (list->isSorted != 1)
    {
        //printf("WARNING::tried to list_AddOrdered to an unsorted list!, sorting before adding!");
        list_BubbleSort(list);
    }
    struct ListNode* newNode = listNode_Constructor(entity);
    list->size++;

    struct ListNode* current = list->head;

    // special case if the item added is smaller than any in the list
    if(list->head == NULL || list->head->data >= newNode->data)
    {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
        newNode->prev = NULL;
    }
    else
    {
        // get the last node that has a value less than the new node
        while (current->next != NULL && current->next->data < newNode->data)
        {
            current = current->next;
        }
        if (current->next != NULL)
        {
            newNode->next = current->next;
            current->next->prev = newNode;
        }
        else
        {
            newNode->next = NULL;
            list->tail = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    return list->size;
}

int list_BinarySearch(struct List* list, int entity)
{
    // doing a binary search on a linked list makes no sense, so just do a linear search
    return list_Search(list, entity);
}

void list_QuickSort(struct List* list)
{
    if (list->isSorted)
    {
        return;
    }
    quickSort(list->head, list->tail);
    list->isSorted = 1;
}


/// ====
/// helpers
/// ====

void quickSort(struct ListNode* left, struct ListNode* right)
{
    if ((right != NULL) && (left != right) && (left != right->next))
    {
        struct ListNode* piviot = partition(left, right);
        quickSort(left, piviot->prev);
        quickSort(piviot->next, right);
    }
}

struct ListNode* partition(struct ListNode* left, struct ListNode* right)
{
    int data = right->data;

    struct ListNode* i = left->prev;

    for (struct ListNode* j = left; j != right; j=j->next)
    {
        if (j->data <= data)
        {
            i = (i == NULL) ? left : i->next;

            swap(&i->data, &j->data);
        }
    }
    i = (i == NULL) ? left : i->next;
    swap(&i->data, &right->data);
    return i;
}

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

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
