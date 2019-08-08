#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int element;
    struct node* next;
} NODE;

typedef struct stack
{
    NODE* head;
} STACK;

STACK* Create_stack()
{
    STACK* new_stack = malloc(sizeof(STACK));
    (*new_stack).head = NULL;
    return new_stack;
}

NODE* create_node(int element)
{
	NODE* new_node = malloc(sizeof(NODE));
	(*new_node).element = element;
	(*new_node).next = NULL;
}

int IS_EMPTY(STACK* stack)
{
	if((*stack).head == NULL) return -1;
	return 1;
}

int POP(STACK* stack)
{
	if((*stack).head == NULL) return -1;
	return ((*(*stack).head).element);
}

STACK* PUSH(STACK* stack, int element)
{
    NODE* new_node = malloc(sizeof(NODE));
    (*new_node).element = element;
    (*new_node).next = (*stack).head;
    (*stack).head = new_node;
    return stack;
}

/*void result(STACK* stack, char operation)
{

}
*/

void Calculadora(STACK* calculadora, int size)
{
	int i, num;
	for (i = 0; i < size; ++i)
	{
		scanf("%d", num);
		calculadora = push(calculadora, num);
	}
}

void printar(STACK* stack)
{
	NODE* aux = stack->head;
	while(aux != NULL)
	{
		printf("%d\n", aux->item);
	}
}

int main()
{
    STACK* calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    //printf("Coordenada 1: %d\n", POP(calculadora));
    printar(calculadora);
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printar(calculadora);
    //printf("Coordenada 2: %d\n", POP(calculadora));
    return 0;
}