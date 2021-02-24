#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[v].push_back(u); 
    adj[u].push_back(v); 
} 

void display(vector<int> adj[],int V)
{
    for(int i=0;i<V;++i)
    {
        cout<<"Adjacency List of vertix "<<i<<" is: "<<endl;
        cout<<"\tHead";
        for(auto it=adj[i].begin();it!=adj[i].end();++it)
        {
            cout<<"->"<<*it;   
        }    
        cout<<endl;
    }
}


int main()
{
    int V=5; 
    vector<int> adj[V];
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    display(adj,V);
    return 0;
}