// this is the O(n) algorithm for a[i]+a[j]=x
// Using the concept of hashing
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a[] = { 1, 2, 4, 6, 7, 14, 25, 56, 98, 124, 156, 207, 1250, 2905  };
  int size = sizeof(a)/sizeof(a[0]);
  int t,x, flag = 0, b[100000] = { 0 };
  cout<<"Enter sum to be found : ";
  cin>>x;
  for(int i = 0 ;i<size;i++){
    t = x-a[i];
    if(t>0 && b[x-a[i]]==1){
      flag = 1;
      break;
    }

      b[i] = 1;

  }
  if(flag==1)
    cout<<endl<<"Found"<<endl;
  else
    cout<<endl<<"Not Found"<<endl;

  return 0 ;

}
