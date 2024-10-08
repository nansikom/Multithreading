#include <pthread.h>
#include <stdio.h>




pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;
int myCount = 0;
pthread_cond_t myCond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t myCond2 = PTHREAD_COND_INITIALIZER;
int iter= 0;
int maxiter= 10; 
//int buffer;
//points to the variable in which the variable of the new thread is written into
// int pthread_create( pthread_t* thread,
// // points to the thread attribute struct that has the flags
// const pthread_attr_t* attr,
// // points to the function that will be the start point of the thread execution for the new thread.
// void* (*start_routine) (void *),
// //points to the arguments that will be passed to start routine and if you have many arguments jst pass in a struct instead.
// void* arg 
// );

// while (1)
// {
// pthread_mutex_lock(&mutex); // Lock the mutex before checking if the buffer has data
// while (count == 0) // Buffer is empty. Wait for signal that the buffer has data
// pthread_cond_wait(&has_data, &mutex);
// value = get_item(); // There's an item, get it! This will decrement int count
// pthread_mutex_unlock(&mutex); // Unlock the mutex
// pthread_cond_signal(&space_available); // Signal that the buffer has space
// }
void *consumerThread(void *arg);
/*
mymutex
special variable to make sure only one thread can access certain parts of code at a time.
Can also be used to lock certain areas and parts of code.
conditio 1 and 2 .
flags.to show if a condition is met by printing while another is just going to be doing the waiting of the other till  a 
condition is met.
show when locking and unlocking of a mutex.
*/
int main(){
    
printf("PROGRAM START\n");
pthread_t consumer;
pthread_create( &consumer, NULL, consumerThread, NULL );
printf("CONSUMER THREAD CREATED\n");

while (iter < maxiter)
{
pthread_mutex_lock(&myMutex); // Lock the mutex before checking if the buffer has data
printf("PRODUCER: myMutex locked \n");
// this is to show our buffer is completely and if it is full signal the consumer to take the item and consume it if it 
//does it will eat it and then create space.
// bufffer is completely full.
while (myCount == 10){ // Buffer is full; Wait for signal that space is available
printf("PRODUCER: waiting  for myCond1 \n");
pthread_cond_wait(&myCond1, &myMutex);
}
printf("PRODUCER: myCount %d -> %d \n", myCount, myCount + 1); // Space is free, add an item! This will increment int count
myCount++;
iter++;
printf("PRODUCER: signaling my Cond1\n");
pthread_cond_signal(&myCond2); // Signal consumer that the buffer is no longer empty

pthread_mutex_unlock(&myMutex); // Unlock the mutex
printf("PRODUCER: MyMutex unlocked \n");
//pthread_cond_signal(&myCond2); // Signal consumer that the buffer is no longer empty
}
pthread_join(consumer, NULL);
printf("PROGRAM END\n");
return 0;
}


void *consumerThread(void *arg){
//pthread_mutex_lock(&myMutex);
//printf("CONSUMER THREAD CREATED\n");
while (iter < maxiter)
{
pthread_mutex_lock(&myMutex); // Lock the mutex before checking if the buffer has data
printf("CONSUMER: myMutex locked \n");
while  (myCount ==0) {// Buffer is full; Wait for signal that space is available
printf("CONSUMER: waiting for myCond2 \n");
pthread_cond_wait(&myCond2, &myMutex);
}
printf("CONSUMER: myCount %d -> %d \n", myCount, myCount - 1); // Space is free, add an item! This will increment int count
myCount--;
iter++;
printf("CONSUMER: signaling myCond2 \n");
pthread_cond_signal(&myCond1); // Signal consumer that the buffer is no longer empty

pthread_mutex_unlock(&myMutex); // Unlock the mutex
printf("CONSUMER: myMutexunlocked \n");
//pthread_cond_signal(&myCond1); // Signal consumer that the buffer is no longer empty
}
return NULL;
}


