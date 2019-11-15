#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define n 5

int main(){
	int A[n][n],B[n],C[n],D[n],X,i,k;

	#pragma omp parallel num_threads(3) private(k)
	{
		#pragma omp for
		for(i=0;i<n;i++){
			for(k=0;k<n;k++){
				A[i][k] = (i*n)+k;
			}
			B[i]=i;
		}

		#pragma omp barrier //Termina el Llenado de A y B
		#pragma omp single
		printf("C=\n");
		#pragma omp for
		for(i=0;i<n;i++){
			for(k=0;k<n;k++){
				C[i]+= A[i][k] * B[k];
			}
			printf("%d\n",C[i]);
		}

		#pragma omp barrier //Termina el Calculo de C
		#pragma omp single
		printf("\nD=\n");
		#pragma omp for
		for(i=0;i<n;i++){
			for(k=0;k<n;k++){
				D[i]+= A[i][k] * C[k];
			}
			printf("%d\n",D[i]);
		}

		#pragma omp barrier //Termina el Calculo de D

		#pragma omp for
		for(i=0;i<n;i++){
			X+= C[i] * D[i];
		}
		#pragma omp single
		printf("\nX = %d\n",X);

		#pragma omp barrier //Termina el Calculo de D

	}
	printf("\n");
	return 0;
}
