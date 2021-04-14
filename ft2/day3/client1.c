#include <stdio.h>

int main()
{
	char ch; int is_newline = 1; // ???
	while((ch = getchar()) != EOF)
	{
		if(ch != ' ')
		{
			if(is_newline)
			{
				printf("parent : %c\n", ch);
			}
			else if(ch != '\n')
			{
				printf("\tchild : %c\n", ch);
			}
		}
		is_newline = ch == '\n';
		//putchar(ch);
	}
}
