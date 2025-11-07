#include<iostream>
using namespace std;
bool is_sorted(int a[],int size)
{
    bool sorted=true;
    for(int i=0;i<size;i++)
    {
        if(i+1 >= size)
        {
            break;
        }
       if(!(a[i]<a[i+1]))
       {
        
        sorted=false;
        return sorted;
       }

    }
    return sorted;
}

void sorting(int a[],int &size)
{
    //we will use bubble sorting to sort an array
    for(int i=0;i<size;i++)
    {  int check=0;
        for(int j=i+1;j<size;j++)
        {
           
          
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                check++;
            } 
            
        }
            if(check==0)
              {
                break;
              }

    }
    return ;
}
bool binary_search(int a[],int &size,int &target)
{
    int left=0;
    int right=size-1;
   
    while(left<=right)
    {   int mid=(left+right)/2;
            if(target==a[mid])
            { 
                cout<<" Element found at index: "<<mid+1<<endl;
                return true;
            }
            else
            if(target<a[mid])
            {
               right=mid-1;
             
               
            }
            else
            if(target>a[mid])
            {
                left=mid+1;
            
            }

        
    }
          return false;
}
    



int main()
{
    int n;
    cout<<" Enter the number of elements ";
    cin>>n;
    int data[n];
    cout<<" Now! enter the elements within the array "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"data["<<i+1<<"]: ";
        cin>>data[i];
    }
    bool check = is_sorted(data,n);
    if(!(check))
    {
        sorting(data,n);
    }
    cout<<"checking data elements"<<endl;
    for(int l=0;l<n;l++)
    {
        cout<<data[l]<<endl;
    }
       cout<<"Enter the target element you want to find in this array!! ";
       int target;
       cin>>target;
       bool Is=binary_search(data,n,target);
       if(!Is)
       {
        cout<<" Target not found! "<<endl;
       }


}