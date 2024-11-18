#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }
               return root;
           }
        }
	// Duyệt trước NLR
    void preOrder(Node *root) {
	 if (root == NULL) return ;
    cout << root -> data <<" ";
    preOrder (root -> left);
    preOrder (root -> right);
    }
    
    // Duyệt giữa LNR
    void inOrder(Node *root) {
    if (root == NULL) return ;
    inOrder (root -> left);
    cout << root -> data <<" ";
    inOrder (root -> right);
    }
    
    // Duyệt sau LRN
    void postOrder(Node *root) {
     if (root == NULL) return ;
    postOrder (root -> left);
    postOrder (root -> right);
    cout << root -> data <<" ";
    }


}; 

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    cout <<"Nhap so luong node: "; cin >> t;
      cout <<"Nhap cac node: "; 
    while(t-- > 0) {
      	cin >> data;
        root = myTree.insert(root, data);
    }
  		cout << "\n-Duyet truoc: ";
    myTree.preOrder(root);
    
    	cout << "\n-Duyet giua: ";
	myTree.inOrder(root);
	
		cout << "\n-Duyet sau: ";
	myTree.postOrder(root);
    return 0;
}
