#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc , char * argv[]) {
	int source;
	int my_rank;		/* rank of process	*/
	int p = 5;			/* number of process	*/
	int dest;		/* rank of reciever	*/
	int tag = 0;		/* tag for messages	*/
	int i, len, sz, st, tmpsz, r, q;
	char *message;	/* storage for message	*/
	char *tmparr;
	MPI_Status status;	/* return status for 	*/
				/* recieve		*/
	/* Start up MPI */
	MPI_Init( &argc , &argv );
	/* Find out process rank */
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	/* Find out number of process */
	MPI_Comm_size(MPI_COMM_WORLD, &p);

	if( my_rank == 0) { // Main process
		scanf("%d", &len);
		message = (char*) malloc((len) * sizeof(char));
		scanf("%s", message);
		q = len / (p - 1), r = len % (p - 1);
		for(dest = 1; dest < p; ++dest) {
			sz = q + (r && dest <= r);
			st = q * (dest - 1);
			if (r && dest <= r)
				st += dest - 1;
			else
				st += r;
			MPI_Send(message + st, sz, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
		}
		for(dest = 1; dest < p; ++dest) {
			sz = q + (r && dest <= r);
			st = q * (dest - 1);
			if (r && dest <= r)
				st += dest - 1;
			else
				st += r;
			MPI_Recv(message + st, sz, MPI_CHAR, dest, tag, MPI_COMM_WORLD, &status);
		}
		printf("%s\n", message);
	}
	else {
		MPI_Recv(tmparr, tmpsz, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
		for(i = 0; i < tmpsz; i++) {
			tmparr[i] = toupper(tmparr[i]);
		}
		MPI_Send(tmparr, tmpsz, MPI_CHAR, 0, tag, MPI_COMM_WORLD);
	}
	/* shutdown MPI */
	MPI_Finalize();
	return 0;
}
