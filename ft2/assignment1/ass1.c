#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

struct node
{
    char *key;
    struct node *left;
    struct node *right;
#if DEBUG
    // struct node *parent; // for debug purpose to 
                            // know who is parent node
#endif
};
typedef struct node node_t;

struct tree
{
    node_t *root;
};
typedef struct tree tree_t;

node_t *add_node(node_t *parent, char *line);
node_t *create_node(node_t *parent, char *line);
void disp_r(const node_t *root, int level);
void disp_tree(const tree_t *ptr_tree);

//tree init
void init_tree(tree_t *ptr_tree)
{
    ptr_tree->root = create_node(NULL, "root");
#if DEBUG 
    //ptr_tree->root->parent = ptr_tree->root;
#endif
}

//create a new node
node_t *create_node(node_t *parent, char *line)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->left = NULL;
    temp->right = NULL;
#if DEBUG 
    //temp->parent = parent;
#endif 
    temp->key = line;
    return temp;
}

node_t *add_node(node_t *parent, char *line)
{
    
    //check for left if not create node to the left  
    if (parent->left == NULL)
    {
        parent->left = create_node(parent, line);
        return parent->left;
    }
    //if left existes then atleast 1 child existes
    else
    {
        
        node_t *pres;
        pres = parent->left;

        while (pres->right != NULL)
        {
            pres = pres->right;
            //prev = pres->right;
        }
        //create a node at the end of the all the siblings 
        pres->right = create_node(parent, line);
        return pres->right;
    }
}

//display tree for debug
#if DEBUG
void disp_r(const node_t *root, int level)
{
    if (root)
    {
        for (int i = 0; i < level; ++i)
        {
            printf("\t");
        }
        printf("%s -->", root->key);
        printf("%s\n", root->parent->key);
    }

    //printf("level increase ", level);
    if (root->left)
    {
        ++level;
        printf("left ");
        disp_r(root->left, level);
        --level;
    }
    if (root->right)
    {

        printf("right");
        // --level;
        disp_r(root->right, level);
    }
}

void disp_tree(const tree_t *ptr_tree)
{
    printf("disp\n");
    if (ptr_tree->root)
    {
        //printf("sanity %s\n", ptr_tree->root->parent->key);
        disp_r(ptr_tree->root, 0);
    }
}
#endif

//display memo for debug purpost 
#if DEBUG
void disp_memo(node_t **memo)
{
    int i = 0;
    while (memo[i] != NULL)
    {
        printf("%d %s\n", i, memo[i]->key);
        ++i;
    }
}
#endif


void main_gen(tree_t *tree);


int main()
{
    tree_t tree;
    init_tree(&tree);

    //disp_tree(&tree);

    char ch;
    int flag = 0;
    int is_newline = 1;
    // node_t* parent = tree.root;
    int max_memo = 1024;
    node_t **memo = (node_t **)malloc(sizeof(node_t *) * max_memo);
    for(int i = 0 ; i < max_memo ; ++i)
    {
        memo[i] = NULL;
    }
    memo[0] = tree.root;

    //int loop_count = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch != '\t')
        {

            if (is_newline)
            {

                //store all the char in a array of 1024    
                char *chr = (char *)malloc(sizeof(char) * 1024);
                int i = 0;
                chr[i++] = ch;
                // printf("%c", ch);
                
                //copy till u reach newline
                while ((ch = getchar()) != '\n' )
                {
                    chr[i++] = ch;
                    // printf("%c", ch);
                }
                //memo[flag] contains its parent
                memo[flag + 1] = add_node(memo[flag], chr);

            }
            flag = 0;
        }
        else if (ch == '\n')
        {
            is_newline = ch == '\n';
        }
        else
        {
            ++flag;
        }

    }
    //for debug purpose
    #if DEBUG 

    printf("flag : %d" , flag );
    printf("\n");
    disp_tree(&tree);
    disp_memo(memo);
    #endif

    //call the code generator function passing tree as parameter
    main_gen(&tree);
}

void gen_tree(const tree_t *ptr_tree);
void gen_header();
void prolog();
void gen_while();
void close_while();
void epilog();
void gen_case(int i, const char *s);
void gen_tree(const tree_t *ptr_tree);
void close_case();
void gen_tree_r(const node_t *root, int case_count, int level);




//sir code

// void gen_fn(const char *fname)
// {
//     printf("void fn_%s()\n", fname);
//     printf("{\n");
//     printf("	printf(\"%s\\n\");\n", fname);
//     printf("}\n");
// }

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
    printf("	scanf(\"%%d\", &opt);\n");
    printf("	while(opt)\n");
    printf("	{\n");
    printf("		switch(opt)\n");
    printf("		{\n");
}
void close_while()
{
    printf("		}\n"); // close switch
    printf("		scanf(\"%%d\", &opt);\n");
    printf("	}\n"); // close while
}
void epilog()
{

    printf("}\n");
}

void gen_case(int i, const char *s)
{
    printf("			case %d : \n", i);
    //printf("				printf(\"%s\\n\");\n", s);
    printf("				printf(\"%s\\n\");\n", s);
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

    // if(root)
    // {
    //     // for(int i = 0 ; i < level ; ++i)
    //     // {
    //     //     printf("\t");
    //     // }

    //     //printf("printf( \"%s\" )" ,root->key);

    // }
    // if left existes increase the level by one
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


void main_gen(tree_t *tree)
{
    gen_header();

    prolog();
    
    gen_tree(tree);

    epilog();
}

