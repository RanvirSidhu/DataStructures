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
        int x=i;    //Linear Probing
        if(h[tmph+x]==0)
        {
            h[tmph+x]=key;
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
        if(h[pos]!=key)
        {
            probe(key);
        }
    }    
}

void display()
{
    for(int i=0;i<hsize;++i)
    {
        if(h[i]==-1)
        {
            cout<<0<<" ";
        }
        else
        {
            cout<<h[i]<<" ";
        }    
    }
    cout<<endl;
}

int search(int num)
{
    int x=0;
    int pos,tmp,flag=0;
    pos=hashfunc(num);
    tmp=pos;
    while(h[tmp]!=0)
    {
        if(h[tmp]==num)
        {
            flag=1;
            break;
        }
        else
        {
            x++;
            tmp=pos+x; 
        }
    }
    if(flag==0)
    {
        cout<<endl<<"The number does not exist";
        exit(0);
    }
    return tmp;
}
    

void deletion(int num)
{
    int pos;
    pos=search(num);
    h[pos]=-1;  //tombstone = -1
}

int main()
{
    insert(5);
    insert(12);
    insert(15);
    insert(9);
    insert(20);
    insert(1);
    insert(14);
    insert(13);
    display();
    deletion(15);
    display();
    return 0;
}