/*   task5.c   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define KEYSIZE 16

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define KEYSIZE 16

void main()
{
printf("PES1201800410  Prashanth A R\n");
int i;
FILE *random;
unsigned char *key = (unsigned char *) malloc (sizeof (unsigned char) * KEYSIZE);
random = fopen("/dev/urandom", "r");
for (i = 0; i< KEYSIZE; i++)
{
     		fread(key, sizeof(unsigned char) * KEYSIZE, 1, random);
       	   	printf("%.2x", *key);
}
printf("\n");
fclose(random);
}
