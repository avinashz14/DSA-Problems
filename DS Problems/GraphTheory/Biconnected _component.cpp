
// Low and  Disc concept used in Articulation point, Bridge and Biconnected , SCC
//Biconnected component

#include "bits/stdc++.h"
using namespace std;

const int Max=100000;
vector<vector<int>> adj(Max);
vector<int> disc(Max);
vector<bool> vis(Max);
vector<int> low(Max);
vector<int> parent(Max);
stack<pair<int, int> > st;
int V, E;
int ok;

void printScc(int u)
{
      static int time =0;
      disc[u] = low[u] = ++time;
      vis[u]= true;
      
      int child =0; 

      for(int i:adj[u])
      {
           int v = i;
           
          
          if(!vis[v])
          {
            child++;
            parent[v]=u;
            st.push({u, v});
            printScc(v);
       

            low[u]= min(low[u], low[v]);  //tree edge

            if((disc[u]==1 && child>1) || (disc[u]!=-1 && low[v]>=disc[u]))
            {
               pair<int, int> w;
                while(st.top().first!=u || st.top().second!=v)
                {
                   w = st.top();
                    st.pop();
                    cout<<w.first<<"--"<<w.second<<" ";
                }
                w = st.top();
                st.pop();
                cout<<w.first<<"--"<<w.second<<"\n";
                ok++;
            }
          
          }
          else if(parent[u]!=v)
          {
              low[u]= min(low[u], disc[v]); // back edge
              if(disc[u]> disc[v])
              st.push({u, v}); 
          }
      }
     
}

int main()
{
     cin>>V>>E;

    for(int i=0; i<E;i++)
    {
      int u, v; cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    
    for(int i=0; i< V; i++)
    {
        vis[i]= false;
        parent[i]=-1;
    }
    int cnt=0;
    for(int i=0; i<V; i++)
    {
        if(!vis[i])
        {  
            printScc(i);
        }
    }
    if(ok==0)  // case: if one Biconnect component is there 
    {
        for(int i=0; i<V; i++)
        {
            for(auto &j:adj[i])
            {
                cout<<i<<"--"<<j<<" "; 
            }
        }
    }
    return 0;

}