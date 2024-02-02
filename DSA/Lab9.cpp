//  Write a recursive program to display the moves in Tower of Hanoi for user input number of disks.

#include <iostream>
using namespace std;
int count = 0;

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source, char temp, char destination)
{
    if (n == 1)
    {
        // Move the top disk from source to destination
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        count++;
        return;
    }
    // Move (n-1) disks from source to temporary peg using destination as the temporary peg
    towerOfHanoi(n - 1, source, destination, temp);
    count++;

    // Move the nth disk from source to destination peg
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // Move (n-1) disks from temporary peg to destination peg using source as the temporary peg
    towerOfHanoi(n - 1, temp, source, destination);
}
int main()
{
    cout << "\t\t====================" << endl;
    cout << "\t\t   Tower of Hanoi   " << endl;
    cout << "\t\t====================" << endl;

    int numDisks;
    cout << "Enter the number of disks: ";
    cin >> numDisks;

    if (numDisks < 1)
        cout << "Invalid input. Please enter a positive integer." << endl;
    else
        cout << "Moves to solve the Tower of Hanoi problem with " << numDisks << " disks:" << endl;
    towerOfHanoi(numDisks, 'A', 'B', 'C');

    cout << "Total Number of Steps: " << count << endl;
    return 0;
}