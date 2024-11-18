#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i) {
    int largest = i;  // Gán nút gốc là lớn nhất
    int left = 2 * i + 1;  // Vị trí nút con trái
    int right = 2 * i + 2; // Vị trí nút con phải

    // Nếu nút con trái lớn hơn nút gốc
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Nếu nút con phải lớn hơn nút lớn nhất hiện tại
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Nếu largest không phải là gốc
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Gọi đệ quy để sửa lại Heap con
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    // Xây dựng Heap (sắp xếp lại mảng)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Lần lượt lấy phần tử lớn nhất ra khỏi Heap
    for (int i = n - 1; i >= 0; i--) {
        // Đổi chỗ phần tử gốc (lớn nhất) với phần tử cuối
        swap(arr[0], arr[i]);

        // Gọi heapify để sửa lại Heap
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    cout << "Mang da sap xep: \n";
    printArray(arr, n);
    return 0;
}