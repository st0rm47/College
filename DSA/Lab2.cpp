// WAP to implement the operations of stack.

#include <iostream>
#define max_size 10
using namespace std;
int arr[max_size];
int top = -1;
int item, ch;

// Push into Stack
void push(int stack[], int item)
{
    if (top == (max_size - 1))
        cout << "Stack is Full" << endl;
    else
    {
        top += 1;
        stack[top] = item;
    }
}

// Pop from Stack
void pop(int stack[])
{
    int top_item;
    if (top == -1)
        cout << "Stack is Empty" << endl;
    else
    {
        top_item = stack[top];
        top -= 1;
        cout << "Popped item is " << top_item << endl;
    }
}

// Display from Stack
void display(int stack[])
{
    if (top == -1)
        cout << "Stack is Empty" << endl;
    else
    {
        for (int i = top; i >= 0; i--)
            cout << stack[i] << endl;
    }
}

int main()
{
    cout << "\t\t========================" << endl;
    cout << "\t\t  Stack Implementation  " << endl;
    cout << "\t\t========================" << endl;
    while (1)
    {   
        cout << endl;
        cout << "Program Menu" << endl;
        cout << "1. Push an Element" << endl;
        cout << "2. Pop an Element" << endl;
        cout << "3. Display Stack" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
            case 1:
                cout << "Enter the element to be pushed: ";
                cin >> item;
                push(arr, item);
                break;
            case 2:
                pop(arr);
                break;
            case 3:
                display(arr);
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid Choice" << endl;
                break;
        }
    }
    return 0;
}