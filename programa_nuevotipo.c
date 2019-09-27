#include<stdio.h>
#include<stdlib.h>
#include<mpi.h> 
#include<math.h>
 

#define N 10
#define count 4
#define longBloque 4


int main(int argc, char *argv[])
{
 
	int A[N][N];
	int id,i,j;
	MPI_Status estado;
	MPI_Datatype nuevo_tipo;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&id);
	
	MPI_Type_vector(count,longBloque,N,MPI_INT,&nuevo_tipo);
	MPI_Type_commit(&nuevo_tipo);

	
	if(id==0)
	{
		for(i=0;i<N;i++)
		{	
			for(j=0;j<N;j++)
			{			
				A[i][j]=i;
				printf("%d \t",A[i][j]);
			}
		printf("\n");
		}
		MPI_Send(&A[0][2],1,nuevo_tipo,1,0,MPI_COMM_WORLD);
	}
	
	else
		if(id==1)
		{
			MPI_Recv(&A[0][0],1,nuevo_tipo,0,0,MPI_COMM_WORLD,&estado);
			
			for(i=0;i<count;i++)
			{
				for(j=0;j<count;j++)
				{
					printf("%d",A[i][j]);
				}
			printf("\n");
			}
		}

	MPI_Type_free(&nuevo_tipo);
	MPI_Finalize(); // Finaliza de ambiente
	return 0;
}


