#include<stdio.h>
#include<stdlib.h>
#include<mpi.h> 

void main(int argc, char *argv[])
{
	int i,id,inicio,fin,n=1000,np,nrec;
	double h,pi_p,x;
	
	MPI_Init(&argc,&argv); // Inicializa el ambiente
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	
	nrec=n/np;	
	//inicio=id*nrec;
	//(fin=(id+1)*nrec-1;
	h=1.0/(double)n;
	pi_p=0.0;
	for (i=id;i<n;i=i+np) 
	{
 		x=(double)i/(double)n;
		pi_p+= (4.0/(1.0+ x*x))*h;
	}
		
	printf("Pi es aproximadamente %22.16e\n", 4.0*pi_p);

	
	MPI_Finalize(); // Finaliza de ambiente
	return 0;
}

