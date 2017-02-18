#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <assert.h>

float getSum(float* arr, int size) {

  float sum = 0.f;
  int i;
  for (i = 0; i < size; i++)
    sum += arr[i];
  return sum;
}

int main(int argc, char** argv) {

  int world_rank;
  int world_size;
  int size;
  int step;
  float *array = NULL;
  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  
  if (world_rank == 0) {
    puts("Enter array size: ");
    int shit = scanf("%d", &size);
    step = size / world_size;
    array = (float*)malloc(sizeof(float) * size);
    puts("Enter Array Elements: ");
    int i;
    for (i = 0; i < size; i++)
      shit = scanf("%f", &array[i]);
/*
    for (i = 0; i < size; i++)
      shit = printf("%f%c", array[i],  " \n"[i == size - 1]); 
*/
  }

  MPI_Bcast(&size, 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(&step, 1, MPI_INT, 0, MPI_COMM_WORLD);

  float *sub_array = (float*)malloc(sizeof(float) * step);
  MPI_Scatter(array, step, MPI_FLOAT, sub_array, step, MPI_FLOAT, 0, MPI_COMM_WORLD);
  float sub_sum = getSum(sub_array, step);
  float *sub_sums = NULL;
  if (world_rank == 0) {
    sub_sums = (float*)malloc(sizeof(float) * world_size);
  }
  MPI_Gather(&sub_sum, 1, MPI_FLOAT, sub_sums, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);

  if (world_rank == 0) {
    int i;
    float total_sum = 0.f;
    for (i = 0; i < world_size; i++)
      total_sum += sub_sums[i];
  
    int k = step * world_size;
    for (; k < size; k++)
      total_sum += array[k];

    total_sum /= size;
    printf("Average = %f\n", total_sum);
  }


  if (world_rank == 0) {
    free(array);
    free(sub_array);
  }
  free(sub_sums);
  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();
  return 0;
}






