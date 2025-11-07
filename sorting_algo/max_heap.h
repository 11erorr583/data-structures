#include<iostream>
using namespace std;

void swop(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

class max_heap
{
    int size;
    int *max;
    int tracker;

public:
    max_heap(int n)
    {
        size = n;
        tracker = 0;
        max = new int[size]();
    }

    ~max_heap()
    {
        delete[] max; // Ensure memory is freed
    }

    void heapifyup(int arr[], int size)
    {
        int child = size;
        while (child > 0) // Fixed condition to avoid infinite loop
        {
            int parent = (child - 1) / 2;
            if (arr[child] > arr[parent])
            {
                swop(arr[child], arr[parent]);
                child = parent;
            }
            else
                break;
        }
    }

    void heapifydown(int arr[], int size)
    {
        int root = 0;
        while (true)
        {
            int left = 2 * root + 1;
            int right = 2 * root + 2;
            int maximum = root;

            if (left < size && arr[left] > arr[maximum])
                maximum = left;
            if (right < size && arr[right] > arr[maximum])
                maximum = right;

            if (maximum != root)
            {
                swop(arr[maximum], arr[root]);
                root = maximum;
            }
            else
                break;
        }
    }

    void insertion(int element)
    {
        if (tracker == size)
        {
            cout << "Heap is filled" << endl;
            return;
        }
        else
        {
            max[tracker] = element;
            heapifyup(max, tracker);
            tracker++;
        }
    }

    int deletion()
    {
        if (tracker == 0)
        {
            cout << "Heap is empty" << endl;
            return -1; // Return an invalid value to indicate error
        }

        int deleted = max[0];
        max[0] = max[tracker - 1];
        tracker--;
        heapifydown(max, tracker);

        return deleted;
    }

    void print_heap()
    {
        for (int i = 0; i < tracker; i++)
        {
            cout << max[i] << " ";
        }
        cout << endl;
    }

    void heapify(int arr[], int size)
    {
        for (int i = (size / 2) - 1; i >= 0; i--)
        {
            heapifydown(arr, size);
        }
    }

    void complete_array()
    {
        cout << "Enter the number of elements in heap: ";
        cin >> size;

        delete[] max; // Free previously allocated memory
        max = new int[size];

        cout << "Now enter the elements of heap: ";
        for (int k = 0; k < size; k++)
        {
            cin >> max[k];
        }

        heapify(max, size);

        // Printing the max_heap
        for (int j = 0; j < size; j++)
        {
            cout << max[j] << " ";
        }
        cout << endl;
    }
};

