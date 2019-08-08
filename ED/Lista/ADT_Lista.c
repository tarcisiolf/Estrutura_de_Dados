#include <stdio.h>

// ADT Lista Encadeada
	
// Estrutura do nó

typedef struct node 
{
	void *value;
	struct node *next;

} node;


// Criar Lista
node* create_list()
{
	return NULL;
}

// Limpar Lista
node* clear_list(node* current)
{
	if (current == NULL) return NULL;
	node* aux = (*current).next;
	free(current);
	clear_list(aux);
}

// Conta os elementos da lista e retorna seu tamanho
int list_count(node *head, int size)
{
	if (head == NULL) return size;
	list_count((*head).next, size+1);
}

// Verifica se a lista está vazia
int is_empty(node *head)
{
	return (head == NULL);
}

// Adiciona um elemento no início da lista
node* add_head(node *head, void* value)
{
	node* new_node = malloc(sizeof(node));
	(*new_node).value = value;
	(*new_node).next = head;
	return new_node;
}

// Adiciona um elemento no fim da lista
node* add_tail(node* head, void* value)
{
	node* new_node = malloc(sizeof(node));
	(*new_node).value = value;

	if (head == NULL)
	{
		(*new_node).next = head;
		return new_node;
	}

	else
	{
		node* aux = head;

		while((*head).next != NULL) 
		{
			head = (*head).next;
		}

		(*new_node).next = (*head).next;
		(*head).next = new_node;
		return aux;
	}
}

// Verifica se os elementos são iguais (void)

int int_equal(void* a, void* b)
{
	return (*((int*) a)) == (*((int*) b));
}

int char_equal(void* a, void* b)
{
	return (*((char*) a)) == (*((char*) b));
}

int float_equal(void* a, void* b)
{
	return (*((float*) a)) == (*((float*) b));
}

int double_equal(void* a, void* b)
{
	return (*((double*) a)) == (*((double*) b));
}

int string_equal(void* a, void* b)
{
	return !strcmp(a,b);
}

// Procura um elemento da lista

node* search(node* head, void* value, int(*equal)(void *a, void *b))
{
	if (head == NULL) return NULL;
	if (!((*equal)((*head).value, value))) search((*head).next, value, equal);
	else return head;
}

// Remove um elemento da lista

node* remove_element(node* head, node* current, node* previous, void* value, int (*equal)(void* a, void* b))
{
	if(current == NULL) return head;
    if(!((*equal)((*current).value,value))) remove_element(head,(*current).next,current,value,equal);
    else
    {
    	if(previous == NULL) return (*current).next;
        else
        {
       		(*previous).next = (*current).next;
            free(current);
        }
    }

    return head;
}

// Limpar Lista
node* clear_list(node *current)         
{
	if (current == NULL) return NULL;
	node* aux = (*current).next;		 
	free(current);
	clear_list(aux);
}

// Imprime a Lista

void print_ints(node* head)			
{
	if(head == NULL) 
	{
		printf("\n");
		return;	
	}
	printf("%d ", *((int*)(*head).value));
	print_ints((*head).next);
}

void print_char(node* head)
{
	if(head == NULL) 
	{
		printf("\n");
		return;	
	}
	printf("%c ", *((char*)(*head).value));
	print_char((*head).next);
}

void print_float(node* head)
{
	if(head == NULL) 
	{
		printf("\n");
		return;	
	}
	printf("%f ", *((float*)(*head).value));
	print_float((*head).next);
}

void print_double(node* head)
{
	if(head == NULL) 
	{
		printf("\n");
		return;	
	}
	printf("%lf ", *((float*)(*head).value));
	print_double((*head).next);
}

void print_string(node* head)
{
	if(head == NULL) 
	{
		printf("\n");
		return;	
	}
	printf("%s ", *((char*)(*head).value));
	print_string((*head).next);
}

// Bubble Sort de Lista
node* bubble_sort_list(node* head)
{
	node* auxi = head;
	node* auxj = head;
	node* aux = NULL;

	while((*auxi).next != NULL)
	{
		while((*auxj).next != NULL)										
		{
			if (*((int*)(*auxj).value) >= *((int*)(*(*auxj).next).value))
			{
				aux = (*auxj).value;
				(*auxj).value = (*(*auxj).next).value;
				(*(*auxj).next).value = aux;
			}
			auxj = (*auxj).next;										//j++
		}		
		auxj = head;													//j = 0
		auxi = (*auxi).next;											//i++
	}
	return head;
}

// Para ler

	int i, qtd1
	int* int_aux = NULL;
	int aux;

	scanf("%d", &qtd1);
	node* list1 = create_linked_list();
		
	for (i = 0; i < qtd1; ++i)
	{
		scanf("%d", &aux);
		int_aux = malloc(sizeof(int));
		*int_aux = aux;
		list1 = add_tail(list1, int_aux);
		int_aux = NULL;			
	}	
