#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<limits.h>
#include<pthread.h>
#include<semaphore.h>

sem_t forks[5];
sem_t bowl;

void* p1(){
	sem_wait(&forks[1]);
	printf("philosopher 1 got fork 1\n");
	sem_wait(&forks[0]);
	printf("philosopher 1 got fork 0\n");
	sem_wait(&bowl);
	printf("philosopher 1 got a bowl\n");
  	//critical section
  	printf("Philosopher 1 is eating!\n");
    sleep(1);
    printf("Philosopher 1 has finished eating!\n");
    //signal
    sem_post(&bowl);
    printf("philosopher 1 released a bowl\n");
    sem_post(&forks[1]);
    printf("philosopher 1 released fork 1\n");
    sem_post(&forks[0]);
    printf("philosopher 1 released fork 0\n");
	return NULL; 
}

void* p2(){
	sem_wait(&forks[1]);
	printf("philosopher 2 got fork 1\n");
	sem_wait(&forks[2]);
	printf("philosopher 2 got fork 2\n");
	sem_wait(&bowl);
	printf("philosopher 2 got a bowl\n");
    //critical section
    printf("Philosopher 2 is eating!\n");
    sleep(1);
    printf("Philosopher 2 has finished eating!\n");    
    //signal
    sem_post(&bowl);
    printf("philosopher 2 released a bowl\n");
    sem_post(&forks[1]);
    printf("philosopher 2 released fork 1\n");
    sem_post(&forks[2]);
    printf("philosopher 2 released fork 2\n");
	return NULL; 
}

void* p3(){
	sem_wait(&forks[3]); 
	printf("philosopher 3 got fork 3\n");
	sem_wait(&forks[2]);
	printf("philosopher 3 got fork 2\n");
	sem_wait(&bowl);
	printf("philosopher 3 got a bowl\n");
    //critical section
    printf("Philosopher 3 is eating!\n");
    sleep(1);
    printf("Philosopher 3 has finished eating!\n");     
    //signal
    sem_post(&bowl);
    printf("philosopher 3 released a bowl\n");
    sem_post(&forks[3]);
    printf("philosopher 3 released fork 3\n");
    sem_post(&forks[2]);
    printf("philosopher 3 released fork 2\n");
	return NULL; 
}

void* p4(){
	sem_wait(&forks[3]);
	printf("philosopher 4 got fork 3\n");
	sem_wait(&forks[4]);
	printf("philosopher 4 got fork 4\n");
	sem_wait(&bowl);
	printf("philosopher 4 got a bowl\n");
    //critical section
    printf("Philosopher 4 is eating!\n");
    sleep(1);
    printf("Philosopher 4 has finished eating!\n");  
    //signal
    sem_post(&bowl);
    printf("philosopher 4 released a bowl\n");
    sem_post(&forks[3]);
    printf("philosopher 4 released fork 3\n");
    sem_post(&forks[4]);
    printf("philosopher 4 released fork 4\n");
	return NULL; 
}

void* p5(){
	sem_wait(&forks[4]);
	printf("philosopher 5 got fork 4\n");
	sem_wait(&forks[0]);
	printf("philosopher 5 got fork 0\n");
	sem_wait(&bowl);
    //critical section
    printf("Philosopher 5 is eating!\n");
    sleep(1);
    printf("Philosopher 5 has finished eating!\n");   
    //signal
    sem_post(&bowl);
    printf("philosopher 5 released a bowl\n");
    sem_post(&forks[4]);
    printf("philosopher 5 released fork 4\n");
	sem_post(&forks[0]);
	printf("philosopher 5 released fork 0\n");
	return NULL; 
}

int main(){
while(1){
    printf("Philosopher 1 is thinking\n");
    printf("Philosopher 2 is thinking\n");
    printf("Philosopher 3 is thinking\n");
    printf("Philosopher 4 is thinking\n");
    printf("Philosopher 5 is thinking\n");
	sem_init(&bowl,0,2);
	sem_init(&forks[0], 0, 1);
	sem_init(&forks[1], 0, 1);
	sem_init(&forks[2], 0, 1);
	sem_init(&forks[3], 0, 1);
	sem_init(&forks[4], 0, 1);
	pthread_t thread1 , thread2 , thread3 , thread4 , thread5;
	pthread_create(&thread1 , NULL , p1 , NULL);  
	pthread_create(&thread2 , NULL , p2 , NULL); 
	pthread_create(&thread3 , NULL , p3 , NULL); 
	pthread_create(&thread4 , NULL , p4 , NULL); 
	pthread_create(&thread5 , NULL , p5 , NULL); 
	pthread_join(thread1 , NULL);
	pthread_join(thread2 , NULL); 
	pthread_join(thread3 , NULL); 
	pthread_join(thread4 , NULL); 
	pthread_join(thread5 , NULL); 	 
	sem_destroy(&forks[0]); 
	sem_destroy(&forks[1]); 
	sem_destroy(&forks[2]); 
	sem_destroy(&forks[3]);  
	sem_destroy(&forks[4]); 
	sem_destroy(&bowl);
    printf("\n");
}
	return 0;
}
