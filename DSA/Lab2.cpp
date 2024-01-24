// WAP 

#include<iostream>
#define max_size 10
using namespace std;
int top=-1;
int item, ch;

//Push into Stack
void push(int stack[], int item)
{
    if (top==(max_size-1))
        cout << "Stack is Full" << endl;
    else
    {
        top+=1;
        stack[top]=item;
    }
}

//Pop from Stack
void pop(int stack[])
{
    int top_item;
    if(top==-1)
        cout << "Stack is Empty" << endl;
    else
    {
        top_item = stack[top];
        top-=1;
        cout << "Popped item is " << top_item << endl;
    }
}

//Display from Stack
void display(int stack[])
{
    if(top==-1)
        cout << "Stack is Empty" << endl;
    else
    {
        for (int i = top; i>=0; i--)
            cout << stack[i] << endl;
    }
}

int main()
{
    while(1)
    {
        cout << "Program Menu" << endl;
        cout << "1. Push an Element\n"
             << "2. Pop an Element\n"
             << "3. Display Stack\n"
             << "4. Exit \n";
    }
}