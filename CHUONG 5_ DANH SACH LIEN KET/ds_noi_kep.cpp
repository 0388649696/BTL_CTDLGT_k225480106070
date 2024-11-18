#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong danh sách móc nối kép
struct Node {
    int info;
    Node* prev; // Con trỏ trỏ đến nút trước
    Node* next; // Con trỏ trỏ đến nút sau
};

// Hàm tạo một nút mới
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->info = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Hàm hiển thị danh sách
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}

// Yêu cầu 1: Loại bỏ một phần tử được trỏ bởi con trỏ M
void removeNode(Node*& head, Node* M) {
    if (head == nullptr || M == nullptr) {
        cout << "Danh sách trống hoặc nút không hợp lệ." << endl;
        return;
    }
    // Trường hợp M là nút đầu tiên
    if (M == head) {
        head = M->next;
        if (head != nullptr)
            head->prev = nullptr;
    } else {
        M->prev->next = M->next;
        if (M->next != nullptr)
            M->next->prev = M->prev;
    }
    delete M;
    cout << "Nut da duoc loai bo." << endl;
}

// Yêu cầu 2: Bổ sung một phần tử mới vào sau nút trỏ bởi con trỏ M
void insertAfter(Node* M, int value) {
    if (M == nullptr) {
        cout << "Con tro M khong hop le." << endl;
        return;
    }
    Node* newNode = createNode(value);
    newNode->next = M->next;
    newNode->prev = M;
    if (M->next != nullptr)
        M->next->prev = newNode;
    M->next = newNode;
    cout << "Phan tu moi da duoc them sau nut M." << endl;
}

// Yêu cầu 3: Xóa một nút có trường info = x
void deleteNodeWithValue(Node*& head, int x) {
    Node* current = head;
    while (current != nullptr) {
        if (current->info == x) {
            removeNode(head, current);
            return;
        }
        current = current->next;
    }
    cout << "Khong tim thay nut voi gia tri " << x << "." << endl;
}

// Yêu cầu 4: Thêm một nút mới vào cuối danh sách
void appendNode(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    cout << "Phan tu moi da duoc them vao cuoi danh sach." << endl;
}

int main() {
    Node* head = nullptr; // Danh sách ban đầu trống
    int choice, value;
    do {
        cout << "\nMENU:" << endl;
        cout << "1. Them mot nut vao cuoi danh sach" << endl; 
        cout << "2. Loai bo mot nut (theo con tro M)" << endl;
        cout << "3. Them mot nut moi sau mot nut (theo con tro M)" << endl;
        cout << "4. Xoa mot nut co gia tri info = x" << endl;
        cout << "5. Hien thi danh sach" << endl;
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Nhap gia tri muon them: ";
            cin >> value;
            appendNode(head, value);
            break;
        }
        case 2: {
            int pos;
            cout << "Nhap vi tri nut muon xoa (bat dau tu 1): "; 
            cin >> pos;
            Node* current = head;
            int count = 1;
            while (current != nullptr && count < pos) {
                current = current->next;
                count++;
            }
            if (current != nullptr) {
                removeNode(head, current);
            } else {
                cout << "Khong tim thay nut tai vi tri " << pos << "." << endl;
            }
            break;
        }
        case 3: {
            int pos;
            cout << "Nhap vi tri nut M de them phan tu moi sau: ";
            cin >> pos;
            cout << "Nhap gia tri cua phan tu moi: ";
            cin >> value;
            Node* current = head;
            int count = 1;
            while (current != nullptr && count < pos) {
                current = current->next;
                count++;
            }
            if (current != nullptr) {
                insertAfter(current, value);
            } else {
                cout << "Khong tim thay nut tai vi tri " << pos << "." << endl;
            }
            break;
        }
        case 4: {
            cout << "Nhap gia tri x muon xoa: ";
            cin >> value;
            deleteNodeWithValue(head, value);
            break;
        }
        case 5: {
            cout << "Danh sach hien tai ";
            displayList(head);
            break;
        }
        default:
            cout << "Chon lai." << endl;
        }
    } while (choice != 6);

    return 0;
}
