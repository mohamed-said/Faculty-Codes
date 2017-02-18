#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc , char * argv[]) {
	int source;
	int my_rank;		/* rank of process	*/
	int p;			/* number of process	*/
	int dest;		/* rank of reciever	*/
	int tag = 0;		/* tag for messages	*/
	int i, len, portion, res = 1, fact = 1;
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
	if (my_rank == 0) {
		puts("Enter the number:");
		scanf("%d", &x);
		portion = x / (p - 1);
	}
	MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&portion, 1, MPI_INT, 0, MPI_COMM_WORLD);
	if (my_rank != 0) {
		res = 1;
		for (i = (my_rank - 1) * portion + 1; i <= my_rank * portion; i++)
			res *= i;
		printf("%d %d\n", my_rank, res);
	}
  
	MPI_Reduce(&res, &fact, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);
	if (my_rank == 0) {
		printf("fact = %d\n", fact);
	}
	/* shutdown MPI */
	MPI_Finalize();
	return 0;
}
