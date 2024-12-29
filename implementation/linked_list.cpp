// this is the implementation of reverse linked list
#include<iostream>
using namespace std;
template <typename T>
struct node
{
    T value;
    node<T> *next;
};
template <typename T>
class linked_list
{
    private:
    node<T> *first ;
    public:
    linked_list()
    {
       first=nullptr;
    }
    void insert(T value)
    {        
        
        
          node <T> *newnode = new node<T>;
            newnode->value = value ;
            newnode->next = first;
            first = newnode;
        
    }
    void display()
    {
        node<T> *temp;
        temp = first;
        while(temp != nullptr)
        {
           cout<<temp->value<<"->";
           temp=temp->next;
        }
    }
    // delete a node by value
    void delete_node(T value)
    {
        // if linked list is empty
        if(first == nullptr)
        {
            cout<<" Linked list is empty";
            return ;
        }
        // if the value is in head
        
        while(first != nullptr  && first->value == value)
        {
            
            first=first->next;  
            
        }
       
        // if the value lies in somewhere between the linked list 
       node<T> *current = first ;
       node <T> *temp = nullptr ;
     while(current->next != nullptr && current !=nullptr)
     {
        if(current->next->value == value)
        {
            current->next = current->next->next;
            break;
        }
        else
        current= current->next;
     }

    }

};
int main()
{
    linked_list <int> data;
    data.insert(11);
    data.insert(1234);
    data.display();
    data.delete_node(11);
    cout<<endl;
    data.display();
    return 0;
}