#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int main(){
	int i;
	int max;
	//int a[SIZE]={1,2,3,4,5,6,7,8,9,0};
	int a[SIZE];
	
	for (i=0;i<SIZE;i++){
	a[i]=rand()%5;
	printf("%d\n",a[i]);
}	
	max = a[0];
	#pragma omp parallel for
	for(i=1;i<SIZE;i++){
		if(a[i]>max){
		#pragma omp critical
		{
			if(a[i]>max){
				max= a[i];
					}		
				}
			}
		}
	printf("El valor máximo es: %d\n",max);
	
}