#include<iostream>

using namespace std;

int hsize=13;
int h[13];

int hashfunc(int key)
{
    int tmp;
    tmp=key%hsize;
    return tmp;
}

void probe(int key)
{
    int tmph=hashfunc(key);
    for(int i=1;i<13;i++)
    {
        if(h[tmph+i]==0)
        {
            h[tmph+i]=key;
            break;
        }
    }
}

void insert(int key)
{
    int pos;   
    pos=hashfunc(key);
    if(h[pos]==0)
    {
        h[pos]=key;
    }
    else
    {
        probe(key);
    }
    
}

void display()
{
    for(int i=0;i<hsize;++i)
    {
        cout<<h[i]<<" ";
    }
}

int main()
{
    insert(5);
    insert(12);
    insert(15);
    insert(9);
    insert(20);
    insert(1);
    insert(13);
    display();
    return 0;
}