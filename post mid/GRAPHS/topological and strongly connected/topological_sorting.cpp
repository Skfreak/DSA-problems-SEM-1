#include<iostream>
#include<list>
#include<stack>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;
class Graph{
    int V;            // number of vertices

    list <int> *adj; //array of adjecency lists
    map <int, int> pie;
    int *d;
    int *f;
    int t;
    // A recursive function used by DFS
    void DFSUtil(int v, bool visited[]);
  public:
    Graph(int n) //constructor
    {
      V = n;
      adj = new list<int> [n];
      d = new int[V];
      f = new int[V];
      t=1;
    }

    void addEdge(int v, int u);
    void DFS(int s);

    void printPredecessors();

    void decFinishtimeOrder();
};

void Graph :: addEdge(int v, int u){

  cout<<"\nadding edge "<<v<<" to "<<u;
  adj[v].push_back(u);   //only this for directed graph
  //adj[w].push_back(v)  // if it is an undirected graph
}

void Graph::DFSUtil(int v, bool visited[]){
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";
    d[v] = t++;
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i]){
            pie[*i] = v;
            DFSUtil(*i, visited);
          }
          f[v] = t++;
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int v){
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function
    // to print DFS traversal
    pie[v]=v;
    DFSUtil(v, visited);
}

void Graph :: printPredecessors(){
  for(int i=0;i<V;i++){
    cout<<"predecessor of "<<i<<" is "<<pie[i];
    cout<<"--d[v] : "<<d[i]<<" --f[v] : "<<f[i]<<endl;
  }
}

void Graph :: decFinishtimeOrder(){
  vector< pair<int,int> > vect;
  for(int i=0;i<V;i++)
    vect.push_back(make_pair(f[i],i));

  sort(vect.begin(), vect.end(),greater< pair<int, int> >());
  cout<<"\n sorted order acc. to finish time is : "<<endl;
  for(int i=0;i<V;i++)
    cout<<"vertex : "<<vect[i].second<<" --finish time : "<<vect[i].first<<endl;
}

int main(){
  Graph g(5);
  g.addEdge(0,1);
  g.addEdge(0,3);
  g.addEdge(1,2);
  g.addEdge(1,3);
  g.addEdge(3,4);
  g.addEdge(4,1);
  g.addEdge(4,2);
  //g.addEdge(2,5);
  //g.addEdge(5,6);
  cout<<endl<<"Press a key  to continue :";
  getchar();
  g.DFS(0);
  cout<<endl;

  g.printPredecessors();
  cout<<endl<<"Press a key  to continue :";
  getchar();
  g.decFinishtimeOrder();
  cout<<endl;

  return 0;
}
