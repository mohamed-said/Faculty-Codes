#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <mpi.h>

#define MAX_SIZE 1007
#define LIMIT 1000


bool writeToFile(int *arr) {
  FILE *file = fopen("output.txt", "w");
  if (file == NULL) {
    puts("Error opening output file");
    return 0;
  }
  int counter = 0;
  while (counter < 1000) {
    fprintf(file, "%d\n", arr[counter]);
    ++counter;
  }
  fclose(file);
  return 1;
}

int* initializeArray() {
  int *arr = (int*)malloc(sizeof(int) * MAX_SIZE);
  FILE *file = fopen("numbers.txt", "r");
  int i = 0, x;
  while (fscanf(file, "%d", &x) != EOF && i < 1000) {
    arr[i] = x;
    ++i;
  }
  return arr;
}

int main(int argc, char **argv) {
  
  int rank, p;
  int step;  
  int *A, *B, *C;
  int sum = 0;
  float subAverage = 0.f, totalAverage = 0.f;
  float average = 0.f;
  int i = 0;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &p);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);



////read numbers from file ////////
  if (rank == 0) {
    A = initializeArray();
    step = LIMIT / p;
  }
////////////////////////////////
  MPI_Bcast(&step, 1, MPI_INT, 0, MPI_COMM_WORLD);

  B = (int*)malloc(sizeof(int) * step);
  MPI_Scatter(A, step, MPI_INT, B, step, MPI_INT, 0, MPI_COMM_WORLD);

  for (i = 0; i < step; i++)
    sum += B[i];
  subAverage = (float)sum/LIMIT;

  MPI_Reduce(&subAverage, &totalAverage, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);


////calculate average////////////  
  if (rank == 0) {
    int rest = 0;
    for (i = p * step; i < LIMIT; i++)
      rest += A[i];
    
    average = totalAverage + ((float)rest/LIMIT);
    printf("Parallel Average = %f\n", average);

    int test = 0;
    int k = 0;
    for (k = 0; k < LIMIT; k++)
      test += A[k];

    printf("Ordinary Average = %f\n", (float)test / LIMIT);

    C = (int*)malloc(sizeof(int) * MAX_SIZE);
  }
///////////////////////////////////////////
  MPI_Bcast(&average, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);

  for (i = 0; i < step; i++)
    B[i] -= average;

  MPI_Gather(B, step, MPI_INT, C, step, MPI_INT, 0, MPI_COMM_WORLD);

////write results to file///////
  if (rank == 0) {
    for (i = p * step; i < LIMIT; i++)
      C[i] = A[i] - average;
    
    bool fin = writeToFile(C);
    if (fin)
      puts("All good");
    else
      puts("All not good");
  }
////////////////////////////////////

  MPI_Finalize();

  return 0;
}
