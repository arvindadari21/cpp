#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

class SingleLinkedList
{
    public:
        Node* head;

    public:
        // Constructor
        SingleLinkedList()
        {
            cout << "Constructor called" << endl;
            head = nullptr;
        };

        // Destructor
        ~SingleLinkedList()
        {
            cout << "Desturctor called" << endl;
        };

        // Choice 1
        void addAtBegining(int val)
        {   
            // Create the node
            Node* newNode = new Node;
            newNode->data = val;
            newNode->next = head;

            // Setting the start of SLL to current node
            head = newNode;
            cout << "Head at: " << head << endl;
        }

        // Choice 2
        void addAtEnd(int val)
        {
            // Create the node
            Node* newNode = new Node;
            Node* temp = head;

            // If the SLL is empty
            if(head == nullptr)
            {
                cout << "Single Linked list is empty, adding the data" << endl;
                newNode->data = val;
                newNode->next = head;
                head = newNode;
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
        }

        // Choice 3
        void addAtPosition(int pos, int val)
        {
            // Create the node
            Node* newNode = new Node;
            Node* temp = head;
            Node* prev = nullptr;

            // Check if SLL is empty, if empty add the node at the begining.
            if(head == nullptr)
            {
                cout << "Linked list is empty, adding the node at the start" << endl;
                return addAtBegining(val);
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
                return addAtEnd(val);
            }
            
            // Insert the data
            newNode->data = val;
            newNode->next = temp;
            if(prev != nullptr)
                prev->next = newNode;

            if(position == 1)
                head = newNode;
        }

        // Choice 4
        void deleteAtBegining()
        {
            if(head == nullptr)
            {
                cout << "Linked list empty, cannot delete" << endl;
            }
            else
            {
                cout << "Deleting the element: " << head->data << " at position: 1" << endl;

                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }

        // Choice 5
        void deleteAtEnd()
        {
            Node* temp = head;
            Node* prev = nullptr;

            if(head == nullptr)
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
                    head = nullptr;

                delete temp;
            }
        }

        // Choice 6
        void deleteAtPosition(int pos)
        {
            Node* temp = head;
            Node* prev = nullptr;

            if(head == nullptr)
                cout << "Linked list empty, cannot delete" << endl;
            
            // Move to the position
            int position = 1;
            while(temp->next != nullptr && position != pos)
            {
                prev = temp;
                temp = temp->next;
                position++;
            }

            if(position < pos)
                // Mentioned position is greater than length of linked list, in this case, add at the end
                cout << "Mentioned position is greater than linked list length, cannot delete" << endl;

            if(position == 1)
                head = temp->next;
            else
                prev->next = temp->next;

            delete temp;
        }

        // Choice 7
        void display()
        {
            int pos = 1;
            if(head == nullptr)
            {
                cout << "Empty linked list" << endl;
            }
            else
            {
                while(head != nullptr)
                {
                    cout << head->data << "(" << pos << ")";
                    head = head->next;
                    if(head != nullptr)
                        cout << "->";
                    pos++;
                }
                cout << endl;
            }
        }

        // Choice 8
        void reverseLinkedList()
        {
            // Display the actual order
            cout << "************************" << endl;
            cout << "Before reversing the SLL" << endl;
            display();
            cout << "************************" << endl;

            Node* currentNode = head;
            Node* prevNode = nullptr;
            Node* nextNode = nullptr;
            // Reverse the SLL logic
            // Check if SLL empty
            if(head == nullptr)
                cout << "Linked list empty, cannot reverse" << endl;

            while(currentNode->next != nullptr)
            {
                nextNode = currentNode->next;
                currentNode->next = prevNode;

                prevNode = currentNode;
                currentNode = nextNode;
            }
            currentNode->next = prevNode;

            head = currentNode;

            // Display the reversed order
            cout << "************************" << endl;
            cout << "After reversing the SLL" << endl;
            display();
            cout << "************************" << endl;
        }

};

int main()
{
    int choice;
    bool run_loop = true;
    
    // Head pointer
    SingleLinkedList sll;

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
                sll.addAtBegining(dataToAddAtBegining);
                break;
            case 2:
                int dataToAddAtEnd;
                cout << "Please enter the value to add to linked list: ";
                cin >> dataToAddAtEnd;

                cout << "Adding the value: " << dataToAddAtEnd << " to the single linked list" << endl;
                sll.addAtEnd(dataToAddAtEnd);
                break;
            case 3:
                int dataAtPosition, position;
                cout << "Please enter the position: ";
                cin >> position;
                cout << "Please enter the value to add to linked list: ";
                cin >> dataAtPosition;

                cout << "Adding the value: " << dataAtPosition << " to the single linked list at position: " << position << endl;
                sll.addAtPosition(position, dataAtPosition);
                break;
            case 4:
                sll.deleteAtBegining();
                break;
            case 5:
                sll.deleteAtEnd();
                break;
            case 6:
                int nodePosition;
                cout << "Please enter the position: ";
                cin >> nodePosition;
                sll.deleteAtPosition(nodePosition);
                break;
            case 7:
                cout << "Displaying the single linked list" << endl;
                sll.display();
                break;
            case 8:
                cout << "Reversing the single linked list" << endl;
                sll.reverseLinkedList();
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