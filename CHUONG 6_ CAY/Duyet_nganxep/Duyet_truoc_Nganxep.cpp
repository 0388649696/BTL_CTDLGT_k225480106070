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
        stack<Node *> s;
        Node *p;
        if (root != NULL) s.push(root);
        while (!s.empty()) {
            p = s.top();
            s.pop();
            if (p->right != NULL) s.push(p->right);
            if (p->left != NULL) s.push(p->left);
            cout << p->data << " ";
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
  
    myTree.preOrder(root);

    return 0;
}
