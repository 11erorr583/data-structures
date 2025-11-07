//counting sort is for the specific range of numbers that are repitative with t=in the array
//counting sort is not for negative numbers
//counting sort is not a comparison algorithm
#include<iostream>
using namespace std;
//count_sort function with parameters array and it's size
//this function uses count sort algorithm to sort an array
void count_sort(int arr[],int size)
{
    //find the max element is an array the range of given array will be 0 <= arr[i] <= max;
    int max = arr[0];
    for(int i=0;i<size;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    //declare another array to keep track  of frequency elements with in the array
    int size2 = max+1;
    int tracker[size2];
    // initialize each elements of tracker with zero 
    for(int i=0;i<size2;i++)
    {
        tracker[i]=0;      
    }
    // Now! count the frequency of each element
    
    for(int j=0;j<size2;j++)
    {
        int k=0;
        while(k<=size-1)
        {
            if(arr[k]==j)
            {
                tracker[arr[k]]++;
            }
            k++;
        }
    }
   //now determine the index of each element and keep it's track on tracker
   //updating tracker
   tracker[0]=tracker[0];
   for(int l=1;l<size2;l++)
   {
      tracker[l]=tracker[l]+tracker[l-1];
   }
   //the elements of original array = the indices ot tracker;
   //the elements of tracker array-1 = the indices of result array
   int result[size];
   for(int m=0;m<size;m++)
   {
    int n=0;
    while(n<=size2)
    {
    if(arr[m]==n)
    {
        tracker[arr[m]] = tracker[arr[m]]-1;
        result[tracker[arr[m]]] = arr[m];
    }
    n++;    
    }
   }
   //update the original array with result to sort it
   for(int o=0;o<size;o++)
   {
    arr[o]=result[o];
   }
}
int main()
{
    //prompt the user to enter array size; and elements;
    cout<<" Enter the size of an array "<<endl;
    int n;
    cin>>n;
    int *array;
    array = new int[n];
    cout<<" Now! enter the elements of an array starting from 0 "<<endl;
    again:for(int i=0;i<n;i++)
    {
        cin>>array[i];
        if(array[i]<0)
        {
            cout<<" Array elements can't be less than 0"<<endl;
            cout<<" again: ";
            goto again;
        }
    }

  cout<<" array before sorting: "<<endl;
    cout<<"{";
   for(int j=0;j<n;j++)
    {
      cout<<array[j]<<" ";
       if(j<n-1)
        {
          cout<<",";
        }
          }
    cout<<"}"<<endl;
    count_sort(array,n);
    cout<<" The sorted array is: ";
      cout<<"{";
   for(int j=0;j<n;j++)
    {
      cout<<array[j]<<" ";
       if(j<n-1)
        {
          cout<<",";
        }
          }
    cout<<"}"<<endl;

    
    delete[] array;
    return 0;

}