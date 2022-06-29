/************************************************************************* \
*                              Group 8                                    *
*                             Assignment                                  *
* This program is about semaphore and mutex,here we use an mutex array,   *
* which is mutex[2] to represent two table and one semaphore initialed    *
* by 1.Because one table shoule be used by only one person.We will        *
* explain more in report                                                  *
\*************************************************************************/


/* 

   
*/
#include <pthread.h>
#include "tlpi_hdr.h"
#include <unistd.h>
#include <wait.h>
#include <semaphore.h>


static pthread_mutex_t mutex[2] = {PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER};
static sem_t semaphore;
static int customer[6]={1,2,3,4,5,6};
static int i=0;


/*In table 1,using mutex[0] to make sure that only one person could eat*/ 
static void *                  
table1(void *arg)
{
       pthread_mutex_lock(&mutex[0]);
	sem_wait(&semaphore);
	printf("No.%d customer is eating at table 1\n",customer[i]);
	i++;
	sleep(2);
	sem_post(&semaphore);
	pthread_mutex_unlock(&mutex[0]);
	
   return NULL;
}


/*In table 2,using mutex[1] to make sure that only one person could eat*/  
static void *
table2(void *arg)
{
	 pthread_mutex_lock(&mutex[1]);
	sem_wait(&semaphore);
	printf("No.%d customer is eating at table 2\n",customer[i]);
	i++;
	sleep(2);
	sem_post(&semaphore);
	pthread_mutex_unlock(&mutex[1]);
	return NULL;
}

/*************************************************************************\
*                                                                         *
*  In this part, I using system function to                               *
*                                                                         *
*                                                                         *
*                                                                         *
\*************************************************************************/
static void
printTitle()
{
system("echo Group 8\n");
system("echo NIE WENYU\tCST1909148\n");
system("echo CHEN NUO\tCST1909128\n");
system("echo YAO LAN\tCST1909161\n");
system("echo ZHANG WEI\tCST1909168\n");
system("echo ZHU QIJIN\tCST1909173\n");
printf("**********************************\n\t\tOutput\t\t\n");
}

/***************************************************************\
*                                                               *
* Semaphore is initial by 1, becasue when arrange one person to *
* one table, then wait(semaphore) and index i is added by 1,    *
* whcih means this program will arrange the next customer.      *
*                                                               *
****************************************************************/
int
main(int argc, char *argv[])
{
    pthread_t t[3];
	printTitle();
    sem_init(&semaphore,0,1);
	for(int i=0;i<3;i++)
	{
		pthread_create(&t[i],NULL,table1,NULL);
		pthread_create(&t[i],NULL,table2,NULL);
		pthread_join(t[i],NULL);
	}
	
    printf("\t\tEND\t\t\n**********************************\n");
    exit(EXIT_SUCCESS);
}
