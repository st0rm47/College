// wap to insert a node at the end of singly linked list
#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

void insertAtBEG(node*& head, int value) {
    node* new_node = (node*) malloc (sizeof(node));
    new_node->data = value;
    new_node->next = nullptr;
    
    if(head == nullptr){
        head = new_node;
        new_node->next = nullptr;
    }
    else{
        new_node->next = head;
        head = new_node;
    }

}

void insertAtEND(node*& head, int value) {
    node* new_node = (node*) malloc (sizeof(node));
    new_node->data = value;
    new_node->next = nullptr;
    
    if (head == nullptr) {
        cout << "List is Empty";
        head = new_node;
    } else {
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void deleteFromBEG(node*& head) {
    if (head == nullptr) {
        cout << "List is Empty. Cannot delete from the beginning." << endl;
    } else {
        node* temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteFromEND(node*& head) {
    if (head == nullptr) {
        cout << "List is Empty" << endl;
    } else if (head->next == nullptr) {
        free(head);
        head = nullptr;
    } else {
        node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = nullptr;
    }
}

void displayList(node* head) {
    if (head == nullptr) {
        cout << "List is Empty" << endl;
    }

    node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* head = nullptr;
    int ch, item;

    while (true) {
        cout << "Program Menu\n";
        cout << "1. Insert at the Beginning.\n";
        cout << "2. Insert at the End.\n";
        cout << "3. Delete from the Beginning.\n";
        cout << "4. Delete from the End.\n";
        cout << "5. Display the List.\n";
        cout << "6. EXIT.\n";
        
        cout << "Enter your Choice:";
        cin >> ch;

        switch (ch) {
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
                cout << "Invalid choice! Please enter a valid option." << endl;
                break;
        }
    }

    return 0;
}
