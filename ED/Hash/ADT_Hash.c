#include <stdio.h>
#include <stdio.h>

typedef struct element
{
	int key;
	void value;
} element;

typedef struct ht
{
	element* table[11];
}ht;

ht* create_hash_table()
{
	ht* new_ht = malloc(sizeof(ht));
	int i;
	for (i = 0; i < 11; ++i) new_ht.table[i] = NULL;
	return new_ht;
}

void put(ht* ht, int key, void* value, int(*hashing)(int key))
{
	int h = (*hashing)(key);

	element* new_e = malloc(sizeof(element));
	(*new_e).key = key;
	(*new_e).value = value;

	if ((*ht).table[h] == NULL)
	{
		(*new_e).next = (*ht).table[h];
		(*ht).table[h] = new_e;
	}

	else //ADD TAIL
	{
		element *current = (*ht).table[h];
		while((*current).next != NULL) current = (*current).next;
		(*current).next = new_e; 
	}
}

void* get(ht *ht, int key, int(*hashing)(int key)) //retorna um ponteiro para o elemento
{
	int h = (*hashing)(key);

	if((*ht).elements[h] != NULL)
  	{
   		element* current = (*ht).elements[h];
    	while(current != NULL)
    	{
     		if((*current).key == key) return (*current).value;
      		current = (*current).next;
    	}
    	return NULL;
  	}
  	else return NULL;
}

void remove_hash(ht* ht, int key, int (*hashing)(int key))
{
  int hd = (*hashing)(key);
  if((*ht).elements[hd] != NULL)
  {
    element* current = (*ht).elements[hd];
    while((*current).next != NULL)
    {
      if((*(*current).next).key == key)
      {
        element* removed = (*current).next;
        (*current).next = (*removed).next;
        free(removed);
        return;
      }
      current = (*current).next;
    }
    printf("Element doesn't exist\n");
  }
  else printf("Element doesn't exist\n");
}

int contain_key(hash* ht, int key, int (*hashing)(int key))
{
  int h = (*hashing)(key);
  if((*ht).elements[h] != NULL)
  {
    element* current = (*ht).elements[h];
    while(current != NULL)
    {
      if((*current).key == key) return 1;
      current = (*current).next;
    }
    return 0;
  }
  else return 0;
}