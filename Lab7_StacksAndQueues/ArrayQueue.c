#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

//Dynamic resizing and circularising
/// ====
/// TypeDefs
/// ====


/// ====
/// Defines
/// ====
#define INITIAL_QUEUE_SIZE 10

/// ====
/// Prototypes
/// ====


/// ====
/// Structures
/// ====

struct Queue
{
    int length;
    int* array;
	int* start;
	int* end;
};


/// ====
/// Constructors and Destructor
/// ====

Queue *queue_Constructor()
{
    Queue *queue;
    queue = malloc(sizeof(Queue));
    
    queue->length = INITIAL_QUEUE_SIZE;
    queue->array = malloc(INITIAL_QUEUE_SIZE * sizeof(int));
    queue->start = queue->array;
	queue->end = queue->array;
    
    return queue;
}

void queue_Deconstructor(Queue *queue)
{
	free(queue->array);
    
    free(queue);
}


/// ====
/// Public Functions
/// ====

// returns 1 if queue is empty, 0 if queue isnt empty, -1 if queue is NULL
int queue_isEmpty(Queue *queue)
{
    if (queue == NULL)
    {
        return -1;
    }
    
    if (queue->end == queue->start)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

// returns 1 if enqueue was successful, -1 if queue is null
int queue_Enqueue(Queue *queue, int value)
{
    if (queue == NULL)
    {
        return -1;
    }
        
	*queue->end = value;
	queue->end++;
    
    return 1;
    
}

// returns 1 if dequeue was successful, 0 if it was unsuccessful, -1 if queue is null
int queue_Dequeue(Queue *queue, int *dequeuedvalue)
{
    if (queue == NULL)
    {
        // this queue hasnt been initialized
        return -1;
    }
    
	*dequeuedvalue = *queue->start;

	queue->start++;
        
    return 1;
}

// returns 1 if peek was successful, 0 if it was unsuccessful, -1 if queue is null
int queue_Peek(Queue *queue, int index, int *peeked)
{
    if (queue == NULL)
    {
        return -1;
    }
    
    if (index < 0 || index >= queue->length)
    {
        return 0;
    }
    
	*peeked = queue->array[index];
    
    return 1;
}



/// ====
/// Helper Functions
/// ====