#include<iostream>
#include<list>
#include<queue>
#include<map>
#include<climits>

using namespace std;
// iPair ==>  Integer Pair
typedef pair<int, int> iPair;

////start of min heap
////end of minheap


////graph part
class Graph{
    int V;            // number of vertices

    list < pair<int,int> > *adj; //array of adjecency lists
    map <int, int> pie;
    map<int, int> distance;
  //  map<int, int > priority;
  public:
    Graph(int n){
      V = n;
      adj = new list< pair<int,int> > [n];
    }

    void addEdge(int v, int u, int w);
    void Prims(int s);

    void printPredecessors();
};

void Graph :: addEdge(int v, int u, int w){

  cout<<"\nadding edge "<<v<<" to "<<u<<" and weight :(undirected) "<<w;
  adj[v].push_back(make_pair(u, w));   //only this for directed graph
  adj[u].push_back(make_pair(v,w));  // if it is an undirected graph
  //priority[v] = INT_MAX;
  //priority[u] = INT_MAX;
}

void Graph :: Prims(int s){


  priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

  // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INT_MAX);

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, s));
    dist[s] = 0;

    vector<bool> inMST(V, false);// keep track of vertices included in MST
    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty()){
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorted path to v through u.
            if (inMST[v]== false && dist[v] > weight)
            {
                // Updating distance of v
                dist[v] = weight;
                pq.push(make_pair(dist[v], v));
                pie[v] = u;
            }
        }
    }

    // Print shortest distances stored in dist[]
    printf("Vertex   Distance in MST\n");
    for (int i = 0; i < V; ++i){
      printf("%d \t\t %d\n", i, dist[i]);
      distance[i] = dist[i];
    }


}


void Graph :: printPredecessors(){
  for(int i=0;i<V;i++)
    cout<<"predecesso of "<<i<<" is "<<pie[i]<<" and distance in MST : "<<distance[i]<<endl;
}

////graph ends here

int main(){
  Graph g(5);
  g.addEdge(0,1,3);
  g.addEdge(0,3,6);
  g.addEdge(1,2,9);
  g.addEdge(1,3,2);
  g.addEdge(3,4,4);
  g.addEdge(4,1,2);
  g.addEdge(4,2,1);
  cout<<endl<<"Press a key  to continue :";
  getchar();
  //g.BFS(0);
  cout<<endl;
  g.Prims(0);
  g.printPredecessors();
  cout<<endl;

  return 0;
}
