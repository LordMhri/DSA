#include <iostream>

using namespace std;

struct Node {
    Node *left;
    Node *right;
    int data;

    Node(int data) : left(nullptr), right(nullptr), data(data) {};
};

class BinaryTree
{
private:
    Node *root;
public:
    BinaryTree() : root(nullptr) {};
    

    void insert(int data) {
        if (!root)
        {
            root = new Node(data);
            return;
        }

        Node *current = root;
        while (true)
        {
            if (data < current->data){ // if the current data is less than the root data
                if (current->left == nullptr) //if left node doesn't exist
                {
                    current->left = new Node(data);
                    break;
                }
                current = current->left; 
                // continue as long as we dont find an appropriate place
                // to put the new node in

            } else {
                if (current->right == nullptr)
                {
                    current->right = new Node(data);
                    break;
                }
                current = current->right;
            }
        }
        
    }
};





int main(int argc, char const *argv[])
{
    
    return 0;
}
