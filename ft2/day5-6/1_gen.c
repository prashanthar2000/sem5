#include <stdio.h>
// gen switch case statement

void prolog()
{
	printf("#include <stdio.h>\n");
	printf("int main()\n");
	printf("{\n");
	printf("	int opt;\n");
	printf("	scanf(\"%%d\", &opt);\n");
	printf("	while(opt)\n");
	printf("	{\n");
	printf("		switch(opt)\n");
	printf("		{\n");
}
void epilog()
{
	printf("		}\n"); // close switch
	printf("		scanf(\"%%d\", &opt);\n");
	printf("	}\n"); // close while
	printf("}\n");
	
}

void gen_case(int i, const char* s)
{
	printf("			case %d : \n", i);
	printf("				printf(\"%s\\n\");\n", s);
	printf("				break;\n");
}

int main()
{
	prolog();
	int i = 1;
	char item[20];
	while(scanf("%s", item) != EOF)
	{
		gen_case(i, item);
		++i;
	}
	epilog();
}
