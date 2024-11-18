#include <iostream>
using namespace std;
// Lớp Stack hỗ trợ các thao tác cơ bản của ngăn xếp
class Stack {
public:
    // Hàm thêm phần tử vào stack
    void push(int x, int& top, int size, int a[]) {
        if (top >= size - 1) { // Kiểm tra stack đã đầy hay chưa
            cout << "Stack day\n";
        } else {
            top++; // Tăng vị trí top
            a[top] = x; // Gán giá trị vào vị trí top
        }
    }

    // Hàm xóa phần tử khỏi stack
    void pop(int& top) {
        if (top <= -1) { // Kiểm tra stack rỗng hay không
            cout << "Stack rong\n";
        } else {
            top--; // Giảm vị trí top để loại bỏ phần tử
        }
    }
};

// Lớp Queue hỗ trợ các thao tác cơ bản của hàng đợi
class Queue {
public:
    // Hàm thêm phần tử vào hàng đợi
    void queue_them(int queue[], int x, int rear, int size) {
        if (rear == size) { // Kiểm tra hàng đợi đã đầy hay chưa
            cout << "Queue day, khong the them!";
        } else {
            queue[rear] = x; // Thêm phần tử vào vị trí rear
        }
    }

    // Hàm xóa phần tử khỏi hàng đợi
    void queue_xoa(int queue[], int x, int front, int rear) {
        if (rear == 0) { // Kiểm tra hàng đợi rỗng hay không
            cout << "Khong con phan tu nao trong queue";
        } else {
            int j = 0;
            // Dịch các phần tử trong hàng đợi lên một vị trí
            while (j < rear) {
                queue[j] = queue[j + 1];
                j++;
            }
        }
    }
};

// Hàm hiển thị menu cho người dùng
void displayMenu() {
    cout << "\n" << endl;
    cout << "\n====== STACK va QUEUE ======" << endl;
    cout << "1. Them phan tu vao stack" << endl;
    cout << "2. Them phan tu vao queue" << endl;
    cout << "3. Exit" << endl;
    cout << "==================" << endl;
    cout << "Nhap lua chon cua ban: ";
}

// Hàm hiển thị mảng
void displayArr(int a[], int i, int size) {
    for (i = 0; i < size; i++) {
        if (i == 0) {
            cout << "{" << a[i] << "; ";
        } else if (i == size - 1) {
            cout << a[i] << "}";
        } else {
            cout << a[i] << "; ";
        }
    }
}

// Hàm chính
int main() {
    int size = 0;
    int i;

    // Nhập kích thước mảng từ người dùng
    cout << "Nhap do dai cua a: ";
    cin >> size;

    // Khởi tạo mảng động
    int* a = new int[size];
    for (i = 0; i < size; i++) {
        cout << "Nhap phan tu thu a[" << i << "]: ";
        cin >> a[i];
    }

    // Hiển thị mảng ban đầu
    cout << "a[]= ";
    displayArr(a, i, size);

    int menu = 0, choice;
    do {
        Stack s;
        Queue q;

        // Hiển thị menu và đọc lựa chọn của người dùng
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: { // Thêm phần tử vào stack
                int x;
                int top = size - 1; // Vị trí top ban đầu
                cout << "Nhap phan tu muon them vao stack: ";
                cin >> x;
                cout << "Lay phan tu a[" << size - 1 << "] ra khoi stack" << endl;
                s.pop(top); // Loại bỏ phần tử ở top
                cout << "Them phan tu moi vao vi tri a[" << size - 1 << "]" << endl;
                s.push(x, top, size, a); // Thêm phần tử mới
                displayArr(a, i, size); // Hiển thị mảng sau khi thêm
                break;
            }

            case 2: { // Thêm phần tử vào queue
                int x;
                cout << "Nhap phan tu muon them vao queue: ";
                cin >> x;
                q.queue_xoa(a, x, 0, size); // Xóa phần tử đầu tiên
                cout << "Xoa phan tu a[0]: " << a[0];
                cout << "\n";
                displayArr(a, i, size - 1); // Hiển thị mảng sau khi xóa
                cout << "\nThem phan tu moi vao vi tri a[" << size - 1 << "] ";
                q.queue_them(a, x, size - 1, size); // Thêm phần tử mới vào cuối
                cout << "\nQueue moi: " << endl;
                displayArr(a, i, size); // Hiển thị mảng mới
                break;
            }

            case 3: { // Thoát chương trình
                exit(0);
            }
        }
    } while (menu == 0);

    return 0;
}
