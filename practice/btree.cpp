#include<iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node* newNode(int data){
    node* n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return  n;
}
node* insert(node *root, int data){
     if(root ==NULL) return newNode(data);
     if(data < root->data){
        root->left = insert(root->left, data);
     }else{
        root->right = insert(root->right,data);
     }
     return root;
}

int count(node *root){
    if(root ==NULL) return 0;
    return 1+ count(root->left) + count(root->right);
}

int sum(node *root){
    if(root ==NULL) return 0;
    return sum(root->left) + sum(root->right) + root->data;
}

int height(node *root){
    if(root==NULL) return 0;
    return 1+max( height(root->left), height(root->right));
}

int leaves(node *root){
    if(root==NULL) return 0;
    if(root->left ==NULL && root->right ==NULL) return 1;
    return leaves(root->left) + leaves(root->right);
}

void inorder(node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool isBST(node *root, int min, int max){
    if(root ==NULL) return true;
    if(root->data <= min || root->data > max) return false;
    return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
}

void printPath(node *root, int path[],int pathLen){
    if( root ==NULL){
        return;
    }
    path[pathLen++] = root->data;
    if(root->left ==NULL && root->right ==NULL){
        for(int i=0; i<pathLen; i++){
            cout<<path[i]<<"-->";
        }
        cout<<endl;
        pathLen=0;
    }else{
        printPath(root->left,path,pathLen);
        printPath(root->right, path, pathLen);
    }
}

int main(){
int path[100];
int pathLen=0;
    node *root=NULL;
    int a[]={4,5,12,54,1,3,13,2,65};
    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++){
        root = insert(root,a[i]);
    }
    inorder(root);
    cout<<leaves(root)<<endl;
    if(isBST(root, INT_MIN, INT_MAX)){
        cout<<"this is a BST"<<endl;
    }
    printPath(root,path,pathLen);
    return 0;
}
