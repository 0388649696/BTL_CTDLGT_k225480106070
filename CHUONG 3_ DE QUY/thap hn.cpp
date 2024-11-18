//thap ha noi
#include <iostream>
using namespace std;
// Ham de quy giai bai toan Thap Ha Noi
void HaNoi(int n, int a, int b, int c) {
    // Truong hop co so: neu chi co 1 dia
    if (n == 1) {
        cout << a << " -> " << c << endl; // Chuyen dia tu coc a sang coc c
        return; // Ket thuc de quy
    }
    // B1: Chuyen n-1 dia tu coc a sang coc b, coc c la trung gian
    HaNoi(n - 1, a, c, b);
    // B2: Chuyen dia lon nhat (dia cuoi cung) tu coc a sang coc c
    HaNoi(1, a, b, c);
    // B3: Chuyen n-1 dia tu coc b sang coc c, coc a la trung gian
    HaNoi(n - 1, b, a, c);
}
int main() {
    int n;
    // Nhap so luong dia tu nguoi dung
    cout << "Nhap so dia: ";
    cin >> n;

    // Hien thi cac buoc chuyen dia
    cout << "Cac buoc chuyen dia nhu sau:" << endl;
    HaNoi(n, 1, 2, 3); // Goi ham de quy, voi 1: coc dau, 2: coc trung gian, 3: coc dich
    return 0;
}
