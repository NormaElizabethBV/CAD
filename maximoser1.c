#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include<omp.h>

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
  int max[10],i,maxi,nth,id;
  max[id]=0;
#pragma omp paralell private(max,id)
{
	id=omp_get_thread_num();
	nth=omp_get_num_threads();
    #pragma omp for
   for(i=1;i<n;i++){
    if(a[i]>max)
	if(a[i]>max)
      	max[id]=a[id];
}

	if(id==0){
	maxi=max[0];
	for(i=1;i<nth;i++){
	  if(max[i]>maxi)
		if(a[i]>max)
	      	maxi=max[i];

}
}
}

   return max;
}

