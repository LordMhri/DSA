#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {};
};

class BinarySearchTree
{
public:
    Node *root;

    BinarySearchTree() : root(nullptr) {};

    void insert(int data)
    {
        root = insertRec(root, data);
    }

    void deleteNode(int value)
    {   
        int choice;
        cout << "1) Delete From Max Left\n";
        cout << "2) Delete From Min Right\n";
        cin >> choice;
        if (choice == 1)
        {
            deleteRec(root,value,1);
        } else {
            deleteRec(root,value,2);
        }
    }

    void deleteByMerge(int value)
    {
        int choice;
        cout << "1) Delete From Max Left\n";
        cout << "2) Delete From Min Right\n";
        cin >> choice;
        if (choice == 1)
        {
            deleteMerge(root, value, 1);
        }
        else
        {
            deleteMerge(root, value, 2);
        }
    }

    void printInorderTraversal()
    {
        inorderTraversal(root);
        cout << endl;
    }

    void printPostOrderTraversal()
    {
        postOrderTraversal(root);
        cout << endl;
    }

    int height()
    {
        return heightOfTree(root);
    }

    void depthOfANode(int data)
    {
        int depth = depthOfANode(root, data, 0);
        if (depth != -1)
        {
            cout << "Depth of node with data " << data << " is: " << depth << endl;
        }
        else
        {
            cout << "Node with data " << data << " not found in the tree." << endl;
        }
    }

    void printPreOrderTraversal()
    {
        preOrderTraversal(root);
        cout << endl;
    }

private:
    int depthOfANode(Node *node, int data, int depth = 0)
    {
        if (node == nullptr)
        {
            return -1; // Node not found
        }
        if (node->data == data)
        {
            return depth;
        }
        int leftDepth = depthOfANode(node->left, data, depth + 1);
        if (leftDepth != -1)
        {
            return leftDepth;
        }
        return depthOfANode(node->right, data, depth + 1);
    }

    int heightOfTree(Node *root)
    {
        if (!root)
        {
            return 0;
        }
        int left_height = heightOfTree(root->left);
        int right_height = heightOfTree(root->right);
        return max(left_height, right_height) + 1;
    }

    Node *insertRec(Node *node, int data)
    {
        if (node == nullptr)
        {
            return new Node(data);
        }
        if (data < node->data)
        {
            node->left = insertRec(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insertRec(node->right, data);
        }
        return node;
    }

    Node *deleteRec(Node *root, int value,int choice)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (root->data < value)
        {
            root->right = deleteRec(root->right, value,choice);
        }
        else if (root->data > value)
        {
            root->left = deleteRec(root->left, value,choice);
        }
        else
        {
            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node *temp;
            if (choice == 1) {
                temp = minValueNode(root->right);
            } else {
                temp = maxValueNode(root->left);
            }            
            root->data = temp->data;
            root->right = deleteRec(root->right, temp->data,choice);
        }
        return root;
    }
    Node *deleteMerge(Node *root, int value, int choice)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (value < root->data)
        {
            root->left = deleteMerge(root->left, value, choice);
        }
        else if (value > root->data)
        {
            root->right = deleteMerge(root->right, value, choice);
        }
        else
        {
            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            } else if(root->right == nullptr) {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                if (choice == 1) // delete by merging the maxNode from the left
                {
                    Node *temp = maxValueNode(root->left);
                    temp->right = root->right;
                    temp = root;
                    root = root->left;
                    delete temp;
                } else { //delete by merging the minNode from the right
                    Node *temp = minValueNode(root->right);
                    temp->left = root->left;
                    temp = root;
                    root = root->right;
                    delete temp;
                }

            }
        }

        return root;
    }
   
    Node *minValueNode(Node *root)
    {
        Node *current = root;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    Node *maxValueNode(Node *root)
    {
        Node *current = root;
        while (current && current->right != nullptr)
        {
            current = current->right;
        }
        return current;
    }

    void inorderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void postOrderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }

    void preOrderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
};

int main()
{
    BinarySearchTree Btree;
    int arr[7] = {10, 5, 3, 7, 12, 15, 18};

    for (int i = 0; i < 7; i++)
    {
        Btree.insert(arr[i]);
    }

    cout << "These are the values in the tree now\n" << endl;
    Btree.printInorderTraversal();

    
    int choice, value;
    BinarySearchTree Copy;
    while (true)
    {
        cout << "Menu:\n";
        cout << "1. Inorder Traversal\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Postorder Traversal\n";
        cout << "4. Delete Node from a Copy Tree (Copy)\n";
        cout << "5. Delete Node from a Copy Tree (Merge) \n";
        cout << "6. Delete Node from real Tree Completely\n";
        cout << "7. Height of Tree\n";
        cout << "8. Depth of a Node\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Btree.printInorderTraversal();
            break;
        case 2:
            Btree.printPreOrderTraversal();
            break;
        case 3:
            Btree.printPostOrderTraversal();
            break;
        case 4:
            cout << "Removing from a copy tree\n";
            cout << "Enter value to delete: ";
            cin >> value;
            Copy = Btree;
            Copy.deleteNode(value);
            cout << "Height of tree After Deletion by Copying: " << Btree.height() << endl;
            cout << "InOrderTraversal After Deletion: ";
            Copy.printInorderTraversal();
            break;
        case 5:
            cout <<"Removing from a copy tree\n";
            cout << "Enter value to delete: ";
            cin >> value;
            Copy = Btree;
            Btree.deleteByMerge(value);
            cout << "Height of tree After Deletion by Merge: " << Copy.height() << endl;
            cout << "InOrderTraversal After Deletion: ";
            Copy.printInorderTraversal();
            break;
        case 6:
            cout << "Remove From original Tree\n";
            cout << "Enter value to delete: ";
            cin >> value;
            Btree.deleteNode(value);
            cout << "Height of tree After Deletion by Merge: " << Btree.height() << endl;
            cout << "InOrderTraversal After Deletion\n";
            Btree.printInorderTraversal();
            break;
        case 7:
            cout << "Height of tree: " << Btree.height() << endl;
            break;
        case 8:
            cout << "Enter value to find depth: ";
            cin >> value;
            Btree.depthOfANode(value);
            break;
        case 9:
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
   

    return 0;
}
// #share sort
// #quick sort

