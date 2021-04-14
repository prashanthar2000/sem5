#include <stdio.h>
// gen function stubs
void gen_fn(const char* fname)
{
	printf("void fn_%s()\n", fname);
	printf("{\n");
	printf("	printf(\"%s\\n\");\n", fname);
	printf("}\n");
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
	printf("	int opt;\n");
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

void gen_case(int i, const char* s)
{
	printf("			case %d : \n", i);
	//printf("				printf(\"%s\\n\");\n", s);
	printf("				fn_%s();\n", s);
	printf("				break;\n");
}
#define MAX 5
int main()
{
	gen_header();
	char items[MAX][20]; int i;
	i = 0;
	while(scanf("%s", items[i]) != EOF)
	{
		gen_fn(items[i]);
		++i;
	}
	prolog();
	gen_while();
	int j = 0;
	//char item[20];
	while(j < i)
	{
		gen_case(j + 1, items[j] );
		++j;
	}
	close_while();
	epilog();
}
