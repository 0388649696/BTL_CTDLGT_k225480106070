#include <iostream>
using namespace std;
// Hàm tìm kiếm tuần tự
int SEQUEN_SEARCH(int k[], int n, int X) {
    int i = 0; // Bắt đầu từ phần tử đầu tiên của mảng
    k[n] = X;  // Thêm giá trị cần tìm X vào cuối mảng như "điểm gác"
    // Vòng lặp tìm kiếm cho đến khi gặp giá trị X
    while (k[i] != X) {
        i = i + 1; // Tăng chỉ số để kiểm tra phần tử tiếp theo
    }
    // Kiểm tra kết quả tìm kiếm
    if (i == n) { 
        return 0; // Nếu chỉ số đạt tới cuối mảng, không tìm thấy X
    } else {
        return i + 1; // Trả về vị trí tìm thấy (đánh số từ 1)
    }
}

int main() {
    int n, X;
    // Nhập số lượng phần tử trong mảng
    cout << "Nhap so phan tu trong mang: ";
    cin >> n;
    // Khai báo mảng có kích thước n + 1 (để chứa "điểm gác")
    int k[n + 1];
    // Nhập các phần tử mảng
    cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    // Nhập giá trị cần tìm
    cout << "Nhap gia tri can tim: ";
    cin >> X;
    // Gọi hàm tìm kiếm tuần tự
    int result = SEQUEN_SEARCH(k, n, X);
    // Kiểm tra kết quả và in ra
    if (result == 0) {
        cout << "Khong tim thay " << X << " trong mang." << endl;
    } else {
        cout << "Tim thay " << X << " tai vi tri " << result << "." << endl;
    }
    return 0;
}
