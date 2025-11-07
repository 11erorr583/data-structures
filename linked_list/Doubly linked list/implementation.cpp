#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
};
class doubly_linkedList
{
  private:
  Node *head;
  Node *temp;
  Node *tail;
  public:
  doubly_linkedList()
  {
    head=nullptr;
    temp = nullptr;
    tail = nullptr;
  }
  ~doubly_linkedList()
  {
    delete temp;
    delete head;
    delete tail;
  }
  bool empty()
  {
    
    if(head==nullptr )
    {
       return true;
    }
    return false;
  }
  void insertion_first(int value)
  {
    // create new node
    Node *new_node = new Node;
    new_node->data = value;
    new_node->prev = nullptr;
    new_node->next = nullptr;
    //🫗if the linked list is empty
    if(empty())
    {
        head = new_node;
        tail = new_node;
    }
    else //if the list is not empty🌕
    {
    head  -> prev=new_node;
    new_node-> next = head;
    head = new_node;
    }
 }
 void insertion_last(int value)
 {
    //create new_node
    Node *new_node = new Node;
    new_node->data = value;
    new_node->prev = nullptr;
    new_node->next = nullptr;
     //🫗if the linked list is empty
    if(empty())
    {
        head = new_node;
        tail = new_node;
    }
     else //if the list is not empty🌕
     {
       tail->next = new_node;
       new_node -> prev = tail;
       tail = new_node;
     }
 }
 // insert the position with refrence to position
 
 void delete_head()
 {
    if(empty())
    {
        return ;
    }
    else
    if(head != nullptr && head->next == nullptr && head->prev == nullptr)
    {
      delete head;
      head = nullptr;
    }
    else
    if(head != nullptr)
    {
        temp = head;
        head = head-> next;
        head-> prev = nullptr;
        delete temp;
        temp = nullptr;
    }
 }
void delete_tail()
{
    if(empty())
    {
        return;
    }
    else
    if(head == tail)
    {
        delete head;
        
        head = nullptr;
        tail = nullptr;
    }
    else
    if(tail != nullptr)
    {
        temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        temp = nullptr;
    }
}
//traverse linked list through head;🤯
void traversal_forward()
{
  temp = head;
  if(temp == nullptr)
  {
   return;
  }
  while(temp != nullptr)
  {
    cout<<temp->data<<"->";
    temp = temp->next;
  
  }
  cout<<"NULL"<<endl;
}
void traverse_backword()
{
  temp = tail;
  if(tail == nullptr)
  {
    return;
  }
  else
  while(temp != nullptr)
  {
    cout<<temp->data<<"->"<<" ";
    temp = temp->prev;
  }
  cout<<"NULL"<<endl;
}
void insertion_position_head(int position)
{
  // create new node🖇️
  cout<<" Enter the value you want to insert at position "<<position<<endl;
  int value;
  cin>>value;
  Node *new_node = new Node;
  new_node->data = value;
  new_node->prev = nullptr;
  new_node->next = nullptr;
  //////////////////////////////////////////////////////
  int check = 0;
  temp = head ;
  if(empty())
  {
    return ;
  }
  else
  if(position == 0)
  {
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
  }
  while(temp != nullptr && check <= position-2)
  {
       temp = temp->next;
       check ++;
  }
  // check if the position is valid 
  if(temp == nullptr)
  {
    cerr<<"\033[81m Invalid Position"<<endl;

  }
  else
  if(temp != nullptr )
  {
    new_node->next = temp->next;
    if(temp->next != nullptr)
     { temp->next->prev = new_node;
     }
     else
     tail = new_node;
    temp->next = new_node;
    new_node->prev = temp;
  }

}
};
int main()
{
    doubly_linkedList list;
   
    list.insertion_last(16);
    list.insertion_last(15);
    list.insertion_last(14);
     list.insertion_first(11);
    list.insertion_first(12);
   list.insertion_first(13);
  /*  list.delete_head();
    list.delete_tail();
    
    
    list.traverse_backword();*/
    list.insertion_position_head(10);
    list.traversal_forward();
    
    return 0;

}