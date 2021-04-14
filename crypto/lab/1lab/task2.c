/*    task2.c   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define KEYSIZE 16

void main()
{
int i, j;
FILE *f;
char key[KEYSIZE];
int value1, value2;

// value1 :  output of date -d "2018-04-17 21:08:49" +%s
// value2 :  output of date -d "2018-04-17 23:08:49" +%s

value1 = 1524013729;
value2 = 1524020929;
//("%d  , %d \n", value1 , value2);

f = fopen("keys.txt","w");
for (j = value1; j <= value2; j++) {
srand (j);
for (i = 0; i< KEYSIZE; i++){
key[i] = rand()%256;
fprintf(f, "%.2x", (unsigned char)key[i]);
}
fprintf(f , "\n");
	}
}
