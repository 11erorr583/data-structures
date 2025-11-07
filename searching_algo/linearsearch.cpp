#include<iostream>
#include<vector>
using namespace std;
bool linear_search(vector<int> &data,int &n,int &target)
{
    bool found=true;
    for(int i=0;i<n;i++)
    {
        if(data[i]==target)
        {
            found=true;
            cout<<" Target found at position "<<i+1<<endl;
            break;
        }
        else 
        if(data[i]!=target)
        {
           found=false;
        }
    }
    return found;
}
int main()
{
    cout<<" Enter the number of elements for array ";
    int n,element;
    cin>>n;
    vector<int>data;
    cout<<"Enter your target you want to search: ";
    int target;
    cin>>target;
    
    cout<<" Now enter the elements ";  
    for(int i=0;i<n;i++)
    {
        cout<<"data[ "<<i+1<<"]: ";
        cin>>element;
        data.push_back(element);
     }
    bool search= linear_search(data,n,target);
   if (search)
   {
     return 0;
   }
   else
   cout<<" target not found "<<endl;
   return 1;
}