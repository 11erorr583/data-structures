#include<iostream>
using namespace std;
void swap(int a,int b)
{
    int temp = a;
    a=b;
    b=temp;
}
void shell_sort(int arr[],int size)
{
   for(int gap = size/2; gap > 0 ; gap = gap/2 )
   {
     for( int j = gap ; j<size ; j++)
     {
        int i=j;
        int comparison = arr[i];
        while(i>=gap && arr[i-gap] > comparison )
        {
            arr[i]=arr[i-gap];
            i-=gap;
        }
        arr[i]=comparison;
     }
   }
}

int main()
{
    int size;
    cout<<" Enter the size of an array "<<endl;
    cin>>size;
    int arr[size];
    for(int k=0;k<size;k++)
    {
        cout<<"arr["<<k+1<<"]: ";
        cin>>arr[k];
    }
    shell_sort(arr,size);
    cout<<" Sorted array is:";
    for(int n=0;n<size;n++)
    {
        cout<<arr[n]<<" ";
    }

    return 0;
}