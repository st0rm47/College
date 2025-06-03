#include <stdio.h>

int main() {
    printf("\t===========================================");
    printf("\n\t  Bank Queue Analysis using Poisson Model  ");
    printf("\n\t===========================================\n");


    float inter_arrival_time_min = 10.0; 
    float service_time_min = 5.0;

    // Convert to per hour rates
    float lambda = 60.0 / inter_arrival_time_min; 
    float mu = 60.0 / service_time_min;         

    // Utilization
    float rho = lambda / mu;

    // M/M/1 queueing theory
    float prob_no_wait = 1 - rho;           
    float expected_customers = rho / (1 - rho); 
    float expected_time_in_bank = 1 / (mu - lambda);
    float expected_time_in_minutes = expected_time_in_bank * 60;

    printf("Probability that a customer will not have to wait: %.2f\n", prob_no_wait);
    printf("Expected number of customers in the bank: %.2f\n", expected_customers);
    printf("Expected time a customer spends in the bank: %.2f minutes\n", expected_time_in_minutes);

    printf("\nCompiled by : Subodh Ghimire ");
    return 0;
}
