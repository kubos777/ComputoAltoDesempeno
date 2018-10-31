#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "omp.h"


int main(int argc, char* argv[]) 
{
  double *x, *y, *local_x, *local_y;
  int    res, n_local; 
  double  dot, local_dot,sum_local;
  int    inicio,size, rank, i, n=2;
  
  printf("Tamaño del vector %d\n",n);
    // scanf("%d", &n);
  x = (double *) calloc(n, sizeof(double));
  y = (double *) calloc(n, sizeof(double));
  //Llenado
  for (i=0; i<n; i++) 
  {
    x[i] = 1.0;  y[i] = 1.0;
  }
//Producto punto
#pragma omp parallalel for private(i) shared(sum_local) 
  for(i=inicio;i<n;i++){
    #pragma omp critical
    sum_local += x[i]*y[i];
  }
  printf("Inicio : %d, n : %d, sum_local : %.2f\n",inicio,n,sum_local);
  
  //printf("sum_local: %.2f, dot : %.2f\n",sum_local,dot);
  dot+=sum_local;
  
  printf("El producto punto es %.2f \n", dot);

  return 0;
}  
