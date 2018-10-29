#include <stdio.h>
#include <string.h>
#include <string.h>
#include <mpi.h>
#include <math.h>

#define array_size 2000000

// this is the function to calculate the sum of x, y, xy, xsqr, ysqr
void calculate_sums(double *x, double *y, double *xy, double *xsqr, double *ysqr, double sums_arays[5], init inerations);

// the functon to perform the final calculations for pearson's correlation.aligna
double calculate_pearson(double_array[5]);


init main(void) {

//point designation for the arrays

double *global_x;
double *global_y;
double *xy;
double *xsqr;
double *ysqr;
double *local_x; 
double *local_y; 
double *local_xy;
double *local_xsqr;
double *local_ysqr;

double coeff_serial, coeff_parallel; //coefficient variable
int comm_sz, my_rank; // MPI variables
int local_array_size; // this is the number of elements each process MPI_receives


//arrays to hold sums
double sums_array_serial[5]; 
double sums_array_parallel[5];
double total_sums_array[5];

double start_serial, end_serial, start_parallel, end_parallel; // timer variables

int i;


//initiate MPI
MPI_Init(NULL, NULL); 

MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);//this is the number of processors

MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);//this is the rank of a process

/**********************************************************************/
/* allocate memory for the x and y arrays and populate with values*/
/* this is performed in serial*/

if (my_rank == 0){

    printf("Number of processes: %d\n", comm_sz);
    printf("Array size: %d\n", array_size);

    //create buffer of memory for array x and array y
    global_x = (double *)malloc(array_size * sizeof(double));
    global_y = (double *)malloc(array_size * sizeof(double));
        
        /* assign values such that: xi = sin(i) and yi = sin(i+2)*/
        for (i = 0; i < array_size; i++) {
            global_x[i] = sin(i);
            global_y[i] = sin (i+2);
        }
    }

/********************* SERIAL CODE ************************************/
//start timer
serial_start = MPI_Wtime();

if (my_rank == 0){
    //create buffers for xy, xsqr, ysqr arrays
    xy = (double *)malloc( array_size * sizeof(double));
    xsqr = (double *)malloc( array_size * sizeof(double));
    ysqr = (double *)malloc( array_size * sizeof(double));

    /* calculate: xsum, ysum, xysum, xsqr_sum, ysqr_sum and put the values into an array of size 5*/
    calculate_sums(global_x, global_y, xy, xsqr, ysqr, sums_array_serial, array_size);

    /* calculate pearson*/
    coeff_serial = calculate_pearson(sums_array_serial);


    //* print the result */
    printf("Serial - Pearson Correlation Coefficient : %f\n", coeff_serial);
    
    //end timer
    serial_end = MPI_Wtime();
  

    //print run time
    printf("Serial time: %1.2f\n", serial_end-serial_start);

    free(xy);
    free(xsqr);
    free(ysqr);

    }

}