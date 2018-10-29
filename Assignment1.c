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
int local_array_size; // number of elements each process receives


}