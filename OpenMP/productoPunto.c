#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "omp.h"


int main(int argc, char* argv[]) 
{
  double *x, *y, *local_x, *local_y;
  int    res, n_local; 
  double  dot, local_dot,sum_local;
  int    inicio,size, rank, i, n=10000;
  
  my_first = myid * n/numprocs;
  my_last = (myid) * n/numprocs;

///////////////// Rank = 0 ////////////////////////////////////////////  
  if (rank == 0) {
    printf("Tamaño del vector %d",n);
    // scanf("%d", &n);
    x = (double *) calloc(n, sizeof(double));
    y = (double *) calloc(n, sizeof(double));
    for (i=0; i<n; i++) 
    {
      x[i] = 1.0;  y[i] = 1.0;
    }
    }
  //////////////////// Todos //////////////////////////////////////////
  n_local = n/size;
  local_x = (double *) calloc(n_local, sizeof(double));
  local_y = (double *) calloc(n_local, sizeof(double));
  
  local_dot = 0.0;

  for (i = 0; i < n_local; i++){
    local_dot += local_x[i] * local_y[i];
  }
  free(local_x);
  free(local_y); 
  //////////////////////////Rank = 0 //////////////////////////////////
  if (rank==0){
  res=n%size;
  printf("residuo: %d\n",res);
  
  if(res != 0)
    {
      sum_local=0.0;
      inicio=(size)*(n/size);
      
    for(i=inicio;i<n;i++)
    {
      sum_local += x[i]*y[i];
      }
        printf("inicio : %d, n : %d, sum_local : %.2f\n",inicio,n,sum_local);
    }
  else sum_local=0.0;
  
  }
 /////////////////  Todos  ////////////////////////////////////////////   

  //////////////////  Rank = 0 ////////////////////////////////////////
  if (rank == 0){
    printf("sum_local: %.2f, dot : %.2f\n",sum_local,dot);
    dot+=sum_local;
    printf("El producto punto es %.2f \n", dot);
    
  }
 ///////////////////  Todos  /////////////////////////////////////////// 

 return 0;
}  
