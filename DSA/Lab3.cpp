// WAP to implement the operations of linear queue.

#include <iostream>
using namespace std;

int *queue;
int max_size;
int front = -1, rear = -1;

// Function to set the maximum size of the queue
void size()
{
    cout << "Enter the maximum size of the queue: ";
    cin >> max_size;
    queue = (int *)malloc(max_size * sizeof(int));
}

// Function to enqueue an element into the queue
void enqueue(int x)
{
    if (rear == max_size - 1)
        cout << "Queue is Full" << endl;
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear += 1;
        queue[rear] = x;
    }
}

// Function to dequeue an element from the queue
void dequeue()
{
    if (front == -1)
        cout << "Queue is empty" << endl;
    else
        front += 1;
}

// Function to display the elements of the queue
void display()
{
    if (front == -1)
        cout << "Queue is empty" << endl;
    for (int i = front; i <= rear; i++)
        cout << queue[i] << "  ";
    cout << endl;
}

int main()
{
    cout << "\t\t========================" << endl;
    cout << "\t\t  Queue Implementation  " << endl;
    cout << "\t\t========================" << endl;

    size();
    int ch, item;
    while (1)
    {
        cout << endl;
        cout << "Program Menu" << endl;
        cout << "1. Enqueue an Element." << endl;
        cout << "2. Dequeue an Element." << endl;
        cout << "3. Display Queue." << endl;
        cout << "4. Exit." << endl;
        cout << "Enter your Choice:";
        cin >> ch;
        switch (ch)
        {
            case 1:
                cout << "Enter an element:";
                cin >> item;
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                free(queue);
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
    return 0;
}
