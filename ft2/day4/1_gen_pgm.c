/* write a program to generate a program */
#if 0
#include <stdio.h>

int main()
{
	printf("hello world\n");
}
#endif


#include <stdio.h>
void pre_amble()
{
	printf("#include <stdio.h>\n");
}

void prolog()
{
	printf("\nint main()\n");
	printf("{\n");
}

void epilog()
{
	printf("}\n");
}

void disp_str(const char* s)
{
	printf("\tprintf(\"%s\\n\");\n", s);
}

int main()
{
	pre_amble();
	prolog();
	disp_str("hello world");
	epilog();
}
