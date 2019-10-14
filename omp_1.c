#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

 int main()

{
	//omp_set_num_threads(5);
	
	int i=5; //Compartidas
	
	#pragma omp parallel num_threads(5) //Clausula
	{
		int i=5; //Variable privada, cuando sale no la reconocen funciones externas

		printf("Hola Mundo :) \n");
		i=i+1;
		printf("%d \n",i);

	}
		printf("%d \n",i);
		return 0;
} 


//Compilar como -fopenmp archivo.c -o h
// Ejecutar como ./h

//export OMP_NUM_THREADS=4 

//www.openmp.org
