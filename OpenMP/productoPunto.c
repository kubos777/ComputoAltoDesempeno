#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "omp.h"

double prod_punto(double* x,double* y,int N);

double prod_punto(double* x,double* y,int N){
   //Producto punto
  double dot,sum_local = 0.0;
  #pragma omp parallalel for private(i) shared(sum_local) 
  for(int i=0;i<N;i++){
    #pragma omp critical
    sum_local += x[i]*y[i];
  }
  printf("Inicio : 0, n : %d, sum_local : %.2f\n",N,sum_local);
  
  //printf("sum_local: %.2f, dot : %.2f\n",sum_local,dot);
  dot+=sum_local;
  
  //printf("El producto punto es %.2f \n", dot);
 return dot;
}
int main(int argc, char* argv[]) 
{
  double *x, *y,producto_punto;
  int    res, n,i;
  printf("Ingresa el tamaño del vector: \n");
  scanf("%d", &n);
  x = (double *) calloc(n, sizeof(double));
  y = (double *) calloc(n, sizeof(double));
  //Llenado
  for (i=0; i<n; i++) 
  {
    x[i] = 1.0;  y[i] = 3.0;
  }
 producto_punto = prod_punto(x,y,n);
printf("El producto punto es: %f\n",producto_punto);  
return 0;


}
