
# include "bits/stdc++.h"
using namespace std;
typedef pair<long long , int>  pii;
const int mxn = 1e5;
vector<pii>  adj[mxn];
bool visited[mxn];

long long prim(int x)
{
  int y;
  priority_queue<pii, vector<pii>, greater<>> pq;
  long long  minimumCost=0;
   
   pq.push(make_pair(0,x));
   while(!pq.empty())
   {
        pii p = pq.top();
        pq.pop();

        x = p.second;
  
        if(!visited[x])  // not visited so it to be consider for MST
        {
          minimumCost+=p.first;
          visited[x]=true;
          for(int i=0; i<adj[x].size(); i++)
          {
            y = adj[x][i].second;

              if(!visited[y])
              {
                pq.push(adj[x][i]);
              }
          }
        }
   }
   return minimumCost;
}

int main()
{
    int nodes, edges;
    long long weight, minimumCost;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
      int x, y; cin>>x>>y>>weight;
      
      adj[x].push_back(make_pair(weight, y));
      adj[y].push_back(make_pair(weight, x));

    }
  
   minimumCost = prim(1);
   cout<<minimumCost<<"\n";
   
   return 0;
}
