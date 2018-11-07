#include <math.h>
#include <stdio.h>
#include <omp.h>
int main(int argc, char *argv[])
{
    int n,i;
    printf("Introzca la precisión para calcular PI (n > 0): \n");
    scanf("%d",&n);
    double PI25DT = 3.141592653589793238462643;
    double h = 1.0 / (double) n;
    double sum = 0.0;
 
    #pragma omp parallel for shared( sum )
    for (i=1; i <= n; i++) {
        double x = h * ((double)i - 0.5);
        sum += (4.0 / (1.0 + x*x));
    }
 
    double pi = sum * h;

    printf("El valor aproximado de PI es: %f  con un error de %f\n",pi,fabs(pi -
PI25DT));
    
    return 0;
}