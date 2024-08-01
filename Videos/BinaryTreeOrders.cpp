#include<iostream>
#include<queue>
using namespace std;
//input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
//preorder output: 1 2 4 5 7 3 6
//inorder:4 2 7 5 1 3 6
class Node{
    public:
    int data;
    Node * left;
    Node * right;
    
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
Node* BuildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    Node* n = new Node(d);
    n->left=BuildTree();
    n->right= BuildTree();
    return n;
}
void PrintPreorder(Node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    PrintPreorder(root->left);
    PrintPreorder(root->right);
}

void PrintInorder(Node * root){
    if(root==NULL){
        return;
    }
    PrintInorder(root->left);
    cout<<root->data<<" ";
    PrintInorder(root->right);
}

void PrintPostorder(Node * root){
    if(root== NULL){
        return;
    }
    PrintPostorder(root->left);
    PrintPostorder(root->right);
    cout<<root->data<<" ";
}

void PrintLevelorder(Node * root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node * temp = q.front();
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

Node* LevelOrder(){
    int d;
    cin>>d;

    Node* root = new Node(d);

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        
        int c1,c2;
        cin>>c1>>c2;

        if(c1!=-1){
        current->left = new Node(c1);
        q.push(current->left);
        }
        if(c2!=-1){
        current->right = new Node(c2);
        q.push(current->right);
        }
    }
    return root;
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int h1= height(root->left);
    int h2= height(root->right);
    return 1+ max(h1,h2);
}

int diameter(Node *root){
    //basecase
    if(root==NULL){
        return 0;
    }
    //rec case
    int D1= height(root->left)+height(root->right);
    int D2= diameter(root->left);
    int D3= diameter(root->right);

    return max(D1,max(D2,D3));
}
//optimised diameter of order o(n)

class HDPair{
    public:
    int height;
    int diameter;
};

HDPair optDiameter(Node* root){
    HDPair p;
    if(root==NULL){
        p.height=p.diameter=0;
        return p;
    }
    HDPair left = optDiameter(root->left);
    HDPair right= optDiameter(root->right);
    
    p.height = max(left.height,right.height)+1;

    int D1= left.height + right.height;
    int D2= left.diameter;
    int D3=right.diameter;

    p.diameter= max(D1,max(D2,D3));
    return p;
}

int main(){
 /* Node * root = BuildTree();
    PrintPreorder(root);
    cout<<endl;
    PrintInorder(root);
    cout<<endl;
    PrintPostorder(root);
    cout<<endl<<"LEVEL ORDER:"<<endl;
    PrintLevelorder(root);
    cout<<endl;
    cout<<height(root);
*/

    Node* root =  LevelOrder();
    PrintLevelorder(root);
    cout<<"diameter:"<<diameter(root)<<endl;
    cout<<"optDiameter"<<optDiameter(root).diameter<<endl;
     return 0;
}