#include<iostream>
using namespace std;
void merge_sort(int *a,int start,int end)
{
   //divide the array into two halves and the output
   //result array
   int *first;
   int *second;
   
   int mid=(start+end)/2;

   int Fsize=mid-start+1;
   first=new int[Fsize];
   int elements=end-mid;
   second=new int[elements];
   //initializing first and second halves
   for(int i=0;i<Fsize;i++)
   {
      first[i]=a[start+i];
   }
   for(int j=0;j<elements;j++)
   {
      second[j]=a[j+mid+1];
   }
 //comparing sorting and merging the array
 int i=0;
 int j=0;
 int k=start;
 while(i<Fsize && j<elements)
 {
   if(first[i]<=second[j])
   {
      a[k]=first[i];
      i++;
   }
   else
   {
      a[k]=second[j];
      j++;
   }
   k++;
 }
 while(i<Fsize)
 {
   a[k]=first[i];
   k++;
   i++;
 }
 while(j<elements)
 {
   a[k]=second[j];
   k++;
   j++;
 }
 // now copying result and updating the actual array
 
 //deleting the dynamic array allocation
 delete[] first;
 delete[] second;
 
}
void divide_array(int *arr,int start,int end)
{
    if(start>=end)
    {
        
        
          return;
    }
   int  mid=(start+end)/2;
     
    divide_array(arr,start,mid);
     
    divide_array(arr,mid+1,end);
    merge_sort(arr,start,end);
    
    return ;
}
int main()
{
   int arr[]={12,2,31,4,599,912,28,32,22,0,2};
   int size = sizeof(arr)/sizeof(int);
    divide_array(arr,0,size-1);
    for( int j=0;j<size;j++)
    {
      cout<<arr[j]<<endl;
    }
} 