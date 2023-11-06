#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void * multiplicacao(void *valor);

int main(int argc, char *argv[]) {
	pthread_t thread1, thread2;
	long valor1, valor2;

	printf("Digite valor 1: ");
	scanf("%ld", &valor1);
	printf("Digite valor 2: ");
	scanf("%ld", &valor2);


//	multiplicacao(( void *) &valor1);
//	multiplicacao(( void *) &valor1);
	
	pthread_create(&thread1, NULL, multiplicacao, (void*) &valor1);
	pthread_create(&thread2, NULL, multiplicacao, (void*) &valor2);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	return 0;
}

void *multiplicacao(void *add){
	long *num = (long*) (add);
	
	
	printf("\n\nTABUADA DE 100 DO NUMERO: %ld\n\n", *num);
	
	int i;
	for(i = 1;i <= 100; i++){
		printf("%ld - ", *num * i);
	}
	
	return NULL;
}
