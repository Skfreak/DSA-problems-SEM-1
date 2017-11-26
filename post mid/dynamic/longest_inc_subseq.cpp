#include<iostream>

using namespace std;

void longestIncSubs(int a[], int size){
  int i, j, res[size], pos[size], n =size;
  for(i=0;i<n;i++){
    res[i] = 1;
    pos[i] = -1;
  }
  int max = 1, index = -1;
  for(i=1;i<n;i++){
    for(j=0;j<i;j++){
      if(a[i] > a[j]){
        if(res[i] < res[j] + 1){
          res[i] = res[j] + 1;
          pos[i] = j;

          if(max < res[i]){
            max = res[i];
            index = i;
          }

        }
      }
    }
  }

  cout<<"\nLongest increasing subsequence is of length : "<<max;
  cout<<"\n Longest inc subsequence in reverse is : ";
  while(index!= -1){
    cout<<a[index]<<" ";
    index = pos[index];
  }


}

int main(){
  int arr[] = {3, 4, -1, 0, 6, 2, 3};
  int n = sizeof(arr)/sizeof(arr[0]);
  longestIncSubs(arr,n);

  cout<<endl;
  return 0;
}
