#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    //intialized a constructor
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insertIntoBST(Node* root,int d){
    //base case
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d < root->data){
        root->left = insertIntoBST(root->left,d);
    }
    else{
        root->right = insertIntoBST(root->right,d);
    }
    return root;
}
Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxVal(Node* root){
    Node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}
int main(){
    Node* root = NULL;
    cout<<"Enter data for creating bst:"<<endl;
    takeInput(root);
    cout<<"Printing BST:"<<endl;
    return 0;
}