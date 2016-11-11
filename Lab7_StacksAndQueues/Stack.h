#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

/// ====
/// TypeDefs
/// ====
typedef struct Stack Stack;


/// ====
/// Constructors and Destructor
/// ====
Stack *stack_Constructor();
void stack_Deconstructor(Stack *stack);


/// ====
/// Functions
/// ====
int stack_isEmpty(Stack *stack);
int stack_isFull(Stack *stack);
int stack_Push(Stack *stack, int value);
int stack_Pop(Stack *stack, int* popped);
int stack_Peek(Stack *stack, int index, int* peeked);



#endif // STACK_H_INCLUDED
