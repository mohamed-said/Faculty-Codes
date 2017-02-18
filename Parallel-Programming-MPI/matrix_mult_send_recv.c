#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

#define REP(i,n) for((i)=0;(i)<(n);(i)++)

int main(int argc , char * argv[])
{
	int my_rank;	/* rank of process	*/
	int p;			/* number of process	*/
	int source;		/* rank of sender	*/
	int dest;		/* rank of reciever	*/
	int tag = 0;		/* tag for messages	*/
	int rA, cA, rB, cB, rR, cR, i, j, k;
	int **A, **B, **R;
	MPI_Status status;	/* return status for 	*/
						/* recieve		*/

	/* Start up MPI */
	MPI_Init( &argc , &argv );

	/* Find out process rank */
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	/* Find out number of process */
	MPI_Comm_size(MPI_COMM_WORLD, &p);

	if( my_rank != 0)
	{
		/* create message */
		dest = 0;
		int rowA, colA;
		MPI_Recv(&rowA, 1, MPI_INT, dest, tag, MPI_COMM_WORLD, &status);
		MPI_Recv(&colA, 1, MPI_INT, dest, tag, MPI_COMM_WORLD, &status);
		int ** subA = (int **) malloc(rowA * sizeof(int*));
		REP(i,rowA) {
			subA[i] = (int *) malloc(colA * sizeof(int));
			MPI_Recv(subA[i], colA, MPI_INT, dest, tag, MPI_COMM_WORLD, &status);
		}
				
		int rowB, colB;
		MPI_Recv(&rowB, 1, MPI_INT, dest, tag, MPI_COMM_WORLD, &status);
		MPI_Recv(&colB, 1, MPI_INT, dest, tag, MPI_COMM_WORLD, &status);
		int ** subB = (int **) malloc(rowB * sizeof(int*));
		REP(i,rowB) {
			subB[i] = (int *) malloc(colB * sizeof(int));
			MPI_Recv(subB[i], colB, MPI_INT, dest, tag, MPI_COMM_WORLD, &status);
		}
				
		int rowRes = rowA, colRes = colB;
		int **Res = (int **) malloc(rowRes * sizeof(int*));
		REP(i,rowRes) {
			Res[i] = (int *) malloc(colRes * sizeof(int));
			REP(j,colRes)
				Res[i][j] = 0;
		}
		
		REP(i,rowA)
			REP(k,colA)
				REP(j,colB)
					Res[i][j] += subA[i][k] * subB[k][j];
				
		MPI_Send(&rowRes, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
		MPI_Send(&colRes, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
		REP(i,rowRes){
			MPI_Send(Res[i],colRes, MPI_INT, dest, tag, MPI_COMM_WORLD);
		}
	}else
	{
		printf("Enter dimensions of Matrix A: ");
		scanf("%d %d", &rA, &cA);
		printf("Enter Matrix A:\n");
		A = (int**) malloc (rA * sizeof(int *));
		REP(i,rA) {
			A[i] =  (int *) malloc (cA * sizeof(int));
			REP(j,cA)
				scanf("%d", A[i] + j);
		}
		
		printf("Enter dimensions of Matrix B: ");
		scanf("%d %d", &rB, &cB);
		printf("Enter Matrix B:\n");
		B = (int**) malloc (rB * sizeof(int *));
		REP(i,rB) {
			B[i] =  (int *) malloc (cB * sizeof(int));
			REP(j,cB)
				scanf("%d", B[i] + j);
		}
		rR = rA, cR = cB;
		R = (int**) malloc (rR * sizeof(int *));
		REP(i,rR) {
			R[i] =  (int *) malloc (cR * sizeof(int));
			REP(j,cR)
				R[i][j] = 0;
		}
		int portion = rA/(p-1);
		int currentPosition = 0;
		printf("Sending portions to slave processes ...");
		for( source = 1; source < p ; source++)
		{
			int newPortion = portion;
			if (source == p-1)
				newPortion += rA % (p-1);
			printf("\n\tProcess%d will compute rows [%d-%d]" , source, currentPosition, currentPosition+newPortion-1);
			MPI_Send(&newPortion, 1, MPI_INT, source, tag, MPI_COMM_WORLD);
			MPI_Send(&cA, 1, MPI_INT, source, tag, MPI_COMM_WORLD);
			REP(i,newPortion){
				MPI_Send(A[currentPosition], cA, MPI_INT, source, tag, MPI_COMM_WORLD);
				currentPosition++;
			}
			MPI_Send(&rB, 1, MPI_INT, source, tag, MPI_COMM_WORLD);
			MPI_Send(&cB, 1, MPI_INT, source, tag, MPI_COMM_WORLD);
			REP(i,rB){
				MPI_Send(B[i], cB, MPI_INT, source, tag, MPI_COMM_WORLD);
			}
		}
		
		printf("\n\nReceiving converted portions from slave processes ...\n");
		currentPosition = 0;
		for( source = 1; source < p ; source++)
		{
			int newPortion = portion;
			if (source == p-1)
				newPortion += rA % (p-1);
			int rowR, colR;
			MPI_Recv(&rowR, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
			MPI_Recv(&colR, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
			int ** subR = (int **) malloc(rowR * sizeof(int*));
			REP(i,rowR) {
				subR[i] = (int *) malloc(colR * sizeof(int));
				MPI_Recv(subR[i], colR, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
				REP(j,colR)
					R[currentPosition + i][j] = subR[i][j];
			}				
			printf("\n\tProcess%d computed rows [%d-%d]\n" , source, currentPosition, currentPosition+newPortion-1);
			currentPosition += newPortion;
		}
		printf("\nThe Result Matrix is:\n");
		REP(i,rR)
			REP(j,cR)
				printf("%d%c", R[i][j], " \n"[j == cR - 1]);
	}

	/* shutdown MPI */
	MPI_Finalize();
	return 0;
}
