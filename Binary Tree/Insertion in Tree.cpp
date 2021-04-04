#include <iostream>
#include <queue>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};


Node* createNode(int data){
    Node* new_node=new Node();
    new_node->data=data;
    new_node->left=new_node->right=NULL;
    return new_node;
}

Node* insertNode(Node* root,int val){
   
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        
        if(temp->left ==NULL){
           temp->left=createNode(val);
           return root;
        }
        else
           q.push(temp->left);
     
        if(temp->right==NULL){
            temp->right=createNode(val);
            return root;
        }
        else
           q.push(temp->right);
    }

    return root;
}

void inorder(Node* temp){
  if (temp == NULL)
        return;
 
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);   
}

int main()
{
   Node *root;
   root=createNode(10);
   root->left=createNode(11);
   root->left->left=createNode(12);
   root->right=createNode(13);
   root->right->left=createNode(14);
   inorder(root);
   int val=15;
   root=insertNode(root,val);
   //after insertion
   cout<<endl;
   inorder(root);

    return 0;
}
