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
    {
        cout << "Stack is Full" << endl;
    }
    else
    {
        top+=1;
        stack[top]=item;
    }
}
