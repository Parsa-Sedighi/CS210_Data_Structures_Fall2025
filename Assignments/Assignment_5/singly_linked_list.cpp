#include <iostream>

class sLinkedList
{
public: 
    // singly linked list node 
    struct Node {
        // data inside the node
        int   data;
       
        // Pointer to the prev node
        Node* next;
        // Constructor, using member initialized
        explicit Node(int d) : data(d), next(nullptr) {}

        Node(int d, Node* next){
        this->data = d;
        this->next = next;
        }    

        };

    // Head of the list
    Node* head;

    sLinkedList() {
     head = nullptr; 
    }  

    void push_front(int data)
    {
        Node* tempNode = new Node(data, head);
        head = tempNode;
    }

    void push_back(int data)
    {
        if (!head) {                          
            head = new Node(data);
            return;
        }
        Node* prevLastNode = head;
        while (prevLastNode->next != nullptr) 
            prevLastNode = prevLastNode->next;

        prevLastNode->next = new Node(data); 
    };
    
    void insert(int index, int data )
    {
        if(index == 0)
        {
            head = new Node(data,head);
        }
        else {
            Node* temp = head;
            for(int i=0; i<index-1; ++i)
            {
                temp = temp->next;
            }
            // New node, pointing to the next element
            Node* newNode = new Node(data,temp->next);

            temp->next = newNode;
        }        
    };

    void erase(int index)
    {
        if (!head || index < 0) return;       
        if (index == 0)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < index - 1 && temp->next; ++i) 
            temp = temp->next;

        if (!temp->next) return;              
        Node* tbd = temp->next;
        temp->next = tbd->next;
        delete tbd;
    }

    // Returns the index where the value was found
    int find(int value)
    {
        // Initialize index
        int i = 0;
        // Assign head to temp value
        Node* temp = head;
        // Repeat the following loop until have reached the end of the list
        while(temp != nullptr)
        {
            //If the data pointed to by temp is equal...
            if(temp->data == value)
            {
                // Return the index
                return i;
            }
            temp = temp->next;
            // Increment index;
            ++i;  
        }
        //Not found anything
        return -1;
    }

    //Return the size of the linked list
    int size(){
        // Initialize temporary value
        Node* temp = head;
        // Initialize length
        int length = 0;
        // While the current node is not a null pointer
        while(temp != nullptr)
        {
            // traverse to the next node
            temp = temp->next;
            //Increment length
            length++;
        }
        //Return the length
        return length;
    }

    void printListForward(Node* head)
    {
    Node* temp = head;
    std::cout << "Forward List: ";
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
    }


};



int main () {
    
     sLinkedList singly_linkedlist;
    singly_linkedlist.push_front(20);
    singly_linkedlist.push_front(10);
    singly_linkedlist.push_back(40);
    std::cout << "index of 40: " << singly_linkedlist.find(40) << std::endl;
    singly_linkedlist.insert(3,30);
    singly_linkedlist.printListForward(singly_linkedlist.head);
    singly_linkedlist.erase(2);
    
    singly_linkedlist.printListForward(singly_linkedlist.head);
    std::cout << "Size: " << singly_linkedlist.size() << std::endl;

    return 0;
};