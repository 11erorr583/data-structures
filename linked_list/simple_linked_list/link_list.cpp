#include<iostream>
using namespace std;
template <typename T>
struct node
{
  T value;
  node* next;
};
template <typename T>
class linked_list
{
    private:
      node <T> * temp;
     node <T> *head;
     public:
     linked_list()
     {
       temp = nullptr;
       head = nullptr;
     }
     ~linked_list()
     {
        delete temp;
        head = nullptr;
     }
     // displaying the results in head
     void display_head()
     {
        node <T> * jump = head ;
        if(jump != nullptr)
        {
            cout<<jump->value<<endl;
           
        }
        else
        cout<<" THe linked list is empty ";
    return ;
     }
     // checking if linked list is empty
     bool is_empty()
     {
        bool empty = false;
        if(head == nullptr)
        {
            empty = true;
            return empty;
        }
        return empty;
     }
     // traversing an array
     void traverse()
     {
        temp = head;
        while(temp!=nullptr)
        {
           cout<<temp->value<<" "<<"-> ";
           temp = temp->next;
        }
        cout<<"NULL"<<endl;
        if(is_empty())
         cout<<" The list was empty";
        return ;
     }
     // simple insert -- inserting vlue a first --
     void insert_last()
     {
        // make new node
        node <T> *newnode;
        newnode = new node<T>;
        cout<<" Enter the element you want to insert at the last";
        T element;
        cin>>element;
        newnode->value = element;
        newnode->next = nullptr;
        // if list is empty
        if(head == nullptr)
        {
           head = newnode;
           return ;
        }
        // if list is not empty
        temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;

     }
      void insertion_first()
      {
        node <T> *new_node;
        new_node = new node<T>;
        // enter the data 
        cout<<" Enter the value you want to insert at last "<<endl;
        T data;
        cin>>data;
        new_node->value = data;
        new_node->next = head;
        head = new_node;
      }
// inserting the value by position
 void insert_position(int position)
 {
   temp = head ;
   int counter = 0;
   // creating a new_node
   cout<<" Enter the value you want to insert at position  "<< position <<endl;
   T data;
   cin>>data;
   node<T>*newnode;
   newnode = new node<T>;
   newnode->value = data;
   newnode->next = nullptr;
   //////////////////////////////////////
   if(position == 0)
   {
    newnode->next = head;
     head = newnode;
   }
   // traverse the linked list untill we reach at the position-1 value

   while(temp->next != nullptr && counter != position-1)
   {
    temp = temp->next ;
    counter ++;
   }
   
   
   if(temp == nullptr)
   {
    cerr<<" INVALID ERORR "<<endl;
    return ;
   }
   else
   if(temp != nullptr)
   { 
    newnode->next = temp->next;
    temp->next = newnode;
     
   }
 }
 // delete from first
 void delete_first()
 {
    if(head == nullptr)
    {
        cout<<" linked list is empty";
        return;
    }
    else
    {node <T> *first;
    first = head;
    head = head->next;
    delete first;}

 }
 // delete from last
 void delete_last()
 {
    if(is_empty())
    {
        throw runtime_error("linked list is empty");
    }
    // if the list has only one element
    if(head->next == nullptr)
    {
        head = head->next;
    }
    // traverse the list untill last node is not found!!
    node<T> * current = head;
  while(current->next->next != nullptr)
  {
    current = current->next;
  }
  current->next = nullptr;
 }
 // deleting a node by value
 void delete_value(T value)
 {
    if( head == nullptr)
    {
        throw runtime_error("There exist an error!! ");

    }
     // if value is at head  
    if(head->value == value)
    {
        node<T> *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    // if value is in the middle or end
    node<T> *now = head; 
    while(now->next != nullptr && now->next->value != value)
    {
        now = now->next;
    }
    if(now->next == nullptr)
    {
        throw runtime_error("Value not found in the list");
    }
   
    now->next = now->next->next;
 }

// deleting by position
void delete_position(int position)
 {
   temp = head ;
   int counter = 0;
   
   if(position == 0)
   {
     head = head->next;
     return ;
   }
   // traverse the linked list untill we reach at the position-1 value

   while(temp->next != nullptr )
   {
    if(counter != position-1)
    {temp = temp->next ;
      counter ++;
    }
   }
   
   
   if(temp->next == nullptr)
   {
    throw runtime_error(" INVALID ""THE POSITION IS INVALID""ERORR ");
    
   }
   else
   if(temp != nullptr)
   { 
     temp->next = temp->next->next;
     
   }
 }

};
int main()
{
    linked_list <int> nodes;
   // nodes.insert_first();
   // nodes.insert_first();
   nodes.insertion_first();
    nodes.insertion_first();
    nodes.insertion_first();
    nodes.insertion_first();
    nodes.insertion_first();
    nodes.insertion_first();
    nodes.insert_position(1);
    cout<<nodes.is_empty()<<endl;
    nodes.display_head();

    while(!(nodes.is_empty()))
    {
      nodes.display_head();
      nodes.delete_first();
    }

      
        nodes.insert_last();
    nodes.insert_last();
    nodes.insert_last();
    nodes.insert_last();
    nodes.insert_last();
    nodes.insert_last();
    nodes.insert_position(1);    

    cout<<" Enter the value of any linked_ list_ node you want to delete"<<endl;
    auto value= 0;
    cin>>value;
    nodes.delete_value(value);
    cout<<"Remaining!! "<<endl;
    nodes.traverse();
    
    
    

    return 0;
}