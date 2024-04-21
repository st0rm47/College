// Wap to show the implementation of singly linked list

#include <iostream>
using namespace std;

// Node structure for the singly linked list
struct node
{
    int data;      
    node *next;    
};

// Function to insert a new node at the beginning of the linked list
void insertAtBEG(node *&head, int value)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = nullptr;
    if (head == nullptr)
        head = new_node;
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

// Function to insert a new node at the end of the linked list
void insertAtEND(node *&head, int value)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = nullptr;
    if (head == nullptr)
    {
        cout << "List is Empty";
        head = new_node;
    }
    else
    {
        node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to delete a node from the beginning of the linked list
void deleteFromBEG(node *&head)
{
    if (head == nullptr)
        cout << "List is Empty. Cannot delete from the beginning." << endl;
    else
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to delete a node from the end of the linked list
void deleteFromEND(node *&head)
{
    if (head == nullptr)
        cout << "List is Empty" << endl;
    else if (head->next == nullptr)
    {
        free(head);
        head = nullptr;
    }
    else
    {
        node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = nullptr;
    }
}

// Function to display the linked list
void displayList(node *head)
{
    if (head == nullptr)
        cout << "List is Empty" << endl;
    
    // Traverse and display each node's data
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{  
    cout << "\t\t=====================================" << endl;
    cout << "\t\t  Singly Linked List Implementation  " << endl;
    cout << "\t\t=====================================" << endl;

    node *head = nullptr;
    int ch, item;
    while (1)
    {
        cout << endl;
        cout << "Program Menu" << endl;
        cout << "1. Insert at the Beginning." << endl;
        cout << "2. Insert at the End." << endl;
        cout << "3. Delete from the Beginning." << endl;
        cout << "4. Delete from the End." << endl;
        cout << "5. Display the List." << endl;
        cout << "6. EXIT." << endl;
        cout << "Enter your Choice:";
        cin >> ch;
        switch (ch)
        {
            case 1:
                cout << "Enter an element:";
                cin >> item;
                insertAtBEG(head, item);
                break;
            case 2:
                cout << "Enter an element:";
                cin >> item;
                insertAtEND(head, item);
                break;
            case 3:
                deleteFromBEG(head);
                break;
            case 4:
                deleteFromEND(head);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
    return 0;
}
