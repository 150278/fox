/*#define_XOPEN_SOURCE 600

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<syd/types.h>
#include<errno.h>
#include<unistd.h>
#include<bit/types.h>



static pthread_spinlock_t spinlock;

volatile int slock;


void *spinloackThread(void *i)
{
int rc;
int count=0;

printf("Entererd thread %d, getting spin lock\n",(int *)i);


rc=pthread_spin_lock(&spinlock);


printf("%d thread completr\n",(int *)i);

return NULL;
}

int main()
{


int rc=0;
pthread_t thread,thread1;

if(pthread_spin_init(&spinlock,PTHREAD_PROCESS_PRIVATE)!=0)
perror("init");


printf("Main, create ythe spin lock thread\n");
sleep(10);
printf("Main, now unlock the spin lock\n");


rc=pthread_spin_unlock(&spinlock);
if(rc==0)
printf("\n main thread succ")




*/






#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>



static pthread_spinlock_t spinlock;
volatile int slock;



void *spinlockthread(void *t)
{
int rc;
int count=0;



printf("Entered thread: %d, getting spinlock\n",(int *)t);



rc = pthread_spin_lock(&spinlock);



printf("%d: thread unlock the spinlock\n",(int *)t);
pthread_spin_unlock(&spinlock);



printf("%d: thread complete\n",(int *)t);
return NULL;
}



int main()
{
int rc;
pthread_t tid;



if(pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE) != 0)
perror("error\n");

printf("Main: Entering spin lock\n");
pthread_spin_lock(&spinlock);



printf("Main: Creating thread\n");
pthread_create(&tid, NULL, spinlockthread, (int *)1);



sleep(5);



printf("Main: unlocking main thread\n");
rc=pthread_spin_unlock(&spinlock);



if(rc == 0)
printf("Thread unlocked successfully\n");
else
printf("Thread unlocked failes\n");



printf("Main: wait for thread to end\n");
pthread_join(tid, NULL);



printf("Main completed\n");



return 0;
}
