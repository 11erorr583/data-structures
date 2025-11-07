#include<iostream>
using namespace std;
struct node
{
    int key;
    string value;
    node* next_node;//need for chaining
};
class hashing
{
    int size;
    node *table;
    public:
    hashing(int n)
    {
        size = n;
        table = new node[size];
        // initialize it with a value that indicate it's empty
        for(int i=0;i<size;i++)
        {
            table[i].key=-1;
            table[i].value = " ";
            table[i].next_node = nullptr;
        }
    }
    ~hashing()
    {
          // Delete all chains to prevent memory leak
          for (int i = 0; i < size; i++) {
            node* current = table[i].next_node;
            while (current != nullptr) {
                node* next = current->next_node;
                delete current;
                current = next;
            }
        }
        delete[] table;
    }
    void chainning(int position_table , int key)
    {
        cout<<" chaining...."<<endl;
        node *new_node = new node;
        new_node -> key = key;
        cout<<" Enter the value for key "<<key<<" at index "<<position_table<<endl;
        cin>>new_node -> value;
        new_node->next_node = nullptr;
        if( table[position_table].next_node == nullptr)
        table[position_table].next_node = new_node;
       else
       {
         node* temp = table[position_table].next_node;
         while(temp->next_node != nullptr)
         {
            temp = temp->next_node;
         }
         temp->next_node = new_node;
       }
    }
    void insertion(int k)
        { 
            cout<<" Inserting....."<<endl;
            // I will use simple modulo hash function
        int index = (k % size + size) % size;
        if(table[index].key == -1)
        {
            table[index].key = k ;
            cout<<" Enter value for key "<<k <<"at index "<<index<<endl;
            cin>>table[index].value;
        }
        else
        {//if  already contains value then I will use collision handling
        chainning(index,k); }   
    }
   void deletion(int k)
   {
    cout<<" Deleting...."<<endl;
    int index = (k%size + size) % size;
    if(table[index].key == k && table[index].next_node == nullptr) 
    {
        table[index].key = -1;
        table[index].value = " ";
        return ;
    }
    //Key is at main slot, chain exists
    else
    if(table[index].key == k && table[index].next_node != nullptr)
    {
        node* temp = table[index].next_node;
        table[index].key = temp->key;
        table[index].value = temp -> value;
        table[index].next_node = temp->next_node;
        delete temp;
        return;
    }
    //Key is in the chain 
    else    
    {

            node *temp = table[index].next_node;
            node *prev = nullptr;
           
            while(temp != nullptr && temp->key != k)
            {
                prev = temp;
                temp = temp->next_node;
            }
            if(temp == nullptr)
            {
                cout<<" Error: no such key "<<k<<" exists "<<endl;
                return;
            }
            if(prev == nullptr)
            {
                table[index].next_node = temp->next_node;
            }
            else
            {
                prev->next_node = temp->next_node;
            }
            delete temp;



    }
    return;
   }
   void display()
   {
    cout<<" Displaying....."<<endl;
    
     for(int k=0;k<size;k++)
     {
       
        
        if(table[k].key != -1  )
        {
            cout<<table[k].key <<"  ):  "<<table[k].value<<endl;
            node *temp = table[k].next_node ;
            while(temp != nullptr)
            {
                cout<<temp->key <<"  ):  "<<temp->value<<endl;
                 temp = temp -> next_node;
            }
        }
    
     }
   }

   void search(int k)
   {
     /*
        key is at the main and no chaining
        key is at the main , but chaining exists
        key is not at the main , but with in the chain
        key does not exists */
        //case1 : key is at the main and no chaining
        int index = (k%size + size) % size;
        if(table[index].key == k && table[index].next_node == nullptr)
        {
            cout<<" key found at index "<<index<< " with key "<<k;
            return;
        }
        if(table[index].key == k && table[index].next_node!=nullptr)
        {
            cout<<" Key found at index "<<index<<" with key "<<k<<" and chaining exists "<<endl;
        return;
        }
       else
       {
         node *temp = table[index].next_node;
         int counter = 1; // Start counter at 1 for the chain position
         while(temp!=nullptr)
         {
            if(temp->key == k)
            {
                cout<<" key found at the position of chain "<<counter << " of index "<<index<<endl;
                return;
            }
            temp = temp->next_node;
            counter++;
         }
         if(temp == nullptr)
         {
            cout<<" Error: the key does not exist "<<endl;
         }

       } 
    }
};
int main()
{
  cout<<" Enter the size of table ";
  int n;
  cin>>n;
  hashing table(n);
  table.insertion(-13);
  table.insertion(23);
  table.insertion(43);
  table.display();
  table.search(-13);
  table.search(43);
  table.search(22);
  table.deletion(23);
  cout<<" After deleting 23: "<<endl;
  table.display();
  cout<<" After deleting 11: "<<endl;
  table.deletion(11);
  table.display();

  return 0;

}