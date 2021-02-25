#include<iostream>

using namespace std;

int Vertices=6;
int mat[6][6];

void setedge(int u, int v)
{
    mat[u][v]=1;
    mat[v][u]=1;
}

void display()
{
    cout<<"    ";
    for(int i=0;i<Vertices;++i)
    {
        cout<<"["<<i<<"] ";
    }
    cout<<endl;
    for(int i=0;i<Vertices;++i)
    {
        cout<<"["<<i<<"]: ";
        for(int j=0;j<Vertices;++j)
        {
            cout<<mat[i][j]<<"   ";
        }
        cout<<endl;
    }
}

int main()
{
    setedge(0,1);
    setedge(2,1);
    setedge(3,5);
    setedge(4,5);
    setedge(4,4);
    display();
    return 0;
}