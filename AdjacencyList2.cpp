#include<iostream>

using namespace std;

class Node
{
    public:
    int NextV;
    int length;
    Node *ptr;
};

Node *head[5];
int Vertices=5;

Node* insertnode(int v,int len)
{
    Node *frnode=NULL;
    frnode=new Node();
    frnode->NextV=v;
    frnode->length=len;
    frnode->ptr=NULL;
    return frnode;
}

void insertedge(int u,int v,int len)
{
    Node *tmp=head[u];
    if(tmp==NULL)
    {
        tmp=insertnode(v,len);
        head[u]=tmp;
    }
    else
    {
        if(tmp->ptr==NULL)
        {
            tmp->ptr=insertnode(v,len);
            head[u]=tmp;
        }
        else
        {
            while (tmp->ptr!=NULL)
            {
                tmp=tmp->ptr;
            }
            tmp->ptr=insertnode(v,len);
        }
    }
}

void display()
{
    for(int i=0;i<Vertices;++i)
    {
        Node *tmp=head[i];
        cout<<i<<":"<<endl;
        while(tmp!=NULL)
        {
            cout<<"\t V:"<<tmp->NextV<<" D:"<<tmp->length;
            tmp=tmp->ptr;
        }
        cout<<endl;
    }
}

int main()
{
    insertedge(0,1,4);
    insertedge(1,2,2);
    insertedge(2,4,1);
    insertedge(3,5,1);
    insertedge(0,3,6);
    insertedge(4,0,9);
    insertedge(4,2,5);
    insertedge(4,1,5);
    display();
    return 0;
}

