#include <iostream>

class dLinkedList
{
public: 
    // doubly linked list node 
    struct Node {
        // data inside the node
        int   data;
        // Pointer to the next node
        Node* prev;
        // Pointer to the prev node
        Node* next;
        // Constructor, using member initialized
        explicit Node(int d) : data(d), prev(nullptr), next(nullptr) {}
        };

    // Head of the list
    Node* head;

    dLinkedList() {
     head = nullptr; 
    }  
    
    
    void push_front(int data)
    {
        // Initialize a new node
        Node* tempNode = new Node(data);
        // If the list is empty
        if(head == nullptr){
            //the new node will be the head
            head = tempNode;
        }
        //If the list is not empty
        else{
            // the new nodes will point next to the head
            tempNode->next = head;
            // The head node will point prev to new node
            head->prev = tempNode;
            // the new node, will be the head/first item in the list
            head = tempNode;
        }
    }
    void push_back(int data)
    {
        // Initialize a new node
        Node* tempNode = new Node(data);
        // If the list is empty
        if(head == nullptr){
            //the new node will be the head
            head = tempNode;
        }
        //If list is not empty
        else {
            //Assign head to travering node
            Node* traverse = head;
            //Keep traversing until have reached the end/last item of the list
            while(traverse->next != nullptr){
                traverse = traverse->next;
            }
            // Point the last item on the list to new node.
            traverse->next = tempNode;
            // Point the prev pointer of the recent last node/item to the node/item before.
            tempNode->prev = traverse;
        }
    };

    void insert(int index, int data )
    {
        //if the list is empty
        if(head == nullptr)
        {
            // Do not proceed
            return;
        }
        else if(index == 1)
        {
            // we can call push_front function
            push_front(data);

        }
        else{

            // Initialize a new node
            Node* tempNode = new Node(data);
            // Initialize and assign head to new node
            // Traverse through the array until have reached 1 index before the specified index
            Node* traverse = head;
            for(int i = 1; i < index-1;++i)
            {
                traverse = traverse->next;
            }

            // the new node points next to the specified index where the node is
            tempNode->next = traverse->next;
            // The new node points prev to the node before the specified index where node is
            tempNode->prev = traverse;
            // If there is a node after the current node
            if( traverse->next != nullptr){
                // Point the prev to the new node
                traverse->next->prev = tempNode;
            }
            // Point the next to the new node
            traverse->next = tempNode;
        }
        
    };

    void erase(int index)
    {
         //if the list is empty
        if(head == nullptr)
        {
            // Do not proceed
            return;
        }
        else if(index == 1)
        {
            // Assign the head to the new node
            Node* tempNode = head;
            // Traverse once to the next item/node on list
            head = head->next;
            // If the first item after head exists...
            if(head != nullptr)
            {
                //The prev will point to nothing(As head usually is)
                head->prev = nullptr;
            }
            //Delete the tempNode
            delete tempNode;
        }
        else if(index > 1)
        {
            Node* tempNode = head;
            for(int i=1 ; i < index; ++i ){
                tempNode = tempNode->next;
            }
            //If we have not traversed to the last item
            if(tempNode->next != nullptr)
            {
                // Point the prev of the item to the right, to the item of the left ,  
                tempNode->next->prev = tempNode->prev;
            }
            if( tempNode->prev != nullptr)
            {
                // Point the next of the item to the left, to the item of the right ,  
                tempNode->prev->next = tempNode->next;
            }
            // Delete the node
            delete tempNode;
        }
      
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
    
    dLinkedList doublyList;
    doublyList.push_front(2);
    doublyList.push_front(1);
    doublyList.push_back(4);
    doublyList.insert(3,3);
    doublyList.printListForward(doublyList.head);
    doublyList.erase(2);
    doublyList.printListForward(doublyList.head);
    std::cout << "index of 4: " << doublyList.find(4) << std::endl;
    std::cout << "Size: " << doublyList.size() << std::endl;

    return 0;
};