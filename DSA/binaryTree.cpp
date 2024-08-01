#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node* buildTree(node* root){
    cout << "Enter the root data:" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of:" << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of:" << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp=q.front();
        if(temp==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return;
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    node *root = NULL;
    root = buildTree(root);
    cout<<"LEVEL ORDER IS:"<<endl;
    levelOrder(root);
    cout<<"INORDER TRAVERSAL IS:"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"PREORDER TRAVERSAL IS:"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"POSTORDER TRAVERSAL IS:"<<endl;
    postorder(root);
    return 0;
}