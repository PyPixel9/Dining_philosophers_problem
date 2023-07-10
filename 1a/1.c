//13 24 5

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<limits.h>
#include<pthread.h>
#include<semaphore.h>


void* p1(){
  	printf("Philosopher 1 is eating!\n");
    printf("Philosopher 1 has finished eating!\n");
	return NULL; 
}

void* p2(){
    printf("Philosopher 2 is eating!\n");
    printf("Philosopher 2 has finished eating!\n");    
	return NULL; 
}

void* p3(){
    printf("Philosopher 3 is eating!\n");
    printf("Philosopher 3 has finished eating!\n");     
	return NULL; 
}

void* p4(){
    printf("Philosopher 4 is eating!\n");
    printf("Philosopher 4 has finished eating!\n");  
	return NULL; 
}

void* p5(){
    printf("Philosopher 5 is eating!\n");
    printf("Philosopher 5 has finished eating!\n");   
	return NULL; 
}

int main(){
    while(1){
        pthread_t thread1 , thread2 , thread3 , thread4 , thread5;
        printf("Philosopher 1 is thinking\n");
        printf("Philosopher 2 is thinking\n");
        printf("Philosopher 3 is thinking\n");
        printf("Philosopher 4 is thinking\n");
        printf("Philosopher 5 is thinking\n");
        pthread_create(&thread1 , NULL , p1 , NULL);
        pthread_create(&thread3 , NULL , p3 , NULL);
        pthread_join(thread1 , NULL);
        pthread_join(thread3 , NULL);
        pthread_create(&thread2 , NULL , p2 , NULL);
        pthread_create(&thread4 , NULL , p4 , NULL);
        pthread_join(thread2 , NULL);
        pthread_join(thread4 , NULL);
        pthread_create(&thread5 , NULL , p5 , NULL);
        pthread_join(thread5 , NULL);
        printf("\n");
    }
	return 0;
}
