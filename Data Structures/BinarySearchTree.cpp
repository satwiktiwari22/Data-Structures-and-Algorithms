#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    Node(int val,Node* left, Node* right){
        this->data = val;
        this->left = left;
        this->right = right;
    }
};

class BST{
    public:
    Node * root;
    BST(){
        this->root = nullptr;
    }
    BST(Node* root){
        this->root = root;
    }
    void insert(int val){
        Node * ptr = this->root;
        recursive(ptr,val);
    }
    Node* recursive(Node* tree,int val){
        if(tree==nullptr){
            tree = new Node(val);
        }
        else if(tree->data<val){
            tree->right = recursive(tree->right,val);
        }
        else{
            tree-> left = recursive(tree->left,val);
        }
        return tree;
    }
    
   
    
    void display(){
        Node* temp = this->root;
        inorder(temp);
        cout<<endl;
    }
    
    void inorder(Node* tree){
        if(tree){
            inorder(tree->left);
            cout<<tree->data<<" ";
            inorder(tree->right);
        }
    }
    
    
    void search(int ele) {
        if (this->root == nullptr) {
            cout << "Bewakoof!!! tu empty tree me value search kr rha hai. UNDERFLOW!!!" << endl;
        } else {
            bool found = recursiveSearch(this->root, ele);
            if (!found) {
                cout << "Nahi mila!!! ja kisi aur se puch" << endl;
            }
        }
    }
    
    bool recursiveSearch(Node* tree, int ele) {
        if (tree == nullptr) {
            return false;
        }
        if (tree->data == ele) {
            cout << "hoho!!! mil gaya element" << endl;
            return true;
        } else if (ele < tree->data) {
            return recursiveSearch(tree->left, ele);
        } else {
            return recursiveSearch(tree->right, ele);
        }
    }
    
    void deleteNode(int val){
        if(this->root==nullptr){
            cout<<"Bewakoof!!! tu empty tree me delete kr rha hai. UNDERFLOW!!!"<<endl;
        }
        else{
            recursiveDelete(this->root,val);
        }
    }
    
    Node* recursiveDelete(Node* tree,int val){
        if(!tree){
            cout<<"Abe delete krne ke liye value honi bhi toh chahiye!!!"<<endl;
        }
        else if(val<tree->data){
            tree->left = recursiveDelete(tree->left,val);
        }
        else if(val>tree->data){
            tree->right = recursiveDelete(tree->right,val);
        }
        else if(tree->left && tree->right){
            Node* temp = findPre(tree->left);
            tree->data = temp->data;
            tree->left = recursiveDelete(tree->left,temp->data);
        }
        else{
            Node* temp = tree;
            if(!tree->left && !tree->right){
                tree = nullptr;
            }
            else if(tree->left){
                tree = tree->left;
            }
            else{
                tree = tree->right;
            }
            delete temp;
        }
        return tree;
    }
    
    Node* findPre(Node* tree){
        Node* temp = tree;
        while(temp->right){
            temp = temp->right;
        }
        return temp;
    } 
};


int main() {
    Node n1(5);
    // Underflow check
    // BST t1;
    // t1.search(11);
    BST t1(&n1);
    t1.insert(6);
    t1.insert(2);
    t1.insert(1);
    t1.insert(3);
    t1.insert(7);
    t1.display();
    // t1.search(2);
    // t1.search(13);
    t1.deleteNode(2);
    t1.display();

    return 0;
}
