#include "iostream"
#include "vector"
#include "array"




//Queue (Array-Based, Enqueue to Internal Back, Dequeue from Front)
class Array_Queue{
private:
    int allocationSize;
    int* array;
    int front_Index;
    int length;
    int max_Length;

    void Resize() {
      // Allocate new array and copy existing items
      int new_Size = allocationSize * 2;
      if (max_Length >= 0 && new_Size > max_Length) {
         new_Size = max_Length;
      }
      int* new_Array = new int[new_Size];
      for (int i = 0; i < length; i++) {
         int item_Index = (front_Index + i) % allocationSize;
         new_Array[i] = array[item_Index];
      }
        delete[] array;
        array = new_Array;
        allocationSize = new_Size;
        front_Index = 0;
    }
public:
    Array_Queue(int maximum_Length = -1){
        if(0 == maximum_Length) 
        {
            allocationSize = 0;
        }
        allocationSize = 1;
        array = new int[allocationSize];
        length = 0;
        front_Index = 0;
        max_Length = maximum_Length;

    }
    ~Array_Queue() {
        delete[] array;
    }
    
    // Add to internal front
    bool enqueue_front(int data){
        if(length == max_Length){
            return false;
        }
        if(length == allocationSize){
            if(allocationSize == 0){
                allocationSize =1;
                array = new int[allocationSize];
            } else {
                Resize();
            }
        }
        for(int i= length-1; i > 0; i--){
            array[i] = array[i-1];
        }
            
        array[0] = data;
        length++;
        return true;
   }

    // Remove from internal back
    int dequeue_back(){
        int toReturn = array[length-1];
        length--;
      
        return toReturn;
    }

    //- Queue (Array-Based, Enqueue to Internal Back, Dequeue from Front)

    // Add to internal back
    bool enqueue_back(int data){
        if(length == max_Length){
            return false;
        }
        if (length == allocationSize) {
         Resize();
        }

        int item_Index = (front_Index + length) % allocationSize;
        array[item_Index] = data;
        length++;
        return true;

    }

    // Remove from internal front
    int dequeue_front() {
      // Get the item at the front of the queue
      int toReturn = array[front_Index];
      
      // Decrement length and advance frontIndex
      length--;
      front_Index = (front_Index + 1) % allocationSize;
      
      // Return the front item
      return toReturn;
   }

};

//- Queue (LinkedList, Enqueue to Internal Back, Dequeue from Front)
class QueueNode {
public:
   int data;
   QueueNode* next;
   
   QueueNode(int dataValue, QueueNode* nextNode = nullptr) {
      data = dataValue;
      next = nextNode;
   }
};

class LinkedL_Queue{
private:
   QueueNode* front;
   QueueNode* end;

public:
   LinkedL_Queue() {
      front = nullptr;
      end = nullptr;
   }
   
   virtual ~LinkedL_Queue() {
      while (front) {
         QueueNode* nodeToDelete = front;
         front = front->next;
         delete nodeToDelete;
      }
   }

   // Add to internal back
    bool enqueue_back(int newData)  {
      // Create a new node
      QueueNode* newNode = new QueueNode(newData);
      
      // Append newNode to the end of the linked list
      if (nullptr == front) {
         front = newNode;
      }
      else {
         end->next = newNode;
      }
      end = newNode;
      
      return true;
   }
   
   // Remove from internal front
    int dequeue_front()  {
      // Copy front node's data
      QueueNode* dequeuedNode = front;
      int dequeuedItem = front->data;
      
      // Remove front node
      front = front->next;
      delete dequeuedNode;
      if(nullptr == front){
        end = nullptr;
      }
      return dequeuedItem;
    }

    // Queue (LinkedList, Enqueue to Internal Front, Dequeue from Back)

    // Add to internal front
    bool enqueue_front(int newData)  {
        QueueNode* newNode = new QueueNode(newData);
        if(nullptr == front){
            front = end = newNode;
        }
        else{
            newNode->next = front;
            front = newNode;
        }
        
        return true;
    }
    // Remove from internal back
    int dequeue_back(){

        int dequeuedItem = end->data;

        if (front == end){
            delete end;
            front = end = nullptr;
            return dequeuedItem;
        }

        QueueNode* traverseNode = front;
        while(traverseNode->next != end){
            traverseNode = traverseNode->next;
        }

        traverseNode->next = nullptr;
        delete end;
        end = traverseNode;

        return dequeuedItem;

    }

};

int main (){
LinkedL_Queue queue;
queue.enqueue_front(9);
queue.enqueue_front(2);
queue.enqueue_front(3);
queue.enqueue_front(4);


std::cout << queue.dequeue_back()  << std::endl;
std::cout << queue.dequeue_back()  << std::endl;
std::cout << queue.dequeue_back()  << std::endl;


//linked_stack.push_front(1);
//array_stack.push(2);
//array_stack.push(3);
//array_stack.push(4);
//array_stack.push(5);
//
//std::cout << array_stack.pop() << std::endl;
//std::cout << array_stack.pop() << std::endl;
//std::cout << array_stack.pop() << std::endl;

return 0;


}