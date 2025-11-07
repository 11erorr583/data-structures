#include<iostream>
#include "min_heap.h"
#include "max_heap.h"
using namespace std;
int main()
{
    cout<<" press: 1) For accesending order "<<endl;
    cout<<"        2) For descending order "<<endl ;
    int option;
    cin>>option;
    if(option == 1)
    {
        int size;
        cout<<" ENter the number of elements ";
        cin>>size;
        int j=0;
        min_heap arr(size);
        int sorted[size];
        int elements;
        while ( j!= size)
        {
            cin>>elements;
            arr.insertion(elements);
            j++;
        }
        int k=0;
        while(k!=size)
        {
            sorted[k] = arr.deletion() ;
            cout<<sorted[k]<<" ";
            k++;
        }
    }
    else
    {
        int size;
        cout<<" ENter the number of elements ";
        cin>>size;
        int j=0;
        max_heap arr(size);
        int sorted[size];
        int elements;
        while ( j!= size)
        {
            cin>>elements;
            arr.insertion(elements);
            j++;
        }
        int k=0;
        while(k!=size)
        {
            sorted[k] = arr.deletion() ;
            cout<<sorted[k]<<" ";
            k++;
        } 
    }
    return 0;


}