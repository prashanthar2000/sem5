#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void init_tree(tree_t *ptr_tree)
{
	ptr_tree -> root = NULL;
	printf("init\n");
}

void disp_r(const node_t *root)
{
	if(root == NULL)
		return;
	if(root->left!=NULL)
	{
		printf("Parent : %c\n",root->key);
		node_t* temp = root->left;
		while(temp)
		{
			printf("\tChild : %c\n",temp->key);
			temp = temp -> right; 
		}
	}
	if(root->right)
		disp_r(root->right);
	if(root->left)
		disp_r(root->left);
}

void disp_tree(const tree_t *ptr_tree)
{
	printf("disp\n");
	disp_r(ptr_tree -> root);
}

node_t* search(node_t *root, char parent)
{
	if(root == NULL) 
		return NULL;
	if(root -> key == parent)
	{
		return root;
	}
	if(search(root->left,parent) != NULL)
		return search(root->left,parent);
	if(search(root->right,parent) != NULL)
		return search(root->right,parent);
	return NULL;
}

void add_node(tree_t *ptr_tree, char parent, char key)
{
	node_t *temp = (node_t*)malloc(sizeof(node_t));
	node_t* par;
	
	// if the new parent is not root, it is a descendant of root, already exists in the three
	// according to the convention we have followed for insertion
	if(ptr_tree->root!=NULL && key == ' ') 
		return;
	// root node, has no parent 
	else if(ptr_tree->root==NULL && key == ' ')
		temp -> key = parent;
	// a child or sibling node
	else
		temp -> key = key;
	temp -> left = temp -> right = NULL;
	
	if(ptr_tree -> root == NULL)
		ptr_tree -> root = temp;
	else
	{
		par = search(ptr_tree -> root,parent);
		if(par -> left == NULL)
			par -> left = temp;
		else
		{
			par = par -> left;
			while(par -> right)
				par = par ->right;
			par -> right = temp;
		}
	}
	// printf("add\n"); printf("parent %c child %c\n", parent, key);
}
