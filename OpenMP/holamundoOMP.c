#include <stdio.h>
#include <omp.h> //Para poder acceder a la función y setear el número de hilos

int main(){
	omp_set_num_threads(4);
	int i=3;
	#pragma omp parallel
	{
	printf("Hola mundo\n");
	for(i=0;i<6;i++)
		printf("Iteración: %d\n",i);
	}

	printf("¡Adiós!\n");
}