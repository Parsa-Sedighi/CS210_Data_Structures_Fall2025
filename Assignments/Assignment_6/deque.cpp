#include "iostream"
#include "vector"

// DEQUEUE//

// Array Based
class array_deque{
private:
    std::vector<int> array = {0};

public:
    //Push to the front
    void push_front(int data){
        array.insert(array.begin(),data);
    }
    //Push to the back
    void push_back(int data){
        array.push_back(data);
    }
    //Remove from front
    int pop_front(){
        int removed_value = array.front();
        array.erase(array.begin());
        return  removed_value;
    }
    // Remove from back 
    int pop_back(){

        int removed_value = array.back();
        array.pop_back();
        return removed_value;
    }
};

// Linked List based
class QueueNode {
public:
   int data;
   QueueNode* next;
   QueueNode* prev;
   
   QueueNode(int dataValue, QueueNode* nextNode = nullptr,QueueNode* prevNode = nullptr ) {
      data = dataValue;
      next = nextNode;
      prev = prevNode;
   }
};

class linkedL_deque{
private:
    QueueNode* front;
    QueueNode* back;
public:
    linkedL_deque(){
        front = nullptr;
        back = nullptr;
    }

    bool push_front(int data){
        QueueNode* tempNode = new QueueNode(data);
        if(front == nullptr){
            front = back = tempNode;
        }
        else{
            tempNode->next = front;
            front->prev = tempNode;
            front = tempNode;

        }
        return true
    }

    bool push_back(int data){
        QueueNode* tempNode = new QueueNode(data);
        if (back == nullptr){
            front = back = tempNode;
        }
        else{
            back -> next = tempNode;
            tempNode->prev = back;
            back = tempNode;
            
        }
        return true;

    }

    int pop_front(){
        if( front == nullptr){
            return -1;
        }
        
        int data = front->data;
        QueueNode* tempNode = front;
        front = front->next;

        if(front != nullptr){
            front->prev = nullptr;
        }
        else if(back == nullptr){
            back = nullptr;
        }
        delete tempNode;
        return data;
    }

    int pop_back(){
        if(back == nullptr){
            return -1;
        }
        int data = back->data;
        QueueNode* tempNode = back;
        back = back->prev;
        if(back != nullptr){
            back->next = nullptr;
        }
        else{
            front = nullptr;
            delete tempNode;
            return data;
        }
    }

};
