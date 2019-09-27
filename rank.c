#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#include<math.h>

//Uso de estructuras con MPI

#define N 10
#define count 4
#define longBloque 4

int main(int argc, char *argv[])
{
int id, np, i, j;

struct{//NEW
int a;
double b;
} value;
MPI_Datatype mystruct; //NEW

int blocklens[2];

MPI_Aint indices[2]; //NEW
MPI_Datatype old_types[2]; //NEW
MPI_Status estado;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD, &id);
MPI_Comm_size(MPI_COMM_WORLD, &np);

//Un valor por cada tipo
blocklens[0] = 1; //Un dato de tipo entero (a)
blocklens[1] = 1; //Un dato de tipo double (b)

//Los tipos bases
old_types[0] = MPI_INT;
old_types[1] = MPI_DOUBLE;

//Un valor por cada tipo
MPI_Address(&value.a, &indices[0]); 
MPI_Address(&value.b, &indices[1]);

//Se hace relativo
indices[1] = indices[1] - indices[0]; //DONDE EMPIEZA EL (double);
indices[0] = 0; //DONDE EMPIEZA EL (INT);

MPI_Type_struct(2,blocklens,indices,old_types,&mystruct); // El dos representa cuantos tipso de dato hay
MPI_Type_commit(&mystruct);

do{
if(id==0)
scanf("%d %lf", &value.a, &value.b);

MPI_Bcast(&value,1,mystruct,0,MPI_COMM_WORLD);
printf("Proceso %d tuvo a:%d - b:%lf\n",id,value.a,value.b);

} while(value.a >= 0);

MPI_Type_free(&mystruct);

MPI_Finalize(); // Finaliza de ambiente
return 0;
}
