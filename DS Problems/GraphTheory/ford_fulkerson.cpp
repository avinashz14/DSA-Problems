
//Ford-Fulkerson algorithm for finding the max flow in flow-Network 
/*
  preRequesite: https://www.geeksforgeeks.org/max-flow-problem-introduction/
   Steps in Ford-Fulkerson algo:
   step1:  Initialize residual graph as same input Graph matrix 
   step2:  Do BFS or DFS to find path from S to T, here we use BFS as BFS takes minimum verties
           and mantain Parent array to store parents of Verties
   step3: if there is path btw S to T, then using Parent array find minimum flow in StoT path 
          decrease the edge capacity of edge u-v to min_flow and add residual capacity to v-u
          And Add min_flow into max_flow 
   step4: return max_flow    
*/




#include "bits/stdc++.h"
using namespace std;
const int V=6;  // define size of graph matrix

bool bfs(int graph[V][V], int s, int t, int parent[])
{
    vector<bool> vis(V, false);
    vis[s]= 1;
    queue<int> que;
    que.push(s);

    while(!que.empty())
     {
        int u = que.front();
        que.pop();

        for(int v=0; v<V; v++)
        {
            if(!vis[v] && graph[u][v]>0)
            {
                vis[v]=1;
                parent[v]=u;
                que.push(v);
            }
        }

     }
     return vis[t];
}
int ford_fulkerson(int rgraph[V][V])
{
     int* parent= new int[V];
    parent[0]=-1;

    int s=0, t= V-1;
    int max_flow= 0;
    while(bfs(rgraph, s, t, parent))
    {
        int min_flow=INT_MAX;
        for(int v=t; v!=s; v=parent[v])
        {
            min_flow = min(min_flow, rgraph[parent[v]][v]);
        }
        for(int v=t; v!=s; v=parent[v])
        {
            int u = parent[v];
           rgraph[u][v]-=min_flow;
           rgraph[v][u]+=min_flow;
        }
        max_flow+=min_flow;
    }
      
    /*  for(int i=0; i<V; i++)   
        { 
           for(int j=0; j<V; j++)   
           {
               cout<<rgraph[i][j]<<" ";
           }
           cout<<"\n";
        }
    */
    return max_flow;
}

int main()
{
    //cin>>V;

    int graph[V][V];

    for(int i=0; i<V; i++)   
        for(int j=0; j<V; j++)   
           cin>>graph[i][j];

    cout<<"Max Flow in flow Network is : ";
    cout<<ford_fulkerson(graph)<<" ";
}

/*
  Time O(EV^2)
  Space O(V^2)
*/