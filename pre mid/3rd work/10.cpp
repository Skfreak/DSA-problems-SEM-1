// max subarray
// previous one where we calculated all the values wont be efficient when
// the array values are themselves huge
// so following is better in that case
#include<iostream>

using namespace std;
int main(){
  int a[] = { 2,-3,1,2,5,-4,-1,0,5,4 };
  int n = sizeof(a)/sizeof(a[0]);
  int s =a[0], j=1, m =0;
  while(j<n){
    if(s<0){
      s=0;
    }
    s=s+a[j];
    if(m<s)
      m=s;
    j++;
  }

  cout<<"max subarray : "<<m<<endl;
  return 0;
}
