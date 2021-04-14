#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"

int main()
{
	char ch; int is_newline = 1; // ??? 
	char parent;
	tree_t t;
	//assert(check_root(&t));
	init_tree(&t);
	assert(check_root(&t));
	//exit(0);
	while((ch = getchar()) != EOF)
	{
		if(ch != ' ')
		{
			if(is_newline)
			{
				printf("parent : %c\n", ch); 
				parent = ch;
				add_node(&t, parent, ' ');
				break;
			}
			else if(ch != '\n')
			{
				//printf("\tchild : %c\n", ch);
				add_node(&t, parent, ch);
			}
		}
		is_newline = ch == '\n';
		//putchar(ch);
	}
	disp_tree(&t);
}
