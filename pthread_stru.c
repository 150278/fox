#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<pthread.h>
//#include<>

struct my_thread
{
int thread_id;
char mesg[100];

};



void *printHello (void *threadobj)
{
pthread_t thread_ID;

struct my_thread *t1;
t1=( struct my_thread  *) threadobj;


thread_ID=pthread_self();
printf("\n thread ID : %u",thread_ID);

printf("\n %d  thread message %s\n",t1->thread_id,t1->mesg);

}


int main()
{
pthread_t thread2,thread3,thread4,thread_ID;

int rc;

struct my_thread t2,t3,t4;

t4.thread_id=4;

strcpy(t4.mesg,"I am forth thread\n");

t2.thread_id=2;
strcpy(t3.mesg,"I am thrird thread\n");

thread_ID=pthread_self();


printf("\n MAIN Thread ID:%u",thread_ID);


pthread_create(&thread4,NULL,printHello,(void *)&t4);
pthread_create(&thread2,NULL,printHello,(void *)&t2);
pthread_create(&thread3,NULL,printHello,(void *)&t3);


printf("\n Exit from main thread\n");

pthread_exit(NULL);

}











/*

output



 gcc *pthread_stru.c -o test -lpthread
pthread_stru.c: In function ‘printHello’:
pthread_stru.c:25:25: warning: format ‘%u’ expects argument of type ‘unsigned int’, but argument 2 has type ‘pthread_t {aka long unsigned int}’ [-Wformat=]
 printf("\n thread ID : %u",thread_ID);
                        ~^
                        %lu
pthread_stru.c: In function ‘main’:
pthread_stru.c:50:28: warning: format ‘%u’ expects argument of type ‘unsigned int’, but argument 2 has type ‘pthread_t {aka long unsigned int}’ [-Wformat=]
 printf("\n MAIN Thread ID:%u",thread_ID);
                           ~^
                           %lu
abhishek@Abhishek:~/pro_c$ ./test

 MAIN Thread ID:2380855104
 thread ID : 2372327168
 thread ID : 2355541760
 Exit from main thread

 thread ID : 2363934464
 2  thread message 

 4  thread message I am forth thread


 -1920854393  thread message I am thrird thread
*/
