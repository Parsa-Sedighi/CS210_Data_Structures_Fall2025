// Part 1
#include <iostream>

// A simple Binary Search Tree(BST)
struct Tree {

    public:
    int data;
    Tree* left;
    Tree* right;

    Tree (int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// Print function to output Tree in-order
std::ostream& operator<<(std::ostream& os, Tree* Tree){

  
    if(Tree == nullptr){
        return os;
    }

    os << Tree->left << ", " << Tree ->data << Tree->right;
    return os;
}

// Insert function to add an item in-order to the Tree
void insert(Tree*& root, int data){

    if(root == nullptr){

        root = new Tree(data);
        return;
    }
    if(data < root->data){
        insert(root->left,data);
    }
    else
    {
        insert(root->right,data);
    }
}

// Search function to look for items in a Binary Search Tree
bool search(Tree* root, int data){
    if(root == nullptr){
        return false;
    }
    if(root->data == data){
        return true;
    }
    if(root->data > data){
        return search(root->left,data);
    }
    else
    {
        return search(root->right, data);
    }
}


int main(){

    //Create tree pointer
    Tree* tree = nullptr;

    // Insert 3, 1, 2, 5, 6
    insert(tree,3);
    insert(tree,1);
    insert(tree,2);
    insert(tree,5);
    insert(tree,6);

    //Display the Tree in the output stream
    std::cout << tree << std::endl;

    // Display whether found 4
    std::cout << "Found 4? " << search(tree,4) << std::endl;

    // Display whether found 5
    std::cout << "Found 5? " << search(tree,5) << std::endl;
    
    
};
