#include <list>
#include <stack>
#include <iostream>
#define V 6
using namespace std;

///https://github.com/keqhe/leetcode/blob/86b2a453255c909f94f9ea3be7f2a97a6680a854/graph/cycleDirectedGraph.cpp //https://github.com/zaidITpro/CandCplusplusPrograms/blob/e52a9f52e76fa22c22919e37d3ff1a3bbc5bfa62/Graph/detectCycleinDirectedgraph.cpp
//http://www.opita.net/node/486
class detectCycle_DirectedGraph{
     
     std::list<int> adj[V];
     public:
         void get_data();
         bool isCyclic();

};
void detectCycle_DirectedGraph::get_data()
{
    
    /* Let there are 6 vertices total from 1 to 6
       and given edges are
       1--->2
       1--->4
       2--->3
       3--->1
       3--->6
       6--->5
       5--->4

   */

   adj[0].push_back(1);
   adj[0].push_back(3);
   adj[1].push_back(2);
   adj[2].push_back(5);
   adj[2].push_back(0);
   adj[5].push_back(4);
   adj[4].push_back(3);
}
bool detectCycle_DirectedGraph::isCyclic()
{
   bool visited[V];
      std::stack<int> s;
      std::list<int>::iterator it;
      for(int i=1;i<=V;i++)
      {
             for(int j=0;j<V;j++)
             {
                   visited[j]=false;
             }
             visited[i]=true;
             s.push(i);
             int flag=0;
             while(!s.empty())
             {
                  int source=s.top();
                  s.pop();
                  for(it=adj[source].begin();it!=adj[source].end();it++)
                  {
                      if(*it==i)
                      {
                          /*If the traversing node is equal to current source vertex
                            which means there is a cycle */

                          return true;
                      }
                      if(visited[*it]==false)
                      {
                          s.push(*it);
                          visited[*it]=true;
                      }
                  }
                 
             }
      }
      
      /* If we don't find any cycle during traversal then return false*/
      return false;
}

int main()
{
  detectCycle_DirectedGraph graph;
  graph.get_data();
  if(graph.isCyclic())
  {
        cout<<"\n\nYes There is cycle in graph\n\n";
  }  
  else
  {
        cout<<"\n\nThere is not any cycle in graph\n\n";
  }
}