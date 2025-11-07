// this is the implementation of hash with open addressing
// we resolve collision by linear probing , quadratic probing and double hashing
// in this program i will apply linear probing
//I have used INT_MIN as flag for empty
// I have used INT_MAX as flag for deleted
#include<iostream>
#include<climits>
using namespace std;
struct node
{
    int key;
    string value;
};
class hashe
{
    private:
    int size;
    node *table;
    public:
    hashe(int n)
    {
      size = n;
      table = new node[size];
      //sentinal value for empty table
      for(int i=0;i<size;i++ )
      {
        table[i].key=INT_MIN;
        table[i].value = " ";
      }
    }
    ~hashe()
    {
        delete []table;
    }
    void insertion(int k)
    {
        cout<<" Inserting........."<<endl<<endl;
        int index = (k%size + size)%size;
        //case1:is space is empty
        if(table[index].key == INT_MIN || table[index].key == INT_MAX)
        {
            table[index].key = k;
            cout<<" Enter value for key "<< k <<" at index "<<index<<endl;
            cin>>table[index].value;
            return;
        }
        //case2:if the space is not empty
        if(table[index].key != INT_MIN)
        {
            cout<<" linear probing........."<<endl<<endl;
            int counter = 1;
            while(table[index].key != INT_MIN)
            {
                index = (index + 1) % size;
                if(counter == size)
                {
                    cout<<" Hash table is full "<<endl;
                    return;
                }
                counter++;
            }
            table[index].key = k;
            cout<<" ENter value for index "<<index<<"  with key "<<k<<endl;
            cin>>table[index].value ;
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
        cout<<" deleting-------------"<<endl;
        int index=(k%size + size)%size;
        int original = index;
        if(table[index].key == k)
        {
            table[index].key = INT_MAX;
            table[index].value=" ";
            return;
        }
        else
        {
            while(table[index].key != k)
            {
                index = (index+1)%size;
                if(index == original)
                {
                    cout<<" error: No such key exists "<<endl;
                    return;
                }
            }
          
            if(table[index].key == k)
            {
                table[index].key = INT_MAX;
                table[index].value = " ";
            }
        }
    }
    void search_node(int k)
    {
        cout<<" seraching-------------"<<endl<<endl;
        int index = (k%size+size)%size;
        int original = index;
        if(table[index].key == k)
        {
            cout<<" The key found at index "<<index<<" having value "<<table[index].value<<endl;
            return;
        }
    else
    {
        for(int i=0;i<size;i++)
        {
            if(table[i].key == k)
            {
                cout<<" The key found at index "<<index<<" having value "<<table[index].value<<endl;
                return;
            }
        }
        cout<<" No such key exists"<<endl;
    }

    }

};
int main()
{
  cout<<" Enter the size of your hash table "<<endl;
  int n;
  cin>>n;
  hashe table(n);
  table.insertion(11);
  table.insertion(12);
  table.insertion(13);
  table.insertion(14);
  table.insertion(15);
  table.insertion(23);
  table.search_node(23);
  table.search_node(11);
  table.search_node(9);
  table.display();
  table.delete_node(23);
  cout<<" Table after deleting node for key 23 "<<endl;
  table.display();
  table.insertion(43);
  table.display();
  return 0;
}