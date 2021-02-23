#include<iostream>
#include<list>
#include<iterator>

using namespace std;

list <int> *Table[5];
int hsize=5;

int hashfunc(int key)
{
    int tmp;
    tmp=key%hsize;
    return tmp;
}

void insert(int key)
{
    int hkey;
    hkey=hashfunc(key);
    if(Table[hkey]==NULL)
    {
        Table[hkey]=new list <int>;
        Table[hkey]->push_back(key);
    }
    else
    {
        Table[hkey]->push_back(key);
    }
}

void display()
{
    list <int> :: iterator it;
    cout<<"The Hashmap is: ";
    for(int i=0;i<hsize;++i)
    {
        if(Table[i]==NULL)
        {
            continue;
        }
        else
        {
            it=Table[i]->begin();
            cout<<endl;
            for(it;it!=Table[i]->end();++it)
            {
                cout<<*it<<" ";
            }
        }
    }
}

int main()
{
    insert(1);
    insert(2);
    insert(6);
    display();
    return 0;
}