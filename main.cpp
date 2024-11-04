// محمد جمال محمد شرف الدين
// D4
#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int data = rank;
    int next = (rank + 1) % size;
    int prev = (rank - 1 + size) % size;

    if (rank < size)
    {

        MPI_Send(&data, 1, MPI_INT, next, 0, MPI_COMM_WORLD);

        MPI_Recv(&data, 1, MPI_INT, prev, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        data += 1;

        printf("Process %d received data %d from process %d\n",
               rank, data, prev);
    }

    MPI_Finalize();
    return 0;
