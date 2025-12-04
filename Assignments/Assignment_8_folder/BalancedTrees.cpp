// Part 2
#include <iostream>
#include <algorithm>

class AVL_Node{
public:
    int data;
    AVL_Node* left;
    AVL_Node* right;
    int height;  

    AVL_Node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
        height = 1;

    }
};

class AVL_Tree{
public:
    AVL_Node* root;

    int get_height(AVL_Node* node){
        if(node == nullptr)
            return -1;
        return node->height;
    }
    int balance_factor(AVL_Node* node){
        if (node == nullptr){
            return -1;
        }

        return (get_height(node->left) - get_height(node->right));
    }

    AVL_Node* right_rotate(AVL_Node* node){
    AVL_Node* node2 = node->left;
    AVL_Node* node3 = node2->right;

    node2->right = node;
    node->left = node3;

    node->height = max(get_height(node->left), get_height(node->right)) +1;
    node2->height = max(get_height(node2->left), get_height(node2->right)) +1;

    return node2;
    }

    AVL_Node* left_rotate(AVL_Node* node)
    {
        AVL_Node* node2 = node->right;
        AVL_Node* node3 = node2->left;

        node2->left = node;
        node->right = node3;

        // Update heights
        node->height = max(get_height(node->left), get_height(node->right)) + 1;
        node2->height = max(get_height(node2->left), get_height(node2->right)) + 1;

        // Return new root
        return node2;
    }

    // Print function to output Tree in-order
    std::ostream& operator<<(std::ostream& os, AVL_Tree* node){
    if(Tree == nullptr){
        return os;
    }

    os << Tree->left << ", " << Tree ->data << Tree->right;
    return os;
}

      // Insert function to add an item in-order to the Tree
    void insert(AVL_Node*& root, int data){

        if(root == nullptr){

            root = new AVL_Node(data);
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


};

  
int main(){

    //Create tree pointer
    AVL_Tree* tree = nullptr;

    // Insert 3, 1, 2, 5, 6
    insert(tree,3);
    insert(tree,1);
    insert(tree,2);
    insert(tree,5);
    insert(tree,6);

    left_rotate(tree);
    right_rotate(tree);

    std::cout<< "Height" << get_height() << "Tree: " << tree;  
};


