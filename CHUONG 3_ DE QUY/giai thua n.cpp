#include <iostream>
using namespace std;
// Ham tinh giai thua cua mot so nguyen n su dung de quy
int factorial(int n) {
    // Truong hop co so: giai thua cua 0 la 1
    if (n == 0) {
        cout << "Buoc 1: 0! = 1" << endl;
        return 1; // Ket thuc de quy
    } else {
        // Giai thua cua n duoc tinh bang n * (n-1)!
        int result = factorial(n - 1) * n;
        // In buoc tinh toan hien tai
        cout << "Buoc " << n << ": " << n << "! = (" << n - 1 << "!) * " << n 
             << " = " << result << endl;
        return result; // Tra ve ket qua giai thua
    }
}

int main() {
    int n;

    // Nhap gia tri n tu nguoi dung
    cout << "Nhap mot so nguyen n: ";
    cin >> n;
    // Kiem tra dieu kien: giai thua khong xac dinh cho so am
    if (n < 0) {
        cout << "Giai thua khong duoc dinh nghia cho so am!" << endl;
    } else {
        // Tinh giai thua va hien thi ket qua
        cout << "Tinh giai thua cua " << n << ":" << endl;
        int result = factorial(n);
        cout << "Giai thua cua " << n << " la: " << result << endl;
    }
    return 0;
}
