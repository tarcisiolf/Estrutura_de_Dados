#include <stdio.h>
#include <stdlib.h>

typedef struct bt
{
	int item;
	int h;
	struct bt* left;
	struct bt* right;
}bt;

int max(int a, int b)
{
	return (a>b) ? a : b;
}

int h(bt* bta)
{
	if (bt == NULL) return -1;
	else 
	{
		return (1+ max(h((*bta).left),h((*bta).right)))
	}
}

int is_balanced(bt* bta)
{
	int bf = (h((*bta).left),h((*bta).right));
	return ((-1 <= bf) && (bf <= 1));
}

bt* create_empty_binary_tree()
{
	return NULL;
}

bt* create_binary_tree(int item, bt* left, bt* right)
{
	bt* new_bt = malloc(sizeof(bt));
	(*new_bt).item = item;
	(*new_bt).left = left;
	(*new_bt).right = right;

	return new_bt;
}

int balance_factor(bt* bta)
{
	if (bta == NULL) return 0;
	else if (((*bt).left != NULL) && ((bt).right != NULL))
	{
		return( (*(*bt).left).h - (*(*bt).right).h);
	} 
	else if (((*bt).left != NULL) && ((bt).right == NULL))
	{
		return (1 + (*(*bt).left).h);
	}
	else
	{
		return (-(*(*bt).right).h -1);
	}
}

bt* rotate_left(bt* bta)
{
	bt* subtree_root = NULL;

	if (bta != NULL && (*bta).right != NULL)
	{
		subtree_root = (*bta).right;
		(*bta).right = (*subtree_root).left;
		(*subtree_root).left = bta;
	}

	(*subtree_root).h = h(subtree_root);
	(*bta).h = h(bta);
	return subtree_root;
}

bt* rotate_right(bt* bta)
{
	bt* subtree_root = NULL;

	if (bta != NULL && (*bta).left != NULL)
	{
		subtree_root = (*bta).left;
		(*bta).left = (*subtree_root).right;
		(*subtree_root).right = bta;
	}

	(*subtree_root).h = h(subtree_root);
	(*bta).h = h(bta);
	return subtree_root;
}

bt* add(bt* bta, int item)
{
	if (bta == NULL)
	{
		return (create_binary_tree(item, NULL, NULL));
	}

	else if ((*bta).item >= item)
	{
		(*bta).left = add((*bta).left, item);
	}

	else 
	{
		(*bta).right = add(((*bta).right, item))
	}

	(*bta).h = h(bta);
	bt* child;

	if (balance_factor(bta) == 2 || balance_factor(bta) == -2)
	{
		if (balance_factor(bta) == 2)
		{
			child = (*bta).left;
			if (balance_factor(child) == -1)
			{
				(*bta).left = rotate_left(child);
			}

			bta = rotate_right(bta);
		}
		else if (balance_factor(bta) == -2)
		{
			child = (*bta).right;
			if (balance_factor(child) == 1)
			{
				(*bta).right = rotate_right(child);
			}

			bta = rotate_left(bta);
		}
	}

	return bta;
}