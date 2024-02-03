// WAP to implement the operations of circular queue.

#include <iostream>
#define max_size 3
using namespace std;

int circular_queue[max_size];
int front = -1, rear = -1;

void enqueue(int x)
{
    if (front == (rear + 1) % max_size)
        cout << "Queue is Full" << endl;
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % max_size;
        circular_queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1)
        cout << "Queue is empty" << endl;
    else
        front = (front + 1) % max_size;
}

void display()
{
    if (front == -1)
        cout << "Queue is empty" << endl;
    int i = front;
    do
    {
        cout << circular_queue[i] << "  ";
        i = (i + 1) % max_size;
    } while (i != (rear + 1) % max_size);
    cout << endl;
}

int main()
{
    cout << "\t\t=================================" << endl;
    cout << "\t\t  Circular Queue Implementation  " << endl;
    cout << "\t\t=================================" << endl;

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
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
    return 0;
}