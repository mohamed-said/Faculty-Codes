#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {

  int p;
  int rank;
  int source;
  int dest;
  int tag = 0;
  MPI_Status status;


  char str[12];
  int sz;
  MPI_Init(&argc, &argv);
  
  MPI_Comm_size(MPI_COMM_WORLD, &p);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (!rank) {
    puts("Enter a string:");
    scanf("%s", str);
    sz = strlen(str);
  }
  MPI_Bcast(&sz, 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(str, sz, MPI_CHAR, 0, MPI_COMM_WORLD);
  if (rank) {
    printf("rank = %d ,, message = %s\n", rank, str);
  }


  MPI_Finalize();
  return 0;
}
