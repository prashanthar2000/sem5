#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void init_tree(tree_t *ptr_tree)
{
	//printf("init\n");
	ptr_tree->root = NULL;
}

void disp_r(node_t *root)
{
	printf("%c\n", root->key);
}

void disp_tree(const tree_t *ptr_tree)
{
	printf("disp\n");
	disp_r(ptr_tree->root);
}
node_t* make_node(char key)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->key = key; temp->left = temp->right = NULL;
	return temp;
}
void add_node(tree_t *ptr_tree, char parent, char key)
{
//	printf("add\n"); printf("parent %c child %c\n", parent, key);
	// code need to be changed later
	node_t* temp = make_node(parent);
	ptr_tree->root = temp;
}

int check_root(tree_t *ptr_tree)
{
	return ptr_tree->root == NULL;
}
