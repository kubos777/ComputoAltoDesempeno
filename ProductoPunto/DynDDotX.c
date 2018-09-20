#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
	double sum, sum_local;
	//double a[1000],b[1000];
	double *a,*b;
	int n=0, numprocs,myid,my_first,my_last,i;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD,&myid);

//////////////////Rank = 0//////////////////////////////////////////////
if(myid==0){
printf("Tamaño del Vector: ");
scanf("%d",&n);
}

///////////////// Todos ////////////////////////////////////////////////
    MPI_Bcast(&n,1,MPI_DOUBLE, 0, MPI_COMM_WORLD);
    a=(double *)malloc(n*sizeof(double));
	b=(double *)calloc(n,sizeof(double));
/////////////////Rank = 0///////////////////////////////////////////////
	
	if(myid==0){
		
		
				for(i=0;i<n;i++){
					//a[i]=i*0.5;
					//b[i]=i*2.0;
					a[i]=1;
					b[i]=1;
					
				}
				
		}
///////////////// Todos ////////////////////////////////////////////////
	
	sum_local=0;
	
	MPI_Bcast(a,n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	MPI_Bcast(b,n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	
	my_first=myid * n/numprocs;
	my_last=(myid+1)* n/numprocs;
///////////////////Menores a size//////////////////////////////////////	
	if(myid<=numprocs-2){

		for(i=my_first;i<my_last;i++)
		{
			sum_local+=a[i]*b[i];
		}
        printf("++numprocs = %d, rank= %d, numprocs-2 %d Soy %d :Suma= %.2f my_first->%d my_last-> %d\n",numprocs,myid,numprocs-2,myid,sum_local,my_first,my_last);
	 }
/////////////////////////El último///////////////////////////////////////
    if (myid==numprocs-1){
		for(i=my_first;i<n;i++)
		{
			sum_local+=a[i]*b[i];
		}
		
		printf("--Soy %d de %d :Suma= %.2f\n",myid,numprocs,sum_local);
	     
	}
	
///////////////////////// Todos ///////////////////////////////////////
    MPI_Barrier(MPI_COMM_WORLD); 
	MPI_Reduce(&sum_local,&sum,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
///////////////////////// Rank = 0 ///////////////////////////////////
	
	if(myid==0) printf("sum = %.2f\n",sum);
    free(a);
	free(b);   
       
MPI_Finalize();
return 0;
}

