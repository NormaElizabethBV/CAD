#include<stdio.h>
#include<stdlib.h>
#include <math.h>

#define n 1000

void llenaArreglo(int *a);
int buscaMaximo(int *a);

main(){

int max,*arreglo;


arreglo=(int *)malloc(sizeof(int)*n);

llenaArreglo(arreglo);
max=buscaMaximo(arreglo);

printf("El maximo es:%d",max);

}

void llenaArreglo(int *a){
 int i;
 for(i=0;i<n;i++)
   {
    a[i]=rand();
   //printf("%d\n", a[i]);
    }
}

int buscaMaximo(int *a){
  int max,i;
  max=a[0];
#pragma omp paralell
{
    #pragma omp for
   for(i=1;i<n;i++){
    if(a[i]>max)
	#pragma omp critical
	{	if(a[i]>max)
      		max=a[i];
   	}
     }
}

   return max;
}

