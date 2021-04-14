#ifndef TREE_H
#define TREE_H
struct node
{
	char key;
	struct node* left;
	struct node* right;
};
typedef struct node node_t;

struct tree
{
	node_t *tree;
};
typedef struct tree tree_t;
void init_tree(tree_t *ptr_tree);
void disp_tree(const tree_t *ptr_tree);
void add_node(tree_t *ptr_tree, char parent, char key);

#endif

