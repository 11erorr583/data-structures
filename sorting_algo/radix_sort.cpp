#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

struct bucket
{
  vector<int>values;
};
void insertion_sort(vector<int>&arr,int size)
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
int max_index(int arr[],int size)
{
    int max = 0;
    for(int j=0;j<size;j++)
    {
        if(arr[j]>arr[max])
        {
            max = j;
        }
    }
    return max;}
int no_digit(int a)
{
    int digits = 0;
    while(a != 0)
    {
        digits++;
        a=a/10;
    }
    return digits;
}

void radix_sort(int arr[],int size)
{
  //finding max element in an arry
  
  int max_inde = max_index(arr,size);
  int max_element = arr[max_inde];
  int digit = no_digit(max_element); 
  for(int d=0 ; d<digit ; d++)
  {
    bucket buckets[10];
    for(int i=0;i<size;i++)
    {
     int bucket_index =(arr[i]/int(pow(10,d))) % 10;
        
            buckets[bucket_index].values.push_back(arr[i]);
        
    }
    int n=0;
    for(int j=0;j<10;j++)
    {
        if(buckets[j]. values.size()>1)
        {
            insertion_sort(buckets[j].values,buckets[j].values.size());
        }
        for(int data : buckets[j].values)
        {
            arr[n]=data;
            n++;
        }
    }
        // now clear bucker
        for(int f=0;f<10;f++)
        {
            buckets[f].values.clear();
        }
  }
  //sorted array
  for(int a=0;a<size;a++)
  {
    cout<<arr[a]<<" ";
  }
  return;
  
}
int main()
{
    int size;
    cout<<" Enter the size of an array: ";
    cin>>size;
    int arr[size];
    for(int k=0;k<size;k++)
    {
       cin>>arr[k];
    }
    radix_sort(arr,size);
    return 0;
}