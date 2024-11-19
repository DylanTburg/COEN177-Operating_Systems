/*
 * Name: Dylan Thornburg
 * Date: 10-22-2024
 * Title: lab5 - step1
 * Description: Just copying and running the given code
 */

// Thread Sychronization
//To compile this code:
//If using the SCU Linux lab first add #include<fcntl.h>
//Then you're ready to compile.
//To compile just add -lpthread to your gcc command like:
//gcc threadSync.c -lpthread
//gcc threadSync.c -o test -lpthread

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 

#define NTHREADS 10
pthread_t threads[NTHREADS];
sem_t *mutex; 

void* go(void* arg) 
{ 
	sem_wait(mutex); //entry section
  	printf("Thread %d Entered Critical Section..\n", (intptr_t)arg); //critical section; changed from (int) to (intptr_t) to avoid warning 
   	sleep(1); 
  	sem_post(mutex); //exit section 
  	return (NULL);
} 

int main() 
{ 
	mutex = sem_open("mutex", O_CREAT, 0644, 1);
	static int i;
	for (i = 0; i < NTHREADS; i++)  
	   	pthread_create(&threads[i], NULL, go, (void *)(intptr_t)i); //change from (size_t) to (intptr_t) to avoid warning
	for (i = 0; i < NTHREADS; i++) 
	{
		pthread_join(threads[i],NULL);
		printf("\t\t\tThread %d returned \n", i);
	}
	printf("Main thread done.\n");
	sem_unlink("mutex"); 
	return 0; 
} 
