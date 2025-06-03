#include <stdio.h>

int main() {
    printf("\t============================================");
    printf("\n\t  Stadium Entry Time Calculation for a Fan  ");
    printf("\n\t============================================\n");

    float arrival_rate = 1.0;      
    float service_rate = 3.0;     
    float time_to_seat = 1.5;      
    float available_time = 2.0;    

    // Calculate expected time in system (W) = 1 / (μ - λ)
    float waiting_time = 1 / (service_rate - arrival_rate);

    // Total time before fan gets seated
    float total_time = waiting_time + time_to_seat;

    printf("Expected time in queue and ticketing: %.2f minutes\n", waiting_time);
    printf("Time to reach the seat: %.2f minutes\n", time_to_seat);
    printf("Total time to be seated: %.2f minutes\n", total_time);

    if (total_time <= available_time) {
        printf("Yes, the sports fan can expect to be seated before the kick-off.\n");
    } else {
        printf("No, the sports fan may miss the kick-off.\n");
    }

    printf("\nCompiled by : Subodh Ghimire ");
    return 0;
}
