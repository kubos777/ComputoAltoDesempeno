#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
  double sum_local;
  int n=0, numprocs,myid,my_first,my_last,i;
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD,&myid);

//////////////////Rank = 0//////////////////////////////////////////////
if(myid==0){
printf("Número de rectángulos: ");
scanf("%d",&n);
}


}

