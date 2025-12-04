// Part 2
#include <iostream>
#include <algorithm>
//Build a min-heap using an array of 6 integers
//
//Perform one insert and one remove operation, showing the array after each step
//
//Explain briefly how the heap property is maintained

class Heap{

private:
    std::vector<int> array;

    void heap_items(int i);

public:
    Heap(){

    };

    void Heap::heapify(int i){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int size = array.size();

        if (left < size && array[left] > array[largest]){
            largest = left;
        }
        if (right < size && array[right] > array[largest]){
            largest = right;
        }
        if (largest != i) {
            swap(array[i], array[largest]);
            heapify(largest);
        }
    }

    void insert(int key){
        array.push_back(key);
        int size = array.size() - 1;
        while( array[(size-1) / 2] < array[size] && size != 0 ){
            swap(array[size], array[(size-1) / 2]);
            size = (size-1)/2;
        }
    }

    void remove(int index){
        if(index >= array.size()){
            std::cout << "Index does not exist!" << std::endl;
        }

        array[index] = array.back();
        array.pop_back();
        heap_items(index);
    }

    // Function to print the heap elements
    void Heap::printHeap(){
        for (int val : array){
            std::cout << val << " ";

        }
        std::cout << std::endl;
    }

};

int main()
{
    Heap heap;

    heap.insert(3);
    heap.insert(2);
    heap.insert(15);
    heap.printHeap();
    heap.remove(1);
    heap.printHeap();
    heap.remove(0);
    heap.printHeap();
}
