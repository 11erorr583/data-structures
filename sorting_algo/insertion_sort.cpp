//in insertion sort we consider that array is already sorted considering a[1] as a first element we compare it with second adjecent 
// and swap it if the elements are unsorted and repeat this step until the array is sorted
#include<iostream>
using namespace std;
void insertion_sort(int arr[],int &size)
{
   for(int i=1;i<size;i++)
   {
    int j=i-1;
    int comparison=arr[i];
    while(comparison<arr[j] && j>=0)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]= comparison;
   }
   
    
   
  
}

int main()
{
    int n;
    cout<<" Enter the size of an array ";
    cin>>n;
    int *data;
    data = new int[n];
    cout<<" Now enter the elements of an array ";
    for(int i=0;i<n;i++)
    {
        cout<<"data["<<i+1<<"]";
        cin>>data[i];
    }
    //min element considering array is sorted
    insertion_sort(data,n);
    cout<<" The sorted array is: "<<endl;
    for(int j=0;j<n;j++)
    {
        cout<<data[j]<<" ";
    }
   

    delete[] data;
    return 0;
}