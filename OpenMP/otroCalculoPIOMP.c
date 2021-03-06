#include <stdio.h>
#include <omp.h>
static long num_steps = 100000;double step;
#define NUM_THREADS 2

void main(){
	double empezar,terminar;
	int i;double x,pi,sum = 0.0;
	step = 1.0/(double) num_steps;
	omp_set_num_threads(NUM_THREADS);
	empezar = omp_get_wtime();
	#pragma omp parallel for reduction(+:sum) private(x)
	for(i=1;i<=num_steps;i++){
		x = (i-0.5)*step;
		sum = sum + 4.0/(1.0+x*x);
	}
	terminar = omp_get_wtime();
	printf("Empezar: %1f [milisegundos]\n", empezar );
	printf("Terminar: %1f [milisegundos]\n",terminar );
	printf("Tiempo %1f [milisegundos]\n",terminar-empezar );
	pi = step*sum;
}

