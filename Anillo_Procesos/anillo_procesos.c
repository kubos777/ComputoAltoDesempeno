#include <stdio.h>
#include <mpi.h> //Biblioteca para hacer uso de MPI

int main(int argc,char *argv[]){
	int size,rank,token = 0,i,n;
	int tag = 99,origen,destino;
	MPI_STATUS status; //Para el recieve
	MPI_INIT(&arc,&argv);
	MPI_COMM_SIZE(MPI_COMM_WORLD,&size);
	MPI_COMM_RANK(MPI_COMM_WORLD,&rank);

	if(rank == 0){
		MPI_SEND(&token,1,MPI_INT,1,tag,MPI_COMM_WORLD);
		MPI_RECV(&token,1,MPI_INT,size-1,tag,MPI_COMM_WORLD,&status);
	}
	if(rank != 0 && rank != (size-1)){
		MPI_SEND(&token,MPI_INT,rank+1,tag,MPI_COMM_WORLD);
		MPI_RECV(&token,1,MPI_INT,rank-1,tag,MPI_COMM_WORLD,&status);
		//token+1
	}//rank != 0
	if(rank == size-1){
		MPI_SEND(&token,1,MPI_INT,0,tag,MPI_COMM_WORLD);
		MPI_RECV(&token,1,MPI_INT,rank-1,tag,MPI_COMM_WORLD,&status);
	} //rank = size - 1

	MPI_FINALIZE();

	return 0;
}	//main
