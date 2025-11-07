//1. Traversal  2. Insertion  3. Deletion  4. Search  5. Update  6. Checking for Empty List   7. Splitting 
//8. Merging 9.size
#include<iostream>
using namespace std;
struct node
{
       int value;
       node * next;
};
class linked_list
{
 private:
 node *temp;
 node *head;
 public:
 linked_list()
 {
    temp = nullptr;
    head = nullptr;
 }
 ~linked_list()
 {
   while(temp->next != head)
   {
      node *next_temp = temp->next;
      delete temp;
      temp = next_temp;
   }
   head = nullptr;
 }
 void traverse()
 {
   temp = head;
   while(temp ->next != head)
   {
      cout<<temp->value;
      cout<<" -> ";
      temp = temp -> next;
   }
   cout<<temp->value;
   cout<<" -> ";
   cout<<temp->next->value<<endl;
   // traversal back
    //traversal back in linked_list is impossible 
    
 
 }
 // in circular linked_list the the last_node's next pointer = head
 void insertion_simple()
 {
       ////////
      // create a newpointer 
      node *new_node;
      new_node = new node;
      cout<<" Enter any integer value ";
      int data;
      cin>>data;
      new_node -> value = data;
      new_node ->next = head;
      //////////////////////////
      // if list is empty
      if(head == nullptr)
      {
         head = new_node;
         head->next = head;
         return ;
      }
      // if list is not empty
      else
      {
          temp = head;
          while(temp->next != head)
          {
            temp = temp->next;
          }
          temp->next = new_node;
      }
 }
 void delete_simple()
 {
   // simply deleting the first node
   if(head == nullptr)
   {
      cout<<" Linked list is empty ";
      return;
   }
   else
   if(head->next == head)
   {
      head->next = nullptr;
      delete head;
   }
   else
   if(head != nullptr)
   {
      temp = head;
     
      while( temp -> next != head)
      {
         temp = temp ->next;
      }
       head = head -> next;
     temp -> next = head;
   }
   
 }
 void search( int value)
 {
   //if linked list is empty
   if(head == nullptr)
   {
      cout<<" Linked list is empty "<<endl;
      return ;
   }
   else
   if(head->value == value)
   {
      cout<<" Found at position 1"<<endl;
      return;
   }
   // applying linear_search to find target value
   temp = head;
   int position = 0;
   while(temp->next != head)
   { 
      if(temp -> value == value)
      {
         cout<<" The value found at position: "<<position;
         return ;
      }
      position++;
      temp = temp -> next;
   }
   if(temp -> value == value)
      {
         cout<<" The value found at position: "<<position;
         return ;
      }
      else
       if(temp -> value != value)
      {
         cout<<" The value not found  ";
         return ;
      }


 }
void size()
{
   
}
};
int main()
{
   linked_list data;
    cout<<" Enter any value you want to find in linked_list ";
   int Value;
   cin>>Value;
   data.search(Value);
   data.insertion_simple();
   data.traverse();
   data.delete_simple();
   data.insertion_simple();
   data.traverse();
   data.insertion_simple();
   data.traverse();
   data.insertion_simple();
   data.traverse();
   data.insertion_simple();
   data.traverse();
   data.insertion_simple();
   data.traverse();
   data.insertion_simple();
   data.traverse();
   data.insertion_simple();
   data.traverse();
   data.delete_simple();
   data.traverse();

   cout<<" Enter any value you want to find in linked_list ";
   int value;
   cin>>value;
   data.search(value);

   return 0;
}