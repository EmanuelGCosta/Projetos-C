#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>

char condicao[2][8] = { "fechado", "aberto" };

pthread_mutex_t mutex;

void *semaforo1();
void *semaforo2();


int main() {
	pthread_t thread1, thread2;
	pthread_mutex_init(&mutex, NULL);
    
	while(1){
		pthread_create(&thread1, NULL, semaforo1, NULL);	
		pthread_create(&thread2, NULL, semaforo2, NULL);
	
		pthread_join(thread1, NULL);
		pthread_join(thread2, NULL);	
	}

	
    	return 0;
}

void *semaforo1(){

	pthread_mutex_lock(&mutex);
    
	printf("Semaforo 1: %s\n", condicao[0]);
	printf("Semaforo 2: %s\n", condicao[1]);
	printf("Semaforo 3: %s\n", condicao[0]);
	printf("Semaforo 4: %s\n\n\n", condicao[1]);
	sleep(3);
	
	pthread_mutex_unlock(&mutex);

	
	return NULL;
}

void *semaforo2(){
	
	pthread_mutex_lock(&mutex);
    
	printf("Semaforo 1: %s\n", condicao[1]);
	printf("Semaforo 2: %s\n", condicao[0]);
	printf("Semaforo 3: %s\n", condicao[1]);
	printf("Semaforo 4: %s\n\n\n", condicao[0]);
	sleep(3);

	pthread_mutex_unlock(&mutex);

	
	return NULL;
}
