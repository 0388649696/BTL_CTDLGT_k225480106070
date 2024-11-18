#include <iostream>
using namespace std;
// Ham tinh so Fibonacci thu n bang phuong phap lap
int fibonacci_n(int n) {
    // Truong hop co so: Neu n <= 1, tra ve n va in ket qua buoc dau
    if (n <= 1) {
        cout << "Buoc 1: F(" << n << ") = " << n << endl;
        return n;
    }

    // Khoi tao mang de luu cac gia tri Fibonacci tu 0 den n
    int f[n + 1];
    f[0] = 0; // Gia tri dau tien cua day Fibonacci
    f[1] = 1; // Gia tri thu hai cua day Fibonacci
    // In ket qua cac buoc dau tien
    cout << "Buoc 1: F(0) = 0" << endl;
    cout << "Buoc 2: F(1) = 1" << endl;

    // Vong lap tinh cac so Fibonacci tu 2 den n
    for (int i = 2; i <= n; ++i) {
        f[i] = f[i - 1] + f[i - 2]; // Cong thuc tinh Fibonacci
        // Hien thi buoc hien tai va cong thuc
        cout << "Buoc " << i + 1 << ": F(" << i << ") = " << f[i] 
             << " (F(" << i - 1 << ") + F(" << i - 2 << "))" << endl;
    }
    // Tra ve ket qua so Fibonacci thu n
    return f[n];
}
int main() {
    int n;
    // Nhap so n tu nguoi dung
    cout << "Nhap so n de tinh so Fibonacci thu n: ";
    cin >> n;

    // Kiem tra dieu kien: So Fibonacci chi duoc dinh nghia cho so >= 0
    if (n < 0) {
        cout << "So Fibonacci khong duoc dinh nghia cho so am!" << endl;
    } else {
        // Tinh va hien thi ket qua
        cout << "Ket qua: F(" << n << ") = " << fibonacci_n(n) << endl;
    }
    return 0;
}
