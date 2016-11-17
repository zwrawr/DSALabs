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
void expand(Queue *queue);

/// ====
/// Structures
/// ====

struct Queue
{
    int capacity;
    int count;
    
    int *bufferStart;
    int *bufferEnd;
    
    int *front;
    int *back;
};


/// ====
/// Constructors and Destructor
/// ====

Queue *queue_Constructor()
{
    Queue *queue;
    queue = malloc(sizeof(Queue));
    
    queue->count = 0;
    queue->capacity = INITIAL_QUEUE_SIZE;
    
    queue->bufferStart = malloc(INITIAL_QUEUE_SIZE * sizeof(int));
    queue->bufferEnd = queue->bufferStart + queue->capacity;
    
    queue->front = queue->bufferStart;
    queue->back = queue->bufferStart;
    
    return queue;
}

void queue_Deconstructor(Queue *queue)
{
    free(queue->bufferStart);
    
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
    
    if (queue->count == 0)
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
    
    if (queue->count == (queue->capacity - 1))
    {
        expand(queue);
    }
    
    *queue->front = value;
    
    if (queue->front == queue->bufferEnd)
    {
        queue->front = queue->bufferStart;
    }
    else
    {
        queue->front++;
    }
    
    queue->count++;
    
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
    
    if (queue->count == 0)
    {
        return 0;
    }
    
    *dequeuedvalue = *queue->back;
    
    if (queue->back == queue->bufferEnd)
    {
        queue->back = queue->bufferStart;
    }
    else
    {
        queue->back++;
    }
    
    queue->count--;
    
    return 1;
}

// returns 1 if peek was successful, 0 if it was unsuccessful, -1 if queue is null
int queue_Peek(Queue *queue, int index, int *peeked)
{
    if (queue == NULL)
    {
        return -1;
    }
    
    if (index < 0 || index >= queue->count)
    {
        return 0;
    }
    
    
    int *p = queue->back;
    
    for (int i = 0; i < index; i++)
    {
        if (p == queue->bufferEnd)
        {
            p = queue->bufferStart;
        }
        else
        {
            p++;
        }
    }
    
    *peeked = *p;
    
    return 1;
}

void queue_Display(Queue *queue)
{
    printf("\t\t\t= QUEUE \t[ ");
    
    int *p = queue->back;
    
    for (int i = 0; i < queue->count; i++)
    {
        printf(" %d:(%d) ", i , *p);
        
        if (p == queue->bufferEnd)
        {
            p = queue->bufferStart;
        }
        else
        {
            p++;
        }
    }
    
    printf(" ] \n");
    
}



/// ====
/// Helper Functions
/// ====

void expand(Queue *queue)
{
    //tmp storage for the queue
    int *tmp = malloc(queue->count * sizeof(int));
    
    // populate the tmp queue, make the first element of the tmp the oldest value in the queue
    int *p = queue->back;
    
    for (int i = 0; i < queue->count; i++)
    {
        tmp[i] = *p;
        
        if (p == queue->bufferEnd)
        {
            p = queue->bufferStart;
        }
        else
        {
            p++;
        }
    }
    
    // now expand the original buffer
    queue->capacity += (int)(queue->capacity * 0.5);
    queue->bufferStart = realloc(queue->bufferStart, queue->capacity * sizeof(int));
    queue->bufferEnd = queue->bufferStart + queue->capacity;
    queue->back = queue->bufferStart;
    queue->front = queue->back + queue->count;
    
    // now add the values stroed in the tmp array back to the orignal queue
    for (int i = 0; i < queue->count; i++)
    {
        queue->back[i] = tmp[i];
    }
    
    // get rid of the tmp buffer
    free(tmp);
}