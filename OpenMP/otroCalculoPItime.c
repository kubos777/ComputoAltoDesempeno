#include <stdio.h>
#include <omp.h>
#include <time.h>

static long num_steps = 100000;double step;
#define NUM_THREADS 2

void main(){
	double tiempo_total;
 	clock_t inicio, fin;
	int i;double x,pi,sum = 0.0;
	step = 1.0/(double) num_steps;
	omp_set_num_threads(NUM_THREADS);
	
	inicio = clock(); //Inicia el conteo
	
	#pragma omp parallel for reduction(+:sum) private(x)
	for(i=1;i<=num_steps;i++){
		x = (i-0.5)*step;
		sum = sum + 4.0/(1.0+x*x);
	}
	
	fin = clock(); //Termina medición
	
	printf("Tiempo total %1f [milisegundos]\n",(double)(fin-inicio)/1000 );
	pi = step*sum;
}