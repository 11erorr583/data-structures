#include<iostream>
using namespace std;
int smallest_element(int a[],int &start, int & size)
{ 
    int smallest=a[start];
    int end=size-1;
    int index=start;
    for(int j=start;j<=end;j++)
    {
       if(smallest>a[j])
       {
        smallest=a[j];
        index=j;
       } 
    }
    return index;
}
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
    return ;
}
int main()
{
    
    int n=0;
    cout<<" Enter the size of an array ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of an array "<<endl;
    for(int k=0;k<n;k++)
    {
        cout<<"data["<<k+1<<"]: ";
        cin>>arr[k];
    }
    cout<<"data[]="<<"{";   
   for(int i=0;i<n;i++)
    {   
        int small_index=smallest_element(arr,i,n);
        swap(arr[i],arr[small_index]);
        cout<<arr[i];
        if( i<n-1)
        {
            cout<<", ";
        }
      
    }
    cout<<"}";
    return 0;
}