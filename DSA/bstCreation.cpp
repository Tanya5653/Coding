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
Node* deleteFromBST(Node* root,int x){
    if(root==NULL){
        return NULL;
    }
    if(root->data==x){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1child
        if(root->left!=NULL && root->right==NULL){
            Node* temp= root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right !=NULL){
            Node* temp= root->right;
            delete root;
            return temp;
        }
        //2child
        if(root->left!=NULL && root->right!=NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->left,mini);
            return root;
        }
    }
    else if(root->data < x){
        root->right = deleteFromBST(root->right,x);
        return root;
    }
    else{
        root->left = deleteFromBST(root->left,x);
        return root;
    }
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