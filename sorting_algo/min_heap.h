#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
  int temp = a;
  a=b;
  b=temp;
}

class min_heap
{
   private:
   int size;
   int tracker;
   int *min;
   public:
   min_heap(int n)
   {
    size = n;
    tracker = 0;
    min = new int[size];
   }
   ~min_heap()
   {
    delete [] min;
   }
 
    void heapifyup(int arr[], int size)
    {
      int child = size -1;
      while (child > 0)
      {
        int parent = (child - 1) / 2;
        if (arr[parent] > arr[child])
        {
          swap(arr[parent], arr[child]);
          child = parent;
        }
        else
        {
          break;
        }
      }
    }
    void heapifydown(int arr[],int index)
    {
      int root =0;
      int left = 2*root + 1;
      int right = 2*root + 2;
      int minimum = (arr[left] < arr[right] ) ? left : right ;
      while( root < index && left < index && right <index && arr[minimum] < arr[root] )
      {
        swap(arr[minimum],arr[root]);
        root = minimum;
         left = 2*root + 1;
         right = 2*root + 2;
         minimum = (arr[left] < arr[right] ) ? left : right ;
      }   
    }
    void insertion (int element )
    {
       if(tracker == size)
       {
        cout<<"heap filled";
        return ;
       }
       else
       {
        min[tracker] = element;
        if(tracker > 1)
       heapifyup(min,tracker);
        tracker++;
       }
       
    }
    int deletion()
    {
      int root = min[0];
      min[0] = min[tracker-1];
      tracker--;
      heapifydown(min,tracker);
     return root;
    }
    void heapify(int *arr,int size)
    {
      int last_child = int (size/2) - 1 ;
      
      for(int i= last_child ; i>=0;i--)
      {
        
        int left = 2*i + 1;
        int right = 2*i + 2 ;
        int smallest = i  ;      
        if(left<size && arr[smallest] > arr[left] )
        {
          smallest = left;
        }
        if(right < size && arr[smallest] > arr[right] )
        {
          smallest = right;
        }
        if(smallest != i)
        {
          swap(arr[smallest], arr[i]);
          
          heapify(arr,size);
        }
       
      }
    }


    void complete_array()
    {
      cout<<" Enter elements of an array:  ";
      for(int i=0;i<size;i++)
      {
        cout<<"arr["<<i+1<<"]: ";
        cin>>min[i];
      }
      heapify (min,size);
      //printing a min_heap
      for(int j=0;j<size;j++)
      {
        cout<<min[j]<<" ";
      }

    }
     void print_heap()
     {
      for(int k=0;k<tracker;k++)
      {
        cout<<min[k]<<" ";
      }
     }



    };