// In this program I will implement quadratic probing
// simple hash function: (k%size + size)%size;
// quad_prob: hash function:( h(k) + i**2 ) % size;
#include<iostream>
#include<climits>
using namespace std;
struct node
{
   int key;
   string value;
};
class quadratic_probing
{
    int size;
    node *table;
    public:
    quadratic_probing(int n)
    {
        size = n;
        table = new node[size];
        // INT_MIN is the flag for empty
        for(int j=0;j<size;j++)
        {
            table[j].key=INT_MIN;
            table[j].value=" ";
        }
    }
    ~quadratic_probing()
    {
        delete  []table;
    }
    bool duplicate(int k)
    {
        
        for(int i=0;i<size;i++)
        {
            if(table[i].key == k)
            {
                return true;
            }
        }
        return false;
    }
    void insertion(int k)
    {
        while(duplicate(k))
        {
            cout<<" the key "<<k << "already exist in table try for another key ";
            cin>>k;
        }
        cout<<" insertion............."<<endl<<endl;
        int index = (k%size + size)% size;
        // if table slot is empty
        if(table[index].key == INT_MIN || table[index].key == INT_MAX)
        {
            table[index].key = k;
            cout<<" Enter the value for key "<<k<<" at index "<<index<<endl;
            cin>>table[index].value;
            return;
        }
        else
        {
            //collision happenes we will use quadratic probing
            cout<<" collision--------------"<<endl<<endl;
            int count = 1;
            int original = index;
            int loop = 0;
            while(table[index].key != INT_MIN && loop<size)
            {
                index = (original + (count*count))%size;
                count++;
                loop ++;
            }
            if(loop == size)
            {
                cout<<" Can not enter more key "<<k<<endl<<" Hash table is full"<<endl<<" or might be there is clustering"<<endl;
                return;
            }
            table[index].key = k;
            cout<<" Enter the value for key "<<k<<" at index "<<index<<endl;
            cin>>table[index].value;
           
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
    void deletion(int k)
    {
        cout<<" deleting--------------"<<endl<<endl;
        int index = ((k%size)+size)%size;
        int original = index;
        if(table[index].key == k)
        {
           table[index].key = INT_MAX;
           table[index].value = " ";  
           return; 
        }
        else
        {
            int count = 1;
            int loops = 0;
            
            while(table[index].key != k && loops<size)
            {
                index = (original + (count*count)) % size;
                count++;
                loops++;
            }
            if(loops==size)
            {
                cout<<" Key does not exist in table "<<endl;
                return;
            }
            if(table[index].key == k )
            {
                
           table[index].key = INT_MAX;
           table[index].value = " ";  
           return; 
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
       int original = index;
       int count = 1;
       int loops = 0;
       while(table[index].key != k && loops<size && table[index].key != INT_MIN)
       {
         index = (original + (count * count )) % size;
         count++;
         loops++;
       }
    if(table[index].key == k)
    {
        cout<<" The key "<<k<<" exist at index "<<index<<" having value "<<table[index].value<<endl;
    }
    else
    {
        cout<<" key "<<k<<" does not exist in table "<<endl;
    }


    }
}
};
int main()
{
    cout << ">>> Starting Clustering Demo <<<\n";

    // Small size to make clustering more obvious
    quadratic_probing table(7);

    // All these keys have hash index = 0
    table.insertion(0);   // index = 0
    table.insertion(7);   // index = 0 → probe 1^2 = 1 → index = 1
    table.insertion(14);  // index = 0 → 2^2 = 4 → index = 4
    table.insertion(21);  // index = 0 → 3^2 = 2 → index = 2
    table.insertion(28);  // index = 0 → 4^2 = 16 % 7 = 2 (already filled) → keep probing
    table.insertion(35);  // index = 0 → more probes...
    table.insertion(42);  // fills up or may fail due to quadratic wrap

    table.display();
}
