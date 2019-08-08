#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    void* value;
    struct node* next;
} node;

typedef struct stack
{
    int size;
    node* top;
} st;

st* create_stack()
{
    st* new_stack = malloc(sizeof(st));
    (*new_stack).top = NULL;
    (*new_stack).size = 0;
    return new_stack;
}

st* push(st* stack, void* value)
{
    node* new_node = malloc(sizeof(node));
    (*new_node).value = value;
    (*new_node).next = (*stack).top;
    (*stack).top = new_node;
    (*stack).size++;
    return stack;
}

st* pop(st* stack)
{
    if((*stack).size == 0)
    {
        printf("Stack Underflow!\n");
        return stack;
    }

    node* previous = (*stack).top;
    (*stack).top = (*previous).next;
    free(previous);
    (*stack).size--;
    return stack;
}

st* clear_stack(stack* stack)
{
    if ((*stack).size == 0) return stack;
    else
    {
        node* previous = (*stack).top;
        (*stack).top = (*previous).next;        
        free(previous);                         
        (*stack).size--;
        clear_stack(stack);
    }
}

int stack_empty(st* stack)
{
    return((*stack).size);
}

int peek_int(st* stack)
{
    return (*(int*)(*(*stack).top).value);
}

float peek_float(st* stack)
{
    return (*(float*)(*(*stack).top).value);
}

char peek_char(st* stack)
{
    return (*(char*)(*(*stack).top).value);
}

char* peek_string(st* stack)
{
    return ((char*)(*(*stack).top).value);
}
