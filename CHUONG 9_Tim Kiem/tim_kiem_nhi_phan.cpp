#include <iostream>
using namespace std;
// Hàm tìm kiếm nhị phân
int BINARY_SEARCH(int k[], int n, int X) {
    int l = 0; // Chỉ số trái ban đầu
    int r = n - 1; // Chỉ số phải ban đầu
    while (l <= r) { // Vòng lặp chạy khi l <= r
        int m = (l + r) / 2; // Tìm chỉ số giữa
        if (X < k[m]) { // Nếu X nhỏ hơn phần tử giữa
            r = m - 1; // Giảm phạm vi tìm kiếm, di chuyển chỉ số phải sang trái
        } else if (X > k[m]) { // Nếu X lớn hơn phần tử giữa
            l = m + 1; // Tăng phạm vi tìm kiếm, di chuyển chỉ số trái sang phải
        } else { 
            return m + 1; // Tìm thấy, trả về vị trí (đánh số từ 1)
        }
    }
    return 0; // Không tìm thấy, trả về 0
}

int main() {
    int n, X;
    // Nhập số lượng phần tử của mảng
    cout << "Nhap so phan tu trong mang (sap xep tang): ";
    cin >> n;
    int k[n]; // Khai báo mảng có n phần tử
    // Nhập các phần tử của mảng theo thứ tự tăng dần
    cout << "Nhap " << n << " phan tu theo thu tu tang dan: ";
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    // Nhập giá trị cần tìm
    cout << "Nhap gia tri can tim: ";
    cin >> X;
    // Gọi hàm tìm kiếm nhị phân
    int result = BINARY_SEARCH(k, n, X);
    // In kết quả
    if (result == 0) {
        cout << "Khong tim thay " << X << " trong mang." << endl;
    } else {
        cout << "Tim thay " << X << " tai vi tri " << result << "." << endl;
    }
    return 0;
}
