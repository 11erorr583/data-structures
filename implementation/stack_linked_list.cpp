#include<iostream>
using namespace std;
template <typename T>
struct stack_node
{
    T data;
    stack_node<T> *next;
};
template <typename T>
class stack
{
    private:
    stack_node <T> *top;
    public:
    stack()
    {
        top = nullptr;
    }
    void push(T value)
    {
        stack_node <T> *newnode = new stack_node<T>;
        newnode->data = value;
        newnode->next = top;
        top=newnode;
    }
    //pop() removes the element related to top
    void pop()
    {
        if(top == nullptr)
        {
            cout<<" Stack is empty";
            return;
        }
        stack_node <T> *temp = top;
        top = top->next;
        delete temp;
    }
    //peek returns the top value of element
    T peek()
    {
        T value = top->data;
        return value;
    }
    //isEmpty check is the stack is empty
    bool isEmpty()
    {
        if(top == nullptr)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    stack<int>data;
    data.push(123);
    data.push(11);
    
    cout<<data.isEmpty();
    while(!(data.isEmpty()))
    {
       cout<<data.peek()<<endl;
       data.pop();
    }
    return 0;
}