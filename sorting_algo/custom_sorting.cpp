#include<iostream>
using namespace std;
void insertion_sort(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
        int j=i-1;
        int key = arr[i];
        while(j>=0 && key%10 < arr[j]%10)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    return;
}
int main()
{
   int size;
   cout<<" enter the size of an array ";
   cin>>size;
   int arr[size];
   cout<<" Enter the elements of an array ";
   for(int i=0;i<size;i++)
   {
    cin>>arr[i];
   }
   insertion_sort(arr,size);
   cout<<" sorted array: ";
   for(int l=0;l<size;l++)
   {
    cout<<arr[l]<<" ";
   }
   return 0;

}