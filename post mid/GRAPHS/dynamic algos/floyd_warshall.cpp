#include<iostream>
#include<climits>

#define MAX 99999
#define NIL -1
using namespace std;

/* A utility function to print solution */
void printSolution(int dist[][5], int N[][5])
{
    int V = 5;
    cout<<"Following matrix shows the shortest distances";
    cout<<" between every pair of vertices \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == MAX)
                cout<<"MAX\t";
            else
                cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nFollowing is the matrix showing number of shortest paths \n";
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
        cout<<N[i][j]<<"  ";
      }
      cout<<endl;
    }
}

//print the path
void PSP(int pie[][5], int i, int j){
  if(pie[i][j] != NIL){
    int k = pie[i][j];
    PSP(pie, i, k);
    cout<<" "<<k;
    PSP(pie, k, j);
  }
}

// Solves the all-pairs shortest path problem using Floyd Warshall algorithm
void APSP (int graph[][5]){
    int V = 5;
    /* dist[][] will be the output matrix that will finally have the shortest
      distances between every pair of vertices */
    int dist[5][5], i, j, k, pie[5][5], N[5][5];

    /* Initialize the solution matrix same as input graph matrix. Or
       we can say the initial values of shortest distances are based
       on shortest paths considering no intermediate vertex. */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++){
            dist[i][j] = graph[i][j];
            pie[i][j] = NIL;
            if(graph[i][j]==0 || graph[i][j]==MAX)
              N[i][j] = 0;
            else
              N[i][j] = 1;
          }
    /* Add all vertices one by one to the set of intermediate vertices.
      ---> Before start of a iteration, we have shortest distances between all
      pairs of vertices such that the shortest distances consider only the
      vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of a iteration, vertex no. k is added to the set of
      intermediate vertices and the set becomes {0, 1, 2, .. k} */
    for (k = 0; k < V; k++){
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++){
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++){
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pie[i][j] = k;
                    N[i][j] = N[i][k] * N[k][j];
                  }
                else if(dist[i][k] + dist[k][j] == dist[i][j]){
                  N[i][j] = N[i][j] + (N[i][k] * N[k][j]);
                }
            }
        }
    }
    // Print the shortest distance matrix
    printSolution(dist, N);
/*
    char ch;
    cout<<"\nDo you want the shortest path b/w the vertices : ";
    cin>>ch;
    if(ch=='y'){
      int i, j;
      cout<<"\nEnter the vertices : ";
      cin>>i>>j;
      PSP(pie,i,j);
    }
*/
}



int main(){
  int arr[][5]  = {
                    {0,3,MAX,MAX,1},
                    {MAX,0,MAX,MAX,4},
                    {1,MAX,0,MAX,3},
                    {MAX,1,MAX,0,8},
                    {MAX,2,MAX,MAX,0}
                  };
  APSP(arr);
  return 0;
}
