#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

/// ====
/// TypeDefs
/// ====
typedef struct Queue Queue;


/// ====
/// Constructors and Destructor
/// ====
Queue *queue_Constructor();
void queue_Deconstructor(Queue *queue);


/// ====
/// Functions
/// ====
int queue_isEmpty(Queue *queue);
int queue_Enqueue(Queue *queue, int value);
int queue_Dequeue(Queue *queue, int* dequeuedvalue);
int queue_Peek(Queue *queue, int index, int* peeked);



#endif // QUEUE_H_INCLUDED
