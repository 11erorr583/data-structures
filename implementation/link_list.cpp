// this is the implementation of singly linked list
#include<iostream>
using namespace std;
template <typename T>
struct node
{
    T data;
    node<T>* next;
};
template <typename T>
class linked_list
{
    private:
    node<T>* head;
    public:
    linked_list()
    {
        head = nullptr;
    }
    // making insert function
    void insert(T value)
    {
        node<T> *newnode;
        newnode = new node<T>;
        newnode->data = value;
        newnode->next = nullptr;
        if(head == nullptr)
        {
            head = newnode;
        }
        else
        
        {
            node<T> *temp = head;
            while(temp->next !=nullptr)
            {
                 temp = temp->next;
            }
            temp->next = newnode;
        }
        
    }
    void display()
    {
        node<T> *tempo;
        tempo=head;
        while(tempo!=nullptr)
        {
            cout<<tempo->data<<"-->";
            tempo=tempo->next;
        }
        cout<<"NULL"<<endl;
    }
    void delete_node(int value)
    {
        if(head == nullptr)
        {
            cout<<" Linked list is empty "<<endl;
            return ;
        }
        // if head.value == value
        else
        if(head->data == value )
        {
            head=head->next;
        }
        // if the value lies in between the linked list
        node<T> *current = head;
        while(current != nullptr && current->next!=nullptr )
        {
            if(current->next->data == value)
            {
            current->next = current->next->next;
            }
            current = current->next;

        }
    }
};
int main()
{
    linked_list<int> data;
    data.insert(11);
    data.insert(13);
    data.insert(59);
    data.delete_node(11);
    data.delete_node(59);
    data.display();
    return 0;
}