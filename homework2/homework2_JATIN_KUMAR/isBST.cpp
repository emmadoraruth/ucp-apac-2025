#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;


    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;

    }
};  

bool isBST(Node* root,long long int LB, long long int UB){
    // base case
    if(root==NULL) return true;

    bool cond1=root->data<UB;
    bool cond2=root->data>LB;
    bool leftAns=isBST(root->left,LB,root->data);
    bool rightAns=isBST(root->right,root->data,UB);

    if(cond1 && cond2 && leftAns && rightAns){
        return true;
    }
    else{
        return false;
    }
}
    bool isValidBST(Node* root) {
       long long int LB= -2147483657;
       long long int UB=  2147483657;

       bool ans=isBST(root,LB,UB);
       return ans;
    }

    int main(){
    Node* root1 = new Node(10);
    root1->left = new Node(8);
    root1->right = new Node(16);

    
    root1->left->right = new Node(9);

    root1->right->left = new Node(13);
    root1->right->right = new Node(17);

    root1->right->right->right = new Node(20);
    if(isValidBST(root1)){
        cout<<"The given tree is a BST"<<endl;
    }
    else{
        cout<<"The given tree is not a BST"<<endl;
    }
}