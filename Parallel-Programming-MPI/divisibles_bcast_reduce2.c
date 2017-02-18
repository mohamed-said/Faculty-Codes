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


  int number;
  int div;
  int step;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &p);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (rank == 0) {
    puts("Enter a number:");
    scanf("%d", &number);
    puts("Enter a div: ");
    scanf("%d", &div);
    step = number / (p - 1);
  }
  

  MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(&step, 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(&div, 1, MPI_INT, 0, MPI_COMM_WORLD);

  
  int cnt = 0;
  if (rank) {
    int start = (rank - 1) * step + 1;
    int end = start + step - 1;
    if (rank == p - 1)
      end = number;
    for (; start <= end; start++)
      if (start % div == 0)
        cnt++;
  }

  int res;
  MPI_Reduce(&cnt, &res, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  if (rank == 0)
    printf("Number of divisibles = %d\n", res);

  return 0;
}
