

#include "bits/stdc++.h"
using namespace std;

const int M = 100000;
vector<vector< int> > adj(M);

void apUtil(int u, vector<int> &disc, vector<int> &low, vector<int> &parent,
                      vector<bool> &ap, vector<bool>& visit)
{
      static int time = 0;

	  disc[u]= low[u] = ++time;
      int child=0;
	  visit[u]= true;


      
	  for(auto &i: adj[u])
	  {
		  int v = i;
		  child++;
          if(!visit[v])
		  {
				parent[v]= u;

				apUtil(v, disc, low, parent, ap, visit);

				low[u] = min(low[u], low[v]);

				if(parent[u]==-1 && child>1)  // Articulation point condi.
				ap[u]=true;
                
				if(low[v] > disc[u])  // Bridge condition 
				cout<<u<<" "<<v<<"\n";
				
				if(parent[u]!=-1 && low[v]>=disc[u]) // Articulation point condi.
				ap[u]=true;
		  }
		  else if(v!=parent[u])
		  {
			  low[u]= min(low[u], disc[v]);
		  }
	  }
}

int main()
{
  int V; cin>>V; 
  int E; cin>>E;

  for(int i=0; i< E; i++)
  {
	  int u, v; cin>>u>>v;
	  adj[u].push_back(v);
	  adj[v].push_back(u);
  }
  vector<int> disc(V), low(V), parent(V, -1);
  vector<bool> ap(V, false), visit(V, false);
  
  apUtil(0, disc, low, parent, ap, visit);

  for(int i=0; i< V; i++)
  {
     // cout<<i<<"-"<<disc[i]<<" "<<low[i]<<" "<<parent[i]<<"\n"; 
     if(ap[i]) cout<<i<<" ";
  }

}