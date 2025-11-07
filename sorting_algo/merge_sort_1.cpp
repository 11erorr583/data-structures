#include <iostream>
using namespace std;

// Merge two subarrays
void merge_sort(int *a, int mid, int start, int end) {
    // Determine sizes of subarrays
    int Lsize = mid - start + 1;
    int Rsize = end - mid;

    // Allocate memory for subarrays
    int *left = new int[Lsize];
    int *right = new int[Rsize];

    // Initialize left and right subarrays
    for (int i = 0; i < Lsize; i++) {
        left[i] = a[i + start];
    }
    for (int j = 0; j < Rsize; j++) {
        right[j] = a[j + mid + 1];
    }

    // Merge the subarrays into the original array
    int i = 0, j = 0, k = start;
    while (i < Lsize && j < Rsize) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            k++;
            i++;
        } else
         {
            a[k] = right[j];
            k++;
            j++;
        }
    }

    // Copy remaining elements from left array
    while (i < Lsize) {
        a[k++] = left[i++];
    }

    // Copy remaining elements from right array
    while (j < Rsize) {
        a[k++] = right[j++];
    }

    // Free allocated memory
    delete[] left;
    delete[] right;
}

// Divide the array into halves
void divide_array(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;
    divide_array(arr, start, mid);    // Sort left half
    divide_array(arr, mid + 1, end); // Sort right half
    merge_sort(arr, mid, start, end); // Merge the two halves
}

int main() {
    int arr[] = {12, 2, 31, 4, 599, 912, 28, 32, 22, 0, 2};

    int size = sizeof(arr) / sizeof(arr[0]);
    int start = 0;
    int end = size - 1;

    // Perform merge sort
    divide_array(arr, start, end);

    // Print the sorted array
    cout << "Sorted array:" << endl;
    for (int k = 0; k < size; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    return 0;
}
