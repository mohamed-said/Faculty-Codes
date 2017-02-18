#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

#define REP(i,n) for((i)=0;(i)<(n);(i)++)

int main(int argc , char * argv[]) {
	int my_rank;	/* rank of process	*/
	int p;			/* number of process	*/
	int source;		/* rank of sender	*/
	int dest;		/* rank of reciever	*/
	int tag = 0;		/* tag for messages	*/
	int n, i;
	int *arr;
	MPI_Status status;	/* return status for 	*/
						/* recieve		*/

	/* Start up MPI */
	MPI_Init( &argc , &argv );

	/* Find out process rank */
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	/* Find out number of process */
	MPI_Comm_size(MPI_COMM_WORLD, &p);

	if( my_rank != 0) {
		/* create message */
		dest = 0;
		int len, sum = 0, m;
		MPI_Recv(&m, 1, MPI_INT, dest, tag, MPI_COMM_WORLD, &status);
		MPI_Recv(&len, 1, MPI_INT, dest, tag, MPI_COMM_WORLD, &status);
		int *A = (int *) malloc(len * sizeof(int));
		MPI_Recv(A, len, MPI_INT, dest, tag, MPI_COMM_WORLD, &status);
		REP(i,len)
			sum += A[i];
		float curavg = (float)sum / m;
		MPI_Send(&curavg, 1, MPI_FLOAT, dest, tag, MPI_COMM_WORLD);
	} else {
		printf("Enter the number of elements: ");
		scanf("%d", &n);
		printf("Enter The array\n");
		arr = (int*) malloc (n * sizeof(int));
		REP(i,n)
			scanf("%d", &arr[i]);

		int portion = n/(p-1);
		int currentPosition = 0;
		float Avg = 0;
		printf("Sending portions to slave processes ...");
		for( source = 1; source < p ; source++) {
			int newPortion = portion;
			if (source == p-1)
				newPortion += n % (p-1);
			printf("\n\tProcess%d will compute sum of range [%d-%d]" , source, currentPosition, currentPosition+newPortion-1);
			MPI_Send(&n, 1, MPI_INT, source, tag, MPI_COMM_WORLD);
			MPI_Send(&newPortion, 1, MPI_INT, source, tag, MPI_COMM_WORLD);
			MPI_Send(&arr[currentPosition], newPortion, MPI_INT, source, tag, MPI_COMM_WORLD);
			currentPosition += newPortion;
		}
		
		printf("\n\nReceiving converted portions from slave processes ...\n");
		currentPosition = 0;
		for( source = 1; source < p ; source++) {
			int newPortion = portion;
			if (source == p-1)
				newPortion += n % (p-1);
			float curavg;
			MPI_Recv(&curavg, 1, MPI_FLOAT, source, tag, MPI_COMM_WORLD, &status);
			Avg += curavg;
			printf("\n\tProcess%d computed range [%d-%d]\n" , source, currentPosition, currentPosition+newPortion-1);
			currentPosition += newPortion;
		}
		printf("\nThe Average is: %.2f\n", Avg);
	}

	/* shutdown MPI */
	MPI_Finalize();
	return 0;
}
