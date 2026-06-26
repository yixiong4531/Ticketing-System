#include <iostream>
using namespace std;

// Node Structure
struct Node
{
    int data;      // Ticket Number
    Node* link;    // Pointer to next node
};

// Global pointers
Node* pHead = NULL;
Node* pTail = NULL;

// Metadata
int noItems = 0;
int currentTicket = 1;

// Enqueue (Insert Item at End)
void Enqueue()
{
    Node* pNew = new Node;

    pNew->data = currentTicket;
    currentTicket++;

    pNew->link = NULL;

    // Empty queue
    if (noItems == 0)
    {
        pHead = pNew;
        pTail = pNew;
    }
    else
    {
        pTail->link = pNew;
        pTail = pNew;
    }

    noItems++;

    cout << ">>> Customer with Ticket #" << pNew->data
        << " joined the queue.\n";
}

// Dequeue (Delete First Node)
void Dequeue()
{
    if (pHead == NULL)
    {
        cout << ">>> Queue is empty.\n";
        return;
    }

    Node* pTemp;

    pTemp = pHead;

    cout << ">>> Serving Customer with Ticket #"
        << pHead->data << endl;

    pHead = pTemp->link;

    delete pTemp;

    noItems--;

    if (pHead == NULL)
    {
        pTail = NULL;
    }
}

// View Front Customer
void QueueFront()
{
    if (pHead == NULL)
    {
        cout << ">>> Queue is empty.\n";
    }
    else
    {
        cout << ">>> Customer at front : Ticket #"
            << pHead->data << endl;
    }
}

// Traverse and Display Queue
void DisplayQueue()
{
    if (pHead == NULL)
    {
        cout << ">>> Queue is empty.\n";
        return;
    }

    Node* pTraverse;

    pTraverse = pHead;

    cout << ">>> Current Queue : ";

    while (pTraverse != NULL)
    {
        cout << "[" << pTraverse->data << "] ";
        pTraverse = pTraverse->link;
    }

    cout << endl;
}

// Display Total Customers
void TotalCustomers()
{
    cout << ">>> Total customers waiting : "
        << noItems << endl;
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n=========================================\n";
        cout << "      BANK COUNTER TICKETING SYSTEM\n";
        cout << "=========================================\n";
        cout << "1. Add a new customer to the line (Enqueue)\n";
        cout << "2. Call the next customer to the counter (Dequeue)\n";
        cout << "3. View the customer currently waiting at the front\n";
        cout << "4. Display all customers in queue\n";
        cout << "5. Display total customers waiting\n";
        cout << "6. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        cout << endl;

        switch (choice)
        {
        case 1:
            Enqueue();
            break;

        case 2:
            Dequeue();
            break;

        case 3:
            QueueFront();
            break;

        case 4:
            DisplayQueue();
            break;

        case 5:
            TotalCustomers();
            break;

        case 6:
            cout << ">>> Exiting system. Have a great day!\n";
            return 0;

        default:
            cout << ">>> Invalid choice. Please try again.\n";
        }
    }

    return 0;
}