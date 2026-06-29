#include <iostream>
using namespace std;

// Node Structure
struct Node
{
    int data;
    Node *next;
};

// Create New Node
Node* createNode(int value)
{
    Node *newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Insert at Beginning
void insertAtBeginning(Node **head, int value)
{
    Node *newNode = createNode(value);

    newNode->next = *head;
    *head = newNode;
}

// Insert at End
void insertAtEnd(Node **head, int value)
{
    Node *newNode = createNode(value);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Delete from Beginning
void deleteAtBeginning(Node **head)
{
    if (*head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;

    delete temp;
}

// Delete from End
void deleteAtEnd(Node **head)
{
    if (*head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    if ((*head)->next == NULL)
    {
        delete *head;
        *head = NULL;
        return;
    }

    Node *temp = *head;

    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

// Search
bool search(Node *head, int key)
{
    while (head != NULL)
    {
        if (head->data == key)
            return true;

        head = head->next;
    }

    return false;
}

// Display
void display(Node *head)
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL" << endl;
}

// Main Function
int main()
{
    Node *head = NULL;

    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);

    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    cout << "Linked List: ";
    display(head);

    if (search(head, 30))
        cout << "30 Found\n";
    else
        cout << "30 Not Found\n";

    deleteAtBeginning(&head);
    deleteAtEnd(&head);

    cout << "After Deletion: ";
    display(head);

    return 0;
}