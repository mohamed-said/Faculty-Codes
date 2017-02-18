#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc , char * argv[])
{
	int source;
	int my_rank;		/* rank of process	*/
	int p;			/* number of process	*/
	int dest;		/* rank of reciever	*/
	int tag = 0;		/* tag for messages	*/
	int i, len, portion, res = 0, div = 0;
	char message[100];	/* storage for message	*/
	int x;
	char *tmparr;
	MPI_Status status;	/* return status for 	*/
				/* recieve		*/
	/* Start up MPI */
	MPI_Init( &argc , &argv );
	/* Find out process rank */
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	/* Find out number of process */
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	message = "Hello World !";
	len = strlen(message);
	portion = len / (p - 1);
	MPI_Scatter();
	if (my_rank != 0) {
		res = 0;
		for (i = (my_rank - 1) * portion + 1; i <= my_rank * portion; i++)
			if (i % x == 0)
				res++;
		printf("%d %d\n", my_rank, res);
	}
	MPI_Reduce(&res, &div, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if (my_rank == 0) {
		printf("number of divisible = %d\n", div);
	}
	/* shutdown MPI */
	MPI_Finalize();
	return 0;
}
