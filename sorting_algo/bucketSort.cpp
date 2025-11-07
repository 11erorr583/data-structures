//bucket_sort for double
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct buckets
{
    vector<double>bucket;
};
void insertion_sort(vector<double>&arr,int size)
{
   for(int i=1;i<size;i++)
   {
    int j=i-1;
    double comparison=arr[i];
    while(comparison<arr[j] && j>=0)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]= comparison;
   }
}
void bucket_sort(double arr[],int size)
{
    //determine the range
    double min_element=arr[0];
    double max_element=arr[0];
    for(int i=0;i<size;i++)
    {
        if(min_element>arr[i])
        { 
            min_element=arr[i];
        }
        else
        max_element= (max_element<arr[i])?arr[i]:max_element;
        
    }
   double range = max_element - min_element;
    //determine the number of buckets make sure atlest 1 bucket must be exist
   int number_bucket = sqrt(size);
   number_bucket = (number_bucket<=0)? 1:number_bucket;
    //create an array of bucket
    buckets bucket[number_bucket];
    //determine the common rage of each bucket means the max elements each bucket can contain
    double bucket_range = (range /number_bucket);
    // enter the element by determining of the range of bucket where that specific element should place
    for(int i=0;i<size;i++)
    {
       int bucket_index = floor((arr[i]-min_element)/bucket_range);
       bucket_index = (bucket_index == number_bucket)? number_bucket-1:bucket_index; 
       bucket[bucket_index].bucket.push_back(arr[i]);
    }
    // now checking if the algo. is working correctly
    for(int k=0;k<number_bucket;k++)
    {
        for(double element:bucket[k].bucket)
        {
            cout<<element<<" ";
        }
        cout<<" "<<endl;
    }
    int j=0;
    for(int n=0;n<number_bucket;n++)
    {
        if(bucket[n].bucket.size()>1)
        {
            int size = bucket[n].bucket.size();
            insertion_sort(bucket[n].bucket,size);
        }
        for(double data:bucket[n].bucket)
        {
            arr[j++]=data;
        }
    }
    
}
int main()
{
    cout<<" Enter the size of an array ";
    int size;
    cin>>size;
    cout<<" Now! Enter the elements of an array ";
    double data[size];
    cout<<" Enter the double (floating point ) values"<<endl;
    for(int j=0;j<size;j++)
    {
        cout<<"data["<<j+1<<"]= ";
        cin>>data[j];
    }
    bucket_sort(data,size);
    cout<<" array after sorting is: ";
    for(int j=0;j<size; j++)
    {
        cout<<data[j]<<endl;
    }

}