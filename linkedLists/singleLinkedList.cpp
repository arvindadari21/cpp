#include<iostream>

using namespace std;

/*
This is the single linked list(SLL) practice in C++
This transaction unit will perform the operations on a single linked list based 
on the user choice.
The operations performed are as mentioned below
1) Add a node at the begining of the SLL
2) Add a node at the end of the SLL
3) Add a node at a specific position in the SLL
4) Delete at the begining of the SLL
5) Delete the last node of the SLL
6) Delete a particular positional node from the SLL
7) Print the SLL
8) Reverse the SLL

*/

struct Node
{
    int data;
    Node* next;
};

// Choice 1
Node* addAtBegining(int val, Node* start)
{   
    // Create the node
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = start;

    // Setting the start of SLL to current node
    start = newNode;

    // returning the start-node of SLL
    return newNode;
}

// Choice 2
Node* addAtEnd(int val, Node* start)
{
    // Create the node
    Node* newNode = new Node;
    Node* temp = start;

    // If the SLL is empty
    if(start == nullptr)
    {
        cout << "Single Linked list is empty, adding the data" << endl;
        newNode->data = val;
        newNode->next = start;
        start = newNode;
    }
    // If the SLL contains data
    else
    {
        // Traverse till the end of the single linked list
        while(temp->next != nullptr)
            temp = temp->next;
            
        // Insert the data and add the new node to SLL
        newNode->data = val;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // returning the start-node of SLL
    return start;
}

// Choice 3
Node* addAtPosition(int pos, int val, Node* start)
{
    // Create the node
    Node* newNode = new Node;
    Node* temp = start;
    Node* prev = nullptr;

    // Check if SLL is empty, if empty add the node at the begining.
    if(start == nullptr)
    {
        cout << "Linked list is empty, adding the node at the start" << endl;
        return addAtBegining(val, start);
    }
    
    // Move to the position
    int position = 1;
    while(temp->next != nullptr && position != pos)
    {
        prev = temp;
        temp = temp->next;
        position++;
    }

    if(position < pos)
    {
        // Mentioned position is greater than length of linked list, in this case, add at the end
        cout << "Mentioned position is greater than linked list length, adding at the end; position: " << position+1 << endl;
        return addAtEnd(val, start);
    }
    
    // Insert the data
    newNode->data = val;
    newNode->next = temp;
    if(prev != nullptr)
        prev->next = newNode;

    if(position == 1)
        start = newNode;

    // Return the head node
    return start;
}

// Choice 4
Node* deleteAtBegining(Node* start)
{
    if(start == nullptr)
    {
        cout << "Linked list empty, cannot delete" << endl;
    }
    else
    {
        cout << "Deleting the element: " << start->data << " at position: 1" << endl;

        Node* temp = start;
        start = start->next;
        delete temp;
    }

    return start;
}

// Choice 5
Node* deleteAtEnd(Node* start)
{
    Node* temp = start;
    Node* prev = nullptr;

    if(start == nullptr)
    {
        cout << "Linked list empty, cannot delete" << endl;
    }
    else
    {
        while(temp->next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }
        if(prev != nullptr)
            prev->next = nullptr;
        else
            start = nullptr;

        delete temp;
    }

    return start;
}

// Choice 6
Node* deleteAtPosition(int pos, Node* start)
{
    Node* temp = start;
    Node* prev = nullptr;

    if(start == nullptr)
    {
        cout << "Linked list empty, cannot delete" << endl;
        return start;
    }
    
    // Move to the position
    int position = 1;
    while(temp->next != nullptr && position != pos)
    {
        prev = temp;
        temp = temp->next;
        position++;
    }

    if(position < pos)
    {
        // Mentioned position is greater than length of linked list, in this case, add at the end
        cout << "Mentioned position is greater than linked list length, cannot delete" << endl;
        return start;
    }

    if(position == 1)
        start = temp->next;
    else
        prev->next = temp->next;

    delete temp;

    // Return the head node
    return start;
}

// Choice 7
void display(Node* start)
{
    int pos = 1;
    if(start == nullptr)
    {
        cout << "Empty linked list" << endl;
    }
    else
    {
        while(start != nullptr)
        {
            cout << start->data << "(" << pos << ")";
            start = start->next;
            if(start != nullptr)
                cout << "->";
            pos++;
        }
        cout << endl;
    }
}

// Choice 8
Node* reverseLinkedList(Node* start)
{
    // Display the actual order
    cout << "************************" << endl;
    cout << "Before reversing the SLL" << endl;
    display(start);
    cout << "************************" << endl;

    Node* currentNode = start;
    Node* prevNode = nullptr;
    Node* nextNode = nullptr;
    // Reverse the SLL logic
    // Check if SLL empty
    if(start == nullptr)
    {
        cout << "Linked list empty, cannot reverse" << endl;
        return start;
    }

    while(currentNode->next != nullptr)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;

        prevNode = currentNode;
        currentNode = nextNode;
    }
    currentNode->next = prevNode;

    start = currentNode;

    // Display the reversed order
    cout << "************************" << endl;
    cout << "After reversing the SLL" << endl;
    display(start);
    cout << "************************" << endl;

    // Return the start point
    return start;
}

int main()
{
    int choice;
    bool run_loop = true;
    
    // Head pointer
    Node* head = nullptr;

    do
    {
        cout << "" << endl;
        cout << "*************  Menu  *************" << endl;
        cout << "1) Add a node at the begining of the SLL" << endl;
        cout << "2) Add a node at the end of the SLL" << endl;
        cout << "3) Add a node at a specific position in the SLL" << endl;
        cout << "4) Delete at the begining of the SLL" << endl;
        cout << "5) Delete the last node of the SLL" << endl;
        cout << "6) Delete a particular positional node from the SLL" << endl;
        cout << "7) Print the SLL" << endl;
        cout << "8) Reverse the SLL" << endl;
        cout << "9) Exit" << endl;
        cout << "**********************************" << endl;
        cout << "" << endl;

        cout << "Enter the choice of operation: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                int dataToAddAtBegining;
                cout << "Please enter the value to add to linked list: ";
                cin >> dataToAddAtBegining;

                cout << "Adding the value: " << dataToAddAtBegining << " to the single linked list" << endl;
                head = addAtBegining(dataToAddAtBegining, head);
                break;
            case 2:
                int dataToAddAtEnd;
                cout << "Please enter the value to add to linked list: ";
                cin >> dataToAddAtEnd;

                cout << "Adding the value: " << dataToAddAtEnd << " to the single linked list" << endl;
                head = addAtEnd(dataToAddAtEnd, head);
                break;
            case 3:
                int dataAtPosition, position;
                cout << "Please enter the position: ";
                cin >> position;
                cout << "Please enter the value to add to linked list: ";
                cin >> dataAtPosition;

                cout << "Adding the value: " << dataAtPosition << " to the single linked list at position: " << position << endl;
                head = addAtPosition(position, dataAtPosition, head);
                break;
            case 4:
                head = deleteAtBegining(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                break;
            case 6:
                int nodePosition;
                cout << "Please enter the position: ";
                cin >> nodePosition;
                head = deleteAtPosition(nodePosition, head);
                break;
            case 7:
                cout << "Displaying the single linked list" << endl;
                display(head);
                break;
            case 8:
                cout << "Reversing the single linked list" << endl;
                head = reverseLinkedList(head);
                break;
            case 9:
                run_loop = false;
                cout << "Exiting the Linked list" << endl;
                break;
            default:
                run_loop = false;
                cout << "Invalid choice, please try again" << endl;
                break;
        }
    } while (run_loop);

}