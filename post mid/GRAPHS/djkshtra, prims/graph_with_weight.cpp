#include<iostream>
#include<list>
#include<queue>
#include<map>

using namespace std;
class Graph{
    int V;            // number of vertices

    list < pair<int,int> > *adj; //array of adjecency lists
    map <int, int> pie;
  public:
    Graph(int n){
      V = n;
      adj = new list< pair<int,int> > [n];
    }

    void addEdge(int v, int u, int w);
    void BFS(int s);

    void printPredecessors();
};

void Graph :: addEdge(int v, int u, int w){

  cout<<"\nadding edge "<<v<<" to "<<u<<" and weight : "<<w;
  adj[v].push_back(make_pair(u, w));   //only this for directed graph
  //adj[w].push_back(v)  // if it is an undirected graph
}

void Graph :: BFS(int s){

  //first mark all vertices as not visited
  bool *visited = new bool[V];
  for(int i=0;i<V;i++){
    visited[i] = false;
  }

  //pie function for predecessor
  //int *pie = new int[V];

  //create queue for traversal and mark first node as visited
  queue <int> q;
  visited[s] = true;
  pie[s] = s;
  q.push(s);

  //iterator to iterate through all vertices
  list< pair<int,int> >::iterator i;

  cout<<"\nBFS traversal is : \t";
  while(!q.empty()){
    //get first element
    s = q.front();
    cout<<s<<" ";
    q.pop();

    // Get all adjacent vertices of the dequeued
    // vertex s. If a adjacent has not been visited,
    // then mark it visited and enqueue it
    for(i = adj[s].begin(); i != adj[s].end(); ++i){
        if (!visited[i->first]){
            pie[i->first] = s;
            visited[i->first] = true;
            q.push(i->first);
        }
    }
  }
}


void Graph :: printPredecessors(){
  for(int i=0;i<V;i++)
    cout<<"predecessor of "<<i<<" is "<<pie[i]<<endl;
}

int main(){
  Graph g(5);
  g.addEdge(0,1,5);
  g.addEdge(0,3,6);
  g.addEdge(1,2,1);
  g.addEdge(1,3,3);
  g.addEdge(3,4,8);
  g.addEdge(4,1,10);
  g.addEdge(4,2,12);
  cout<<endl<<"Press a key  to continue :";
  getchar();
  g.BFS(0);
  cout<<endl;

  g.printPredecessors();
  cout<<endl;

  return 0;
}
