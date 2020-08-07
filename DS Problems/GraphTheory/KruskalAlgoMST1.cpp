// Kruskal's Algorithm

// Kruskal's is a greedy approach 

# include <iostream>
# include <utility>
# include <algorithm>
# include <vector>
using namespace std;
#define ll long long
const int MAX= 1e4+5;
int parent[MAX], rank[MAX], edge, node;
pair<ll, pair<int, int> > p[MAX];

void init()
{
   for(int i=0; i<MAX; i++)
       parent[i]=i, rank[i]=0;
}

int root (int x)
{
     while(parent[x]!=x)
        {
            parent[x]= parent[parent[x]];
            x=parent[x];
        }
      return x; 
}

void Union(int x, int y)
{
      int p= root(x);
      int q= root(y);
      
      parent[p]=parent[q];
}

long long kruskal(pair<ll,  pair<int, int> > p[])
{
    int x, y;
    long long cost , minn=0;
  for(int i=0; i< edge; i++)
   {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        
         if(root(x)!=root(y))
         {
               minn+=cost;
               Union(x,y);  
         }
   }    
  return minn;
}

int main()
{
    int x, y; 
    long long weight, cost, minn;
    init();
    cin>>node>>edge;
    
    for(int i=0; i<edge; i++)
     {
       cin>>x>>y>>weight;
       p[i]= make_pair(weight, make_pair(x,y));
        
     }
   sort(p, p+edge);
   minn = kruskal(p);
   cout<<minn<<"\n";
    return 0;

}





