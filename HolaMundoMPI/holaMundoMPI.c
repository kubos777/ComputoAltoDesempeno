#include <mpi.h> //Biblioteca de MPI
#include <stdio.h>
int main(int argc, char *argv[]){
	int rank,size; 
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	printf("Hola desde el proceso %d de %d\n",rank,size);
	MPI_Finalize();
}//Main
