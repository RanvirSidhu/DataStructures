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
    cout<<endl;
    for(int i=0;i<hsize;++i)
    {
        cout<<"["<<i<<"]: ";
        if(Table[i]==NULL)
        {
            cout<<endl;
            continue;
        }
        else
        {
            it=Table[i]->begin();
            for(it;it!=Table[i]->end();++it)
            {
                cout<<*it<<" ";
            }
        }
        cout<<endl;
    }
}

int search(int num,bool print)
{
    list <int> :: iterator it;
    int hkey,pos=0;
    bool flag=false;
    hkey=hashfunc(num);
    if(Table[hkey]==NULL)
    {
        cout<<"The number doesnt exist";
    }
    else
    {
        for(it=Table[hkey]->begin();it!=Table[hkey]->end();++it)
        {
            if(*it==num)
            {
                flag=true;
                break;
            }
            pos++; 
        }
    }
    if(print==true)
    {
        if(flag==false)
        {
            cout<<"The number doesn't exist";
        }
        else
        {
            cout<<"The number does exist";
            cout<<pos;
        }
    }
    else
    {
        if(flag==false)
        {
            pos=-1;
        }
    }
    return pos;
}

void deletion(int num)
{
    list <int> :: iterator it;
    int pos,hkey;
    hkey=hashfunc(num);
    pos=search(num,false);
    it=Table[hkey]->begin();
    if(pos==-1)
    {
        cout<<"The number doesnt exist"<<endl;
    }
    else
    {
        advance(it,pos);
        Table[hkey]->erase(it);
        display();
    }
}

int main()
{
    insert(5);
    insert(1);
    insert(2);
    insert(6);
    insert(13);
    insert(19);
    insert(24);
    insert(39);
    display();
    deletion(25);
    //search(3,false);
    return 0;
}