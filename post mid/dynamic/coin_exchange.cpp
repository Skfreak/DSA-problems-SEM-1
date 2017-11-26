#include<iostream>

#define MAX 9999
using namespace std;

//function for calculating the result
int coinChange(int a[], int t, int size){
  int s = size;
  int T[t+1], R[t+1];
  T[0] = 0;
  //cout<<endl<<s<<endl;
  //initializing the two arrays
  for(int i=1;i<=t;i++){
    T[i] = MAX;
    R[i] = -1;
  }

  //actual work starts now
  for(int i=0;i<s;i++){
    for(int j=1;j<=t;j++){
      if(j >= a[i]){
        if(T[j - a[i]]+1 < T[j]){
          T[j] = T[j - a[i]]+1;
          R[j] = i;
        }
      }
    }
  }
  //if(R[t]!= -1) then only following is possible
  cout<<" Total coins required are : "<<T[t];

  cout<<endl<<"The combination of coins are : ";
  int start = t;

  while( start > 0){
    int j = R[start];
    cout<<a[j]<<" ";
    start = start - a[j];
  }
  //cout<<R[t];


  return T[t];

}


int main(){
  int denom[] = {2,3,6,5};    //denominations
  int total = 25;             //total we want

  int s = sizeof(denom)/sizeof(denom[0]);
  //calling the function
  int t = coinChange(denom, total, s);
  //cout<<endl<<s<<endl;
  //cout<<"Coins required for "<<total<<" are : "<<t<<endl;
  return 0;
}
