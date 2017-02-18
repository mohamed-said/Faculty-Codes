#include <stdio.h>
#include <string.h>
#include "mpi.h"

int main(int argc , char * argv[])
{
	int rank;		
	int p;			
	int source = 0;		
	int des;		
	int tag = 0;
	int sum=0;
	int totalSum=0;
	int *array_1, *array_2;
  int *sub_array_1, *sub_array_2;
	int step, i;
	int size = 0;
	
	MPI_Init( &argc , &argv );
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	
	if(rank == 0){
	  int ss;
    puts("Enter array size: ");
	  ss = scanf("%d",&size);

	  array_1 = malloc(size * sizeof(int));
    array_2 = malloc(size * sizeof(int));

	  puts("Enter first array Elements: ");
    int x;
    
	  for(i = 0; i < size; i++) {
	    ss = scanf("%d",&x);
	    array_1[i] = x;
	  }
    
    puts("Enter Second Array Elements: ");
    for (i = 0; i < size; i++) {
      ss = scanf("%d", &x);
      array_2[i] = x;
    }

	  step = size / p;
	}

	MPI_Bcast(&step, 1, MPI_INT, 0, MPI_COMM_WORLD);
	sub_array_1 = malloc(step * sizeof(int));
  sub_array_2 = malloc(step * sizeof(int));

  MPI_Scatter(array_1, step, MPI_INT, sub_array_1, step, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Scatter(array_2, step, MPI_INT, sub_array_2, step, MPI_INT, 0, MPI_COMM_WORLD);
	 	
	for(i = 0; i < step; i++) {
		sum += (sub_array_2[i] - sub_array_1[i]) * (sub_array_2[i] - sub_array_1[i]);
	}

	MPI_Reduce(&sum ,&totalSum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	if(rank == 0){
  
  printf("total sum before = %d\n", totalSum);
	for(i = p * step; i < size; i++) {
	  totalSum += (array_2[i] - array_1[i]) * (array_2[i] - array_1[i]);
  }
    printf("total sum = %d\n", totalSum);     
  	printf("average = %f\n", totalSum/(double)size);
	}
	
	MPI_Finalize();
	return 0;
}
