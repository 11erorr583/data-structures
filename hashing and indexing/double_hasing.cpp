// this program will implement the double hashing
#include<iostream>
#include<climits>
using namespace std;
struct node
{
  int key ;
  string value;
};
class double_hash
{
  private:
  int size;
  node *table;
  public:
  double_hash(int n)
  {
    size = n;
    table = new node[size];
    //flag for empty
    for(int i=0;i<size;i++)
    {
        table[i].key = INT_MIN;
        table[i].value = " ";
    }
  }
  ~double_hash()
  {
    delete []table;
  }
  void insertion(int k)
  {
    cout<<" insertion--------"<<endl<<endl;
    int index = (k%size + size) % size; // this is h1(k)
    int h2 = 1+(k%(size-1));//this is h2(k);
    if( table[index].key == INT_MIN)
    {
        table[index].key = k;
        cout<<" Enter the value for key "<<k<<" at index "<<index<<endl;
        cin>>table[index].value ;
    }
    else
    {
        cout<<"collision--------"<<endl<<endl;
         int prob = 1;
         int attempts = 0;
         while(table[index].key != INT_MIN && attempts<size )
         {
            index = (index + (prob * h2)) % size;
            if(attempts == size)
            {
                cout<<" Hash is full "<<endl;
                return;
            }
            prob++;
            attempts++;
        }
        if(table[index].key == INT_MIN)
        {
            table[index].key = k;
            cout<<" Enter the value for key "<<k<<" at index "<<index<<endl;
           cin>> table[index].value;
           return;
        }
    }
  }
  void display()
    {
        cout<<"--------Hash Table-------------"<<endl<<endl;
        cout<<"index| key  ):   "<<"value"<<endl;
        cout<<"______________________"<<endl;
        for(int i=0;i<size;i++)
        {
            if(table[i].key != INT_MIN && table[i].key != INT_MAX)
            {
                cout<<i<<"    | "<<table[i].key<<"   ):   "<<table[i].value<<endl;

            }
        }

    }
    void delete_node(int k)
    {
        cout<<" deleting-------------"<<endl<<endl;
        int index=(k%size + size)%size;
        int h2 = 1+(k%(size-1));//this is h2(k);
        if(table[index].key == k)
        {
            table[index].key = INT_MAX;
            table[index].value=" ";
            return;
        }
        else
        {
            int attempts = 0;
            int prob = 1;
            while(table[index].key != k && attempts <= size) 
            {
                index = (index + (prob * h2)) % size;               
                attempts ++;
                prob++;
            }
                    
            if(table[index].key == k)
            {
                table[index].key = INT_MAX;
                table[index].value = " ";
            }
            else
            {
                cout<<" no such key exist in table "<<k<<endl;
            }
        }
    }
    void search_node(int k)
    {
        cout<<" seraching-------------"<<endl<<endl;
        int index = (k%size+size)%size;
        int h2 = 1+(k%(size-1));//this is h2(k);
        if(table[index].key == k)
        {
            cout<<" The key found at index "<<index<<" having value "<<table[index].value<<endl;
            return;
        }
    else
    {
       
       int count = 1;
       int loops = 0;
       while(table[index].key != k && loops<size && table[index].key != INT_MIN)
       {
        index = (index + (count * h2)) % size;    
         count++;
         loops++;
       }

    if(table[index].key == k)
    {
        cout<<" The key "<<k<<" exist at index "<<index<<" having value "<<table[index].value<<endl;
    }
    else
    {
        cout<<" The key "<<k<<" does not exist in table"<<endl;
    }


    }
}
};
int main()
{
    double_hash table(7); // small table size to force collisions
    table.insertion(10);  // h1 = 3, h2 = 4
    table.insertion(17);  // h1 = 3, h2 = 3 → collision with 10, uses double hashing
    table.insertion(24);  // h1 = 3, h2 = 2 → another collision at index 3
    table.insertion(31);  // h1 = 3, h2 = 1 → another collision at index 3

    table.display();

    table.search_node(24);  // should be found after probing
    table.search_node(31);  // should be found after more probing

    table.delete_node(17);  // test deletion in a probe chain
    table.search_node(17);  // should show not found
    table.display();

    return 0;
}
