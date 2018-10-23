#include <stdio.h>
#include <omp.h> //Para poder acceder a la función y setear el número de hilos

/*
Programa para dividir el número de iteraciones del ciclo for entre los hilos
*/

//Número de hilos generados
//int nth = omp_get_num_threads();
//Número de hilo
//int nth = omp_get_thread_num();

int main(){
	omp_set_num_threads(4);
	int i=3,tid,nth;
	//Pasamos como private el tid e i porque queremos que sean independientes
	//Se pasan por valor, no por referencia
	#pragma omp parallel private(tid,i)
	{
	printf("Hola mundo\n");
	tid = omp_get_thread_num();
	nth = omp_get_thread_num();
	#pragma omp for
	for(i=0;i<6;i++)
		printf("Número de iteración: %d\nNúmero de hilo: %d\nNúmero total de hilos: %d\n",i,tid,nth);
	}
	printf("¡Adiós!\n");
}