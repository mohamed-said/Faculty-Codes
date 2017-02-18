#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

#define REP(i,n) for((i)=0;(i)<(n);(i)++)
#define max(x,y) (x > y ? x : y)
#define min(x,y) (x < y ? x : y)

int main(int argc , char * argv[]) {
	int my_rank;	/* rank of process	*/
	int p;			/* number of process	*/
	int source;		/* rank of sender	*/
	int dest;		/* rank of reciever	*/
	int tag = 0;		/* tag for messages	*/
	int n, i;
	int *arr;
	const int OO = (int) 2e9;
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
		int len, mx = -OO, mn = OO;
		MPI_Recv(&len, 1, MPI_INT, dest, tag, MPI_COMM_WORLD, &status);
		int *A = (int *) malloc(len * sizeof(int));
		MPI_Recv(A, len, MPI_INT, dest, tag, MPI_COMM_WORLD, &status);
		REP(i,len)
			mx = max(mx, A[i]), mn = min(mn, A[i]);
		MPI_Send(&mn, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
		MPI_Send(&mx, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
	}else {
		printf("Enter the number of elements: ");
		scanf("%d", &n);
		printf("Enter The array\n");
		arr = (int*) malloc (n * sizeof(int));
		REP(i,n)
			scanf("%d", &arr[i]);

		int portion = n/(p-1);
		int currentPosition = 0;
		int totMin = OO, totMax = -OO;
		printf("Sending portions to slave processes ...");
		for( source = 1; source < p ; source++)
		{
			int newPortion = portion;
			if (source == p-1)
				newPortion += n % (p-1);
			printf("\n\tProcess%d will compute sum of range [%d-%d]" , source, currentPosition, currentPosition+newPortion-1);
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
			int curmn, curmx;
			MPI_Recv(&curmn, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
			MPI_Recv(&curmx, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
			totMin = min(totMin, curmn);
			totMax = max(totMax, curmx);
			printf("\n\tProcess%d computed range [%d-%d]\n" , source, currentPosition, currentPosition+newPortion-1);
			currentPosition += newPortion;
		}
		printf("\nMin is: %d\n", totMin);
		printf("\nMax is: %d\n", totMax);
	}

	/* shutdown MPI */
	MPI_Finalize();
	return 0;
}
