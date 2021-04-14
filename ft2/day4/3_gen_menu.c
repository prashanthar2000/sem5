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
#define SIZE 5
int main()
{
	
	pre_amble();
	prolog();
	printf("\tint opt;\n");
	char item[SIZE][20];
	int i = 0;
	while(scanf("%s", item[i]) != EOF)
	{
		++i;
	}
	
	{
		printf("\tscanf(\"%%d\", &opt);\n");
		printf("\tswitch(opt)\n");
		printf("\t{\n");
		for(int j = 1; j <= i; ++j)
		{
			printf("\t\tcase %d : \n", j);
			printf("\t\t\tprintf(\"%s\\n\");\n", item[j-1]);
			printf("\t\t\tbreak;\n");
		}
		
		
		printf("\t}\n");
	}
	disp_str("hello world");
	epilog();
}
