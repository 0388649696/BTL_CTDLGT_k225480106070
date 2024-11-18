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
	// duyet giua LNR                                            
    void inOrder(Node *root) {
    stack<Node *> s;
    Node *p = root;
    
    while (p != NULL || !s.empty()) {
        // Đi hết nhánh bên trái
        while (p != NULL) {
            s.push(p);
            p = p->left;
        }
        // Lấy phần tử trên cùng của ngăn xếp
        p = s.top();
        s.pop();
        // Hiển thị giá trị của node
        cout << p->data << " ";
        // Chuyển sang nhánh bên phải
        p = p->right;
	    }
	}
}; 

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.inOrder(root);

    return 0;
}
