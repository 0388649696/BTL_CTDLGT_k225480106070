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
	// duyet sau LRN
 	void postOrder(Node *root) {
    	if (root == NULL) return;

    stack<Node *> s1, s2;
    s1.push(root);
    // Sử dụng hai ngăn xếp để lưu thứ tự duyệt
    while (!s1.empty()) {
        Node *p = s1.top();
        s1.pop();
        s2.push(p);

        // Đẩy trái và phải vào ngăn xếp s1
        if (p->left != NULL) s1.push(p->left);
        if (p->right != NULL) s1.push(p->right);
    }
    // In kết quả từ ngăn xếp thứ hai
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
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
  
    myTree.postOrder(root);

    return 0;
}
