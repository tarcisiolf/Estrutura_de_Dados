#include <stdio.h>
#include <stdlib.h>

typedef struct bt
{
	int item;
	bt* left;
	bt* right;
}bt;

bt* create_empty_binary_tree()
{
	return NULL;
}

bt* crete_binary_tree(int item, bt* left, bt* right);
{
	bt* new_bt = malloc(sizeof(bt));
	(*new_bt).item = item;
	(*new_bt).left = left;
	(*new_bt).right = right;

	return new_bt;
}

void print_in_order(bt *bt)
{
	if (bt != NULL)
	{
		print_in_order((*bt).left);
		printf("%d", (*bt).item);
		print_in_order((*bt).right);
	}
}

void print_in_preorder(bt *bt)
{
	if (bt != NULL)
	{
		printf("%d", (*bt).item);
		print_in_preorder((*bt).left);
		print_in_preorder((*bt).right);
	}
}

void print_in_postorder(bt *bt)
{
	if (bt != NULL)
	{
		print_in_postorder((*bt).left);
		print_in_postorder((*bt).right);
		printf("%d", (*bt).item);
	}
}