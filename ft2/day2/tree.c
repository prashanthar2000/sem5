#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void init_tree(tree_t *ptr_tree)
{
	printf("init\n");
}
void disp_tree(const tree_t *ptr_tree)
{
	printf("disp\n");
}
void add_node(tree_t *ptr_tree, char parent, char key)
{
	printf("add\n"); printf("parent %c child %c\n", parent, key);
}
