include<bits/stdc++.h> 
using namespace std;

class Graph
{
private:
    int V;
    list<int>* adj;
    void DFSutil(int s, bool vis[]);    
public:
    Graph(int v);
    // add an edge 
    void addEdge(int u, int v);

    // BFS in graph 
    int  BFS(int s);
    void DFS(int s);

    ~Graph();
};

Graph::Graph(int v)
{
    this->V=v;
    adj = new list<int> [V];
}
void Graph::addEdge(int u, int v)
{
    adj(u).push_back(v);
    // if undirected graph use both
    adj(v).push_back(u);
}
int Graph::BFS(int s)
{
     bool* vis = new bool[V];
     int level[V];

     for(int i=0; i<V; i++)
     {
         vis[i] = false;
         level[i]=0;
     }

     list<int> queue;
     vis[s]=true;
     queue.push_back(s);
     level[s]=0;
     
     while (!queue.empty())
     {
         s =  queue.front();
         queue.pop_front();

         for(auto i=adj[s].begin(); i!=dj[s].end(); i++)
           {
               if(!vis[*i])
               {
                   level[*i] = level[s]+1;
                   vis[*i]= true;
                   queue.push_back(*i);
               }
           }
     }
     
}
void Graph::DFS(int s)
{
    vis[s]= true;
    cout<<s<<" ";

    for(auto i= adj[s].begin(); i!=adj[s].end(); i++)
      if(!vis[*i])
         DFSutil(*i, vis);
}
void Graph::DFS(int s)
{
    bool* vis = new bool[V];
    for (int i=0; i<V; i++)
       vis[i] false;

    DFSutil(s, vis);
}

Graph::~Graph()
{
}

int main()
{
    return 0;
}