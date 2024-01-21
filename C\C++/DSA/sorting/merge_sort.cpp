#include <iostream>
using namespace std;

void pt(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int *arr, int low, int mid, int high) {
    int aux[high - low + 1]; // Adjusted size of auxiliary array
    int i = low, j = mid + 1, k = 0; // Initialize i and j correctly

    while (i <= mid && j <= high) { // Compare elements in both subarrays
        if (arr[i] <= arr[j]) {
            aux[k] = arr[i];
            i++;
        } else {
            aux[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from the first subarray, if any
    while (i <= mid) {
        aux[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements from the second subarray, if any
    while (j <= high) {
        aux[k] = arr[j];
        j++;
        k++;
    }

    // Copy elements from the auxiliary array back to the original array
    for (int s = low; s <= high; s++) {
        arr[s] = aux[s - low];
    }
}

void merge_sort(int *arr, int low, int high) {
    if (low < high) {
        int mid = (high + low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {4, 2, 6, 9, 7, 3, 8, 1, 99, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, size - 1); // Pass size - 1 for the correct upper bound

    pt(arr, size);

    return 0;
}
