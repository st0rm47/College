#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100
#define MAX_ITER 1000
#define TOL 1e-6

double u[MAX_SIZE+2][MAX_SIZE+2]; // Solution grid
double f[MAX_SIZE+2][MAX_SIZE+2]; // Source term grid
double u_new[MAX_SIZE+2][MAX_SIZE+2]; // Temporary grid for updates

int NX, NY;

// Function to initialize the grid and source term
void initialize() {
    for (int i = 0; i <= NX+1; i++) {
        for (int j = 0; j <= NY+1; j++) {
            if (i == 0 || i == NX+1 || j == 0 || j == NY+1) {
                u[i][j] = 0.0; // Boundary condition
            } else {
                u[i][j] = 0.0; // Initial guess
                printf("Enter the value for f[%d][%d]: ", i, j);
                scanf("%lf", &f[i][j]); // Source term from user
            }
        }
    }
}

// Function to perform one iteration of Jacobi method
void jacobi_iteration() {
    for (int i = 1; i <= NX; i++) {
        for (int j = 1; j <= NY; j++) {
            u_new[i][j] = 0.25 * (u[i-1][j] + u[i+1][j] + u[i][j-1] + u[i][j+1] - f[i][j]);
        }
    }

    // Update the solution grid
    for (int i = 1; i <= NX; i++) {
        for (int j = 1; j <= NY; j++) {
            u[i][j] = u_new[i][j];
        }
    }
}

// Function to check convergence
int check_convergence() {
    double sum = 0.0;
    for (int i = 1; i <= NX; i++) {
        for (int j = 1; j <= NY; j++) {
            sum += fabs(u_new[i][j] - u[i][j]);
        }
    }
    if (sum / (NX * NY) < TOL) {
        return 1; // Converged
    } else {
        return 0; // Not converged
    }
}

// Function to solve Poisson's equation
void solve_poisson_equation() {
    int iter = 0;
    while (iter < MAX_ITER) {
        jacobi_iteration();
        if (check_convergence()) {
            break;
        }
        iter++;
    }
}

// Function to print the solution grid
void print_solution() {
    for (int i = 0; i <= NX+1; i++) {
        for (int j = 0; j <= NY+1; j++) {
            printf("%.2f ", u[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the size of the grid (NX NY): ");
    scanf("%d %d", &NX, &NY);

    if (NX <= 0 || NY <= 0 || NX >= MAX_SIZE || NY >= MAX_SIZE) {
        printf("Invalid grid size. Exiting...\n");
        return 1;
    }

    initialize();
    solve_poisson_equation();
    print_solution();
    return 0;
}
