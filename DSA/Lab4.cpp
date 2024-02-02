#include <iostream>
#define max_size 5
using namespace std;

int circular_queue[max_size];
int front = -1, rear = -1;

void enqueue(int x) {
    if (front == (rear+1)%max_size) {
        cout << "Queue is Full" << endl;
    } else {
        if (front == -1) {
            front = 0;
        }
        rear  = (rear + 1)%max_size;
        circular_queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
    } else {
        front =(front + 1)%max_size;
    }
}

void display() {
    if (front == -1)  {
        cout << "Queue is empty" << endl;
        return;
    }
    for (int i = front; i <=rear; i++) {
        cout << circular_queue[i] << "  ";
        
    }
    cout << endl;
}

int main() {
    int ch, item;
    while (true) {
        cout << "Program Menu\n";
        cout << "1. Enqueue an Element.\n";
        cout << "2. Dequeue an Element.\n";
        cout << "3. Display Queue.\n";
        cout << "4. Exit\n";
        cout << "Enter your Choice:";
        cin >> ch;
        switch (ch) {
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