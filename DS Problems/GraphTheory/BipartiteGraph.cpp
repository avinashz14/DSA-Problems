#include "bits/stdc++.h"
using namespace std;

///https://www.geeksforgeeks.org/bipartite-graph/

int V, E;
int Gp[500][500];


bool findBipartite(int s, int colorId[])
{
     if(Gp[s][s])
     return false;

     colorId[s]=1;

      queue<int> que;

      que.push(s);

      while(!que.empty())
      {
          int u = que.front();
          que.pop();

		  if(Gp[u][u])
		  return false;



           for(int v=0; v<V; v++)
           {
               if(Gp[u][v] && colorId[v]==-1)
               {
                   colorId[v]=1-colorId[u];
                   que.push(v);
               }
               else if(Gp[u][v] && colorId[v]==colorId[u])
               return false;

           }
      }
      return true;
}

bool Bipartite()
{
	int colorId[V];
    for(int i=0; i<V; i++)
       colorId[i]=-1;
    
    for(int i=0; i<V; i++)
    {
        if(colorId[i]==-1)
            if(findBipartite(i,colorId)==false)
            return false;
    }

    return true;
}

int main()
{
     cin>>V;

     for(int i=0; i<V; i++)
       for(int j=0; j<V; j++)
           cin>>Gp[i][j];

    if(Bipartite())
    cout<<"Yes\n";
    else 
    cout<<"No\n";
}