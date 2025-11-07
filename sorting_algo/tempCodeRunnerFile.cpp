#include<iostream>
using namespace std;
// function for swapping 
void swap(int &a,int &b)
{
    a = a^b;
    b= a^b;
    a= a^b;
}
int quick_sort(int arr[],int start,int size)
{
    // take initial element as pivot
    int pivot = arr[start];
    int pivot_index = start;
    int i=start;
    int j=size-1;
    while(i<j)
    {
        while(arr[i]<pivot && i<=size-1) {i++;}
        while(arr[j]>=pivot && j>=start){j--;}
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
        
           swap(arr[j],arr[start]);
           pivot_index = j;
       
return pivot_index;
}
void quick_partition(int arr[],int size,int start)
{
   if(start >= (size))
   {
       return ;
   }
  int mid = quick_sort(arr,size,start);
   quick_partition( arr,mid, start);
   quick_partition( arr,size-1,mid+1);
   

}


int main()
{
    int size;
    cout<<" enter the size of an array "<<endl;
    cin>>size;
    cout<<" Now enter the elements of an array "<<endl;
    int arr[size];
    for(int i=0;i<size;i++)
    {
         cin>>arr[i];
    }
   quick_partition(arr,size,0);
   cout<<" result = ";
   for(int j=0;j<size;j++)
   {
    cout<<arr[j]<<endl;
   }
   return 0;
}