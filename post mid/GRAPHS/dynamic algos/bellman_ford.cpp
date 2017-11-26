#include<iostream>

using namespace std;
#define inf 9999

//function to add edge to graph
void addEdge(int a[6][6], int u, int v, int w){
  a[u][v] = w;
}

int main(){
  int i, j, d[6], pie[6];

  int w[6][6] = {
    { inf,  10,   inf,  inf,  inf,  8   },
    { inf,  inf,  inf,  2,    inf,  inf },
    { inf,  1,    inf,  inf,  inf,  inf },
    { inf,  inf,  -2,   inf,  inf,  inf },
    { inf,  -4,   inf,  -1,   inf,  inf },
    { inf,  inf,  inf,  inf,  1,    inf }
  };

  int s = 0;

  for(j=0;j<6;j++){
      if(w[s][j] != inf)
        d[j] = w[s][j];
      else
        d[j] = inf;
  }
  d[s] = 0;
  for(int k=0; k<5; k++){
    for(i=0;i<6;i++){
      for(j=0;j<6;j++){
        if(w[i][j]!= inf){
          if(d[i] + w[i][j] < d[j])
            { d[j] = d[i] + w[i][j];
              pie[j] = i;
            }
        }
      }
    }
  }

  cout<<endl;
  for(i=0;i<6;i++)
    cout<<d[i]<<" ";

  cout<<endl;



  return 0;
}
