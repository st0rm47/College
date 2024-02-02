#include <iostream>
using namespace std;

int *queue;
int max_size;
int front = -1, rear = -1;

void size()
{
    cout << "Enter the maximum size of the queue: ";
    cin >> max_size;
    queue = (int *)malloc(max_size * sizeof(int));
}
void enqueue(int x)
{
    if (rear == max_size - 1)
    {
        cout << "Queue is Full" << endl;
    }
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

void dequeue()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        front += 1;
    }
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << "  ";
    }
    cout << endl;
}

int main()
{
    size();
    int ch, item;
    while (true)
    {
        cout << "Program Menu\n";
        cout << "1. Enqueue an Element.\n";
        cout << "2. Dequeue an Element.\n";
        cout << "3. Display Queue.\n";
        cout << "4. Exit\n";
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
            exit(0);
        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
            break;
        }
    }
    return 0;
}