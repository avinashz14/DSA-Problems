// Kruskal's Algorithm

// Kruskal's is a greedy approach 

# include <iostream>
# include <utility>
# include <algorithm>
# include <vector>
using namespace std;

const int MAX= 1e4+5;
int id[MAX], edge, nodes;
pair<ll,  pair<int, int> > p[MAX];

void init()
{
   for(int i=0; i<MAX; i++)
       id[i]=i;
}

int root (int x)
{
     while(id[x]!=x)
        {
            id[x]= id[id[x]];
            x=id[x];
        }
      return x; 
}

void union(int x, int y)
{
      int p= root(x);
      int q= root(y);
      id[p]=id[q];
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
               union(x,y);  
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





