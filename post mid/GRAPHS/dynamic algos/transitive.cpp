#include<iostream>

using namespace std;
//function to compute transitive closure
void computeTransitive(int a[][5]){

  int T[5][5], i ,j, k;
  for(i=0;i<5;i++)
    for(j=0;j<5;j++)
      T[i][j] = a[i][j];

  for(k=0;k<5;k++){
    for(i=0;i<5;i++)
      for(j=0;j<5;j++){
        if(T[i][k]==1 && T[k][j]==1)
          T[i][j] = 1;
      }
  }

  cout<<"Transitive closure is :\n";
  for(i=0;i<5;i++){
    for(j=0;j<5;j++)
      cout<<T[i][j]<<"  ";
      cout<<endl;
    }
}
int main(){
  int arr[][5]={{1,1,0,0,0},
                {0,1,1,1,0},
                {0,0,1,0,1},
                {1,0,0,1,1},
                {0,0,0,0,1}};

  computeTransitive(arr);
  return 0;
}
