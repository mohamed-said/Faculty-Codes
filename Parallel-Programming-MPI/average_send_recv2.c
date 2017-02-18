#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>


int main(int argc, char **argv) {
  
  int np;
  int rank;
  int source, dest;
  int tag = 0;
  double *arr;
  int size;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  if (rank == 0) { // Manager
    MPI_Status status;
    int i;
    puts("Enter array size: ");
    scanf("%d", &size);
    arr = (double*)malloc(size * sizeof(double));
    for (i = 0; i < size; ++i)
      scanf("%lf", &arr[i]);
    int chunks = size / (np - 1);
    if (size % (np - 1))
      ++chunks;
    for (i = 1; i < np; ++i) {
      MPI_Send(&chunks, 1, MPI_INT, i, 100, MPI_COMM_WORLD);
      MPI_Send(arr + ((i - 1) * chunks), chunks, MPI_DOUBLE, i, 100, MPI_COMM_WORLD);
    }
    double acc, total = 0;
    for (i = 1; i < np; ++i) {
      MPI_Recv(&acc, 1, MPI_DOUBLE, i, 200, MPI_COMM_WORLD, &status);
      total += acc;
    }
    printf("Average is: %lf\n", total / size);
  } else { // workers
    MPI_Status status;
    int i;
    int sz_process;
    double res = 0.0;
    MPI_Recv(&sz_process, 1, MPI_INT, tag, 100, MPI_COMM_WORLD, &status);
    double *processes = (double*)malloc(sz_process * sizeof(double));
    MPI_Recv(processes, sz_process, MPI_DOUBLE, tag, 100, MPI_COMM_WORLD, &status);
    for (i = 0; i < sz_process; ++i)
      res += processes[i];
   // printf("Result is: %lf\n", res);
    MPI_Send(&res, 1,  MPI_DOUBLE, tag, 200, MPI_COMM_WORLD); 
  }

  MPI_Finalize();
}
