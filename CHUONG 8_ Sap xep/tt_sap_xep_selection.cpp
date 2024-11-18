 #include <iostream>
using namespace std;
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // Di chuyển ranh giới của dãy chưa được sắp xếp một phần tử tại một thời điểm
    for (i = 0; i < n-1; i++)
    {
        // Tìm phần tử nhỏ nhất trong dãy chưa được sắp xếp
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
        swap(arr[min_idx], arr[i]);
    }
}

// Hàm để in mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);   
    cout << "Mang chua sap xep: \n";
    printArray(arr, n);
    selectionSort(arr, n);
    cout << "Mang da sap xep: \n";
    printArray(arr, n);
    return 0;
}