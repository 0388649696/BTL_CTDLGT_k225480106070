 #include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Đổi chỗ hai phần tử
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Hàm để in mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Mang chua sap xep: \n";
    printArray(arr, n);
    bubbleSort(arr, n);
    cout << "Mang da sap xep: \n";
    printArray(arr, n);
    return 0;
}