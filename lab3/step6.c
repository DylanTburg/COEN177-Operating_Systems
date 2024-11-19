/*
 * # Name: Dylan Thornburg
 * # Date: 10-8-2024
 * # Title: Lab3 - step6
 * # Description: Copying and running the step 6 code.
 */


/**************************
* COEN177: Threads *
**************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *go(void *);
#define NTHREADS 10
pthread_t threads[NTHREADS];
int main() 
{
	int i;
	for (i = 0; i < NTHREADS; i++)
		pthread_create(&threads[i], NULL, go, &i);
	for (i = 0; i < NTHREADS; i++) 
	{
		printf("Thread %d returned\n", i);
		pthread_join(threads[i],NULL);
	}
	printf("Main thread done.\n");
	return 0;
}
void *go(void *arg) 
{
	printf("Hello from thread %ld with iteration %d\n", (long)pthread_self(), *(int*)arg);
	return 0;	
}
