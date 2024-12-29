// implementation of stack using arrays
#include<iostream>
using namespace std;
template <typename T>
class stack
{
    private:
    T *arr;
    int max_size;
    int top;

    public:
     stack(int size)
     {
        max_size = size;
        top=-1;
        arr = new T[max_size];
     }
     void push(T data)
     {
        if(top==max_size-1)
        {
            cout<<" Stack overflow ";
        }
        arr[++top]=data;
        return ;
     }
     // removes the top element from the stack
     void pop()
     {
        if(top == -1)
        {
            cout<<" Stack underflow ";
        }
        top = top -1 ;
        return ;

     }
     //returns the top element from the stack
     T peek()
     {
        if(top == -1)
        {
            cout<<" Stack is empty";
        }
        return  arr[top];
     }
     // check if the stac is empty or not
     bool isEmpty()
     {
        if(top== -1)
        {
            return true;
        }
        return false;
     }
     ~ stack()
     {
        delete[] arr;
     }

};
int main()
{
    stack <int> data(5);
    
    data.push(11);
    data.push(12);
    data.push(111);
    data.push(11);
    data.push(12);
   
    while (!(data.isEmpty()))
    {
      cout<<data.peek()<<endl;
      data.pop();
    }
   

   
    return 0;
}