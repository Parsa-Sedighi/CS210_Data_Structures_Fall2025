#include "vector"
#include "array"



// Stack (Array-Based, Push/Pop to Internal Front)
class array_stack {
private:
    int allocation_Size;
    int max_Length;
    int current_Array_Length;
    int* array;

    void resize(){
        
    allocation_Size = allocation_Size * 2;
    int* new_Array = new int[allocation_Size];

    for( int i = 0; i < current_Array_Length; i++){
        new_Array[i] = array[i];
    }
    delete[] array;
    array = new_Array;
    }


public: 
    // Constructor
    array_stack(int optional_Max_Length = -1){
        allocation_Size = 1;
        array = new int[allocation_Size];
        current_Array_Length = 0;
        max_Length = optional_Max_Length;
    }
    // Destructor
    ~array_stack()
    {
        delete[] array;
    }
    // Push items to the bottom of stack
    bool push_bottom(int data){
        if ( current_Array_Length == max_Length)
        {
            return false;
        }
        if( current_Array_Length == allocation_Size)
        {
            resize();
        }
        if(current_Array_Length > 1){
            for(int i=current_Array_Length-1; i > 0; i--){
                array[i] = array[i-1];
            }
            
        }
        array[0] = data;
        current_Array_Length++;
        return true;

    }
    //Pop items from the bottom of stack
    int pop_bottom()
    {
       
        int value_removed = array[0];
        if(current_Array_Length > 1){
            for(int i = 0; i < current_Array_Length-1; i++){
                array[i] = array[i+1];
            }
        }
        current_Array_Length--;
        return value_removed;
    }

    // Stack (Array-Based, Push/Pop to Internal Back)

       // Push items to the top of stack
    bool push_top(int data){
        if ( current_Array_Length == max_Length)
        {
            return false;
        }
        if( current_Array_Length == allocation_Size)
        {
            resize();
        }
        array[current_Array_Length] = data;
        current_Array_Length++;
        return true;
    }
    //Pop items from the top of stack
    int pop_top()
    {
        current_Array_Length--;
        return array[current_Array_Length];
    }
};



// Node class to store an item and be used in linked lists
class StackNode{
public:
    int data = 0;
    StackNode* next;
    StackNode(int data, StackNode* next_Node){
        this->data = data;
        this->next = next_Node;
    }
};

// Stack (LinkedList-Based, Push/Pop to Internal Front)
class internal_front_linkedL_stack {
private:
    StackNode* top;
public: 
    internal_front_linkedL_stack(){
        top = nullptr;
    }
    ~ internal_front_linkedL_stack(){
        while(top){
            StackNode* node_To_Delete = top;
            top = top->next;
            delete node_To_Delete;
        }
    }

    void push_front(int newData){
        top = new StackNode(newData, top);
    }

    int pop_front(){
        StackNode* popped_Node = top;
        int popped_item = top->data;

        top = top->next;

        delete popped_Node;

        return popped_item;
    }

    // Stack (LinkedList-Based, Push/Pop to Internal Back)
    void push_back(int newData){

        if( top == nullptr){
            top = new StackNode(newData, nullptr);
            return;
        }

        StackNode* current_Node = top;
        while(current_Node->next != nullptr){
            current_Node = current_Node->next;
        }

        current_Node->next = new StackNode(newData, nullptr);
      
    }

    int pop_back(){
        if( top->next == nullptr){
            int popped_item = top->data;
            delete top;
            top = nullptr;
            return popped_item;
        }

        StackNode* popped_Node = top;
        while(popped_Node->next->next != nullptr){
            popped_Node = popped_Node->next;
        }
        int popped_Item = popped_Node->next->data ;
        delete popped_Node->next;
        popped_Node->next = nullptr;
        return popped_Item;
    }
};





int main (){
Array_Queue queue;
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