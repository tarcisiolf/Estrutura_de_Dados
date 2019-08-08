#include <stdio.h>
#include <stdlib.h>

typedef struct bst
{
	int item;
	struct bst* left;
	struct bst* right;
}bst;

bst* create_empty_binary_tree()
{
	return NULL;
}

bst* create_binary_tree(int item, bst* left, bst* right)
{
	bst* new_bt = malloc(sizeof(bst));
	(*new_bt).item = item;
	(*new_bt).left = left;
	(*new_bt).right = right;

	return new_bt;
}

// Mínimo e Máximo

bst* minimum(bst* bt)
{
	while((*bt).left != NULL)
	{
		bt = (*bt).left;
	}
	return bt;
}

bst* maximum(bst* bt)
{
	while((*bt).right != NULL)
	{
		bt = (*bt).right;
	}
	return bt;
}

// Sucessor e Predecessor

bst* sucessor(bst* bt)
{
	if ((*bt).right != NULL)
	{
		return minimum((*bt).right);
	}

	return bt;
}

bst* predecessor(bst* bt)
{
	if ((*bt).left != NULL)
	{
		return maximum((*bt).left);
	}

	return bt;
}

// Search
bst* search(bst* bt, int item)
{
	if (((*bt).item == item) || (bt == NULL)) 
	{
		return bt;
	}

	else if (item <= (*bt).item)
	{
		return search((*bt).left, item);
	}

	else
	{
		return search((*bt).right, item);
	}
}

// Search Interativo

bst* isearch(bst* bt, int item)
{
	while((bt != NULL) && (item != (*bt).item))
	{
		if (item <= (*bt).item) bt = (*bt).left;
		else bt = (*bt).right;
		return bt;
	}
}

// Adicionando

bst* add(bst* bt, int item)
{
	if (bt == NULL)
	{
		bt = create_binary_tree(item, NULL, NULL);
	}

	else if (item <= (*bt).item)
	{
		(*bt).left = add((*bt).left, item);
	}

	else
	{
		(*bt).right = add((*bt).right, item);
	}

	return bt;
}

bst* remover(bst* bt, int item)
{
	if (bt == NULL)
	{
		return NULL;
	}

	else if (item < (*bt).item)		(*bt).left = remover((*bt).left, item);
	else if (item > (*bt).item)		(*bt).right = remover((*bt).right, item);
	else							 
	{
		if ((*bt).right == NULL)
		{
			bst* aux = (*bt).left;
			bt = (*bt).left;
			free(bt);
			return aux;
		}

		else if ((*bt).left == NULL)
		{
			bst*  aux = (*bt).right;
			bt = (*bt).right;
			free(bt);
			return aux;	
		}

		else
		{
			bst* suc = sucessor((*bt).right);
			(*bt).item = (*suc).item;
			(*bt).right = remover((*bt).right, (*suc).item);
		}
		return bt;
	}
}