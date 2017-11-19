#include<iostream>
#include<list>
#include<stack>
#include<map>

using namespace std;
class Graph{
    int V;            // number of vertices

    list <int> *adj; //array of adjecency lists
    map <int, int> pie;
  public:
    Graph(int n) //constructor
    {
      V = n;
      adj = new list<int> [n];
    }

    void addEdge(int v, int u);
    void DFS(int s);

    void printPredecessors();
};

void Graph :: addEdge(int v, int u){

  cout<<"\nadding edge "<<v<<" to "<<u;
  adj[v].push_back(u);   //only this for directed graph
  //adj[w].push_back(v)  // if it is an undirected graph
}

void Graph :: DFS(int s){

  //first mark all vertices as not visited
  bool *visited = new bool[V];
  for(int i=0;i<V;i++){
    visited[i] = false;
  }

  //pie function for predecessor
  //int *pie = new int[V];

  //create queue for traversal and mark first node as visited
  stack <int> q;
  visited[s] = true;
  pie[s] = s;
  q.push(s);

  //iterator to iterate through all vertices
  list<int>::iterator i;

  cout<<"\nDFS traversal is : \t";
  while(!q.empty()){
    //get first element
    s = q.top();
    cout<<s<<" ";
    q.pop();

    // doing dfs for the given node s
    for(i = adj[s].begin(); i != adj[s].end(); ++i){
        if (!visited[*i]){
            pie[*i] = s;
            visited[*i] = true;
            q.push(*i);
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
  g.addEdge(0,1);
  g.addEdge(0,3);
  g.addEdge(1,2);
  g.addEdge(1,3);
  g.addEdge(3,4);
  g.addEdge(4,1);
  g.addEdge(4,2);
  cout<<endl<<"Press a key  to continue :";
  getchar();
  g.DFS(0);
  cout<<endl;

  g.printPredecessors();
  cout<<endl;

  return 0;
}
