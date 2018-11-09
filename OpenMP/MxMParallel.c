#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
int a[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
int b[5][2]={{2,2},{2,2},{2,2},{2,2},{2,2}};
int c[5][2]={{0,0},{0,0},{0,0},{0,0},{0,0}};
double inicio,fin;
int i,j,k;
//Impresión
for(i=0;i<5;i++){
	printf("\n");
	for(j=0;j<5;j++){
	printf(" a[%d][%d]=%d \t",i,j,a[i][j]);
	}
}
inicio = omp_get_wtime();
printf("\n"); 
#pragma omp parallel for private(j,k)
for (i=0;i<5;i++){
 	for(j=0;j<2;j++){
	  for(k=0;k<5;k++){
	c[i][j]+=a[i][k]*b[k][j];
	}
    }
}
fin = omp_get_wtime();
//Impresión
for(i=0;i<5;i++){
printf("\n");
	for(j=0;j<2;j++){
	printf("c[%d][%d]=%d\t",i,j,c[i][j]);
	}
}
printf("\n\t\t\t\tInicio: %15f [seg]\n", inicio/1000.00);
printf("\t\t\t\tFin: %15f [seg]\n",fin/1000.00);
printf("\t\t\t\tTiempo total %1f [milisegundos]\n",fin-inicio);
return 0;
}