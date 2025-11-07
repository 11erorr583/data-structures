#include<iostream>
using namespace std;
//function to swap elements
void swap( int &a , int &b)
{
    int temp =a ;
    a=b;
    b=temp;
}
//end= size;
int quick_sort(int arr[],int start,int end)
{
    int i= start +1 ;
    int j= end;
    // sort the array in such a way that small elements are on left of the pivot
    // while large elements than pivot are on right size of pivot
    int pivot = arr[start];
    while(i<j)
    {
        while(i<end && pivot > arr[i])
        {
            i++;
        }
        while(j>start && pivot < arr[j])
        {
            j--;
        }
        if(i<j)
        {
           swap(arr[i],arr[j]);
           i++;
           j--;
        }
    }
    swap(arr[j],arr[start]);
    return j;
}
void quick_partition(int arr[],int start , int end)
{
    if(start >= end)
    {
        return;
    }
    int pivot_index = quick_sort(arr,start,end);
    quick_partition(arr,start,pivot_index-1);
    quick_partition(arr,pivot_index+1,end);

}



int main()
{
    int size;
    cout<<" enter the size of an array";
    cin>>size;
    int arr[size];
    cout<<" Now! enter the elements of an array "<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    quick_partition(arr,0,size -1);

    cout<<" Sorted array : "<<"{"<<" ";
    for(int j=0;j<size;j++)
    {
        cout<<arr[j]<<" ";
        if(j<size-1)
        {
            cout<<",";
        }
    }
    cout<<"}";
    return 0;
}