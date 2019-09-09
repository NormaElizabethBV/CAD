#include<stdio.h>
#include<stdlib.h>
#include<mpi.h> 
main(int argc, char *argv[])
{

	int id,np;
	char dato[5];
	MPI_Init(&argc,&argv); //Inicializa el ambiente
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Comm_size(MPI_COMM_WORLD, &np);

	// Proceso 0
	if (id==0)
	{
		dato[0]='M';
		dato[1]='I';
		dato[2]='L';
		dato[3]='K';
		dato[4]='A';
	}

		
		MPI_Bcast(dato,5,MPI_CHAR,0,MPI_COMM_WORLD);
		printf("Dato= %s del proceso %d \n", dato,id);
		
		
		MPI_Finalize(); //Finaliza el ambiente
		return 0;
} 
