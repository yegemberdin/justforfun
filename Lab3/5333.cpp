#include<iostream>
#include<vector>
using namespace std;

vector< vector< int > > g;
bool visited[10000], used[10000], hasCycle;
int n, e;
void dfs(int v)
{
    visited[v] = used[v] = true;    //push node v in recursion stack

    for(int i=0; i<g[v].size(); i++)
    {
        if(used[g[v][i]])   //if we encounter a node which is already in stack
        {
            hasCycle = true;
            return; 
        }
        else if(!visited[g[v][i]]);
            dfs(g[v][i]);
    }
    used[v] = false;    //pop node v from stack as it's DFS is over
}


int main()
{
    int n, e;
    cin>>n;  //get number of nodes
    cin>>e;;    //get number of edges

    g = vector< vector< int > > (n);

    int u, v;
    for(int i=0; i<e; i++)
    {
        cin>>u;
        cin>>v;
        u--, v--;   //it is assumed that nodes entered are 1-based indexed
        g[u].push_back(v);
    }

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            if(hasCycle)
                break;
        }
    }

    if(hasCycle){
        cout<<"GRAPH HAS A CYCLE\n";
    }
    else
        cout<<"NO CYCLE\n";
    return 0;
}