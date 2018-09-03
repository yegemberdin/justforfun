#include <iostream>
using namespace std; 
int parent [101];
int disc    [101];
int low    [101];
bool visited  [101];
bool is_AP[101]; 
vector<int>adj[100]; 
void dfs(int s)
  static int c=0; 
  visited[s]=true;   
  disc[s]=low[s]=c++;  
  int child=0;
  for(int i=0;i<adj[s].size();i++)
  {
     int to = adj[s][i]; 
     if(to==parent[s])
      continue;      
  
    if(!visited[to])
    { 
      child++; 
      parent[to]=s; 
      dfs(to);
      low[s] = min(low[s] , low[to]); 
      if(parent[s]==-1 && child>1)
      is_AP[s]=true;
      if(parent[s]!=-1 && low[to]>=disc[s])
      is_AP[s]=true;
     }
    else
    {      
      low[s]= min(low[s],disc[to]);
    } 
  } 
}
 
int main()
{
  int n,m;
  cin>>n>>m; 
  for(int i=1;i<=m;i++)
    {
      int a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
       
  parent[1]=-1;
  dfs(1);
  for(int i=1;i<=n;i++)
    {
      if(is_AP[i])
        cout<<i<<" "<<endl;
    }
  return 0;
}