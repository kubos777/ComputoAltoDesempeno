#include <stdio.h>
#include <mpi.h> //Biblioteca para hacer uso de MPI

int main(int argc,char *argv[]){
	int size,rank,token = 0,i,n;
	int tag = 99,origen,destino;
	MPI_Status status; //Para el recieve
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	if(rank == 0){
		MPI_Send(&token,1,MPI_Init,1,tag,MPI_COMM_WORLD);
		MPI_Recv(&token,1,MPI_Init,size-1,tag,MPI_COMM_WORLD,&status);
	}
	if(rank != 0 && rank != (size-1)){
		MPI_Send(&token,1,MPI_Init,rank+1,tag,MPI_COMM_WORLD);
		MPI_Recv(&token,1,MPI_Init,rank-1,tag,MPI_COMM_WORLD,&status);
		//token+1
	}//rank != 0
	if(rank == size-1){
		MPI_Send(&token,1,MPI_Init,0,tag,MPI_COMM_WORLD);
		MPI_Recv(&token,1,MPI_Init,rank-1,tag,MPI_COMM_WORLD,&status);
	} //rank = size - 1

	MPI_Finalize();

	return 0;
}	//main
