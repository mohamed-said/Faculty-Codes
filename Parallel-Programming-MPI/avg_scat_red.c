#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv) {

  int p, rank;
  int *array;
  int size;
  int step;
//  int sub_sum = 0;
  int sub_sum = 0;
  int total_sum = 0;

  int *sub_array = NULL;
  int i;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &p);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (rank == 0) {
    puts("Enter array size: ");
    int shit = scanf("%d", &size);

    printf("size = %d\n", size);
    array = (int*)malloc(size * sizeof(int));

    puts("Enter array elements: ");    
    for (i = 0; i < size; i++)
      shit = scanf("%d", &array[i]);
  
    for (i = 0; i < size; i++)
      printf("%d%c", array[i], " \n"[i == size - 1]);
    step = size / p;
    printf("step = %d ,, size = %d", step, size);
  }

  MPI_Bcast(&step, 1, MPI_INT, 0, MPI_COMM_WORLD);
  
  sub_array = (int*)malloc(sizeof(int) * step);
  MPI_Scatter(array, step, MPI_FLOAT, sub_array, step, MPI_FLOAT, 0, MPI_COMM_WORLD);

  for (i = 0; i < step; i++)
    sub_sum += sub_array[i];

  MPI_Reduce(&sub_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  if (rank == 0) {
    printf("%d\n", total_sum);
    for (i = p * step; i < size; i++)
      total_sum += array[i];
    
    printf("Average = %d\n", total_sum / size);
  
  }
  
  MPI_Finalize();
  return 0;
}
