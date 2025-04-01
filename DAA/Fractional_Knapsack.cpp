#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

// Structure to represent an item
struct Item
{
    int index;  
    int weight;   
    int value;    
    double ratio; 
};

// Function to compare based on value-to-weight ratio
bool compare(Item a, Item b)
{
    return a.ratio > b.ratio; 
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(Item arr[], int n, int capacity)
{
    int step = 1;             
    double total_value = 0.0; 
    int current_weight = 0;   

    // Step 1: Compute value-to-weight ratios
    cout << endl << "Step " << step << ": Initial Items Table" << endl;
    cout << "--------------------------" << endl;
    cout << "| Items | Weight | Value |" << endl;
    cout << "--------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i].ratio = (double)arr[i].value / arr[i].weight; 

        // Print the item's index, weight, and value in a formatted table
        cout << "|  I" << arr[i].index
             << setw(6 - to_string(arr[i].index).length()) << " | "
             << setw(6) << arr[i].weight << " | "
             << setw(5) << arr[i].value << " |" << endl;
    }
    cout << "--------------------------" << endl;
    step++;

    // Step 2: Sort the items by value-to-weight ratio in descending order
    cout << "\nStep " << step << ": Sorting Items by Ratio (vi/wi)\n";
    sort(arr, arr + n, compare); // Sort using the comparison function
    cout << "---------------------------------------" << endl;
    cout << "| Items | Weight | Value | Pi = vi/wi |" << endl;
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        // Print sorted items with their ratio (vi/wi)
        cout << "|  I" << arr[i].index
             << setw(6 - to_string(arr[i].index).length()) << " | "
             << setw(6) << arr[i].weight << " | "
             << setw(5) << arr[i].value << " | "
             << setw(10) << fixed << setprecision(2) << arr[i].ratio << " |\n";
    }
    cout << "---------------------------------------\n";
    step++;

    // Step 3: Fill the knapsack using the sorted items
    cout << endl << "Step " << step << ": Filling Knapsack (Capacity = " << capacity << ")" << endl;
    for (int i = 0; i < n; i++)
    {
        // Display information about the current item being considered
        cout << "Considering Item I" << arr[i].index << ": Value = " << arr[i].value
            << ", Weight = " << arr[i].weight << ", Ratio = " << arr[i].ratio << endl;
        cout << "Current weight = " << current_weight << ", Remaining capacity = " << capacity - current_weight << endl;

        // If the entire item can be taken, add its weight and value
        if (current_weight + arr[i].weight <= capacity)
        {
            current_weight += arr[i].weight;
            total_value += arr[i].value;   
            cout << endl << "=> Taking 100% of Item I" << arr[i].index << " (" << arr[i].weight << "kg)\n";
        }
        else
        {
            // If the item cannot be fully taken, take a fraction of it
            int remaining = capacity - current_weight;          
            double fraction = (double)remaining / arr[i].weight; 
            total_value += arr[i].value * fraction;              
            current_weight = capacity;                           
            cout << endl << "=> Taking " << fixed << setprecision(2) << fraction * 100 << "% of Item I" << arr[i].index
                 << " (" << remaining << "kg of " << arr[i].weight << "kg)" << endl;
            break; 
        }

        // Display the total value and weight of the knapsack after each step
        cout << "Knapsack after Step " << step << ": Total Value = " << fixed << setprecision(2) << total_value
             << ", Total Weight = " << current_weight << endl;
        step++;
    }
    return total_value;
}

int main()
{
    cout << "\t\t=======================" << endl;
    cout << "\t\t  Fractional Knapsack  " << endl;
    cout << "\t\t=======================" << endl;

    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    Item arr[n];
    cout << "Enter weight and value for each item:\n";
    for (int i = 0; i < n; i++)
    {
        arr[i].index = i + 1; 
        cout << "Item I" << i + 1 << " - Weight and Value: ";
        cin >> arr[i].weight  >> arr[i].value;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Perform the fractional knapsack algorithm
    double total_value = fractionalKnapsack(arr, n, capacity);

    // Output the final results
    cout << endl << "Final Total Value in Knapsack: " << fixed << setprecision(2) << total_value << endl;

    cout << "\nCompiled by : Subodh Ghimire " << endl;
    return 0;
}
