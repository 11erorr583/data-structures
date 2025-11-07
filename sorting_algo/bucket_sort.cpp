//bucket sort for arrays of integers
// bucket sort works for the element with in small range near elements
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct buckes
{
    vector<int>bucket;
};
// function that sorts the array using bucket sort
void insertion_sort(vector<int>&arr,int &size)
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
void bucket_sort(vector<int>& arr,int size)
{
    // determine the range of elements with in the array
    int max_element=arr[0];
    int min_element=arr[0];
    for(int k=0;k<size;k++)
    {
        if(min_element>arr[k])
        {
            min_element=arr[k];
        }
        else
        if(max_element<arr[k])
        {
            max_element=arr[k];
        }
    }
    int range = max_element - min_element;
    int number_buckets = sqrt(range);
    // dividing the data set into buckets
     number_buckets=(number_buckets==0)? 1:number_buckets;// make sure that runtime erorr may not occur
    buckes bucket[number_buckets];
    // determining the range of each bucket
   
    int bucket_range = ceil((range+1)/(number_buckets));
    bucket_range = (bucket_range==0)? 1:bucket_range;
    for(int l=0;l<size ;l++)
    {
       int bucket_index = floor((arr[l]-min_element)/bucket_range);
       bucket_index = (bucket_index==number_buckets)? bucket_index-1:bucket_index;
       bucket[bucket_index].bucket.push_back(arr[l]);
    }
    cout<<" Buckets formed! "<<endl;
    for(int k=0;k<number_buckets;k++)
    {
        for(int nums:bucket[k].bucket)
        {
            cout<<nums<<" ";
        }
        cout<<endl;
    }
   
    // again applying bucket sort to each indivisual bucket
    int j=0;
    for(int f=0;f<number_buckets;f++)
    {
       if(bucket[f].bucket.size()>1)
       {
        int length = bucket[f].bucket.size();
        insertion_sort(bucket[f].bucket,length);
       }
       //merge the buckets
       for(int num:bucket[f].bucket)
       {
        arr[j]=num;
        j++;
       }

    }
   
    return; 
      
}
int main()
{
    int size;
    cout<<" Enter the size of an array: ";
    cin>>size;
    cout<<" Now enter the elements of an array ";
    cout<<endl;
    vector<int>data;

    for(int j=0;j<size;j++)
    {
        int element;
        cout<<"data["<<j+1<<"]: ";
        cin>>element;
        data.push_back(element);
    }
    cout<<" Before sorting: "<<endl;
    for(int k=0;k<size;k++ )
    {
        cout<<data[k]<<" ";
    }
    cout<<endl;
    bucket_sort(data,size);
    cout<<" After sorting "<<endl<<"data[]= {";
    for(int m=0;m<size;m++)
    {
        cout<<data[m];
        if(m<size-1)
        {
            cout<<", ";
        }
    }
    cout<<"}";
    return 0;
} 