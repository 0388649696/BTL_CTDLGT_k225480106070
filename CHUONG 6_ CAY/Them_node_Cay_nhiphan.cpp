#include <iostream>
#include <cstddef>

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
    void preOrder(Node *root) {
        if (root == NULL)
            return;

        std::cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    Node *insert(Node *root, int data) {
        Node* p = new Node(data);
        if (root == NULL) root = p;
        else if (root->data > data)
            root->left = insert(root->left, data);
        else if (root->data < data)
            root->right = insert(root->right, data);
        else
            delete p; // Tránh thêm node có giá trị trùng lặp
        return root;
    }
}; // End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;

    int t;
    int data;
    std::cin >> t;

    // Chèn các node ban đầu
    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    // In cây theo thứ tự trước
    std::cout << "Duyet cay theo thu tu truoc: ";
    myTree.preOrder(root);
    std::cout << std::endl;

    // Thêm node mới sau khi cây đã khởi tạo
    int newData;
    std::cout << "Nhap node muon them: ";
    std::cin >> newData;

    root = myTree.insert(root, newData);

    // In cây sau khi thêm node mới
    std::cout << "Sau khi them: ";
    myTree.preOrder(root);
    std::cout << std::endl;

    return 0;
}
