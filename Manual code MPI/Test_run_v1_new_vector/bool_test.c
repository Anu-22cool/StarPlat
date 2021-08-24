/**
 * @author RookieHPC
 * @brief Original source code at https://www.rookiehpc.com/mpi/docs/mpi_c_bool.php
 **/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mpi.h>
 
/**
 * @brief Illustrate how to communicate a boolean between 2 MPI processes.
 * @details This application is meant to be run with 2 MPI processes: 1 sender
 * and 1 receiver. The former sends a boolean to the latter, which prints it.
 **/
int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);
 
    // Check that 2 MPI processes are used.
    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(size != 2)
    {
        printf("This application is meant to be run with 2 MPI processes.\n");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }
 
    // Get my rank and do the corresponding job.
    enum role_ranks { SENDER, RECEIVER };
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    switch(my_rank)
    {
        case SENDER:
        {
            // Send the int
            bool boolToSend = true;
            printf("[MPI process %d] I send bool: %s.\n", my_rank, boolToSend ? "true" : "false");
            MPI_Ssend(&boolToSend, 1, MPI_C_BOOL, RECEIVER, 0, MPI_COMM_WORLD);
            break;
        }
        case RECEIVER:
        {
            // Receive the int
            bool boolReceived;
            MPI_Recv(&boolReceived, 1, MPI_C_BOOL, SENDER, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("[MPI process %d] I received bool: %s.\n", my_rank, boolReceived ? "true" : "false");
            break;
        }
    }
 
    MPI_Finalize();
 
    return EXIT_SUCCESS;
}

