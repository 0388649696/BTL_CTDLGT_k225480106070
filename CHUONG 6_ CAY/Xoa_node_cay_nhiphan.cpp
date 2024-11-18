#include <iostream>
#include <cstddef>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* maxOfLeft(Node* root) {
    Node* p = root->left;
    while (p && p->right != NULL) // Chỉnh sửa để tìm node tối đa ở bên trái
        p = p->right;
    return p;
}

class Solution {
public:
    Node* deleteNode(Node* root, int key) {
        if (root == NULL) return NULL;
        
        if (key > root->data) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->data) {
            root->left = deleteNode(root->left, key);
        } else { // Node cần xóa
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root; 
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* maxNode = maxOfLeft(root); // Lấy node lớn nhất bên trái
                root->data = maxNode->data; // Thay giá trị của node cần xóa
                root->left = deleteNode(root->left, maxNode->data); // Xóa node đó
            }
        }
        return root;
    }

    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        }
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }

    void preOrder(Node* root) {
        if (root == NULL) return;
        std::cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
};

int main() {
    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    // Nhập số lượng node cần thêm vào cây
    std::cin >> t;

    // Chèn các node vào cây
    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    // In cây theo thứ tự trước
    std::cout << "Duyet cay theo thu tu truoc: ";
    myTree.preOrder(root);
    std::cout << std::endl;

    // Nhập giá trị của node cần xóa
    int key;
    std::cout << "Nhap node muon xoa: ";
    std::cin >> key;

    // Xóa node khỏi cây
    root = myTree.deleteNode(root, key);

    // In cây theo thứ tự trước sau khi xóa
    std::cout << "Sau khi xoa: ";
    myTree.preOrder(root);
    std::cout << std::endl;

    return 0;
}
