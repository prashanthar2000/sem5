#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char key[1024];
	int id;
	struct node* left;
	struct node* right;
};
typedef struct node node_t;


struct tree
{
	node_t *root;
};
typedef struct tree tree_t;




struct string_list
{
	node_t* node;
	struct string_list *next;

};
typedef struct string_list string_list_t;

struct parent_stack
{
    string_list_t *head;
};
typedef struct parent_stack parent_stack_t;


//server part


void init_tree(tree_t *ptr_tree)
{
	ptr_tree -> root = NULL;
	//printf("init tree\n");
}

void init_parent_stack(parent_stack_t *ptr_ps)
{
	ptr_ps -> head = NULL;
	//printf("init parent stack\n");
}

node_t* peek(parent_stack_t* stack) {
    return (stack -> head == NULL) ? NULL: stack -> head -> node;
}

int Empty(parent_stack_t* stack) {
    return stack -> head == NULL;
}

void push_parent_stack(parent_stack_t *ptr_ps, node_t* node)
{


	string_list_t* temp = (string_list_t*)malloc(sizeof(string_list_t));
    	temp -> next = NULL;
    	temp -> node = node;
    //strcpy(temp -> key, str );
    
	

	temp -> next = ptr_ps -> head;
        ptr_ps -> head = temp;
}

void pop(parent_stack_t* stack) 
{
    if(Empty(stack)) return;
    string_list_t* temp = stack -> head;
    stack -> head = stack -> head -> next;
    free(temp);
}

node_t* createNode(char* key, int id) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode -> left = newNode -> right = NULL;
    newNode -> id = id;
    strcpy(newNode -> key, key);
    return newNode;
}

void add_Node(tree_t* tree, node_t* parent, node_t* newNode) {
    if(tree -> root == NULL) {
        tree -> root = newNode;
        return;
    }

    if(parent && parent -> left == NULL) {
        parent -> left = newNode;
        return;
    }

    node_t* cur = tree -> root;
    if(parent) cur = parent -> left;
            
    while(cur -> right)
        cur = cur -> right;
    cur -> right = newNode;
}



void gen_header()
{
    printf("#include <stdio.h>\n");
}
void prolog()
{
    printf("int main()\n");
    printf("{\n");
}

void gen_while()
{
    // printf("	int opt;\n");
    printf("\tscanf(\"%%d\", &opt);\n");
    printf("\twhile(opt)\n");
    printf("\t{\n");
    printf("\t\tswitch(opt)\n");
    printf("\t\t{\n");
}
void close_while()
{
    printf("\t\t}\n"); // close switch
    printf("\t\tscanf(\"%%d\", &opt);\n");
    printf("\t}\n"); // close while
}
void epilog()
{

    printf("}\n");
}

void gen_case(int i, const char *s)
{
    printf("\t\t\tcase %d : \n", i);
    //printf("				printf(\"%s\\n\");\n", s);
    printf("\t\t\t\tprintf(\"%s\\n\");\n", s);
    // printf("				break;\n");
}

void close_case()
{
    printf("\t\tbreak;\n");
}

//genration of code stage
//case count is used to count which case no its has to be 
//level definds the which level are we in currently
void gen_tree_r(const node_t *root, int case_count, int level)
{

    if (root->left)
    {
        ++level;

        gen_while();
        gen_case(1, root->left->key);
        gen_tree_r(root->left, 1, level);
        
        // ** decrese the level before going to the siblings **
        --level;
    
    }
    //increse the case count 
    ++case_count;
    //reach all the right nodes before going back to parent
    if (root->right)
    {
        close_case();
        gen_case(case_count, root->right->key);
        gen_tree_r(root->right, case_count, level);
    }

    //all the cases are complete there fore close the swich case and while loop
    if (root->right == NULL)
    {
        close_case();
        close_while();
    }
}

void gen_tree(const tree_t *ptr_tree)
{
    if (ptr_tree->root)
    {
        printf("int opt;\n");
        //gen_tree_r(ptr_tree->root, 1, 0);
        int level = 0 ; 
        int case_count = 1;
        if (ptr_tree->root->left)
        {
            ++level;

            gen_while();
            gen_case(1, ptr_tree->root->left->key);
            gen_tree_r(ptr_tree->root->left, 1, level);

            --level;
        }
        ++case_count;
        if (ptr_tree->root->right)
        {
            close_case();
            gen_case(case_count, ptr_tree->root->right->key);
            gen_tree_r(ptr_tree->root->right, case_count, level);
        }
    }
}


void code_gen(tree_t *tree)
{
    gen_header();

    prolog();
    
    gen_tree(tree);

    epilog();
}


//client

int main() 
{
    parent_stack_t stack; init_parent_stack(&stack);
    tree_t tree; init_tree(&tree);
    int flags = 0; char a[1024];
    char ch;
    int Tabs = 0;
    int newTabs = 0;
    int nodeIds = 1;

    while( (ch = getchar()) != -1 ) 
    {
        if(ch == '\t') 
        {
            ++newTabs;            
        } 
        else if(ch == '\n') 
        {
            node_t* newNode = createNode(a, nodeIds++);
            if(newTabs <= Tabs)
                pop(&stack);                            
            for(int i=0; i < (Tabs - newTabs); ++i)
                pop(&stack);
            
            node_t* parent = peek(&stack);
            add_Node(&tree, parent, newNode);
            
            push_parent_stack(&stack, newNode);
            Tabs = newTabs;
            newTabs = 0;            
            flags = 0;
        } 
        else 
        {
            a[flags++] = ch;
            a[flags] = 0;
        }
    }

     code_gen(&tree);

    return 0;
}



