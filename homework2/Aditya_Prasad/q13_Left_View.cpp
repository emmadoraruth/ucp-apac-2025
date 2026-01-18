
// T.C - O(n) where n is the no of nodes in the tree
// M.C - O(n)  where n is the no of nodes in the tree
// Technique Used - Level Wise Traversal

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;

	Node(int val){
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

vector<int> leftView(Node* root){
    vector<int> ans;
    if(root == nullptr) return ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int s = q.size();
        for(int i=0;i<s;i++){ // each level
            Node*temp=q.front(); q.pop();

            if(i==0) ans.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return ans;
}

int main(){
    Node*root = new Node(7);
    root->left=new Node(8);
    root->right=new Node(3);
    root->right->left=new Node(9);
    root->right->right=new Node(13);
    root->right->left->left=new Node(20);
    root->right->right->left=new Node(14);
    root->right->right->left->right=new Node(15);

    vector<int> ans = leftView(root);
    for(int x : ans) cout << x << " ";
    cout << endl;

    Node*root2 = new Node(7);
    root2->left=new Node(20);
    root2->right=new Node(4);
    root2->left->left=new Node(15);
    root2->left->right=new Node(6);
    root2->right->left=new Node(8);
    root2->right->right=new Node(11);

    ans =leftView(root2);
    for(int x : ans) cout << x << " ";
}
