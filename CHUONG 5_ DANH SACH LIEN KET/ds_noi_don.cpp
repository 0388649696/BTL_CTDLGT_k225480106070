#include <iostream>
using namespace std;
// Cấu trúc một nút trong danh sách nối đơn
struct Node {
    int info;
    Node* link;
};

// Hàm tạo một nút mới
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->info = value;
    newNode->link = nullptr;
    return newNode;
}

// 1) Loại bỏ một phần tử được trỏ bởi con trỏ M
void deleteNode(Node*& L, int position) {
     if (L == nullptr) {
        cout << "Danh sach rong hoac con tro M khong hop le.\n";
        return;
    }
    
    Node* temp = L;

     // Nếu xóa phần tử đầu tiên
    if (position == 1) {
        L = L->link;  // Cập nhật đầu danh sách
        delete temp;   // Xóa nút đầu
        return;
    }

     // Tìm nút tại vị trí "position"
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->link;
    }

    // Nếu vị trí không hợp lệ
    if (temp == nullptr || temp->link == nullptr) {
        cout << "Vi tri khong hop le.\n";
        return;
    }

    // Lưu nút cần xóa và thực hiện liên kết lại
    Node* nodeToDelete = temp->link;
    temp->link = temp->link->link;

    delete nodeToDelete;
}


// 2) Bổ sung một phần tử mới vào sau nút trỏ bởi con trỏ M
void insertAfter(Node* M, int value) {
    if (M == nullptr) {
        cout << "Con tro M khong hop le.\n";
        return;
    }

    Node* newNode = createNode(value);
    newNode->link = M->link;
    M->link = newNode;
}

// 3) Xóa một nút có trường info = x
void deleteByValue(Node*& L, int x) {
    if (L == nullptr) {
        cout << "Danh sach rong.\n";
        return;
    }

    if (L->info == x) { // Nếu nút đầu tiên có giá trị x
        Node* temp = L;
        L = L->link;
        delete temp;
        return;
    }

    Node* P = L;
    while (P->link != nullptr && P->link->info != x) {
        P = P->link;
    }

    if (P->link == nullptr) {
        cout << "Khong tim thay nut co gia tri " << x << ".\n";
        return;
    }

    Node* temp = P->link;
    P->link = temp->link; // Bỏ qua nút cần xóa
    delete temp;
}

// 4) Thêm một nút mới vào cuối danh sách
void insertAtEnd(Node*& L, int value) {
    Node* newNode = createNode(value);
    if (L == nullptr) { // Nếu danh sách rỗng
        L = newNode;
        return;
    }

    Node* temp = L;
    while (temp->link != nullptr) {
        temp = temp->link;
    }
    temp->link = newNode;
}

// Hàm hiển thị danh sách
void displayList(Node* L) {
    while (L != nullptr) {
        cout << L->info << " -> ";
        L = L->link;
    }
    cout << "NULL\n";
}

// Hàm nhập danh sách
void inputList(Node*& L) {
    int n, value;
    cout << "\nNhap so phan tu co trong danh sach: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(L, value);
    }
}

// Demo chương trình
int main() {
	int position;
    Node* L = nullptr; // Danh sách ban đầu rỗng
	
    // Nhập danh sách từ người dùng
    inputList(L);
    cout << "Danh sach ban dau: ";
    displayList(L);

    int choice, value;
    do {
        cout << "1. Loai bo phan tu tro boi M\n";
        cout << "2. Bo sung phan tu moi vao sau nut tro boi M\n";
        cout << "3. Xoa nut co truong info = x\n";
        cout << "4. Them mot nut moi vao cuoi danh sach\n";
        cout << "5. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (L == nullptr) {
                    cout << "Danh sach rong.\n";
                    break;
                }
                cout << "Nhap vi tri cua phan tu can xoa: ";  
                cin >> position;
                deleteNode(L, position);
                cout << "Danh sach sau khi xoa:  ";
                displayList(L);
                break;
            
            case 2:
                if (L == nullptr) {
                    cout << "Danh sach rong.\n";
                    break;
                }
                cout << "Nhap gia tri can chen sau nut M: "; 
                cin >> value;
                insertAfter(L, value); // Bổ sung sau nút đầu tiên
                cout << "Danh sach sau khi them: ";
                displayList(L);
                break;

            case 3:
                cout << "Nhap gia tri X can xoa: ";
                cin >> value;
                deleteByValue(L, value);
                cout << "Danh sach sau khi xoa: ";
                displayList(L);
                break;

            case 4:
                cout << "Nhap gia tri can them vao cuoi danh sach:  "; 
                cin >> value;
                insertAtEnd(L, value);
                cout << "danh sach sau khi them vao cuoi: "; 
                displayList(L);
                break;

            case 5:
                cout << "Thoat chuong trinh\n";
                break;

            default:
                cout << "Thu lai\n";
        }
    } while (choice != 5);

    return 0;
}
