//max subarray with length atmost l
#include<iostream>

using namespace std;
int main(){
  int a[] = { 2,-3,2,-3,-4,4,2 };
  int n = sizeof(a)/sizeof(a[0]);
  int s =a[0], l=3, j=0, m =0,i=0;
  j++;
  while(j<n){
    if(s<0){
      s=0;

    }
    if(m<s)
      m=s;
    if(j==i+l-1){
        s=s-a[i];
        i++;
    }
    s=s+a[j];

    j++;
  //  cout<<endl<<m<<endl;
  }
  cout<<"max subarray : "<<m<<endl;
  return 0;
}
