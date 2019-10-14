#include<stdio.h>
#include<stdlib.h>

 int main()

{
	#pragma omp parallel
	{

		printf("Hola Mundo \n");

	}
		return 0;
} 
