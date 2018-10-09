#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{

int filas = 5;
int columnas = 5;
int i,j;

int **MA;
int **MB;
int **MC;
//Reservando memoria

MA = (int **)malloc(filas*sizeof(int*));
MB = (int **)malloc(filas*sizeof(int*));
MC = (int **)malloc(filas*sizeof(int*));

for (i=0;filas;i++){
	MA[i] = (int*)malloc(columnas*sizeof(int));
	MB[i] = (int*)malloc(columnas*sizeof(int));
	MC[i] = (int*)malloc(columnas*sizeof(int));
}

	// Damos Valores a la Matriz 
	MA[0][0] = 1; 
	MA[0][1] = 2; 
	MA[0][2] = 3; 
	MA[0][3] = 4; 
	MA[0][4] = 5;

	MA[1][0] = 1; 
	MA[1][1] = 2; 
	MA[1][2] = 3; 
	MA[1][3] = 4; 
	MA[1][4] = 5;
	 
	MA[2][0] = 1; 
	MA[2][1] = 2; 
	MA[2][2] = 3; 
	MA[2][3] = 4; 
	MA[2][4] = 5;
	
	MA[3][0] = 1; 
	MA[3][1] = 2; 
	MA[3][2] = 3; 
	MA[3][3] = 4; 
	MA[3][4] = 5;

	MA[4][0] = 1; 
	MA[4][1] = 2; 
	MA[4][2] = 3; 
	MA[4][3] = 4; 
	MA[4][4] = 5;
	

//MA[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
//MB[5][5]={{9,8,7,6,5},{9,8,7,6,5},{9,8,7,6,5},{9,8,7,6,5},{9,8,7,6,5}};

int size,rank;

int offset,ren,renglones,extras;


MPI_Status status;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);

if (rank==0){
  ren=5/(size-1);
  extras=5%(size-1);
  offset=0;
	for(i=1;i<size;i++){
	 renglones=(i<=extras)?ren+1:ren;
	 MPI_Send(&offset,1,MPI_INT,i,3,MPI_COMM_WORLD);
	 MPI_Send(&renglones,1,MPI_INT,i,3,MPI_COMM_WORLD);
	 MPI_Send(&MB[offset][0],renglones*5,MPI_INT,i,3,MPI_COMM_WORLD);
	 offset+=renglones;
	}//for
	offset=0;
	for(i=1;i<size;i++){
	 renglones=(i<=extras)?ren+1:ren;
	 MPI_Send(&offset,1,MPI_INT,i,2,MPI_COMM_WORLD);
	 MPI_Send(&renglones,1,MPI_INT,i,2,MPI_COMM_WORLD);
	 MPI_Send(&MA[offset][0],renglones*5,MPI_INT,i,2,MPI_COMM_WORLD);
	 offset+=renglones;
	}//for


	for(i=1;i<size;i++){
	 MPI_Recv(&offset,1,MPI_INT,i,4,MPI_COMM_WORLD,&status);
	 MPI_Recv(&renglones,1,MPI_INT,i,5,MPI_COMM_WORLD,&status);
	 MPI_Recv(&MC[offset][0],renglones*5,MPI_INT,i,6,MPI_COMM_WORLD,&status);
	}//for


printf("\nSuma:\n");
	for(i=0;i<5;i++){
	 printf("\n");
		for(j=0;j<5;j++){
		 printf("MC[%d][%d]=%d \t",i,j,MC[i][j]);
		}//for j
	}//for i

}//if

else{
	MPI_Recv(&offset,1,MPI_INT,0,3,MPI_COMM_WORLD,&status);
	MPI_Recv(&renglones,1,MPI_INT,0,3,MPI_COMM_WORLD,&status);
	MPI_Recv(MA,renglones*5,MPI_INT,0,3,MPI_COMM_WORLD,&status);

	MPI_Recv(&offset,1,MPI_INT,0,2,MPI_COMM_WORLD,&status);
	MPI_Recv(&renglones,1,MPI_INT,0,2,MPI_COMM_WORLD,&status);
	MPI_Recv(MB,renglones*5,MPI_INT,0,2,MPI_COMM_WORLD,&status);

	 for(i=0;i<renglones;i++){

		for(j=0;j<5;j++){
		  MC[i][j]=MA[i][j]+MB[i][j];
		}//for j
	 }//for i
	MPI_Send(&offset,1,MPI_INT,0,4,MPI_COMM_WORLD);
	MPI_Send(&renglones,1,MPI_INT,0,5,MPI_COMM_WORLD);
	MPI_Send(MC,renglones*5,MPI_INT,0,6,MPI_COMM_WORLD);
 }//else


	MPI_Finalize();
	return 0;
}//main
