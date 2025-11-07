#include<iostream>
using namespace std;
// global function for swapping
void swap(int &a,int& b)
{
   a = a ^ b;
   b = a ^ b;
   a = a ^ b;

}
void bubble_sort(int arr[],int length)
{
   
   for(int i=0;i<length-1;i++)
   { bool sorted = true;
    for(int j=0;j<length-i-1;j++ )
    {
        if(arr[j]>arr[j+1])
        {
            swap(arr[j],arr[j+1]);
            sorted = false ;
        }

    }
      if(sorted)
      {
        
        return ;
      }
   }

   return;
}
int main()
{
    int size;
    cout<<" Enter the number of elements in the dataset:  ";
    cin>>size;
    int dataset[size];
    
    int j=0;
    cout<<" Now!! enter the elements with in the array "<<endl;
    while(j<size)
    {
        cout<<"dataset["<<j+1<<"]";
        cin>>dataset[j];
        j++;
    }
    cout<<" The array before sorting is:  "<<endl;
    for(int element:dataset)
    {
        cout<<element<<endl;
    }
    bubble_sort(dataset,size);
    cout<<" The array after sorting is "<<endl;
    cout<<"dataset[]= "<<"{";
     int i=0;
    for(int elements:dataset)
    {
        cout<<elements;
        i++;
        if(i<=size-1)
        {
            cout<<", ";
        }
 
    }
    cout<<"}"<<endl;
    
     return 0;
   
}