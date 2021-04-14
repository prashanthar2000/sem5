 
/*   task1.c    */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define KEYSIZE 16

void timestamp()
{
    time_t ltime; /* calendar time */
    ltime=time(NULL); /* get current cal time */
    printf("%s",asctime( localtime(&ltime) ) );
}

void main()
{
printf("PES1201800410 -- PRASHANTH ");
timestamp();
//printf("\n");
int i;
char key[KEYSIZE];
printf("%lld\n", (long long) time(NULL));
srand (time(NULL)); 
for (i = 0; i< KEYSIZE; i++){
key[i] = rand()%256;
printf("%.2x", (unsigned char)key[i]);
}
printf("\n");
}

