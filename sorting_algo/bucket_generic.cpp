#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Generic bucket structure
template <typename T>
struct Buckets {
    vector<T> bucket;
};

// Generic insertion sort
template <typename T>
void insertion_sort(vector<T>& arr, int size) {
    for (int i = 1; i < size; i++) {
        int j = i - 1;
        T comparison = arr[i];
        while (j >= 0 && comparison < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = comparison;
    }
}

// Generic bucket sort function
template <typename T>
void bucket_sort(T arr[], int size) {
    // Determine the range
    T min_element = arr[0];
    T max_element = arr[0];
    for (int i = 0; i < size; i++) {
        if (min_element > arr[i]) {
            min_element = arr[i];
        } else {
            max_element = (max_element < arr[i]) ? arr[i] : max_element;
        }
    }

    T range = max_element - min_element;

    // Determine the number of buckets
    int number_buckets = sqrt(size);
    number_buckets = (number_buckets <= 0) ? 1 : number_buckets;

    // Create an array of buckets
    Buckets<T> bucket[number_buckets];

    // Determine the range of each bucket
    T bucket_range = range / number_buckets;

    // Place elements into buckets
    for (int i = 0; i < size; i++) {
        int bucket_index = floor((arr[i] - min_element) / bucket_range);
        bucket_index = (bucket_index == number_buckets) ? number_buckets - 1 : bucket_index;
        bucket[bucket_index].bucket.push_back(arr[i]);
    }

    // Output bucket elements for debugging
    for (int k = 0; k < number_buckets; k++) {
        for (T element : bucket[k].bucket) {
            cout << element << " ";
        }
        cout << endl;
    }

    // Sort individual buckets and merge back into the array
    int j = 0;
    for (int n = 0; n < number_buckets; n++) {
        if (bucket[n].bucket.size() > 1) {
            int size = bucket[n].bucket.size();
            insertion_sort(bucket[n].bucket, size);
        }
        for (T data : bucket[n].bucket) {
            arr[j++] = data;
        }
    }
}

int main() {
    cout << "Enter the size of an array: ";
    int size;
    cin >> size;

    cout << "Now! Enter the elements of an array:" << endl;
    double data[size]; // Replace double with your desired data type when testing
    for (int j = 0; j < size; j++) {
        cout << "data[" << j + 1 << "] = ";
        cin >> data[j];
    }

    bucket_sort(data, size);

    cout << "Array after sorting is: ";
    for (int j = 0; j < size; j++) {
        cout << data[j] << " ";
    }
    cout << endl;

    return 0;
}
