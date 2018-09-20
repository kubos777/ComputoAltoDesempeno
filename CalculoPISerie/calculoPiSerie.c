#include <stdio.h>

//Fragmento de código serie

double f(double a){
	return (4.0/(1+(a*a)));
}

int main(int argc, char *argv[]){
	int n,i; //n es el número de rectángulos
	double PI25DT = 3.141592653589793238462643;
	double pi,h,sum,x; //h incremento de la base
	n = 100;  //100 rectángulos
	h = 1.0/(double)n;
	sum = 0.0;

for(i=1;i<=n;i++){
	x = h*((double)i-0.5);
	sum+=f(x);
}

pi = h*sum;
printf("\npi es aproximadamente %.16f, el error cometido es %16f\n", pi,fabs(pi-PI25DT));

}