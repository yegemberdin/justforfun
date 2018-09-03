#include<bits/stdc++.h>
using namespace std;
vector<int > adj[101];
bool visit[101];
stack <int > st;
void dfs(int s){
    visit[s]=true;
    for(int i=0;i<adj[s].size();++i)
            if(visit[adj[s][i]]==false)    
                dfs(adj[s][i]);
    st.push(s);
}

int main()
{
    int n,m,x,y,cnt=1;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
     cin>>x>>y;
     adj[x].push_back(y);
     adj[y].push_back(x);
    }
 
 for(int i=1;i<=n;i++){
 if(visit[i]==false)
   dfs(i); 
   visit[i]=false;
   while(!st.empty())
   {
   int v=st.top();
     st.pop();
     if(visit[v]==false)
     {
        dfs(v);
        cnt++;        
     }
   }}
   cout<<cnt;
}