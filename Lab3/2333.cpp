#include<iostream>
#include<vector>
using namespace std;
 
const int MAX = 100000;
vector <int> path;
vector< vector <int> > g;
bool visited[MAX], hasCycle;
int n, e;
int cnt=0;
void dfs(int v, int parent)
{
    visited[v] = 1;
 
    for(int i=1; i<=g[v].size(); i++)//traverse through vertexes(1:)
    {
        if(!visited[g[v][i]])//node vertex(:2,3)
            dfs(g[v][i], v);
        else if(g[v][i] != parent)  //visited node other than cur node's parent
        {
            hasCycle = true;
            cnt++;
            return;
        }
    }
}
 
 
int main()
{
    cin>>n;  //get number of nodes
    cin>>e;  //get number of edges
 
    g = vector< vector<int> > (n);
 
    int u, v;
    for (int i=1; i<=e; i++)
    {
        cin>>u;
        cin>>v;
        u--, v--;   //it is assumed that nodes entered are 1-based indexed
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    for (int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            dfs(i, -1);
            if(hasCycle)
                break;
        }
    }
 
    if(hasCycle){
        cout<<"GRAPH HAS A CYCLE\n";
        cout<<cnt;
    }
    else
        cout<<"NO CYCLE\n";
}