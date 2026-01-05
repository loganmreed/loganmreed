#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree{
    public:
        Node* root;
    
    BinarySearchTree(){
        root = nullptr;
    }

    Node* insert(Node* node, int val){
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data){
            node->left=insert(node->left, val);
        } else if (val > node->data){
            node->right = insert(node->right, val);
        }
        return node;
    }

    Node* find(Node* node, int val){
        if (node == nullptr || node->data ==val){
            return node;
        }
        if (val < node->data){
            return find(node->left, val);
        } else {
            return find(node->right, val);
        }
    }

    void inorder(Node* node) {
        if (node == nullptr){
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node){
        if (node == nullptr){
            return;
        }
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node){
        if (node == nullptr){
            return;
        }
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    int heigt(Node* node){
        if (node == nullptr){
            return 0;
        }
        int leftHeigt = heigt(node->left);
        int rightHeigt = heigt(node->right);
        if (leftHeigt > rightHeigt) {
            return leftHeigt + 1;
        } else{
            return rightHeigt + 1;
        }
    }

    Node* MinimumHeightBinarySearchTreeMaker(const vector<int>& victor,int start, int end){
        if (start > end){
            return nullptr;
        }
        int midpoint = (start + end) /2;
        Node* node = new Node(victor[midpoint]);
        node->left = MinimumHeightBinarySearchTreeMaker(victor,start,midpoint - 1);
        node->right= MinimumHeightBinarySearchTreeMaker(victor,midpoint + 1,end);
        return node;
    }
};

int main() {
    BinarySearchTree tree;
    vector<int> victor;
    string userInputStr;
    while(true){
        cout << "Enter numbers in a sorted (ascending) order 1 value at a time.\nEnter -1 when through.\n";
        cin >> userInputStr;

        if (userInputStr == "-1"){
            break;
        }
        bool allNum = true;
        for(char c : userInputStr){
            if (!isdigit(c)){
                cout << "invalid input. please input a number or -1."<< endl;
                allNum = false;
                break;
            }
        }
        if (!allNum){
            continue;
        }

        int userInputInt = stoi(userInputStr);
        victor.push_back(userInputInt);
    }

    if (victor.empty()){
        cout << "There were no numbers entered.\nInput r to reset or Enter to Quit:\n" << endl;
        string UserChoice;
        cin >> UserChoice;
        if (UserChoice == "r") {
            main();
        } else{
            return 0;
        }
    }
    while (true){
        cout << "Did you enter the values in adending order(1,2,3)? (y/n):\n";
        string answer;
        cin >> answer;
        if (answer == "n" || answer == "N"){
            sort(victor.begin(),victor.end());
            cout << "Numbers are now sorted.";
            break;
        } else if ((answer == "Y" || answer == "y")){
            break;
        } else{
            cout << "invalid input. please input y or n";
            continue;
        }
    }

    tree.root = tree.MinimumHeightBinarySearchTreeMaker(victor,0,victor.size()-1);

    cout << "\nthe height of the binary tree is: " << tree.heigt(tree.root) << endl;

    cout << "\nInorder: ";
    tree.inorder(tree.root);
    cout << "\nPreorder: ";
    tree.preorder(tree.root);
    cout << "\nPostorder: ";
    tree.postorder(tree.root);
    cout << endl;

    cout << "\nPress Enter to exit or enter 'r' to retry with a new puzzle: ";
    char choice;
    cin >> choice;

    if (choice == 'r') {
        main();  
    } else {
        return 0; 
    }

    return 0;
}